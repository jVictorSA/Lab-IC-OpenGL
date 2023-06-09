#include "primitivas.hpp"
#include "cores.hpp"
#include "SOIL.h"
#include "matematica.hpp"

class Solua{
    private:
        float x, y, z;
        std::vector<float> cor;
        GLfloat luzAmbiente[4] = {0.1, 0.1, 0.1, 1.0};
        bool noite = false;
        GLfloat a = 0.9;
        GLfloat b = 0.9;
        GLfloat c = 1.0; 
        
        GLfloat sunColor[4] = { 1.0f, 1.0f, 0.0f, 1.0f };
        
        float intensidadeLuzDiaNoite = 0.25;
        
        float intervaloIntensidadeLuz = 0.15;
        float anguloSol = 0;

    public:
        GLuint sunTextureID;
        GLuint moonTextureID;
        Solua(float x1, float y1, float z1){
            x = x1;
            y = y1;
            z = z1;
        }


        ~Solua(){}

        float normalize(float valor, float min, float max){
            x = (valor - min) / (max - min);
            return x;
        }

        // Modifica a movimentação do sol e a iluminação com base no angulo do corpo celeste
        void cicloDiaNoite(){
            // Atualiza o angulo do Sol
            anguloSol = anguloSol + 0.5;

            // Reseta o angulo
            if(anguloSol > 360){ anguloSol = 0; }

            // Durante o dia
            if(anguloSol < 160 || anguloSol > 340 ){
                intensidadeLuzDiaNoite += (clamp<float>(intervaloIntensidadeLuz, 0.05, 0.3) / 300);
                
                luzAmbiente[0] = intensidadeLuzDiaNoite;
                luzAmbiente[1] = intensidadeLuzDiaNoite;
                luzAmbiente[2] = intensidadeLuzDiaNoite;
                luzAmbiente[3] = intensidadeLuzDiaNoite;
                
                luzDia();   

            // Durante a noite                 
            }else{                
                intensidadeLuzDiaNoite -= (clamp<float>(intervaloIntensidadeLuz, 0.05, 0.3) / 300);
                
                luzAmbiente[0] = intensidadeLuzDiaNoite;
                luzAmbiente[1] = intensidadeLuzDiaNoite;
                luzAmbiente[2] = intensidadeLuzDiaNoite;
                luzAmbiente[3] = intensidadeLuzDiaNoite;

                luzNoite();
            }
        }

        void desenhar(){

            GLfloat luzDifusa[4] = {0.7, 0.7, 0.7, 1.0};    // "cor"
            GLfloat luzEspecular[4] = {1.0, 1.0, 1.0, 1.0}; // "brilho"
            GLfloat posicaoLuz[4] = {this->x, this->y, this->z + 50, 1};


            GLfloat materialAmbient[] = {0.25f, 0.25f, 0.25f, 1.0f};
            GLfloat materialDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
            GLfloat materialSpecular[] = {0.3,0.3,0.3,1};
            GLfloat materialShininess[] = {50.0};
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialAmbient);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialDiffuse);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materialSpecular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

            // Capacidade de brilho do material
            // GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0};
            // GLint especMaterial = 60;

            glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

            // glEnable(GL_CULL_FACE);
            // glCullFace(GL_BACK);

            // Habilita o modelo de colorização de Gouraud
            glShadeModel(GL_SMOOTH);

            // Define a refletância do material
            // glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
            // // Define a concentração do brilho
            // glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
            


            // Ativa o uso da luz ambiente
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

            // glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, lua);
            // Define os parâmetros da luz de número 0
            glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
            glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
            glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

            // Habilita a definição da cor do material a partir da cor corrente
            glEnable(GL_COLOR_MATERIAL);
            // Habilita o uso de iluminação
            glEnable(GL_LIGHTING);
            // Habilita a luz de número 0
            glEnable(GL_LIGHT0);
            // Habilita o depth-buffering
            glEnable(GL_DEPTH_TEST);
            
            if (sunTextureID == 0){
                sunTextureID = SOIL_load_OGL_texture("texturas/sun.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                         SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA);
            }

            if(moonTextureID == 0){
                moonTextureID = SOIL_load_OGL_texture("texturas/moon.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                         SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA);
            }
            
            glEnable(GL_TEXTURE_2D);
            if(noite){
                glBindTexture(GL_TEXTURE_2D, moonTextureID);
            }
            else{
                glBindTexture(GL_TEXTURE_2D, sunTextureID);
            }
            
            glEnable(GL_TEXTURE_GEN_S);
            glEnable(GL_TEXTURE_GEN_T);
            GLfloat texCoordScaleS = 0.0;
            GLfloat texCoordScaleT = 0.01;
            glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
            glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
            GLfloat texGenS[] = {0.0f, texCoordScaleS, 0.0f, 0.0f, 0.0f};
            GLfloat texGenT[] = {0.0f,  texCoordScaleT, 0.0f, 0.5f};
            glTexGenfv(GL_S, GL_OBJECT_PLANE, texGenS);
            glTexGenfv(GL_T, GL_OBJECT_PLANE, texGenT);
            

            // A cada frame:
            //      Translada o sol de acordo com o angulo
            //      Atualiza a iluminação com a função cicloDiaNoite()
            glPushMatrix();
                
                cicloDiaNoite();
                glRotatef(anguloSol,0.5,0.5,0);
                glColor3f(a,b,c);
                glTranslatef(this->x, this->y, this->z);
                glutSolidSphere(10,50,50);                
                
            glPopMatrix();
            glDisable(GL_TEXTURE_GEN_S);
            glDisable(GL_TEXTURE_GEN_T);

            glDisable(GL_TEXTURE_2D);

            // glFlush();
            // glutSwapBuffers();
        
        glEnd();
    }
        

    void luzNoite(){
        a = 0.9;
        b = 0.9;
        c = 1.0;
        luzAmbiente[0] = intensidadeLuzDiaNoite;
        luzAmbiente[1] = intensidadeLuzDiaNoite;
        luzAmbiente[2] = intensidadeLuzDiaNoite;
        luzAmbiente[3] = intensidadeLuzDiaNoite;
        noite = true;
    }

    void luzDia(){
        b=0.9;
        c=0.4;
        
        luzAmbiente[0] = intensidadeLuzDiaNoite;
        luzAmbiente[1] = intensidadeLuzDiaNoite;
        luzAmbiente[2] = intensidadeLuzDiaNoite;
        luzAmbiente[3] = intensidadeLuzDiaNoite;
        noite = false;
    }

    void diaNoite(){

        if(noite){
            luzDia();
        }
        else{
            luzNoite();
        }
    }
};
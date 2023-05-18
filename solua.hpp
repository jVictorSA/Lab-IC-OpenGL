#include "primitivas.hpp"
#include "cores.hpp"

class Solua{
    private:
        float x, y, z;
        std::vector<float> cor;
        GLfloat luzAmbiente[4] = {0.1, 0.1, 0.1, 1.0};
        bool noite = true;
        GLfloat a = 0.9;
        GLfloat b = 0.9;
        GLfloat c = 1.0; 
        

    public:
        Solua(float x1, float y1, float z1){
            x = x1;
            y = y1;
            z = z1;
            
            
            
        }

        ~Solua(){}

        void desenhar(){

            
            GLfloat luzDifusa[4] = {0.7, 0.7, 0.7, 1.0};    // "cor"
            GLfloat luzEspecular[4] = {1.0, 1.0, 1.0, 1.0}; // "brilho"
            GLfloat posicaoLuz[4] = {this->x, this->y, this->z + 50, 1};


            GLfloat materialAmbient[] = {0.25f, 0.25f, 0.25f, 1.0f};
            GLfloat materialDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
            GLfloat materialSpecular[] = {a,b,c,1};
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

            glPushMatrix();
                
                glColor3f(a,b,c);
                glTranslatef(this->x, this->y, this->z);
                glutSolidSphere(10,40,40);
                
                
            glPopMatrix();
        
        glEnd();
    }
        

    void diaNoite(){

        if(noite){
            b=0.9;
            c=0.4;
            
            luzAmbiente[0] = 0.2;
            luzAmbiente[1] = 0.2;
            luzAmbiente[2] = 0.2;
            luzAmbiente[3] = 0.2;
            noite = false;

        }
        else{
            a = 0.9;
            b = 0.9;
            c = 1.0;
            luzAmbiente[0] = 0.1;
            luzAmbiente[1] = 0.1;
            luzAmbiente[2] = 0.1;
            luzAmbiente[3] = 0.1;
            noite = true;
        }
    }
};
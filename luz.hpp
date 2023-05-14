#include "primitivas.hpp"
#include "cores.hpp"

class Luz
{
public:
    float xHaste, yHaste, zHaste;
    std::vector<float> corLuz;
    bool desligado = true;

    Luz(float x, float y, float z, std::vector<float> cor)
    {
        xHaste = x, yHaste = y, zHaste = z;
        corLuz = cor;
    }

    void desenhaLuz()
    {

        glPushMatrix();

        glTranslatef(xHaste, yHaste, zHaste);
        glRotatef(-90, 0, 1, 0);
        paralelepipedoFechado(1.66, 0.1, 0.1, 0, 0, 0, cinza);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(xHaste - 0.7, yHaste, zHaste - 0.05);
        glRotatef(-90, 1, 0, 0);
        glRotatef(-90, 0, 0, 1);
        paralelepipedoFechado(1.5, 0.2, 0.2, 0, 0, 0, corLuz);

        glPopMatrix();
        glPopMatrix();
    }

    void ligaDesliga()
    {
        if (this->desligado)
        {
            this->desligado = false;
            this->corLuz = branco;
            
            GLfloat luzAmbiente[4]={0.1,0.1,0.1,1.0};
            GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};	   // "cor"
            GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho"
            
            GLfloat posicaoLuz[4]={this->xHaste, this->yHaste - 3, this->zHaste, 1.0};
            GLfloat spotdirection[] = {0,-1,0};

            // Capacidade de brilho do material
            GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
            GLint especMaterial = 60;

            

            

            // Define a refletância do material
            glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
            // Define a concentração do brilho
            glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

            // Ativa o uso da luz ambiente
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

            // Define os parâmetros da luz de número 0
            glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente);
            glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa );
            glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular );
            glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz );

            // glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
            
            // glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,spotdirection);

            // Habilita a definição da cor do material a partir da cor corrente
            glEnable(GL_COLOR_MATERIAL);
            
            
            glEnable(GL_LIGHT1);
            // Habilita o depth-buffering
            glEnable(GL_DEPTH_TEST);

            
        }
        else
        {
            glDisable(GL_LIGHT1);
            this->corLuz = cinza;
            this->desligado = true;
        }
    }
};
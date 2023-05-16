#include "primitivas.hpp"
#include "cores.hpp"
#include <iostream>

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

            GLfloat luzAmbiente[4] = {0.4, 0.4, 0.4, 1.0};
            
            // glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
            glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente);
            glLightfv(GL_LIGHT2, GL_AMBIENT, luzAmbiente);
            
            
            glEnable(GL_LIGHT1);
            glEnable(GL_LIGHT2);
            
            

            
        }
        else
        {
            glDisable(GL_LIGHT1);
            glDisable(GL_LIGHT2);
            this->corLuz = cinza;
            this->desligado = true;
        }
    }
};
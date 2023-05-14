#include "primitivas.hpp"
#include "cores.hpp"

class Solua{
    private:
        float x, y, z;
        std::vector<float> cor;

    public:
        Solua(float x1, float y1, float z1){
            x = x1;
            y = y1;
            z = z1;
            
            
        }

        ~Solua(){}

        void desenhar(){
            GLfloat luzAmbiente[4] = {0.1, 0.1, 0.1, 1.0};
            GLfloat luzDifusa[4] = {0.7, 0.7, 0.7, 1.0};    // "cor"
            GLfloat luzEspecular[4] = {1.0, 1.0, 1.0, 1.0}; // "brilho"
            GLfloat posicaoLuz[] = {this->x, this->y, this->z, 1};

            // Capacidade de brilho do material
            GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0};
            GLint especMaterial = 60;

            

            // Habilita o modelo de colorização de Gouraud
            glShadeModel(GL_SMOOTH);

            
            
            // Habilita o uso de iluminação
            glEnable(GL_LIGHTING);
            glEnable(GL_LIGHT0);
            glEnable(GL_DEPTH_TEST);
            glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
            glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
            glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
            glEnable(GL_COLOR_MATERIAL);
            
            glPushMatrix();
                glColor3f(cinza[1],cinza[1],cinza[1]);
                glTranslatef(this->x, this->y, this->z);
                glutSolidSphere(10,40,40);
                
            glPopMatrix();
        }
};
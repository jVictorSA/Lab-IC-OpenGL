#include "primitivas.hpp"
#include "cores.hpp"

class Luz{
    public:
        float xHaste, yHaste, zHaste;
        std::vector<float> corHaste;
        

        Luz(float x, float y, float z, std::vector<float> cor){
            xHaste = x, yHaste = y, zHaste = z;
            corHaste = cor;
        }

        void desenhaLuz(){
        
            glPushMatrix();
            
                glTranslatef(xHaste,yHaste,zHaste);
                glRotatef(-90,0,1,0);
                paralelepipedoFechado(1.66,0.1,0.1, 0,0,0, corHaste);
                glPopMatrix();

                glPushMatrix();
                    glTranslatef(xHaste - 0.7,yHaste,zHaste-0.05); 
                    glRotatef(-90,1,0,0);
                    glRotatef(-90,0,0,1);
                    paralelepipedoFechado(1.5, 0.2, 0.2, 0,0,0, cinza);
                


            glPopMatrix();
        glPopMatrix();
        }
};       
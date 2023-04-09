#include "cores.hpp"

class Luz{
    public:
        float xHaste, yHaste, zHaste;
        

        Luz(float x, float y, float z){ xHaste = x, yHaste = y, zHaste = z;}

        void desenhaLuz(){
        
        glPushMatrix();
            
            glTranslatef(xHaste,yHaste,zHaste);
            glRotatef(-90,0,1,0);
            paralelepipedoFechado(1.66,0.1,0.1, 0,0,0,Brown);
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
#include "cores.hpp"


class Ventilador{
    public:
        float xHaste, yHaste, zHaste;
        float angulo;

        Ventilador(float x, float y, float z){ xHaste = x, yHaste = y, zHaste = z;}

        void desenhaVentilador(){
            glPushMatrix();
            glTranslatef(xHaste,yHaste,zHaste);
            glRotatef(-90,0,1,0);
            paralelepipedoFechado(1.5,0.1,0.1, 0,0,0,rosa);
            glPopMatrix();



            glPushMatrix();
            glTranslatef(xHaste+0.07,yHaste-0.1,zHaste + 0.15);
            glRotatef(90,0,0,1);
            trianguloFechado(0.7, 0.1, 0.2,0,0,0,vermelho);
            glPopMatrix();


            glPushMatrix();
            glTranslatef(xHaste+0.15,yHaste-0.1,zHaste + 0.15);
            glRotatef(90,0,0,1);
            glRotatef(90,1,0,0);
            trianguloFechado(0.7, 0.1, 0.2,0,0,0,azul);
            glPopMatrix();



            glPushMatrix();
            glTranslatef(xHaste+0.07,yHaste-0.1,zHaste + 0.15);
            glRotatef(90,0,0,1);
            glScalef(1,-1,1);
            trianguloFechado(0.7, 0.1, 0.2,0,0,0,branco);
            glPopMatrix();


            glPushMatrix();
            glTranslatef(xHaste+0.15,yHaste-0.1,zHaste + 0.15);
            glRotatef(90,0,0,1);
            glRotatef(90,1,0,0);
            glScalef(1,-1,1);
            trianguloFechado(0.7, 0.1, 0.2,0,0,0,verde);
            glPopMatrix();


            
            
        }
};
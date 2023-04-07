#ifndef ARMARIOS_HPP
#define ARMARIOS_HPP
#include "primitivas.hpp"
#include "cores.hpp"

class Armario
{
private:
    float altura, largura, profundidade;
public:
    Armario(float alt, float larg, float prof){
        altura = alt;
        largura = larg;
        profundidade = prof;
    }

    ~Armario(){

    }

    void desenhar(){
        glPushMatrix();
            // Fundo
            paralelepipedoFechado(1,1.5,0.01,0,0,0,vermelho);
            
            // Laterais
            glPushMatrix();
                glRotatef(90,0,1,0);
                glTranslatef(-1.5,0,0);
                paralelepipedoFechado(1,1.5,0.01,0,0,0,branco);
                glTranslatef(0,0,1.5);
                paralelepipedoFechado(1,1.5,0.01,0,0,0,branco);
            glPopMatrix();

            // Parte de baixo e de cima
            glPushMatrix();
                glRotatef(90,1,0,0);
                paralelepipedoFechado(1.5,1.5,0.01,0,0,0,azul);
                glTranslatef(0,0,-1);
                paralelepipedoFechado(1.5,1.5,0.01,0,0,0,azul);
            glPopMatrix();
            
            //Tampa
            glPushMatrix();
                glTranslatef(0,0,1.5);
                paralelepipedoFechado(1,1.5,0.01,0,0,0,verde);
            glPopMatrix();
        glPopMatrix();
    };
};




#endif
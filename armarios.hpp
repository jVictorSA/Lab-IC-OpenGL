#ifndef ARMARIOS_HPP
#define ARMARIOS_HPP

#include <typeinfo>
#include "primitivas.hpp"
#include "cores.hpp"
#include "matematica.hpp"

// Valor do angulo que a porta deve se mexer
float anguloPorta = 1;

//Magnitude do movimento que deve ser incrementado ao angulo da porta
float movimentoAbertura = 0.5;
class Armario {
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
                
                // Porta
                glPushMatrix();
                    glTranslatef(0,1,1.5);
                    glRotatef(180, 1,0,0);
                    anguloPorta += movimentoAbertura;

                    anguloPorta = clamp<float>(anguloPorta, -90.0, 0.0);
                    
                    glRotatef(anguloPorta, 1,0,0);
                    paralelepipedoFechado(1,1.5,0.01,0,0,0,verde);
                    glTranslatef(0.60,0.8,-0.01);
                    paralelepipedoFechado(0.1,0.35,0.07,0,0,0,vermelho);
                glPopMatrix();
            glPopMatrix();
        };

        void abrirOuFecharPorta(){
            // Inverte a movimentação da porta para que ela abra ou feche
            movimentoAbertura *= -1;

        }
};




#endif
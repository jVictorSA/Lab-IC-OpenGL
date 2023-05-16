#ifndef PORTA_HPP
#define PORTA_HPP

#include "primitivas.hpp"
#include "cores.hpp"
#include "matematica.hpp"

class Porta{
    private:
        float altura, largura, profundidade;
        std::vector<float> corPorta, corMacaneta;

        // Valor do angulo que a porta deve se mexer
        float anguloPorta = 0;
        // Valor do angulo que a maçaneta deve se mexer
        float anguloMaçaneta = 0;


        //Magnitude do movimento que deve ser incrementado ao angulo da porta
        float movimentoAberturaPorta = 0.2;

        //Magnitude do movimento que deve ser incrementado ao angulo da maçaneta
        float movimentoAberturaMaçaneta = 0.5;

    public:

        Porta(float alt, float larg, float prof, std::vector<float> corP, std::vector<float> corM){
            altura = alt;
            largura = larg;
            profundidade = prof;
            corPorta = corP;
            corMacaneta = corM;
        }

        ~Porta(){}

        void desenhar(){
            glPushMatrix();
                glNormal3f(0,0,1);
                // Centralização
                glTranslatef(0, 0, profundidade/2);
                glPushMatrix();
                    anguloPorta += movimentoAberturaPorta;

                    anguloPorta = clamp<float>(anguloPorta, -85.0, 0.0);
                    
                    glTranslatef(largura, 0, 0);
                    glRotatef(anguloPorta, 0 , 1, 0);
                    glTranslatef(-largura, 0, 0);                    

                    paralelepipedoFechado(altura,largura, profundidade, 0,0,0, corPorta);

                    // Maçanetas
                    glPushMatrix();
                        glTranslatef(largura/10,altura/2,profundidade*2);

                        // Movimenta a maçaneta
                        anguloMaçaneta += movimentoAberturaMaçaneta;

                        // Quando a maçaneta for totalmente rotacionada ela volta a posição inicial
                        if(anguloMaçaneta == -45){
                            movimentoAberturaMaçaneta  *= -1 ;
                        }

                        anguloMaçaneta = clamp<float>(anguloMaçaneta, -45.0, 0.0);
                        glRotatef(anguloMaçaneta,0,0,1);

                        // Maçaneta da parte exterior
                        paralelepipedoFechado(altura/45,largura/5, profundidade, 0,0,0, corMacaneta);
                        paralelepipedoFechado(altura/45,largura/45, profundidade*2, 0,0,0, corMacaneta);

                        glTranslatef(0, 0, -profundidade*4);
                        // Maçaneta da parte interior
                        paralelepipedoFechado(altura/45,largura/5, profundidade, 0,0,0, corMacaneta);
                        glTranslatef(0, 0, profundidade*2);
                        paralelepipedoFechado(altura/45,largura/45, profundidade*2, 0,0,0, corMacaneta);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        }


        void abrirOuFecharPorta(){
            // Garante que a moivmentação da maçaneta só ocorre quando a porta for aberta
            // Não faz sentido girar a maçaneta ao fechar a porta
            if(movimentoAberturaPorta > 0){
                movimentoAberturaMaçaneta *= -1;
            }
            // Inverte a movimentação da porta para que ela abra ou feche
            movimentoAberturaPorta *= -1;
        }

};

#endif
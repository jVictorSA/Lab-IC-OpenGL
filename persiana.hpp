#ifndef PERSIANA_HPP
#define PERSIANA_HPP

#include <iostream>
#include "primitivas.hpp"
#include "cores.hpp"
#include "matematica.hpp"

// Persiana que fica nas janelas do laboratório
class Persiana{
    private: 
    float largura, altura, profundidade, larguraLamina, alturaSuporte;
    int quantidadadeLaminas;

    // Valor do angulo que a persiana deve se mexer
    float anguloPersiana = 60;

    //Magnitude do movimento que deve ser incrementado ao angulo da persiana
    float movimentoAberturaPersiana = 0.2;

    std::vector<float> corSuporte, corLamina;

    public:
        Persiana(float larg, float alt, float prof, float largLam, float altSup, int qLam, std::vector<float> corS, std::vector<float> corL){
            largura = larg;
            altura = alt;
            profundidade = prof;
            larguraLamina = largLam;
            alturaSuporte = altSup;
            quantidadadeLaminas = qLam;
            corSuporte = corS;
            corLamina = corL;
        }

        void desenhar(){
            glPushMatrix();
                // Centralização
                glTranslatef(-largura/2, altura/2, profundidade/2);
                
                anguloPersiana += movimentoAberturaPersiana;

                anguloPersiana = clamp<float>(anguloPersiana, 0.0, 50.0);

                glPushMatrix();
                    paralelepipedoFechado(alturaSuporte,largura, profundidade, 0,0,0, corSuporte);
                    glTranslatef(larguraLamina, - (altura-alturaSuporte), - profundidade*0.05);
                    
                    glPushMatrix();
                        glRotatef(anguloPersiana,0,1,0);
                        paralelepipedoFechado(altura-alturaSuporte, larguraLamina, profundidade, 0,0,0, corLamina);
                    glPopMatrix();
                    
                    for(int i = 0; i < quantidadadeLaminas-1; i++){
                        glTranslatef(largura/quantidadadeLaminas, 0, 0);
                        glPushMatrix();
                            glRotatef(anguloPersiana,0,1,0);
                            paralelepipedoFechado(altura-alturaSuporte, larguraLamina, profundidade, 0,0,0, corLamina);
                        glPopMatrix();
                    }
                glPopMatrix();
            glPopMatrix();
        }

        void abrirOuFecharPersiana(){
            // Inverte a movimentação da persiana para que ela abra ou feche
            movimentoAberturaPersiana *= -1;

        }
};

#endif
#ifndef PERSIANA_HPP
#define PERSIANA_HPP

#include <iostream>
#include "primitivas.hpp"
#include "cores.hpp"
#include "matematica.hpp"

// Valor do angulo que a persiana deve se mexer
float anguloPersiana = 60;

//Magnitude do movimento que deve ser incrementado ao angulo da persiana
float movimentoAberturaPersiana = 0.2;

vector<vector<float>> cores{Transparente, branco, vermelho, verde, azul,rosa,
                            Yellow, Cyan, Black,
                            Aquamarine, BlueViolet, Brown, CadetBlue};


// Persiana que fica nas janelas do laboratório
class Persiana{
    private: 
    float largura, altura, profundidade, larguraLamina, alturaSuporte;

    public:
        Persiana(float larg, float alt, float prof, float largLam, float altSup){
            largura = larg;
            altura = alt;
            profundidade = prof;
            larguraLamina = largLam;
            alturaSuporte = altSup;
        }

        void desenhar(){
            // Centralização
            glTranslatef(-largura/2, altura/2, profundidade/2);
            
            anguloPersiana += movimentoAberturaPersiana;

            anguloPersiana = clamp<float>(anguloPersiana, 0.0, 50.0);

            glPushMatrix();
                paralelepipedoFechado(alturaSuporte,largura, profundidade, 0,0,0, branco);
                glTranslatef(larguraLamina, - (altura-alturaSuporte), - profundidade*0.05);
                
                glPushMatrix();
                    glRotatef(anguloPersiana,0,1,0);
                    paralelepipedoFechado(altura-alturaSuporte, larguraLamina, profundidade, 0,0,0, vermelho);
                glPopMatrix();
                
                for(int i = 0; i < int(largura/(larguraLamina*2.5)) -1; i++){
                    glTranslatef(larguraLamina*2.5, 0, 0);
                    glPushMatrix();
                        glRotatef(anguloPersiana,0,1,0);
                        paralelepipedoFechado(altura-alturaSuporte, larguraLamina, profundidade, 0,0,0, cores[i%13]);
                    glPopMatrix();
                }
            glPopMatrix();
        }

        void abrirOuFecharPersiana(){
            // Inverte a movimentação da porta para que ela abra ou feche
            movimentoAberturaPersiana *= -1;

        }
};

#endif
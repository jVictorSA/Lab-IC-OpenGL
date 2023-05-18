#ifndef PERSIANA_HPP
#define PERSIANA_HPP

#include <iostream>
#include "primitivas.hpp"
#include "cores.hpp"
#include "matematica.hpp"
#include "SOIL.h"

// Persiana que fica nas janelas do laboratório
class Persiana{
    private: 
    float largura, altura, profundidade, larguraLamina, alturaSuporte;
    int quantidadadeLaminas;
    GLuint persianaTextureID;

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
                glNormal3f(0,0,1);
                // Centralização
                glTranslatef(-largura/2, altura/2, profundidade/2);
                
                anguloPersiana += movimentoAberturaPersiana;

                anguloPersiana = clamp<float>(anguloPersiana, 0.0, 50.0);

                if(persianaTextureID == 0){
                persianaTextureID = SOIL_load_OGL_texture("texturas/persian.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                         SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA);
            }
            
                glEnable(GL_TEXTURE_2D);
                
                glBindTexture(GL_TEXTURE_2D, persianaTextureID);
                glEnable(GL_TEXTURE_GEN_S);
                glEnable(GL_TEXTURE_GEN_T);
                GLfloat texCoordScaleS = 0.3;
                GLfloat texCoordScaleT = 0.3;
                glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
                glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
                GLfloat texGenS[] = {0.0f, texCoordScaleS, 0.0f, 0.0f, 0.0f};
                GLfloat texGenT[] = {0.0f,  texCoordScaleT, 0.0f, 0.0f};
                glTexGenfv(GL_S, GL_OBJECT_PLANE, texGenS);
                glTexGenfv(GL_T, GL_OBJECT_PLANE, texGenT);

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
            glDisable(GL_TEXTURE_GEN_S);
            glDisable(GL_TEXTURE_GEN_T);

            glDisable(GL_TEXTURE_2D);

            // glFlush();
            // glutSwapBuffers();
        }

        void abrirOuFecharPersiana(){
            // Inverte a movimentação da persiana para que ela abra ou feche
            movimentoAberturaPersiana *= -1;

        }
};

#endif
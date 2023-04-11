#ifndef JANELA_HPP
#define JANELA_HPP

#include "primitivas.hpp"
#include "cores.hpp"

class Janela{
    private:
        float altura, largura, profundidade;
        std::vector<float> corJanela, corGrade;

        // Valor do angulo que a persiana deve se mexer
        float anguloJanela = 0;

        //Magnitude do movimento que deve ser incrementado ao angulo da persiana
        float movimentoAberturaJanela = 0.2;

    public:
        Janela(float alt, float larg, float prof,
               std::vector<float> corJ, std::vector<float> corG){
            altura = alt;
            largura = larg;
            profundidade = prof;
            corJanela = corJ;
            corGrade = corG;
        }

        ~Janela(){}

        void desenhar(){
            glPushMatrix();
                // Centralização
                glTranslatef(-largura/2, -altura/2, profundidade/2);

                // Armação da Janela
                glPushMatrix();
                    glTranslatef(0, -altura/35, 0);
                    paralelepipedoFechado(altura/35,largura, profundidade, 0,0,0, corJanela);
                    
                    glPushMatrix();
                        glTranslatef(0, altura/35, 0);
                        paralelepipedoFechado(altura,largura/35, profundidade, 0,0,0, corJanela);
                        glTranslatef(largura-largura/35, 0, 0);
                        paralelepipedoFechado(altura,largura/35, profundidade, 0,0,0, corJanela);
                    glPopMatrix();
                    
                    glTranslatef(0, altura + (altura/35), 0);
                    paralelepipedoFechado(altura/35,largura, profundidade, 0,0,0, corJanela);
                glPopMatrix();
                
                // Quadros da janela
                for(int i = 0; i < 4; i++){
                    glPushMatrix();
                        anguloJanela += movimentoAberturaJanela;

                        anguloJanela = clamp<float>(anguloJanela, -70.0, 0.0);
                        
                        glTranslatef((largura/4)/2,0,0);
                        glRotatef(anguloJanela, 0, 1, 0);
                        glTranslatef((-largura/4)/2,0,0);

                        paralelepipedoFechado(altura,largura/35, profundidade, 0,0,0, corJanela);
                        paralelepipedoFechado(altura/35,largura/4, profundidade, 0,0,0, corJanela);
                        
                        glPushMatrix();
                            glTranslatef(largura/4 - largura/35,0,0);
                            paralelepipedoFechado(altura,largura/35, profundidade, 0,0,0, corJanela);
                        glPopMatrix();

                        glTranslatef(0,altura - altura/35,0);
                        paralelepipedoFechado(altura/35,largura/4, profundidade, 0,0,0, corJanela);
                        
                    glPopMatrix();
                    glTranslatef(largura/4,0,0);
                }


                glTranslatef(-largura*1.3,0,- profundidade);
                glPushMatrix();
                    glTranslatef(0, - altura * 0.05 , - profundidade*1.3);
                    paralelepipedoFechado(altura/35,largura*1.6, profundidade * 0.5, 0,0,0, corGrade);
                    
                    glPushMatrix();
                        glTranslatef(0, 0, profundidade*1.9);                    
                        paralelepipedoFechado(altura/35, largura*0.06, profundidade*2, 0,0,0, corGrade);
                        glTranslatef(largura*1.53 , 0, 0);
                        paralelepipedoFechado(altura/35, largura*0.06, profundidade*2, 0,0,0, corGrade);
                    glPopMatrix();

                    glTranslatef(0, altura * 1.1, 0);
                    paralelepipedoFechado(altura/35,largura*1.6, profundidade * 0.5, 0,0,0, corGrade);
                    
                    glPushMatrix();
                        glTranslatef(0, 0, profundidade*1.9);                    
                        paralelepipedoFechado(altura/35, largura*0.06, profundidade*2, 0,0,0, corGrade);
                        glTranslatef(largura*1.53 , 0, 0);
                        paralelepipedoFechado(altura/35, largura*0.06, profundidade*2, 0,0,0, corGrade);
                    glPopMatrix();

                glPopMatrix();

                glPushMatrix();
                    glTranslatef(0, - altura * 0.05 , - profundidade*1.3);
                    paralelepipedoFechado(altura * 1.1, largura*0.06, profundidade*0.5, 0,0,0, corGrade);
                    
                    glPushMatrix();
                        glTranslatef(largura*1.53 , 0, 0);
                        paralelepipedoFechado(altura * 1.1, largura*0.06, profundidade*0.5, 0,0,0, corGrade);
                    glPopMatrix();

                    
                    glTranslatef(largura*0.3 , 0, 0);
                    paralelepipedoFechado(altura * 1.1, largura*0.06, profundidade*0.5, 0,0,0, corGrade);
                    glTranslatef(largura*0.3 , 0, 0);
                    paralelepipedoFechado(altura * 1.1, largura*0.06, profundidade*0.5, 0,0,0, corGrade);
                    glTranslatef(largura*0.3 , 0, 0);
                    paralelepipedoFechado(altura * 1.1, largura*0.06, profundidade*0.5, 0,0,0, corGrade);
                    glTranslatef(largura*0.3 , 0, 0);
                    paralelepipedoFechado(altura * 1.1, largura*0.06, profundidade*0.5, 0,0,0, corGrade);
                
                glPopMatrix();
            glPopMatrix();
        }

        void abrirOuFecharJanela(){
            // Inverte a movimentação da porta para que ela abra ou feche
            movimentoAberturaJanela *= -1;
        }
};

#endif
#ifndef ARMARIOS_HPP
#define ARMARIOS_HPP

#include <typeinfo>
#include "primitivas.hpp"
#include "cores.hpp"
#include "matematica.hpp"

class ArmarioSemPorta{
    private:
        float altura, largura, profundidade;
        // Magnitude do movimento que deve ser incrementado ao angulo da porta
        float movimentoAbertura = 0.5;
        // Valor do angulo que a porta deve se mexer
        float anguloPorta = 1;

    public:
        ArmarioSemPorta(float alt, float larg, float prof){
            altura = alt;
            largura = larg;
            profundidade = prof;
        }

        ~ArmarioSemPorta(){}

        void desenhar(){
            glPushMatrix();
                // Centralização
                glTranslatef(-largura/2, -altura/2, -profundidade/2);
                glPushMatrix();
                    // Fundo
                    glPushMatrix();
                    glTranslatef(0, 0, -profundidade/2);
                        paralelepipedoFechado(altura, largura, 0.01 ,0,0,0,vermelho);
                    glPopMatrix();

                    // Laterais
                    glPushMatrix();
                        glRotatef(90,0,1,0);
                        glTranslatef(-profundidade/2,0,0);
                        paralelepipedoFechado(altura, profundidade, 0.01,0,0,0,branco);
                        glTranslatef(0,0,largura);
                        paralelepipedoFechado(altura, profundidade, 0.01,0,0,0,verde);
                    glPopMatrix();

                    // Parte de baixo e de cima
                    glPushMatrix();
                        glRotatef(90,1,0,0);
                        glTranslatef(0, -profundidade/2, 0);
                        paralelepipedoFechado(profundidade, largura, 0.01,0,0,0,azul);
                        glTranslatef(0,0,-altura);
                        paralelepipedoFechado(profundidade, largura, 0.01,0,0,0,azul);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        }
};

// Armário que fica suspenso nas paredes do laboratório
class ArmarioSuspenso{
    private:
        float altura, largura, profundidade;
        // Magnitude do movimento que deve ser incrementado ao angulo da porta
        float movimentoAbertura = 0.5;
        // Valor do angulo que a porta deve se mexer
        float anguloPorta = 1;

    public:
        ArmarioSuspenso(float alt, float larg, float prof){
            altura = alt;
            largura = larg;
            profundidade = prof;
        }

        ~ArmarioSuspenso(){}

        void desenhar(){
            glPushMatrix();
                // Centralização
                glTranslatef(-largura/2, -altura/2, -profundidade/2);
                glPushMatrix();
                    // Fundo
                    glPushMatrix();
                    glTranslatef(0, 0, -profundidade/2);
                        paralelepipedoFechado(altura, largura, 0.01 ,0,0,0,vermelho);
                    glPopMatrix();

                    // Laterais
                    glPushMatrix();
                        glRotatef(90,0,1,0);
                        glTranslatef(-profundidade/2,0,0);
                        paralelepipedoFechado(altura, profundidade, 0.01,0,0,0,branco);
                        glTranslatef(0,0,largura);
                        paralelepipedoFechado(altura, profundidade, 0.01,0,0,0,verde);
                    glPopMatrix();

                    // Parte de baixo e de cima
                    glPushMatrix();
                        glRotatef(90,1,0,0);
                        glTranslatef(0, -profundidade/2, 0);
                        paralelepipedoFechado(profundidade, largura, 0.01,0,0,0,azul);
                        glTranslatef(0,0,-altura);
                        paralelepipedoFechado(profundidade, largura, 0.01,0,0,0,azul);
                    glPopMatrix();
                    
                    // Porta
                    glPushMatrix();
                        glTranslatef(0,altura, profundidade/2);
                        glRotatef(180, 1,0,0);
                        anguloPorta += movimentoAbertura;

                        anguloPorta = clamp<float>(anguloPorta, -90.0, 0.0);
                        
                        glRotatef(anguloPorta, 1,0,0);
                        paralelepipedoFechado(altura, largura, 0.01,0,0,0,rosa);
                        glTranslatef(largura/2 - (largura * 0.25)/2, altura - altura/5, -profundidade/40);
                        paralelepipedoFechado(altura/10, largura * 0.25, profundidade/20,0,0,0,branco);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        };

        void abrirOuFecharPorta(){
            // Inverte a movimentação da porta para que ela abra ou feche
            movimentoAbertura *= -1;
        }
};

// Armário que fica no chão do laboratório
class ArmarioDeChao{
    private:
        float altura, largura, profundidade;

        //Magnitude do movimento que deve ser incrementado ao angulo da porta esquerda
        float movimentoAberturaPortaEsq = 0.5;

        //Magnitude do movimento que deve ser incrementado ao angulo da porta direita
        float movimentoAberturaPortaDir = -0.5;

        // Valor do angulo que a porta esquerda deve se mexer 
        float anguloPortaEsq = 1;

        // Valor do angulo que a porta direita deve se mexer
        float anguloPortaDir = 1;

    public:
        ArmarioDeChao(float alt, float larg, float prof){
            altura = alt;
            largura = larg;
            profundidade = prof;
        }

        ~ArmarioDeChao(){}

        void desenhar(){
            glPushMatrix();
                //Centraliza
                glTranslatef(-largura/2, -altura/2, -profundidade/2);

                // Fundo
                glPushMatrix();
                    glTranslatef(0,0,-profundidade/2);
                    paralelepipedoFechado(altura, largura, 0.01 ,0,0,0,vermelho);
                glPopMatrix();

                // Laterais
                glPushMatrix();
                    glRotatef(90,0,1,0);
                    glTranslatef(-profundidade/2,0,0);
                    paralelepipedoFechado(altura, profundidade, 0.01,0,0,0,branco);
                    glTranslatef(0,0,largura);
                    paralelepipedoFechado(altura, profundidade, 0.01,0,0,0,branco);
                glPopMatrix();

                // Parte de baixo e de cima
                glPushMatrix();
                    glRotatef(90,1,0,0);
                    glTranslatef(0,-profundidade/2,0);
                    paralelepipedoFechado(profundidade, largura, 0.01,0,0,0,azul);
                    glTranslatef(0,0,-altura);
                    paralelepipedoFechado(profundidade, largura, 0.01,0,0,0,azul);
                glPopMatrix();
                
                // Portas
                glPushMatrix();
                    glTranslatef(0,0,profundidade/2);
                    
                    glPushMatrix();
                        anguloPortaEsq += movimentoAberturaPortaEsq;
                        anguloPortaEsq = clamp<float>(anguloPortaEsq, -90.0, 0.0);
                        
                        glRotatef(anguloPortaEsq, 0,1,0);
                        paralelepipedoFechado(altura, largura/2, 0.01,0,0,0,verde);
                        glTranslatef(largura/2 - largura/2 * 0.15, altura*0.55, (largura * 0.003 + altura * 0.006 + profundidade * 0.008) * 1.2);
                        paralelepipedoFechado(altura/5, largura * 0.03, (largura*altura*profundidade)*0.003,0,0,0,azul);
                    glPopMatrix();

                    glPushMatrix();
                        glTranslatef(largura/2, 0,0);
                        anguloPortaDir += movimentoAberturaPortaDir;
                        anguloPortaDir = clamp<float>(anguloPortaDir, 0.0, 90.0);
                        
                        glTranslatef(largura/2, 0,0);
                        glRotatef(anguloPortaDir, 0,1,0);
                        glTranslatef(-largura/2, 0,0);
                        paralelepipedoFechado(altura, largura/2, 0.01,0,0,0,branco);
                        glTranslatef((largura/2) * 0.1, altura*0.55, (largura * 0.003 + altura * 0.006 + profundidade * 0.008) * 1.2);
                        paralelepipedoFechado(altura/5, largura * 0.03, (largura*altura*profundidade)*0.003,0,0,0,azul);
                    glPopMatrix();

                glPopMatrix();

            glPopMatrix();
        }

        void abrirOuFecharPortaEsq(){
            // Inverte a movimentação da porta para que ela abra ou feche
            movimentoAberturaPortaEsq *= -1;
        }

        void abrirOuFecharPortaDir(){
            // Inverte a movimentação da porta para que ela abra ou feche
            movimentoAberturaPortaDir *= -1;
        }
};

#endif
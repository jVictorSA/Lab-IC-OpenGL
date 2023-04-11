#ifndef CENA_HPP
#define CENA_HPP
#include <vector>
#include "primitivas.hpp"
#include "ventilador.hpp"
#include "cores.hpp"
#include "teto.hpp"
#include "luz.hpp"
#include "armarios.hpp"
#include "persiana.hpp"
#include "janela.hpp"
#include "porta.hpp"
#include "quadro.hpp"
#include "mesa.hpp"

namespace Cena{
        
        
        ArmarioSemPorta armarioSemPorta1(0.5,0.9,0.3);
        ArmarioSemPorta armarioSemPorta2(0.5,0.9,0.3);

        ArmarioSuspenso armarioSuspenso1(0.5,0.9,0.3);
        ArmarioSuspenso armarioSuspenso2(0.5,0.9,0.3);
        ArmarioSuspenso armarioSuspenso3(0.5,0.9,0.3);
        ArmarioSuspenso armarioSuspenso4(0.5,0.9,0.3);
        ArmarioSuspenso armarioSuspenso5(0.5,0.9,0.3);
        ArmarioSuspenso armarioSuspenso6(0.5,0.9,0.3);
        
        ArmarioDeChao armarioDeChao1(1,1.5, 0.5);
        ArmarioDeChao armarioDeChao2(2.5,1.5, 0.5);

        Persiana persianaEsq(2.5, 3, 0.2, 0.03, 0.5, 27, Black, cinza);
        Persiana persianaDir(2.5, 3, 0.2, 0.03, 0.5, 27, Black, cinza);

        Janela janelaEsq(2,1.5,0.03, Aquamarine, Black);
        Janela janelaDir(2,1.5,0.03, Aquamarine, Black);

        Porta porta(3,1.65,0.05, cinza, Yellow);

        Quadro quadro(2.0, 2.0, 0.05, branco);

        void laboratorio(){
            
            // //Paredes e piso
            glPushMatrix();
                glTranslatef(-3.5 - 0.15,-2,-6);
                paralelepipedoFechado(1,7.3,0.15,0,0,0,branco);
                
                glPushMatrix();
                    glTranslatef(0,1,0);
                    paralelepipedoFechado(2,1.4,0.15,0,0,0,branco);
                    glTranslatef(2.9,0,0);
                    paralelepipedoFechado(2,1.5,0.15,0,0,0,branco);
                    glTranslatef(3,0,0);
                    paralelepipedoFechado(2,1.4,0.15,0,0,0,branco);
                glPopMatrix();
                
                glTranslatef(0, 3, 0);
                paralelepipedoFechado(1,7.3,0.15,0,0,0,branco);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-3.5,-2,4);
                paralelepipedoFechado(0.15,7,10, 0,0,0,vermelho);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-3.5 - 0.15,-2,4);
                paralelepipedoFechado(4,0.15,10,0,0,0,verde);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(3.5, -2, 4);
                paralelepipedoFechado(4,0.15,10, 0,0,0,azul);
            glPopMatrix();
            
            //Parede da frente
            glPushMatrix();
                glTranslatef(-3.5 - 0.15,-2,4);
                paralelepipedoFechado(4,4,0.15,0,0,0,branco);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(2,-2,4);
                paralelepipedoFechado(4,1.5,0.15,0,0,0,verde);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.35,1,4);
                paralelepipedoFechado(1,1.5 + 0.15,0.15,0,0,0,vermelho);
            glPopMatrix();

            // Desenha Teto
            glPushMatrix();
                teto(2,7,10,0,0,0, azul, vermelho);
            glPopMatrix();

            // Desenha piso e teto do corredor
            glPushMatrix();
                glTranslatef(-16,-2,7);
                
                glPushMatrix();
                    glTranslatef(0,4,0);
                    paralelepipedoFechado(0.15,30,3,0,0,0,rosa);
                glPopMatrix();
                paralelepipedoFechado(0.15,30,3,0,0,0,rosa);
                
                glTranslatef(0,0,-3);
                glPushMatrix();
                    glTranslatef(0,4,0);
                    paralelepipedoFechado(0.15,3,13,0,0,0,vermelho);
                glPopMatrix();
                paralelepipedoFechado(0.15,3,13,0,0,0,vermelho);
                //retangulo(4,13,0,0,0,azul);
                
                glTranslatef(27,0,0);
                glPushMatrix();
                    glTranslatef(0,4,0);
                    paralelepipedoFechado(0.15,3,13,0,0,0,branco);
                glPopMatrix();
                paralelepipedoFechado(0.15,3,13,0,0,0,branco);
                
                glTranslatef(3,0,-10);
                glPushMatrix();
                    glTranslatef(0,4,0);
                    paralelepipedoFechado(0.15,7,3,0,0,0,verde);
                glPopMatrix();
                paralelepipedoFechado(0.15,7,3,0,0,0,verde);
            glPopMatrix();

            //Desenha paredes do corredor
            glPushMatrix();
            glTranslatef(0,-2,0);
                glPushMatrix();
                    glTranslatef(-16,0,7);
                    retangulo(4,30,0,0,0,azul);
                glPopMatrix();
                
                glPushMatrix();
                    glRotatef(90, 0,1,0);
                    glTranslatef(-7,0,-16);
                    retangulo(4,16,0,0,0,azul);
                    glTranslatef(3,0,3);
                    retangulo(4,13,0,0,0,azul);
                glPopMatrix();

                glPushMatrix();
                    glTranslatef(-13, 0, 4);
                    retangulo(4,9.35,0,0,0,azul);
                    glTranslatef(16.65, 0, 0);
                    retangulo(4,7.35,0,0,0,azul);
                glPopMatrix();

                glPushMatrix();
                    glRotatef(90, 0,1,0);
                    glTranslatef(-4, 0, 11);
                    retangulo(4,13,0,0,0,azul);
                    glTranslatef(-3, 0, 3);
                    retangulo(4,13,0,0,0,azul);
                glPopMatrix();

                glPushMatrix();
                    glTranslatef(14, 0, -6);
                    retangulo(4,7,0,0,0,vermelho);
                    glTranslatef(-3, 0, -3);
                    retangulo(4,10,0,0,0,vermelho);
                glPopMatrix();

            glPopMatrix();

            // Desenha ventiladores        
                Ventilador ventilador1(1,1.2,1.4);
                Ventilador ventilador2(-1,1.2,1.4);
                ventilador1.desenhaVentilador();
                ventilador2.desenhaVentilador();
                Luz luz1(1,2,-1.0);
                Luz luz2(-1,2,-1.0);
                luz1.desenhaLuz();
                luz2.desenhaLuz();
             Mesa mesa(2,20,0, -1.5, -0.6);
        Mesa mesa1(2,20,0, -1.5, -0.59);
        Mesa mesa2(2,20,0, -1.5, -0.58);
        Mesa mesa3(2,20,0, -1.5, -0.57);
        Mesa mesa4(2,20,0, -1.5, -0.56);
        Mesa mesa5(2,20,0, -1.5, -0.55);
        
            // Desenha Janelas
            glPushMatrix();
                glTranslatef(-1.5, 0, -6 -0.1);
                glPushMatrix();
                    janelaEsq.desenhar();
                glPopMatrix();

                glPushMatrix();
                    glTranslatef(3, 0, 0);
                    janelaDir.desenhar();
                glPopMatrix();
                
                glTranslatef(0, -0.4, 0.2);

                glPushMatrix();
                    persianaEsq.desenhar();
                    glTranslatef(3, 0, 0);
                    persianaDir.desenhar();
                glPopMatrix();

            glPopMatrix();

            // Desenha porta
            glPushMatrix();
                glTranslatef(0.35, -2, 4-0.05);
                porta.desenhar();
            glPopMatrix();
        mesa.desenhaMesa();
        mesa1.desenhaMesa();
        mesa2.desenhaMesa();
        mesa3.desenhaMesa();
        mesa4.desenhaMesa();
        mesa5.desenhaMesa();

            // Desenha o quadro
            glPushMatrix();
                glTranslatef(-2, -1, 4-0.15);
                quadro.desenhar();
            glPopMatrix();


            // Desenha armárioS suspensoS
            glPushMatrix();
                glPushMatrix();
                    glRotatef(90, 0, 1, 0);
                    glTranslatef(0, 0.5,-3.5 + 0.31);
                    
                    armarioSuspenso1.desenhar();
                    //glPushMatrix();
                    glTranslatef(-0.9, 0, 0);
                    armarioSuspenso2.desenhar();
                    glTranslatef(-0.9, 0, 0);
                    armarioSemPorta1.desenhar();

                    glTranslatef(0.9*3, 0, 0);
                    armarioSuspenso3.desenhar();
                    glTranslatef(0.9, 0, 0);
                    armarioSuspenso4.desenhar();
                    glTranslatef(0.9, 0, 0);
                    armarioSuspenso5.desenhar();
                    glTranslatef(0.9, 0, 0);
                    armarioSemPorta2.desenhar();
                glPopMatrix();

                glPushMatrix();
                    glRotatef(-90, 0, 1, 0);
                    glTranslatef(-0.9*2, 0.5,-3.5 + 0.31);
                    
                    armarioSuspenso1.desenhar();
                    
                    glTranslatef(-0.9, 0, 0);
                    armarioSuspenso2.desenhar();
                    

                    glTranslatef(0.9*2, 0, 0);
                    armarioSuspenso3.desenhar();
                                        
                    glTranslatef(0.9, 0, 0);
                    armarioSemPorta2.desenhar();
                glPopMatrix();


            glPopMatrix();

            // Armários de chão
            glPushMatrix();
                glPushMatrix();
                    glRotatef(90, 0, 1, 0);
                    glTranslatef(0.9*4, -1.35,-3);
                    armarioDeChao1.desenhar();
                glPopMatrix();

                glPushMatrix();
                    glRotatef(-90, 0, 1, 0);
                    glTranslatef(-0.9*5, -0.6,-3);
                    armarioDeChao2.desenhar();
                glPopMatrix();


            glPopMatrix();
        }
//};

}
//Cena::armario1(2,4.5,2.7);

#endif
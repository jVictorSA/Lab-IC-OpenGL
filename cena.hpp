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
#include "solua.hpp"
namespace Cena{
        
        
        ArmarioSemPorta armarioSemPorta1(0.5,0.9,0.3, BlueViolet, cinza);
        ArmarioSemPorta armarioSemPorta2(0.5,0.9,0.3, BlueViolet, cinza);

        ArmarioSuspenso armarioSuspenso1(0.5,0.9,0.3, BlueViolet, cinza, Brown);
        ArmarioSuspenso armarioSuspenso2(0.5,0.9,0.3, BlueViolet, cinza, Brown);
        ArmarioSuspenso armarioSuspenso3(0.5,0.9,0.3, BlueViolet, cinza, Brown);
        ArmarioSuspenso armarioSuspenso4(0.5,0.9,0.3, BlueViolet, cinza, Brown);
        ArmarioSuspenso armarioSuspenso5(0.5,0.9,0.3, BlueViolet, cinza, Brown);
        ArmarioSuspenso armarioSuspenso6(0.5,0.9,0.3, BlueViolet, cinza, Brown);
        ArmarioSuspenso armarioSuspenso7(0.5,0.9,0.3, BlueViolet, cinza, Brown);
        ArmarioSuspenso armarioSuspenso8(0.5,0.9,0.3, BlueViolet, cinza, Brown);
        
        ArmarioDeChao armarioDeChao1(1,1.5, 0.5, LightBlue, Quartz, cinza);
        ArmarioDeChao armarioDeChao2(2.5,1.5, 0.5, LightBlue, Quartz, cinza);

        Persiana persianaEsq(2.5, 3, 0.2, 0.03, 0.5, 27, Black, cinza);
        Persiana persianaDir(2.5, 3, 0.2, 0.03, 0.5, 27, Black, cinza);

        Janela janelaEsq(2,1.5,0.03, Aquamarine, Black);
        Janela janelaDir(2,1.5,0.03, Aquamarine, Black);

        Porta porta(3,1.65,0.05, cinza, Yellow);

        Quadro quadro(2.0, 2.0, 0.05, branco);

        Luz luz1(1,2,-1.0, cinza);
        Luz luz2(-1,2,-1.0, cinza);

        Solua solua(1,50,-200);

        void laboratorio(){
            
            // //Paredes e piso
            
            glPushMatrix();
                glNormal3f(0,0,1);
                glTranslatef(-3.5 - 0.15,-2,-6);
                paralelepipedoFechado(1,7.3,0.15,0,0,0,Quartz);
                
                glPushMatrix();
                    
                    glTranslatef(0,1,0);
                    paralelepipedoFechado(2,1.4,0.15,0,0,0,Quartz);
                    glTranslatef(2.9,0,0);
                    paralelepipedoFechado(2,1.5,0.15,0,0,0,Quartz);
                    glTranslatef(3,0,0);
                    paralelepipedoFechado(2,1.4,0.15,0,0,0,Quartz);
                glPopMatrix();
                
                glTranslatef(0, 3, 0);
                paralelepipedoFechado(1,7.3,0.15,0,0,0,Quartz);
            glPopMatrix();

            // Piso do lab
            glPushMatrix();
                GLfloat especularidade[4] = {0.1, 0.1, 0.1, 1.0};
                GLint especMaterial = 10;
                // Define a refletância do material
                glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
                // Define a concentração do brilho
            glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
                glNormal3f(0,1,0);
                glTranslatef(-3.5,-2,4);
                paralelepipedoFechado(0.15,7,10, 0,0,0,Khaki);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-3.5 - 0.15,-2,4);
                paralelepipedoFechado(4,0.15,10,0,0,0,Quartz);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(3.5, -2, 4);
                paralelepipedoFechado(4,0.15,10, 0,0,0,Quartz);
            glPopMatrix();
            
            //Parede da frente
            glPushMatrix();
                
                glTranslatef(-3.5 - 0.15,-2,4);
                
                glNormal3f(0,0,1);
                paralelepipedoFechado(4,4,0.15,0,0,0,Quartz);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(2,-2,4);
                paralelepipedoFechado(4,1.5,0.15,0,0,0,Quartz);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.35,1,4);
                paralelepipedoFechado(1,1.5 + 0.15,0.15,0,0,0,Quartz);
            glPopMatrix();

            // Desenha Teto
            glPushMatrix();
                
                teto(2,7,10,0,0,0, Firebrick, Quartz);
            glPopMatrix();

            // Desenha piso e teto do corredor
            glPushMatrix();
                
                glTranslatef(-16,-2,7);
                
                glPushMatrix();
                    glTranslatef(0,4,0);
                    paralelepipedoFechado(0.15,30,3,0,0,0,CornflowerBlue);
                glPopMatrix();
                paralelepipedoFechado(0.15,30,3,0,0,0,Khaki);
                
                glTranslatef(0,0,-3);
                glPushMatrix();
                    glTranslatef(0,4,0);
                    paralelepipedoFechado(0.15,3,13,0,0,0,CornflowerBlue);
                glPopMatrix();
                paralelepipedoFechado(0.15,3,13,0,0,0,Khaki);
                //retangulo(4,13,0,0,0,azul);
                
                glTranslatef(27,0,0);
                glPushMatrix();
                    glTranslatef(0,4,0);
                    paralelepipedoFechado(0.15,3,13,0,0,0,CornflowerBlue);
                glPopMatrix();
                paralelepipedoFechado(0.15,3,13,0,0,0,Khaki);
                
                glTranslatef(3,0,-10);
                glPushMatrix();
                    glTranslatef(0,4,0);
                    paralelepipedoFechado(0.15,7,3,0,0,0,CornflowerBlue);
                glPopMatrix();
                paralelepipedoFechado(0.15,7,3,0,0,0,Khaki);
            glPopMatrix();

            //Desenha paredes do corredor
            glPushMatrix();
            glTranslatef(0,-2,0);
                glPushMatrix();
                    glTranslatef(-16,0,7);
                    retangulo(4,30,0,0,0,Quartz);
                glPopMatrix();
                
                glPushMatrix();
                    glRotatef(90, 0,1,0);
                    glTranslatef(-7,0,-16);
                    retangulo(4,16,0,0,0,Quartz);
                    glTranslatef(3,0,3);
                    retangulo(4,13,0,0,0,Quartz);
                glPopMatrix();

                glPushMatrix();
                    glTranslatef(-13, 0, 4);
                    retangulo(4,9.35,0,0,0,Quartz);
                    glTranslatef(16.65, 0, 0);
                    retangulo(4,7.35,0,0,0,Quartz);
                glPopMatrix();

                glPushMatrix();
                    glRotatef(90, 0,1,0);
                    glTranslatef(-4, 0, 11);
                    retangulo(4,13,0,0,0,Quartz);
                    glTranslatef(-3, 0, 3);
                    retangulo(4,13,0,0,0,Quartz);
                glPopMatrix();

                glPushMatrix();
                    glTranslatef(14, 0, -6);
                    retangulo(4,7,0,0,0,Quartz);
                    glTranslatef(-3, 0, -3);
                    retangulo(4,10,0,0,0,Quartz);
                glPopMatrix();

            glPopMatrix();

            // Desenha ventiladores        
                Ventilador ventilador1(1,1.2,1.4, LightSteelBlue, MediumSeaGreen);
                Ventilador ventilador2(-1,1.2,1.4, LightSteelBlue, MediumSeaGreen);
                ventilador1.desenhaVentilador();
                ventilador2.desenhaVentilador();
                
                luz1.desenhaLuz();
                luz2.desenhaLuz();
             Mesa mesa(2,20,0, -1.5, -0.6);
        Mesa mesa1(2,20,0, -1.5, -0.59);
        Mesa mesa2(2,20,0, -1.5, -0.58);
        Mesa mesa3(2,20,0, -1.5, -0.57);
        Mesa mesa4(2,20,0, -1.5, -0.56);
        Mesa mesa5(2,20,0, -1.5, -0.55);
        
        solua.desenhar();
        
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
                    glTranslatef(-0.9-0.005, 0, 0);
                    armarioSuspenso2.desenhar();
                    glTranslatef(-0.9-0.005, 0, 0);
                    armarioSemPorta1.desenhar();

                    glTranslatef(0.9*3 + 0.005, 0, 0);
                    armarioSuspenso3.desenhar();
                    glTranslatef(0.9 + 0.005, 0, 0);
                    armarioSuspenso4.desenhar();
                    glTranslatef(0.9 + 0.005, 0, 0);
                    armarioSuspenso5.desenhar();
                    glTranslatef(0.9 + 0.005, 0, 0);
                    armarioSemPorta2.desenhar();
                glPopMatrix();

                glPushMatrix();
                    glRotatef(-90, 0, 1, 0);
                    glTranslatef(-0.9*2, 0.5,-3.5 + 0.31);
                    
                    armarioSuspenso6.desenhar();
                    
                    glTranslatef(-0.9 - 0.005, 0, 0);
                    armarioSuspenso7.desenhar();
                    

                    glTranslatef(0.9*2 + 0.005, 0, 0);
                    armarioSuspenso8.desenhar();
                                        
                    glTranslatef(0.9 + 0.005, 0, 0);
                    armarioSemPorta2.desenhar();
                glPopMatrix();


            glPopMatrix();

            // Armários de chão
            glPushMatrix();
                glPushMatrix();
                    glRotatef(90, 0, 1, 0);
                    glTranslatef(0.9*4, -1.35,-3+0.1);
                    armarioDeChao1.desenhar();
                glPopMatrix();

                glPushMatrix();
                    glRotatef(-90, 0, 1, 0);
                    glTranslatef(-0.9*5, -0.6,-3+0.1);
                    armarioDeChao2.desenhar();
                glPopMatrix();
                

            glPopMatrix();
        }
//};

}
//Cena::armario1(2,4.5,2.7);

#endif
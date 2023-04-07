#ifndef CENA_HPP
#define CENA_HPP
#include <vector>
#include "primitivas.hpp"
#include "ventilador.hpp"
#include "cores.hpp"
#include "teto.hpp"

void laboratorio(){
    
    // //Paredes e piso
    glPushMatrix();
    glTranslatef(-3.5 - 0.15,-2,-6);
    paralelepipedoFechado(4,7.3,0.15,0,0,0,branco);
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
    
    // Desenha Teto
    glPushMatrix();
    teto(2,7,10,0,0,0, azul, vermelho);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-16,-2,7);
    paralelepipedoFechado(0.15,26,3,0,0,0,rosa);
    glPopMatrix();

    
    glPushMatrix();
    glTranslatef(0,1,-2.5);
    Ventilador ventilador1(1,1.2,1.4);
    Ventilador ventilador2(-1,1.2,1.4);
    ventilador1.desenhaVentilador();
    ventilador2.desenhaVentilador();
    glPopMatrix();
}

#endif
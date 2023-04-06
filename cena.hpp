#ifndef CENA_HPP
#define CENA_HPP
#include "primitivas.hpp"
#include "ventilador.hpp"

void laboratorio(){
    
    // //Paredes e piso
    glPushMatrix();
    glTranslatef(-2,-2,0);
    paralelepipedoFechado(4,4,0.15,0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,-2,4);
    paralelepipedoFechado(0.15,4,4, 0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,-2,4);
    paralelepipedoFechado(4,0.15,4,0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.85, -2, 4);
    paralelepipedoFechado(4,0.15,4, 0,0,0);
    glPopMatrix();
    
    // Desenha Teto
    glPushMatrix();
    glTranslatef(-2,2,0);
    glRotatef(65, 1,0,0);
    paralelepipedoFechado(2.3,4,0.15,0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,2,4);
    glRotatef(-60, 1,0,0);
    paralelepipedoFechado(2.2,4,0.15,0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,2,0);
    glRotatef(-90,0,1,0);
    trianguloFechado(1,4,0.1, 0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.85,2,0);
    glRotatef(-90,0,1,0);
    trianguloFechado(1,4,0.1, 0,0,0);
    glPopMatrix();


    
    Ventilador ventilador1(1,1.2,1.4);
    Ventilador ventilador2(-1,1.2,1.4);
    ventilador1.desenhaVentilador();
    ventilador2.desenhaVentilador();
    
}

#endif
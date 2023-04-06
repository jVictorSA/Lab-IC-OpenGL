#ifndef CENA_HPP
#define CENA_HPP
#include "primitivas.hpp"

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
}

#endif
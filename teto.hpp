#ifndef TETO_HPP
#define TETO_HPP
#include "primitivas.hpp"
#include "cores.hpp"


void teto(float altura, float largura, float profundidade,
          float xInicial, float yInicial, float zInicial,
          const std::vector<float> corCima,
          const std::vector<float> corLateral){

    //Parte de cima do teto
    glColor3f(corCima[0],corCima[1],corCima[2]);
    glPushMatrix();
        glTranslatef(-3.5,2,-1);
        glBegin(GL_QUADS);
            glVertex3f(xInicial, yInicial,  zInicial - profundidade/2);
            glVertex3f(xInicial + largura, yInicial,  zInicial - profundidade/2);
            glVertex3f(xInicial + largura, yInicial + altura * 0.85,  zInicial);
            glVertex3f(xInicial,  yInicial + altura * 0.85,  zInicial);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3.5,2,-1);
        glBegin(GL_QUADS);
            glVertex3f(xInicial, yInicial,  zInicial + profundidade/2);
            glVertex3f(xInicial + largura, yInicial,  zInicial + profundidade/2);
            glVertex3f(xInicial + largura, yInicial + altura * 0.85,  zInicial);
            glVertex3f(xInicial,  yInicial + altura * 0.85,  zInicial);
        glEnd();
    glPopMatrix();

    //Parte lateral do teto
    glColor3f(corLateral[0],corLateral[1],corLateral[2]);
    glPushMatrix();
        glTranslatef(-3.5,2,-1);
        glBegin(GL_TRIANGLES);
            glVertex3f(xInicial, yInicial,  zInicial + profundidade/2);
            glVertex3f(xInicial, yInicial,  zInicial - profundidade/2);
            glVertex3f(xInicial, yInicial + altura * 0.85,  zInicial);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(3.5,2,-1);
        glBegin(GL_TRIANGLES);
            glVertex3f(xInicial, yInicial,  zInicial + profundidade/2);
            glVertex3f(xInicial, yInicial,  zInicial - profundidade/2);
            glVertex3f(xInicial, yInicial + altura * 0.85,  zInicial);
        glEnd();
    glPopMatrix();
}

#endif
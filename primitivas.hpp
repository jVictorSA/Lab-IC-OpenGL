#ifndef PRIMITIVAS_HPP
#define PRIMITIVAS_HPP
#include <GL/glut.h>
#include <vector>
// Desenha paralelepipedo aberto
void paralelepipedoAberto(float altura, float largura, float profundidade,
                          float xInicial, float yInicial, float zInicial,
                          const std::vector<float> cor){
    //Se retirar os glBegin(GL_TRIANGLES), o que de errado pode acontecer??
    glBegin(GL_POLYGON);
        // Face da frente
        glBegin(GL_QUADS);
            glColor3f(cor[0],cor[1],cor[2]);           //Vermelho
            glVertex3f(xInicial, yInicial,  zInicial);
            glVertex3f(xInicial + largura, yInicial,  zInicial);
            glVertex3f(xInicial + largura, yInicial + altura,  zInicial);
            glVertex3f(xInicial,  yInicial + altura,  zInicial);
        glEnd();

        //Face de trás
        glBegin(GL_QUADS);
            glColor3f(0,1,0);           //Verde
            glVertex3f(xInicial, yInicial,  zInicial - profundidade);
            glVertex3f(xInicial + largura, yInicial,  zInicial - profundidade);
            glVertex3f(xInicial + largura, yInicial + altura,  zInicial - profundidade);
            glVertex3f(xInicial,  yInicial + altura,  zInicial - profundidade);
        glEnd();

        // Face de baixo
        glBegin(GL_QUADS);
            glColor3f(0,0,1);           //Azul
            glVertex3f(xInicial, yInicial,  zInicial - profundidade);
            glVertex3f(xInicial, yInicial,  zInicial);
            glVertex3f(xInicial + largura, yInicial,  zInicial);
            glVertex3f(xInicial + largura,  yInicial,  zInicial - profundidade);
        glEnd();

        // Face de cima
        glBegin(GL_QUADS);
            glColor3f(1,1,0);           //Amarelo
            glVertex3f(xInicial, yInicial + altura,  zInicial - profundidade);
            glVertex3f(xInicial, yInicial + altura,  zInicial);
            glVertex3f(xInicial + largura, yInicial + altura,  zInicial);
            glVertex3f(xInicial + largura,  yInicial + altura,  zInicial - profundidade);
        glEnd();
    glEnd();
}

// Desenha paralelepipedo fechado
void paralelepipedoFechado(float altura, float largura, float profundidade,
                           float xInicial, float yInicial, float zInicial,
                           const std::vector<float> cor){

        
    glColor3f(cor[0],cor[1],cor[2]);
    glBegin(GL_POLYGON);
        // Face da frente
        glBegin(GL_QUADS);
            glVertex3f(xInicial, yInicial,  zInicial);
            glVertex3f(xInicial + largura, yInicial,  zInicial);
            glVertex3f(xInicial + largura, yInicial + altura,  zInicial);
            glVertex3f(xInicial,  yInicial + altura,  zInicial);
        glEnd();

        //Face de trás
        glBegin(GL_QUADS);
            //glColor3f(0,1,0);           //Verde
            glVertex3f(xInicial, yInicial,  zInicial - profundidade);
            glVertex3f(xInicial + largura, yInicial,  zInicial - profundidade);
            glVertex3f(xInicial + largura, yInicial + altura,  zInicial - profundidade);
            glVertex3f(xInicial,  yInicial + altura,  zInicial - profundidade);
        glEnd();

        // Face de baixo
        glBegin(GL_QUADS);
            //glColor3f(0,0,1);           //Azul
            glVertex3f(xInicial, yInicial,  zInicial - profundidade);
            glVertex3f(xInicial, yInicial,  zInicial);
            glVertex3f(xInicial + largura, yInicial,  zInicial);
            glVertex3f(xInicial + largura,  yInicial,  zInicial - profundidade);
        glEnd();

        // Face de cima
        glBegin(GL_QUADS);
            //glColor3f(1,1,0);           //Amarelo
            glVertex3f(xInicial, yInicial + altura,  zInicial - profundidade);
            glVertex3f(xInicial, yInicial + altura,  zInicial);
            glVertex3f(xInicial + largura, yInicial + altura,  zInicial);
            glVertex3f(xInicial + largura,  yInicial + altura,  zInicial - profundidade);
        glEnd();

        // Face direita
        glBegin(GL_QUADS);
            //glColor3f(1,0,1);           //Rosa
            glVertex3f(xInicial + largura, yInicial,  zInicial - profundidade);
            glVertex3f(xInicial + largura, yInicial,  zInicial);
            glVertex3f(xInicial + largura, yInicial + altura,  zInicial);
            glVertex3f(xInicial + largura,  yInicial + altura,  zInicial - profundidade);
        glEnd();

        // Face esquerda
        glBegin(GL_QUADS);
            //glColor3f(0.5,0.5,0.3);           //Verde Oliva
            glVertex3f(xInicial, yInicial,  zInicial - profundidade);
            glVertex3f(xInicial, yInicial,  zInicial);
            glVertex3f(xInicial, yInicial + altura,  zInicial);
            glVertex3f(xInicial,  yInicial + altura,  zInicial - profundidade);
        glEnd();
}

void trianguloFechado(float altura, float largura, float profundidade,
                      float xInicial, float yInicial, float zInicial,
                      const std::vector<float> cor){

    glColor3f(cor[0],cor[1],cor[2]);                        
    glBegin(GL_TRIANGLES);
        glVertex3f(xInicial, yInicial,  zInicial);
        glVertex3f(xInicial + largura / 2, yInicial + altura,  zInicial);
        glVertex3f(xInicial + largura, yInicial,  zInicial);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex3f(xInicial, yInicial,  zInicial - profundidade);
        glVertex3f(xInicial + largura/2, yInicial + altura,  zInicial - profundidade);
        glVertex3f(xInicial + largura, yInicial,  zInicial - profundidade);
    glEnd();

    glBegin(GL_QUADS); 
        glVertex3f(xInicial, yInicial,  zInicial - profundidade);
        glVertex3f(xInicial, yInicial,  zInicial);
        glVertex3f(xInicial + largura/2, yInicial + altura,  zInicial);
        glVertex3f(xInicial + largura/2 , yInicial + altura,  zInicial - profundidade);
    glEnd();
    
    glBegin(GL_QUADS);
        glVertex3f(xInicial + largura, yInicial,  zInicial - profundidade);
        glVertex3f(xInicial + largura , yInicial,  zInicial);
        glVertex3f(xInicial + largura/2, yInicial + altura,  zInicial);
        glVertex3f(xInicial + largura/2 , yInicial + altura,  zInicial - profundidade);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(xInicial + largura, yInicial,  zInicial - profundidade);
        glVertex3f(xInicial + largura , yInicial,  zInicial);
        glVertex3f(xInicial, yInicial,  zInicial);
        glVertex3f(xInicial, yInicial,  zInicial - profundidade);
    glEnd();

}

#endif
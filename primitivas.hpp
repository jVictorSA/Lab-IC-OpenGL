#ifndef PRIMITIVAS_HPP
#define PRIMITIVAS_HPP
#include <GL/glut.h>
#include <vector>
#include <cmath>

// Desenha um retângulo, mas do mesmo modo de nossas outras primitivas
void retangulo(float altura, float largura,
               float xInicial, float yInicial, float zInicial,
               const std::vector<float> cor){
    
    glBegin(GL_QUADS);
        glColor3f(cor[0],cor[1],cor[2]);
        glVertex3f(xInicial, yInicial,  zInicial);
        glVertex3f(xInicial + largura, yInicial,  zInicial);
        glVertex3f(xInicial + largura, yInicial + altura,  zInicial);
        glVertex3f(xInicial,  yInicial + altura,  zInicial);
    glEnd();
}

// Desenha paralelepipedo aberto
void paralelepipedoAberto(float altura, float largura, float profundidade,
                          float xInicial, float yInicial, float zInicial,
                          const std::vector<float> cor){
    
    glColor4f(cor[0],cor[1],cor[2], cor[3]);
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
            glVertex3f(xInicial, yInicial,  zInicial - profundidade);
            glVertex3f(xInicial + largura, yInicial,  zInicial - profundidade);
            glVertex3f(xInicial + largura, yInicial + altura,  zInicial - profundidade);
            glVertex3f(xInicial,  yInicial + altura,  zInicial - profundidade);
        glEnd();

        // Face de baixo
        glBegin(GL_QUADS);
            glVertex3f(xInicial, yInicial,  zInicial - profundidade);
            glVertex3f(xInicial, yInicial,  zInicial);
            glVertex3f(xInicial + largura, yInicial,  zInicial);
            glVertex3f(xInicial + largura,  yInicial,  zInicial - profundidade);
        glEnd();

        // Face de cima
        glBegin(GL_QUADS);
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

    glColor4f(cor[0],cor[1],cor[2], cor[3]);
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

    glColor4f(cor[0],cor[1],cor[2], cor[3]);            
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

GLvoid circulo(const GLfloat raio,const GLuint vertices, const std::vector<float> cor)
{
    GLfloat vertex[4]; 
    GLfloat texcoord[2];
    
    const GLfloat delta_angle = 2.0*M_PI/vertices;
    
    glBegin(GL_TRIANGLE_FAN);

    glColor4f(cor[0], cor[1], cor[2], cor[3]);
    
    
    texcoord[0] = 0.5;
    texcoord[1] = 0.5;
    glTexCoord2fv(texcoord);
    
    vertex[0] = vertex[1] = vertex[2] = 0.0;
    vertex[3] = 1.0;        
    glVertex4fv(vertex);
    
    for(int i = 0; i < vertices ; i++)
    {
        texcoord[0] = (std::cos(delta_angle*i) + 1.0)*0.5;
        texcoord[1] = (std::sin(delta_angle*i) + 1.0)*0.5;
        glTexCoord2fv(texcoord);
        
        vertex[0] = std::cos(delta_angle*i) * raio;
        vertex[1] = std::sin(delta_angle*i) * raio;
        vertex[2] = 0.0;
        vertex[3] = 1.0;
        glVertex4fv(vertex);
    }
    
    texcoord[0] = (1.0 + 1.0)*0.5;
    texcoord[1] = (0.0 + 1.0)*0.5;
    glTexCoord2fv(texcoord);
    
    vertex[0] = 1.0 * raio;
    vertex[1] = 0.0 * raio;
    vertex[2] = 0.0;
    vertex[3] = 1.0;
    glVertex4fv(vertex);
    glEnd();
    
    
  
}

#endif
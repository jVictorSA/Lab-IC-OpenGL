#include <GL/glut.h>
#include <iostream>
#include <cmath>

#include "primitivas.hpp"
#include "cena.hpp"

float angulo = 0.0;
float angulo2 = 0.0;
float lx, ly = 0.0f, lz = -1.0f;
float xOlho = 0.0f, zOlho = 10.0f;
float yOlho = 0;
float velocity = 1.0f;
float delta = 0.1f;

float deltaAngle = 0.0f;
float deltaAngle2 = 0.0f;
int xOrigin = 0;
int yOrigin = 0;

void olharProCentro(){
    lx = -xOlho; ly = -yOlho; lz = -zOlho;
    //lx = -xOlho; ly = -yOlho; lz = -zOlho;
    xOrigin -= xOlho; yOrigin -= yOlho;
    //(x - xOrigin)
    angulo = 0; angulo2 = 0;
    deltaAngle = 0; deltaAngle2 = 0;
}


// Renderiza a cena
void render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    
    gluLookAt(
            xOlho, yOlho, zOlho,
			xOlho+lx, yOlho+ly,  zOlho+lz,
            //0,0,0,
			0.0f, 1.0f,  0.0f);

    glRotatef(0, 0, 1, 0);

    laboratorio();
    
    glEnd();

    glutSwapBuffers();
}

void inicializar(){

    // Habilita o teste de profundidade para evitar sobrepor objetos
    glEnable(GL_DEPTH_TEST);

    glClearColor(0.0, 0.0, 0.0, 0.0);
}

// Permite alterar o tamanho da janela, recalculando
// o viewport em relação ao tamanho da janela
void mudaTamJanela(int largura, int altura){

    if(altura == 0){
        altura = 1;
    }

    float aspecto = largura * 1.0 / altura;

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glViewport(0, 0, largura, altura);

    gluPerspective(45, aspecto, 1, 1000);

    glMatrixMode(GL_MODELVIEW);
}

// x e y são paramêtros necessárias caso queiramos
// usar a coordenada do mouse no momento da chamada desta callback
void teclasEspeciais(unsigned char tecla, int x, int y){
    if(tecla == 'r' || tecla == 'R'){ olharProCentro(); }
    if(tecla == 'q' || tecla == 'Q'){ exit(0); }
}

void moverTeclado(int tecla, int x, int y){
    double deltaPosicao = 0.1;

    //É necessário dividir lz, lx, e ly pela norma para efetuar as translações
    //Caso contrário, devido lz,lx e ly não serem recalculados, eles terão valores altos após a câmera olhar para o centro
    //Ocasionando numa translação demasiada rápida
    double norma = sqrt( (lz*lz)+(lx*lx) );

    //Adiciona boost na movimentação da câmera quando o shift é pressionado
    if(glutGetModifiers() == GLUT_ACTIVE_SHIFT){
        deltaPosicao = 0.5;
    }

    switch(tecla){
        case GLUT_KEY_RIGHT :
            // angulo += 0.1f;
            // lx = sin(angulo);
            // lz = -cos(angulo);
            // xOlho += deltaPosicao;            
            xOlho += - (lz/norma) * deltaPosicao;
            zOlho += (lx/norma) * deltaPosicao;
            break;

        case GLUT_KEY_LEFT :
            // angulo -= 0.1f;
            // lx = sin(angulo);
            // lz = -cos(angulo);
            // xOlho -= deltaPosicao;            
            xOlho -= -(lz/norma) * deltaPosicao;
            zOlho -= (lx/norma) * deltaPosicao;    
            break;

        case GLUT_KEY_UP :
            // angulo2 += 0.1f;
            // ly = sin(angulo2);
            // lz = -cos(angulo2);
            // x += lx * delta;
            // z += lz * delta;
            
            // zOlho -= deltaPosicao;
            xOlho += (lx/norma) * deltaPosicao;
            yOlho += (ly/norma) * deltaPosicao;
            zOlho += (lz/norma) * deltaPosicao;            
            break;

        case GLUT_KEY_DOWN :
            // angulo2 -= 0.1f;
            // ly = sin(angulo2);
            // lz = -cos(angulo2);
            // x -= lx * delta;
            // z -= lz * delta;
            xOlho -= (lx/norma) * deltaPosicao;
            yOlho -= (ly/norma) * deltaPosicao;
            zOlho -= (lz/norma) * deltaPosicao;
            break;
    }
}

void mouseButton(int button, int state, int x, int y) {

	
	if (button == GLUT_LEFT_BUTTON) {

		
		if (state == GLUT_UP) {
			angulo += deltaAngle;
            angulo2 += deltaAngle2;
			xOrigin = -1;
            yOrigin = -1;
		}
		else  {
			xOrigin = x;
            yOrigin = y;
		}
	}
}


void mouseMove(int x, int y) {

	// this will only be true when the left button is down
	if (xOrigin >= 0) {
		
		deltaAngle = (x - xOrigin) * 0.005f;
		
		lx = sin(angulo + deltaAngle);
		lz = -cos(angulo + deltaAngle);
        
        // lx = cos(deltaAngle) * cos(deltaAngle2);
        // ly = sin(deltaAngle2);
		// lz = sin(deltaAngle)*cos(deltaAngle2);
        // std::cout<<deltaAngle<<std::endl;   
	}

    if (yOrigin >= 0) {
		
		deltaAngle2 = -(y - yOrigin) * 0.005f;        
		
		ly = sin(angulo2 + deltaAngle2);
		// lz = -cos(angulo2 + deltaAngle2);        
	}    
}


int main (int argc, char **argv){
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize(800, 600);

    glutCreateWindow("Laboratorio");

    inicializar();

    glutDisplayFunc(render);
    glutKeyboardFunc(teclasEspeciais);
    glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
    glutSpecialFunc(moverTeclado);
    glutReshapeFunc(mudaTamJanela);

    // Não me perguntem oq essa bagaça faz
    // Eu só sei que essa função é chamada
    // Quando a janela está ociosa, sem interações
    glutIdleFunc(render);

    glutMainLoop();

    return 0;
}
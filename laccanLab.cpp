#include <GL/glut.h>
#include <iostream>
#include <cmath>

#include "primitivas.hpp"
#include "cena.hpp"
#include "armarios.hpp"
#include "persiana.hpp"
#include "janela.hpp"


const int BARRA_DE_ESPAÇO = 32;

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

// Aponta a câmera para a origem da cena.
void olharProCentro(){
    lx = -xOlho; ly = -yOlho; lz = -zOlho;
    xOrigin -= xOlho; yOrigin -= yOlho;
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
			0.0f, 1.0f,  0.0f);

    // // Cena principal
    Cena::laboratorio();

    // // Descomente para testar o armário suspenso
    // armario.desenhar();

    // // Descomente para testar o armário de chão
    // armarioDeChao.desenhar();


    // // Descomente para testar a persiana
    //persiana.desenhar();

    // Descomente para testar a janela
    //janela.desenhar();

    glutSwapBuffers();
}

void inicializar(){
    // Habilita o teste de profundidade para evitar sobrepor objetos
    glEnable(GL_DEPTH_TEST);

    glClearColor(0.2, 0.3, 0.4, 0.0);
}

// Permite alterar o tamanho da janela, recalculando
// o viewport em relação ao tamanho da janela
void mudaTamJanela(int largura, int altura){

    // Impede divisões por zero
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
    if(tecla == 'c' || tecla == 'C'){ olharProCentro(); } // Aponta a câmera para a origem da cena
    if(tecla == 'q' || tecla == 'Q'){ exit(0); }
    if(tecla == BARRA_DE_ESPAÇO)    { yOlho += 0.07; }   // Sobe a câmera
    if(tecla == 'z' || tecla == 'Z'){ yOlho -= 0.07; }   // Desce a câmera
    if(tecla == 'f' || tecla == 'F'){ Cena::armarioSuspenso1.abrirOuFecharPorta(); }    // Abre ou fecha armário
    if(tecla == 'e' || tecla == 'E'){ Cena::armarioDeChao1.abrirOuFecharPortaEsq(); }    // Abre ou fecha armário
    if(tecla == 'r' || tecla == 'R'){ Cena::armarioDeChao1.abrirOuFecharPortaDir(); }    // Abre ou fecha armário
    if(tecla == 'p' || tecla == 'P'){ Cena::persianaEsq.abrirOuFecharPersiana();   }    // Abre ou fecha persiana
    if(tecla == 'a' || tecla == 'A'){ Cena::persianaDir.abrirOuFecharPersiana();   }    // Abre ou fecha persiana
    if(tecla == 'j' || tecla == 'J'){ Cena::janelaEsq.abrirOuFecharJanela();       }    // Abre ou fecha janela
    if(tecla == 'o' || tecla == 'O'){ Cena::porta.abrirOuFecharPorta();            }    // Abre ou fecha porta do laboratório
}

void moverTeclado(int tecla, int x, int y){
    double deltaPosicao = 0.1;

    //É necessário dividir lz, lx, e ly pela norma para efetuar as translações
    //Caso contrário, devido lz,lx e ly não serem recalculados, eles terão valores altos após a câmera olhar para o centro
    //Ocasionando numa translação demasiada rápida
    double norma = sqrt( (lz*lz)+(lx*lx) );

    int teclaEspecial = glutGetModifiers();

    //Adiciona boost na movimentação da câmera quando o shift é pressionado ou CAPS LOCK é ativado
    if(teclaEspecial == GLUT_ACTIVE_SHIFT){
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
    
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

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
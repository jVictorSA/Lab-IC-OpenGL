#include <GL/glut.h>
#include <iostream>
#include <cmath>

#include "primitivas.hpp"
#include "cena.hpp"
#include "armarios.hpp"
#include "persiana.hpp"
#include "janela.hpp"


const int BARRA_DE_ESPAÇO = 32;

// Indica se a tecla ALT fora pressionada (funciona como um CAPS LOCK)
bool altLigado = false;

float angulo = 0.0;
float angulo2 = 0.0;
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
float xOlho = 5.0f, zOlho = 40.0f;
float yOlho = 10.0f;
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


            // GLfloat luzAmbiente[4] = {0.1, 0.1, 0.1, 1.0};
            GLfloat luzDifusa[4] = {0.7, 0.7, 0.7, 1.0};    // "cor"
            GLfloat luzEspecular[4] = {1.0, 1.0, 1.0, 1.0}; // "brilho"
            GLfloat posicaoLuz[4] = {1-0.7,2.2,-1-0.05, 1};

            // Capacidade de brilho do material
            GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0};
            GLint especMaterial = 60;
            

            
            

            // Habilita o modelo de colorização de Gouraud
            glShadeModel(GL_SMOOTH);

            // Define a refletância do material
            glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
            // Define a concentração do brilho
            glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

            // Ativa o uso da luz ambiente
            // glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

            // Define os parâmetros da luz de número 0
            glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz);
            // glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente);
            glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa);
            glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular);
            

            glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 80.0);
            GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
            glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);

            // Habilita a definição da cor do material a partir da cor corrente
            glEnable(GL_COLOR_MATERIAL);
            // Habilita o uso de iluminação
            glEnable(GL_LIGHTING);
            // Habilita a luz de número 0
            // glEnable(GL_LIGHT1);
            // Habilita o depth-buffering
            glEnable(GL_DEPTH_TEST);
            glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 2.0);
            glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);

   
    Cena::laboratorio();

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

void abrirOuFecharPersiana(Persiana& persianaEsq, Persiana& persianaDir){
    if (altLigado == false){
        persianaEsq.abrirOuFecharPersiana();
    
    }else{
        persianaDir.abrirOuFecharPersiana();
    }
}

void abrirOuFecharJanela(Janela& janelaEsq, Janela& janelaDir){
    if (altLigado == false){
        janelaEsq.abrirOuFecharJanela();
    
    }else{
        janelaDir.abrirOuFecharJanela();
    }
}

void abrirOuFecharPortaDeArmarioDeChao(ArmarioDeChao& armario){
    if (altLigado == false){
        armario.abrirOuFecharPortaEsq();
    
    }else{
        armario.abrirOuFecharPortaDir();
    }
}

// x e y são paramêtros necessárias caso queiramos
// usar a coordenada do mouse no momento da chamada desta callback
void teclasEspeciais(unsigned char tecla, int x, int y){
    if(tecla == 'c' || tecla == 'C'){ olharProCentro(); }    // Aponta a câmera para a origem da cena
    if(tecla == 'q' || tecla == 'Q'){ exit(0); }            // Fecha o programa
    if(tecla == BARRA_DE_ESPAÇO)    { yOlho += 0.07; }      // Sobe a câmera
    if(tecla == 'z' || tecla == 'Z'){ yOlho -= 0.07; }      // Desce a câmera
    if(tecla == 'e' || tecla == 'E'){ abrirOuFecharPortaDeArmarioDeChao(Cena::armarioDeChao1); }    // Abre ou fecha armário de chão da esquerda
    if(tecla == 'r' || tecla == 'R'){ abrirOuFecharPortaDeArmarioDeChao(Cena::armarioDeChao2); }    // Abre ou fecha armário de chão da direita
    if(tecla == 'p' || tecla == 'P'){ abrirOuFecharPersiana(Cena::persianaEsq,                      // Abre ou fecha persiana
                                                            Cena::persianaDir); }    
    if(tecla == 'j' || tecla == 'J'){ abrirOuFecharJanela(Cena::janelaEsq,                          // Abre ou fecha janela
                                                          Cena::janelaDir); }    
    if(tecla == 'o' || tecla == 'O'){ Cena::porta.abrirOuFecharPorta(); }                           // Abre ou fecha porta do laboratório
    if(tecla == 'b'){
        Cena::luz1.ligaDesliga();
        Cena::luz2.ligaDesliga();
    }
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

    if (teclaEspecial == GLUT_ACTIVE_ALT){
            if(altLigado == true){
                std::cout << "ALT DESLIGADO!\n";
                altLigado = false;
            }else{
                std::cout << "ALT LIGADO!\n";
                altLigado = true;
            }
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
        
        // Abrir ou fechar armários suspensos
        case GLUT_KEY_F1:
            Cena::armarioSuspenso2.abrirOuFecharPorta();
            break;
        case GLUT_KEY_F2:
            Cena::armarioSuspenso1.abrirOuFecharPorta();
            break;
        case GLUT_KEY_F3:
            Cena::armarioSuspenso3.abrirOuFecharPorta();
            break;
        case GLUT_KEY_F4:
            Cena::armarioSuspenso4.abrirOuFecharPorta();
            break;
        case GLUT_KEY_F5:
            Cena::armarioSuspenso5.abrirOuFecharPorta();
            break;
        case GLUT_KEY_F6:
            Cena::armarioSuspenso7.abrirOuFecharPorta();
            break;
        case GLUT_KEY_F7:
            Cena::armarioSuspenso6.abrirOuFecharPorta();
            break;
        case GLUT_KEY_F8:
            Cena::armarioSuspenso8.abrirOuFecharPorta();
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
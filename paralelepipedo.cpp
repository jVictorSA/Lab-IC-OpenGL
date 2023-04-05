//Código referente à um triangulo tridimensional

#include <GL/glut.h>

#include <cmath>

float angulo = 0.0;
float angulo2 = 0.0;
float lx, ly = 0.0f, lz = -1.0f;
float x = 0.0f, z = 10.0f;
float y = 0;
float velocity = 1.0f;
float delta = 0.1f;

float deltaAngle = 0.0f;
float deltaAngle2 = 0.0f;
int xOrigin = 0;
int yOrigin = 0;

// Desenha retângulo
void retangulo(float x0, float y0, float altura, float largura){

}

// Desenha paralelepipedo aberto
void paralelepipedoAberto(float altura, float largura, float profundidade,
                          float xInicial, float yInicial, float zInicial){
    //Se retirar os glBegin(GL_TRIANGLES), o que de errado pode acontecer??
    glBegin(GL_POLYGON);
        // Face da frente
        glBegin(GL_QUADS);
            glColor3f(1,0,0);           //Vermelho
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
                           float xInicial, float yInicial, float zInicial){
    glBegin(GL_POLYGON);
        // Face da frente
        glBegin(GL_QUADS);
            glColor3f(1,0,0);           //Vermelho
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

        // Face direita
        glBegin(GL_QUADS);
            glColor3f(1,0,1);           //Rosa
            glVertex3f(xInicial + largura, yInicial,  zInicial - profundidade);
            glVertex3f(xInicial + largura, yInicial,  zInicial);
            glVertex3f(xInicial + largura, yInicial + altura,  zInicial);
            glVertex3f(xInicial + largura,  yInicial + altura,  zInicial - profundidade);
        glEnd();

        // Face esquerda
        glBegin(GL_QUADS);
            glColor3f(0.5,0.5,0.3);           //Verde Oliva
            glVertex3f(xInicial, yInicial,  zInicial - profundidade);
            glVertex3f(xInicial, yInicial,  zInicial);
            glVertex3f(xInicial, yInicial + altura,  zInicial);
            glVertex3f(xInicial,  yInicial + altura,  zInicial - profundidade);
        glEnd();
}

void trianguloFechado(float altura, float largura, float profundidade,
                      float xInicial, float yInicial, float zInicial){

    glBegin(GL_TRIANGLES);
        glColor3f(1,0,0);           //Vermelho
        glVertex3f(xInicial, yInicial,  zInicial);
        glVertex3f(xInicial + largura / 2, yInicial + altura,  zInicial);
        glVertex3f(xInicial + largura, yInicial,  zInicial);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0,1,0);           //Verde
        glVertex3f(xInicial, yInicial,  zInicial - profundidade);
        glVertex3f(xInicial + largura/2, yInicial + altura,  zInicial - profundidade);
        glVertex3f(xInicial + largura, yInicial,  zInicial - profundidade);
    glEnd();

    glBegin(GL_QUADS); 
        glColor3f(0,0,1);           //Azul
        glVertex3f(xInicial, yInicial,  zInicial - profundidade);
        glVertex3f(xInicial, yInicial,  zInicial);
        glVertex3f(xInicial + largura/2, yInicial + altura,  zInicial);
        glVertex3f(xInicial + largura/2 , yInicial + altura,  zInicial - profundidade);
    glEnd();
    
    glBegin(GL_QUADS);
        glColor3f(1,0,1);           //Rosa
        glVertex3f(xInicial + largura, yInicial,  zInicial - profundidade);
        glVertex3f(xInicial + largura , yInicial,  zInicial);
        glVertex3f(xInicial + largura/2, yInicial + altura,  zInicial);
        glVertex3f(xInicial + largura/2 , yInicial + altura,  zInicial - profundidade);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1,1,1);           //Branco
        glVertex3f(xInicial + largura, yInicial,  zInicial - profundidade);
        glVertex3f(xInicial + largura , yInicial,  zInicial);
        glVertex3f(xInicial, yInicial,  zInicial);
        glVertex3f(xInicial, yInicial,  zInicial - profundidade);
    glEnd();

}

void laboratorio(){
    // //Paredes e piso
    paralelepipedoFechado(4,4,0.15,-2,-2,0);
    paralelepipedoFechado(0.15,4,4,-2,-2,4);
    paralelepipedoFechado(4,0.15,4,-2,-2,4);
    paralelepipedoFechado(4,0.15,4, 1.85,-2,4);
    
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

// Renderiza o triangulo e rotaciona-o em torno do eixo X e Y
void render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(
            x, y, z,
			x+lx, y+ly,  z+lz,
			0.0f, 1.0f,  0.0f);

    glRotatef(0, 0, 1, 0);


    laboratorio();

    
    glEnd();

    // angulo += 1.8;

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

// Encerra o programa
// x e y são paramêtros necessárias caso queiramos
// usar a coordenada do mouse no momento da chamada desta callback
void sair(unsigned char tecla, int x, int y){
    if(tecla == 'q' || tecla == 'Q'){ exit(0); }
}

void moverTeclado(int tecla, int x, int y){
    switch(tecla){
        case GLUT_KEY_RIGHT :
            angulo += 0.1f;
            lx = sin(angulo);
            lz = -cos(angulo);
            break;

        case GLUT_KEY_LEFT :
            angulo -= 0.1f;
            lx = sin(angulo);
            lz = -cos(angulo);
            
            
            break;

        case GLUT_KEY_UP :
            angulo2 += 0.1f;
            ly = sin(angulo2);
            lz = -cos(angulo2);
            // x += lx * delta;
            // z += lz * delta;
            
            break;


        case GLUT_KEY_DOWN :

            angulo2 -= 0.1f;
            ly = sin(angulo2);
            lz = -cos(angulo2);
            // x -= lx * delta;
            // z -= lz * delta;
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

    glutCreateWindow("Triangulo 3D");

    inicializar();

    glutDisplayFunc(render);
    glutKeyboardFunc(sair);
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
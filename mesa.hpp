#include "cores.hpp"
#include "primitivas.hpp"

class Mesa{
    public:
        float raio;
        int vertices;
        float x,y,z;
        

        Mesa(float r, int v, float xCord, float yCord, float zCord){ raio = r, vertices = v, x = xCord, y = yCord, z = zCord;}

        void desenhaMesa(){

        glPushMatrix();
            
            glRotatef(-90,0,1,0);
            glRotatef(-90,1,0,0);
            glTranslatef(x,y,z);
            circulo(raio,vertices, Brown);
        glPopMatrix();

        glPushMatrix();

            glTranslatef(x - 0.5,y - 0.46,z - 0.5);
            glRotatef(-90,0,1,0);
            paralelepipedoFechado(1.40,0.1,0.1, 0,0,0,cinza);
            

        glPopMatrix();

        glPushMatrix();

            glTranslatef(x-2.5,y-0.46,z -0.5);
            glRotatef(-90,0,1,0);
            paralelepipedoFechado(1.4,0.1,0.1, 0,0,0,cinza);
            

        glPopMatrix();


        glPushMatrix();

            glTranslatef(x-0.5,y - 0.46,z + 1.5);
            glRotatef(-90,0,1,0);
            paralelepipedoFechado(1.40,0.1,0.1, 0,0,0,cinza);
            

        glPopMatrix();

        glPushMatrix();

            glTranslatef(x-2.5,y-0.46,z +1.5);
            glRotatef(-90,0,1,0);
            paralelepipedoFechado(1.4,0.1,0.1, 0,0,0,cinza);
            

        glPopMatrix();
        
        }
};       
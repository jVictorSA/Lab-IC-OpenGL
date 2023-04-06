


class Ventilador{
    public:
        float xHaste, yHaste, zHaste;
        float angulo;

        Ventilador(float a, float b, float c){ xHaste = a, yHaste = b, zHaste = c;}

        void desenhaVentilador(){
            glPushMatrix();
            glTranslatef(xHaste,yHaste,zHaste);
            glRotatef(-90,0,1,0);
            paralelepipedoFechado(1.5,0.1,0.1, 0,0,0);
            glPopMatrix();

            
        }
};
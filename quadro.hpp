#ifndef QUADRO_HPP
#define QUADRO_HPP

#include "primitivas.hpp"
#include "cores.hpp"

class Quadro{
    private:
        float altura, largura, profundidade;
        std::vector<float> cor;

    public:
        Quadro(float alt, float larg, float prof, std::vector<float> corQ){
            altura = alt;
            largura = larg;
            profundidade = prof;
            cor = corQ;
        }

        ~Quadro(){}

        void desenhar(){
            glPushMatrix();
                paralelepipedoFechado(altura, largura, profundidade, 0, 0, 0, Aquamarine);
            glPopMatrix();
        }
};

#endif
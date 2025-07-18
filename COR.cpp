#include "COR.h"
#include <iostream>
using namespace std;

Colors::Colors(int r, int g, int b) : R(r), G(g), B(b){ //inicializado durante a execucao

}

Colors::~Colors(){
    //cout << "Limpeza de Colors realizada" << endl;
}

    //VERMELHO
    void Colors::setR (int red){ //funcao para receber Colors R, e alterar para o valor de red;
        if(red > -1 and red < 256){
            R = red;
        }
    }
    int Colors::getR(){return R;}

    //AZUL
    void Colors::setB (int blue){
        if(blue > -1 and blue < 256){
            B = blue;
        }
    }
    int Colors::getB(){return B;}

    //VERDE
    void Colors::setG (int green){
        if(green > -1 and green < 256){
            G = green;
        }
    }
    int Colors::getG(){return G;}

    //escurecer // sombrear
    void Colors::escurece(int fator) {
    // Aplica um fator de redução nas cores para simular a sombra
    R = int(R * fator);
    G = int(G * fator);
    B = int(B * fator);

    // Garantir que os valores de R, G e B não sejam menores que 0
    if (R < 0) R = 0;
    if (G < 0) G = 0;
    if (B < 0) B = 0;
}

    
    

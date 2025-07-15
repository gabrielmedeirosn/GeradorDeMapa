#include "COR.h"
#include <iostream>
using namespace std;

/*"colors::"" assessor da classe .H, entra na classe e ve os metodos que
podem ser completados
**USAR NOME DA CLASSE + dois pontos ":"
*/

/*Colors::Colors() : R(0), G(0), B(0) { //inicializacao ffixa, usando set para mudar

}*/

Colors::Colors(int r, int g, int b) : R(r), G(g), B(b){ ///inicializa;'ao durante a execucao

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

    

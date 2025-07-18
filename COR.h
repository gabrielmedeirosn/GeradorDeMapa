#ifndef COR_H
#define COR_H
#include <iostream>
using namespace std;
//ARQUIVO DE CABECALHO


//classe Colors para definir as cores RGB
class Colors{
private:
    int R,G,B;

public:
    Colors(int r = 0, int g = 0, int b = 0); //construtor para facilitar a criação dos objetos com inicializadores de lista
    ~Colors();//declarando destrutor
    void setR(int red);
    int getR();

    void setB(int blue);
    int getB();

    void setG(int green);
    int getG();

    void escurece (float fator);

};



#endif
#ifndef IMG_H
#define IMG_H
#include <iostream>
#include "COR.h"
using namespace std;


class Image{

private:
    int height, width;
    int* altitude; //declarando array de altitudes
    Colors* pixels; //definidas em tempo de execução -  array é alocado dinamicamente - liberar a memória no destrutor da classe
    

public:
    Image(); //definido durante tempo de execucao  
    Image(int w, int h);  //pode ser definido no codigo alocando memoria diretamente
    ~Image();
    
    
    void setHeight(int altura);
    void setWidth(int largura);
    void setAltitude (int linha, int coluna, int valor);
    int getHeight();
    int getWidth();
    float getAltitude(int linha, int coluna) const;
    
    void setPixel (int linha, int coluna, Colors cor);
    Colors getPixel(int linha, int coluna) const;
    void salvarComoPPM(const string& nomeArquivo) const; //const para a funcao nao alterar atributos da classe & para nao gerar copias acessando diretamente

};


#endif
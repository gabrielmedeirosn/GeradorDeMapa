#include "IMG.h"
#include <iostream>
#include <fstream>
using namespace std;

    Image::Image() : width(0), height(0), pixels(nullptr), altitude(nullptr){ //nullptr evita lixo de memoria

    }

    Image::Image(int w, int h) : width(w), height(h){ //Inicializa um objeto da classe Image com a largura (width) e altura (height) fornecidas, alocando dinamicamente memória
        if (width > 0 and height > 0){ //verificacao 
            pixels = new Colors[width * height]; // aloca array de pixels nna heap(memoria usada no tempo de execucao)
            //um array de Colors chamado pixels, que representa as cores dos pixels da imagem;
            altitude = new int [width * height]; //um array de int chamado altitude, que armazena a altitude de cada pixel.
        }
        else {
            pixels = nullptr; //nao aloca array caso altura e largura seja invvalida
            altitude = nullptr;
        }
    }

    Image::~Image() {
        delete[] pixels;
        delete [] altitude;
        cout << "Memória liberada" << endl;
    }

    //----------------------------------HEIGHT----------------------------------
    void Image::setHeight(int altura){ //DEFINE ALTURA
        height = altura;
    }
    int Image::getHeight(){return height;} //RETORNA ALTURA

    //----------------------------------WIDTH----------------------------------
    void Image::setWidth(int largura){ //DEFINE LARGURA
        width = largura;
    }
    int Image::getWidth(){return width;} //RETORNA LARGURA

    // ----------------------------------ALTITUDE----------------------------------

    void Image::setAltitude (int linhaAltitude, int colunaAltitude, int valor){
        if(colunaAltitude>= 0 and colunaAltitude< width and linhaAltitude >= 0 and linhaAltitude< height){//verifica se esta dentro dos limites
            altitude[linhaAltitude *width + colunaAltitude] = valor;
        }
    }
    int Image::getAltitude (int linhaAltitude, int colunaAltitude) const{
        if(colunaAltitude>= 0 and colunaAltitude< width and linhaAltitude >= 0 and linhaAltitude< height){//verifica se esta dentro dos limites
            return altitude[linhaAltitude *width + colunaAltitude];
        }
        else {
        return 0;
        }
    }

    // ----------------------------------PIXELS----------------------------------
    void Image::setPixel(int linhaPixels, int colunaPixels, Colors cor){ //Define a COR de um pixel na posição (linhaPixels, colunaPixels).
        if(colunaPixels>= 0 and colunaPixels < width and linhaPixels >= 0 and linhaPixels < height){//verifica se esta dentro dos limites
            pixels[linhaPixels *width + colunaPixels] = cor; // atribui uma cor(RGB) ao pixel
        }
    }
    Colors Image::getPixel(int linhaPixels, int colunaPixels) const{ //Retorna a cor (RGB) do pixel localizado em (linhaPixels, colunaPixels).(CONST para expecificar que nao vai alterar nenhum valor)
        return pixels[linhaPixels * width + colunaPixels];
    }

    
    
    //CRIAR IMAGEM
    void Image::salvarComoPPM(const string& nomeArquivo) const {
        ofstream arquivo(nomeArquivo);
        if(!arquivo.is_open()){ //funcao para vereficar se o arquivo foi NAO(!) aberto para ser feita a escrita
            cout << "ERRO" << endl;
            return;
        }
        //cabecalho PPM
        arquivo << "P3" << endl;
        arquivo << width << " " << height << endl;
        arquivo << "255" << endl;

        //set pixels
        //definindo um R,G e B para cada pixel da matriz [i,j]
        for(int i = 0; i < height; i++){
            for (int j = 0; j<width; j++){
                Colors c = getPixel(i,j);
                arquivo << c.getR() << " " << c.getG() << " " << c.getB() << " ";
        }
        arquivo << endl;
        }
        arquivo.close();
        cout << "Imagem salva" << endl;

}
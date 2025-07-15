#include "IMG.h"
#include <iostream>
#include <fstream>
using namespace std;

    Image::Image() : width(0), height(0), pixels(nullptr){ //nullptr evita lixo de memoria

    }

    Image::Image(int w, int h) : width(w), height(h){ //A lista de inicialização inicializa os membros da classe diretamente com os valores passados,
        if (width > 0 and height > 0){ //verificacao
            pixels = new Colors[width * height]; // aloca array de pixels nna heap(memoria usada no tempo de execucao)
        }
        else {
            pixels = nullptr; //nso aloca array caso altura e largura seja invvalida
        }
    }

    Image::~Image() {
        delete[] pixels;
        cout << "Memória liberada da Image" << endl;
    }

    //----------------------------------HEIGHT----------------------------------
    void Image::setHeight(int altura){
        height = altura;
    }
    int Image::getHeight(){return height;}

    //----------------------------------WIDTH----------------------------------
    void Image::setWidth(int largura){
        width = largura;
    }
    int Image::getWidth(){return width;}

    // ----------------------------------PIXELS----------------------------------
    void Image::setPixel(int linhaPixels, int colunaPixels, Colors cor){
        if(colunaPixels>= 0 and colunaPixels < width and linhaPixels >= 0 and linhaPixels < height){//verifica se esta dentro dos limites
            pixels[linhaPixels *width + colunaPixels] = cor; // atribui uma cor(RGB) ao pixel
        }
    }
    Colors Image::getPixel(int linhaPixels, int colunaPixels) const{
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
        for(int i = 0; i < height; i++){
            for (int j = 0; j<width; j++){
                Colors c = getPixel(i,j);
                arquivo << c.getR() << " " << c.getG() << " " << c.getB() << " ";
        }
        arquivo << endl;
        }
        arquivo.close();
        cout << "imagem salva" << endl;

}
#include <iostream>
#include <fstream>  // para ifstream
#include <string>
#include <cmath>
#include "COR.h"
#include "PALETA.h"
#include "IMG.h"
//#include "paleta.h"
using namespace std;


int main() {

    Paleta paleta;
    
    //leitura de arquivo COR
    ifstream arquivo("colors.cor");  // Abrir o arquivo
    int r,g,b;
    int numCores;
    int i = 0;
    double valor;

    arquivo >> numCores;

    while(arquivo >> valor >> r >> g >> b){
        if(i>=numCores){
            break;
        }
        paleta.valores[i] = valor;
        paleta.cores[i] = Colors(r,g,b);

        ++i;

    }

    cout << "Levando em conta que o tamanho do mapa e definido pela formula"<< endl << "2^n + 1" <<
    endl << "n = 1  →  3 x 3" << endl <<
    "n = 2  →  5 x 5" << endl <<
    "n = 3  →  9 x 9" << endl <<
    "n = 4  →  17 x17" << endl <<
    "n = 5  →  33 x 33" << endl <<
    "n = 6  →  65 x 65" << endl <<
    "n = 7  →  129 x 129" << endl <<
    "n = 8  →  257 x 257" << endl <<
    "n = 9  →  513 x 513" << endl <<
    "n = 10 →  1025 x 1025" << endl <<
    "n = 11 →  2049 x 2049" << endl;

    cout << "Digite o N desejado: " << endl;
    //definindo tamanho do mapa
    int n;// tamanho do N para gerar altura e largura
    cin >> n;
    int size;
    size = pow(2,n) + 1;
    cout << size << " tamanho da img" << endl;
    

    Image mapa(size, size);
    /*mapa.setHeight(size);
    mapa.setWidth(size);*/
    

    //definindo altitude do mapa
    Image altitudeMap(size, size);
    srand(time(0)); //gerar uma "semente de numero aleatorio baseado no horario"
    //int valor = rand()%28; //->> 0,1,2,3,4,5,6,7,8,9,10
    
    for(int linha=0; linha < mapa.getHeight(); linha++){
        for(int coluna = 0; coluna<mapa.getWidth(); coluna++) {
            int randomNum = rand()%28;
            Colors cor = paleta.consultarCor(randomNum);
            mapa.setPixel(linha,coluna,cor);
        }
    }

    mapa.salvarComoPPM("teste1.ppm");

    

    /*int valorConsulta;
    cout << "Digite um valor entre 1 e 28: ";
    cin >> valorConsulta;

    Colors resultado = paleta.consultarCor(valorConsulta);

    cout << "Cor correspondente: RGB("
         << resultado.getR() << ", "
         << resultado.getG() << ", "
         << resultado.getB() << ")" << endl;

    //cout << resultado.getR() + resultado.getB() << endl;*/

    return 0;
}
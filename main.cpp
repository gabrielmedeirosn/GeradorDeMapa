#include <iostream>
#include <fstream>  // para ifstream
#include <string>
#include <cmath>
#include "COR.h"
#include "PALETA.h"
#include "IMG.h"
#include "diamondSquare.h"
using namespace std;


int main() {

    Paleta paleta;
    
    //leitura de arquivo COR
    ifstream arquivo("colors.cor");  // Abrir o arquivo
    int r,g,b;
    int numCores;
    int i = 0;
    int valor;

    arquivo >> numCores;

    while(arquivo >> valor >> r >> g >> b){
        if(i>=numCores){
            break;
        }
        paleta.valores[i] = valor;
        paleta.cores[i] = Colors(r,g,b);

        ++i;

    }

    cout << "Levando em conta que o tamanho do mapa e definido pela formula "<< endl << "2^n + 1" <<
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

    cout << "Digite o N desejado(Recomendado opção 10 e 11 para uma melhor qualidade): " << endl;
    //definindo tamanho do mapa
    int n;// tamanho do N para gerar altura e largura
    cin >> n;
    
    if(n>12){ //verificacao
        cout << "Um mapa tão grande não é recomendado, escolha um valor dentro da faixa." << endl;
        return 1;
    }

    //definir tamanho do mapa apartir da formula
    int size;
    size = pow(2,n) + 1;
    
    // Image que vai receber as cores por Colors pixels
    Image mapa(size, size); 
    //definindo um mapa para receber apenas os valores das altitudes
    Image altitudeMap(size, size);

    
    



    srand(time(0)); // seed
    //Altitudes serao aplicadas na Image altitudeMap
    diamondSquare(altitudeMap, paleta.valores[0], numCores); //o range de cores vai ser definido de acordo com o arquivo colors.cor

    
    

    //Colorir a imagem pixel por pixel
    for(int lin = 0; lin < mapa.getHeight(); lin++) {
        for(int col = 0; col < mapa.getWidth(); col++) {
            int altura = altitudeMap.getAltitude(lin, col);

            if (lin > 0 && col > 0) { // Não aplica para a primeira linha ou coluna
                int alturaSuperiorEsquerda = altitudeMap.getAltitude(col - 1, lin - 1); // Altura do pixel superior esquerdo

                if (altura < alturaSuperiorEsquerda) { // Se a altura for menor, aplica o escurecimento
                    Colors cor = paleta.consultarCor(altura);
                    cor.escurece(0.3f); //fator de escurecimento
                    mapa.setPixel(lin, col, cor);
                }

            else{
                Colors cor = paleta.consultarCor(altura);
                mapa.setPixel(lin, col, cor);
                }
            }

        else {
            // Para a primeira linha ou coluna, não há comparação com pixels superiores
            Colors cor = paleta.consultarCor(altura);
            mapa.setPixel(lin, col, cor);
            }
    
        }
    }   

    cout << "Digite o nome desejado do arquivo (sem extensão)"  << endl;
    cin.ignore();
    string nomeImagem;
    getline(cin, nomeImagem);
    nomeImagem+= ".ppm";
    


    mapa.salvarComoPPM(nomeImagem);

    return 0;
}
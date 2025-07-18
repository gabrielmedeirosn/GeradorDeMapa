#include <cstdlib> // para rand()
#include <ctime>   // para time()
#include "IMG.h"
#include "COR.h"
#include "PALETA.h"
#include <iostream>

using namespace std;

//garante que os valores apos variacao esteja sempre dentro dos limites
int clamp(int val, int minVal, int maxVal) {
    if (val < minVal) return minVal;
    if (val > maxVal) return maxVal;
    return val;
}
//Gera um mapa de altitude utilizando o algoritmo Diamond-Square
void diamondSquare(Image& altitudeMap, int minValue, int maxValue) {
    int size = altitudeMap.getWidth();
    int stepSize = size - 1;
    float roughness = 0.27f; //rugosidade, gerar mudancas no terreno
    

    //Define valores aleatórios nos quatro cantos do mapa
    altitudeMap.setAltitude(0, 0, rand() % (maxValue - minValue + 1) + minValue);
    altitudeMap.setAltitude(0, stepSize, rand() % (maxValue - minValue + 1) + minValue);
    altitudeMap.setAltitude(stepSize, 0, rand() % (maxValue - minValue + 1) + minValue);
    altitudeMap.setAltitude(stepSize, stepSize, rand() % (maxValue - minValue + 1) + minValue);


    while (stepSize > 1) {
        int halfStep = stepSize / 2;

        // Diamond Step - calcula a media das quinas , adiciona variacao, define o valor central
        for (int lin = halfStep; lin < size; lin += stepSize) {
            for (int col = halfStep; col < size; col += stepSize) {
                int a = 0, b = 0, c = 0, d = 0;
                int count = 0;

                if (lin - halfStep >= 0 && col - halfStep >= 0) {
                    a = altitudeMap.getAltitude(lin - halfStep, col - halfStep);
                    count++;
                }
                if (lin + halfStep < size && col - halfStep >= 0) {
                    b = altitudeMap.getAltitude(lin + halfStep, col - halfStep);
                    count++;
                }
                if (lin - halfStep >= 0 && col + halfStep < size) {
                    c = altitudeMap.getAltitude(lin - halfStep, col + halfStep);
                    count++;
                }
                if (lin + halfStep < size && col + halfStep < size) {
                    d = altitudeMap.getAltitude(lin + halfStep, col + halfStep);
                    count++;
                }

                if (count > 0) {
                    int media = (a + b + c + d) / count;
                    int offset = (rand() % (stepSize + 1)) - halfStep;
                    int newMedia = media + (int)(offset * roughness);
                    newMedia = clamp(newMedia, minValue, maxValue);
                    altitudeMap.setAltitude(col, lin, newMedia);
                }
            }
        }

        /*offset: stepSize=8, halfStep=4, rand()%stepSize+1 -> gera um numero de 0-8
        e subtrai o halfStep variando o resultado de -4 ate 4;
        newMedia forca um numero inteiro e chama a funcao clamp para ver se esta dentro dos limites*/


        // Square Step - calcula media dos vizinhos, em cruz, adiciona variacao, define valor central
        for (int lin = 0; lin < size; lin += halfStep) {
            for (int col = (lin + halfStep) % stepSize; col < size; col += stepSize) {
                int sum = 0, count = 0;

                if (lin - halfStep >= 0) {
                    sum += altitudeMap.getAltitude(lin - halfStep, col);
                    count++;
                }
                if (lin + halfStep < size) {
                    sum += altitudeMap.getAltitude(lin + halfStep, col);
                    count++;
                }
                if (col - halfStep >= 0) {
                    sum += altitudeMap.getAltitude(lin, col - halfStep);
                    count++;
                }
                if (col + halfStep < size) {
                    sum += altitudeMap.getAltitude(lin, col + halfStep);
                    count++;
                }

                int mediaSquare = sum / count;
                int offset = (rand() % (stepSize + 1)) - halfStep;
                int newValue = mediaSquare + (int)(offset * roughness);
                newValue = clamp(newValue, minValue, maxValue);
                altitudeMap.setAltitude(col, lin, newValue);
            }
        }

        stepSize /= 2;
    }
}


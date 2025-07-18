#ifndef DIAMONDSQUARE_H
#define DIAMONDSQUARE_H

#include "IMG.h"

/**ALGORITIMO DIAMOND-SQUARE (RECEBE A VARIVAL QUE QUE VAI ARMZENAR AS ALTITUDES,POR REFERENCIA PRA EVITAR COPIAR
, O VALOR MINIMO QUE VAI SER A COR MAIS "BAIXA" E O VALOR MAXIMO QUE VAI SER A COR MAIS ALTA)*/

/*altitudeMap: uma referência para um objeto Image que armazenará os valores de altitude.
minValue: valor mínimo possível para a altitude.
maxValue: valor máximo possível para a altitude.
modifica diretamente o objeto altitudeMap*/
void diamondSquare(Image &altitudeMap, int minVal, int maxVal);

#endif

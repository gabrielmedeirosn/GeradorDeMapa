#ifndef PALETA_H
#define PALETA_H
#include "COR.h"

struct Paleta {
    int quantidade = 28;
    Colors cores[100];
    int valores[100];

    //retorna a cor do pixel de acordo com a altitude
    Colors consultarCor(int valor) const {
        if (valor >= 1 && valor <= quantidade) {
            return cores[valor - 1]; // -1 porque o array começa no índice 0
        }
        else{
            return cores[0]; //retorna cor padrão
        }
    }

};

#endif


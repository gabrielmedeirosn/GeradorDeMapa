#include <iostream>
#include "IMG.h"
#include "COR.h"

using namespace std;

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*Diamond Square Funcionamento::
    matriz de altitudes[height][width]: 
    */
    //valor = 1+rand()%10 -> 1,2,3,4,5,6,7,8,9,10

    /*Para isso eh gerado uma altura aleatoria para os extremos [0,0] = 8 || [0,256] = 6 || [256,0] = 6 || [256,256] = 7
    MEDIA ENTRE OS 4 PONTOS DEFINIDOS DE FORMA ALEATORIA ANTERIORMENTE DEFININDO UM VALOR MAXIMO Heights[1,28](numero de cores)
    Ponto central: [128][128] = 8+6+6+7 = 27 / 4 = 7 (arredondamento pra cima) + deslocamento randomico double roughness[n] -> a cada
    interacao n/2 (Definido no PDF)
    [8] X X X X X X X  [6]
    X                   X
    X                   X
    X                   X
    X                   X
    X                   X
    X                   X
    X                   X 
    [6] X X X X X X X  [7]
    
    Usando os extremos da esqueda + ponto central, calculamos o meio da coluna [0], depois o meio da linha 128,
    depois o meio da coluna 128, e depois o meio da linha 0

    alternar entre algoritimo diamond and square:

    calcula o ponto central dos quadrados (square step).

    calcula os pontos centrais dos diamantes entre esses quadrados (diamond step).

    divide o tamanho pela metade e repete, detalhando mais o terreno.

    vai parando quando os passos ficam muito pequenos.
*/

int main(){
   
   
    srand(time(0)); //gerar uma "semente de numero aleatorio baseado no horario"
    int valor = rand()%10; //->> 0,1,2,3,4,5,6,7,8,9,10

    
    return 0;
}

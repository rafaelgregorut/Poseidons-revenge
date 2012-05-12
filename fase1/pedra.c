#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "pedra.h"

/*Gera um número aleatório nos intervalos:
  - eixo x: intervalo baseado na posição x da catapulta
  - eixo y: intervalo baseado na posição y do barco.*/
float calculaDistanciaRandY(float posicaoCatapultaY, float coordenadaBarcoY, int tamanhoDaTela)
{
  float distancia = rand()%tamanhoDaTela;
  float epsilon = 5;
  srand(time(NULL));
  while(distancia < (coordenadaBarcoY - epsilon) || distancia > (coordenadaBarcoY + epsilon))
    distancia = rand()%tamanhoDaTela;
  return distancia;
}

/*Calcula o tempo do movimento da pedra, que ocorre no eixo y.*/
float tempoMovimentoPedra(float distanciaRandY, float velocidadePedraY)
{
  return distanciaRandY/velocidadePedraY;
}

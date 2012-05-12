#include <math.h>
#include "barco.h"

/*Retorna o ângulo alfa entre o eixo y e o vetor da velocidade do vento.*/
float anguloIncidenciaVento(float velocidadeVentoX, float velocidadeVentoY)
{
  float tangente = velocidadeVentoX/velocidadeVentoY;
  return atan(tangente);
}

/*Retorna o ângulo teta entre o eixo x e o vetor da velocidade do barco. */
float anguloDirecaoBarco(float velocidadeBarcoX, float velocidadeBarcoY)
{
  float tangente = velocidadeBarcoY/velocidadeBarcoX;
  return atan(tangente);
}
/*O ângulo final é o alfa + 90° - teta. O valor (1.570796327) é PI/2*/
float calculaAnguloFinal(float anguloDirecaoBarco,float anguloIncidenciaVento)
{
  return (anguloIncidenciaVento+((1.570796327)-(anguloDirecaoBarco))); 
}

/*Fórmula obtida pelo grupo na modelagem. a = Vvento^2 * cos(ângulo final) / sqrt(area da vela)*/
float aceleracaoBarco(float velocidadeVento, float anguloFinal, float areaVela)
{
  return (velocidadeVento*velocidadeVento*cos(anguloFinal))/sqrt(areaVela);
}


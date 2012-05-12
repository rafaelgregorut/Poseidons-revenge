#include <math.h>
#include "formulas.h"

/*Fórmulas do movimento retilineo uniformemente acelerado.*/

/*V = Vo + a * t*/
float velocidadeFinal(float velocidadeInicial,float aceleracao,float tempo)
{
  return(velocidadeInicial+(aceleracao*tempo));
}

/*S = So + Vo * t + (a * t^2) / 2*/
float deslocamentoFinal(float deslocamentoInicial,float velocidadeInicial,float aceleracao,float tempo)
{
  float aceleracaoTempo;
  aceleracaoTempo = (aceleracao*((tempo*tempo)/2));
  return(deslocamentoInicial + (velocidadeInicial*tempo) + aceleracaoTempo);
}

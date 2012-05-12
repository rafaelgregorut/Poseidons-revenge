#include <math.h>
#include <inttypes.h>
#include "flecha.h"

/*Retorna o angulo gama entre o delta Y dividido pelo Delta X*/
float anguloInimigo(float coordenadaBarcoX, float coordenadaBarcoY, float coordenadaInimigoX, float coordenadaInimigoY)
{
  float moduloY, moduloX;
  moduloY = coordenadaInimigoY - coordenadaBarcoY;
  moduloX = coordenadaInimigoX - coordenadaBarcoX;
  if(moduloY < 0)
    moduloY *= -1;
  if(moduloX < 0)
    moduloX *= -1;
  return atan(moduloY / moduloX);
}

/*Vx = V * cos(gama)*/
float velocidadeFlechaX(float anguloInimigo, float velocidadeFlecha)
{
  return velocidadeFlecha*cos(anguloInimigo);
}

/*Vy = v * sen(gama)*/
float velocidadeFlechaY(float anguloInimigo, float velocidadeFlecha)
{
  return velocidadeFlecha*sin(anguloInimigo);
}
	      

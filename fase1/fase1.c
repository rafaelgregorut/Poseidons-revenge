#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "barco.h"
#include "formulas.h"
#include "pedra.h"
#include "flecha.h"
#define TRUE 1
#define FALSE 0

/*Captura os números no arquivo de entrada. Esses números na entrada podem estar em int ou float.*/
float pegaNumero(FILE *entrada, char *letra)
{
  int numeroAposVirgula = FALSE, racional = 1;
  float numero = 0.0;
  for(*letra = fgetc(entrada); (*letra >= 48 && *letra <= 57) || *letra == '.'; *letra = fgetc(entrada)){
    if(*letra == '.')
      numeroAposVirgula = TRUE;
    else{
      if(numeroAposVirgula == TRUE)
	racional *= 10;
      numero  = (10 * numero) + (*letra - 48);
    }
  }
  return numero / racional;
}

/*Os valores abaixo foram escolhidos durante o projeto e foram feitos na mão os cálculos das funções.
  O tempo q consideramos foi 5 unidades de tempo.*/
/*void iniciaTeste()
{
  FILE arquivo;
  char entrada[17];
  entrada = "testeEntrada.txt";
  arquivo = fopen(entrada, "w");
  fprintf(arquivo,".w\n");
  fprintf(arquivo,"%f\n", 20);
  fprintf(arquivo,"%f\n", 35);
  fprintf(arquivo,".b\n");
  fprintf(arquivo,"%f\n", 10);
  fprintf(arquivo,"%f\n", 5);
  fprintf(arquivo,"%f\n", 8);
  fprintf(arquivo,"%f\n", 6);
  fprintf(arquivo,"%f\n", 45);
  fprintf(arquivo,"%f\n", 61);
  fprintf(arquivo,".f\n");
  fprintf(arquivo,"%f\n", 50);
  fprintf(arquivo,"%f\n", 52);
  fprintf(arquivo,"%f\n", 75);
  fprintf(arquivo,"%f\n", 40);
  fprintf(arquivo,".s\n");
  fprintf(arquivo,"%f\n", 100);
  fprintf(arquivo,"%f\n", 32);
  fprintf(arquivo,"%f\n", 47);
  fprintf(arquivo,"%f\n", 30);
  fprintf(arquivo,"%f\n", 25);
  fclose(arquivo);
}

void finalizaTeste()
{
  FILE *arquivo;
  char saida[15], *letra;
  int numeroErros = 0;
  float epsilon = 0.001;
  float velocidadeVentoX, velocidadeVentoY;
  float coordenadaSereiaX, coordenadaSereiaY, coordenadaTornadoX, coordenadaTornadoY, coordenadaMonstroX, coordenadaMonstroY;
  float moduloVelocidadeFlecha, velocidadeFlechaXF, velocidadeFlechaYF;
  float coordenadaCatapultaX, coordenadaCatapultaY, velocidadePedraY, distanciaPedra, tempoPedra;
  float massa, coordenadaBarcoXF,coordenadaBarcoYF,velocidadeBarcoYF,velocidadeBarcoXF;
  saida = "testeEntrada.txt";
  arquivo = fopen(saida, "r");
  letra = malloc(sizeof (char));
  *letra = fgetc(arquivo);
  while(*letra != EOF){
    if(*letra == '.'){
      *letra = fgetc(arquivo);
      if(*letra == 'w'){
	*letra = fgetc(arquivo);
	velocidadeVentoX = pegaNumero(arquivo, letra);
	velocidadeVentoY = pegaNumero(arquivo, letra);
      }
      else if(*letra == 'b'){
	*letra = fgetc(arquivo);
	coordenadaSereiaX = pegaNumero(arquivo, letra);
	coordenadaSereiaY = pegaNumero(arquivo, letra);
	coordenadaTornadoX = pegaNumero(arquivo, letra);
	coordenadaTornadoY = pegaNumero(arquivo, letra);
	coordenadaMonstroX = pegaNumero(arquivo, letra);
	coordenadaMonstroY = pegaNumero(arquivo, letra);
      }
      else if(*letra == 'f'){
	*letra = fgetc(arquivo);
	moduloVelocidadeFlecha = pegaNumero(arquivo, letra);
	velocidadeFlechaXF = pegaNumero(arquivo, letra);
	velocidadeFlechaYF = pegaNumero(arquivo, letra);
	coordenadaCatapultaX = pegaNumero(arquivo, letra);
	coordenadaCatapultaY = pegaNumero(arquivo, letra);
	velocidadePedraY = pegaNumero(arquivo, letra);
	distanciaPedra = pegaNumero(arquivo, letra);
	tempoPedra = pegaNumero(arquivo, letra);
	  }
      else if(*letra == 's'){
	*letra = fgetc(arquivo);
	massa = pegaNumero(arquivo, letra);
	coordenadaBarcoXF = pegaNumero(arquivo, letra);
	coordenadaBarcoYF = pegaNumero(arquivo, letra);
	velocidadeBarcoXF = pegaNumero(arquivo, letra);
	velocidadeBarcoYF = pegaNumero(arquivo, letra);
      }
    }
    *letra = fgetc(arquivo);
  }
  free(letra);
  fclose(arquivo);
  if(velocidadeBarcoXF < 64.93824494 - epsilon || velocidadeBarcoXF > 64.93824494 + epsilon){
    printf("ERRO O TESTE!!! A velocidade final no eixo x do barco está errada.\n");
    numeroErros++;
  }
  if(velocidadeBarcoYF < 131.9983751 - epsilon || velocidadeBarcoYF > 131.9983751 + epsilon){
    printf("ERRO O TESTE!!! A velocidade final no eixo y do barco está errada.\n");
    numeroErros++;
  }
  if(coordenadaBarcoXF < 269.3456124 - epsilon || coordenadaBarcoXF > 269.3456124 + epsilon){
    printf("ERRO O TESTE!!! A coordenada final no eixo x do barco está errada.\n");
    numeroErros++;
  }
  if(coordenadaBarcoYF < 439.4959379 - epsilon || coordenadaBarcoYF > 439.4959379 + epsilon){
    printf("ERRO O TESTE!!! A coordenada final no eixo y do barco está errada.\n");
    numeroErros++;
  }
  if(velocidadeFlechaXF < 34.02255497 - epsilon || velocidadeFlechaXF > 34.02255497 + epsilon){
    printf("ERRO O TESTE!!! A velocidade final no eixo x da flecha está errada.\n");
    numeroErros++;
  }
  if(velocidadeFlechaYF < 36.63967458 - epsilon || velocidadeFlechaYF > 36.63967458 + epsilon){
    printf("ERRO O TESTE!!! A velocidade final no eixo y da flecha está errada.\n");
    numeroErros++;
  }
  if(tempoPedra < (distanciaPedra / velocidadePedraY) - epsilon || tempoPedra > (distanciaPedra / velocidadePedraY) + epsilon){
    printf("ERRO O TESTE!!! O tempo do movimento da pedra está errado.\n");
    numeroErros++;
  }
  if(numeroErros == 0)
    printf("Não ocorreram erros no teste!\n");
}*/

int main(int argc, char *argv[])
{
  FILE *arquivo;
  char entrada[30],saida[30];
  float tempo,areaVela, tamanhoTela;
  float velocidadeVentoX, velocidadeVentoY;
  float coordenadaSereiaX, coordenadaSereiaY, coordenadaTornadoX, coordenadaTornadoY, coordenadaMonstroX, coordenadaMonstroY;
  float distanciaPedra, coordenadaCatapultaX, coordenadaCatapultaY, velocidadePedraY, tempoPedra;
  float velocidadeFlechaXF, velocidadeFlechaYF, moduloVelocidadeFlecha;
  float massa, coordenadaBarcoXI, coordenadaBarcoYI, velocidadeBarcoXI, velocidadeBarcoYI;
  float coordenadaBarcoXF,coordenadaBarcoYF,velocidadeBarcoYF,velocidadeBarcoXF;
  float anguloVento, anguloBarco, anguloFlecha, anguloFinal;
  float aceleracaoX, aceleracaoY;
  char *letra;
  /*Captura do arquivo de entrada e do arquivo de saida.*/
  /*if(argc == 3 && strcmp(argv[2], "-teste") == 0){
    iniciaTeste();
    entrada = "testeEntrada.txt";
    saida = "testeSaida.txt"
  }
  else{  */
    printf("O nome do arquivo de entrada:\n");
    scanf("%s",entrada);
    printf("O nome do arquivo de saida:\n");
    scanf("%s",saida);
    /*}*/
  arquivo = fopen(entrada, "r");
  /*Apontador para a função pegaNumero.*/
  letra = malloc(sizeof (char));
  /*Recebendo os valores float do arquivo de entrada.*/
  *letra = fgetc(arquivo);
  while(*letra != EOF){
    if(*letra == '.'){
      *letra = fgetc(arquivo);
      if(*letra == 'w'){
	*letra = fgetc(arquivo);
	velocidadeVentoX = pegaNumero(arquivo, letra);
	velocidadeVentoY = pegaNumero(arquivo, letra);
      }
      else if(*letra == 'b'){
	*letra = fgetc(arquivo);
	coordenadaSereiaX = pegaNumero(arquivo, letra);
	coordenadaSereiaY = pegaNumero(arquivo, letra);
	coordenadaTornadoX = pegaNumero(arquivo, letra);
	coordenadaTornadoY = pegaNumero(arquivo, letra);
	coordenadaMonstroX = pegaNumero(arquivo, letra);
	coordenadaMonstroY = pegaNumero(arquivo, letra);
      }
      else if(*letra == 'f'){
	*letra = fgetc(arquivo);
	moduloVelocidadeFlecha = pegaNumero(arquivo, letra);
	coordenadaCatapultaX = pegaNumero(arquivo, letra);
	coordenadaCatapultaY = pegaNumero(arquivo, letra); 
	velocidadePedraY = pegaNumero(arquivo, letra);
      }
      else if(*letra == 's'){
	*letra = fgetc(arquivo);
	massa = pegaNumero(arquivo, letra);
	coordenadaBarcoXI = pegaNumero(arquivo, letra);
	coordenadaBarcoYI = pegaNumero(arquivo, letra);
	velocidadeBarcoXI = pegaNumero(arquivo, letra);
	velocidadeBarcoYI = pegaNumero(arquivo, letra);
      }
    }
    *letra = fgetc(arquivo);
  }
  free(letra);
  fclose(arquivo);
  /*Constantes do programa.*/
  if(argc == 2)
    tempo = atof(argv[1]);
  else{
    printf("./fase1 tempo\n");
    return 0;
  }
  areaVela = 100;
  tamanhoTela = 1000;
  /*Calculo dos ângulos do movimento retilinio acelerado.*/
  anguloVento = anguloIncidenciaVento(velocidadeVentoX,velocidadeVentoY); 
  anguloBarco = anguloDirecaoBarco(velocidadeBarcoXI,velocidadeBarcoYI);
  anguloFinal = calculaAnguloFinal(anguloBarco,anguloVento);
  /*Calculo da aceleração, velocidade e coordenada do barco no eixo X.*/
  aceleracaoX = aceleracaoBarco(velocidadeVentoX, anguloFinal, areaVela);
  velocidadeBarcoXF = velocidadeFinal(velocidadeBarcoXI,aceleracaoX,tempo);
  coordenadaBarcoXF = deslocamentoFinal(coordenadaBarcoXI,velocidadeBarcoXI,aceleracaoX,tempo);
  /*Calcula da aceleração, velocidade e coordenada do barco no eixo Y.*/
  aceleracaoY = aceleracaoBarco(velocidadeVentoY, anguloFinal, areaVela);
  velocidadeBarcoYF = velocidadeFinal(velocidadeBarcoYI,aceleracaoY,tempo);
  coordenadaBarcoYF = deslocamentoFinal(coordenadaBarcoYI,velocidadeBarcoYI,aceleracaoY,tempo);
  /*Calculo do ângulo do movimento da flecha e suas velocidades nos eixos X e Y. Pra efeito de calculo as flechas são atiradas no inicio do movimento.*/
  anguloFlecha = anguloInimigo(coordenadaBarcoXI, coordenadaBarcoYI, coordenadaMonstroX, coordenadaMonstroY);
  velocidadeFlechaXF = velocidadeFlechaX(anguloFlecha, moduloVelocidadeFlecha);
  velocidadeFlechaYF = velocidadeFlechaY(anguloFlecha, moduloVelocidadeFlecha);
  /*Calculo do tempo que a pedra fica no ar até percorrer a distância pseudo-aleatória.*/
  distanciaPedra = calculaDistanciaRandY(coordenadaCatapultaX, coordenadaCatapultaY, tamanhoTela);
  tempoPedra = tempoMovimentoPedra(distanciaPedra, velocidadePedraY);
  /*Colocando os valores obtidos após as contas no arquivo de saida.*/
  arquivo = fopen(saida, "w");
  fprintf(arquivo,".w\n");
  fprintf(arquivo,"Velocidade vento no eixo x: %f\n", velocidadeVentoX);
  fprintf(arquivo,"Velocidade vento no eixo y: %f\n",velocidadeVentoY);
  fprintf(arquivo,".b\n");
  fprintf(arquivo,"Coordenada sereia no eixo x: %f\n", coordenadaSereiaX);
  fprintf(arquivo,"Coordenada sereia no eixo y: %f\n", coordenadaSereiaY);
  fprintf(arquivo,"Coordenada tornado no eixo x: %f\n", coordenadaTornadoX);
  fprintf(arquivo,"Coordenada tornado no eixo y: %f\n", coordenadaTornadoY);
  fprintf(arquivo,"Coordenada monstro no eixo x: %f\n", coordenadaMonstroX);
  fprintf(arquivo,"Coordenada monstro no eixo y: %f\n", coordenadaMonstroY);
  fprintf(arquivo,".f\n");
  fprintf(arquivo,"Modulo velocidade flecha: %f\n", moduloVelocidadeFlecha);
  fprintf(arquivo,"Velocidade flecha no eixo x: %f\n", velocidadeFlechaXF);
  fprintf(arquivo,"Velocidade flecha no eixo y: %f\n", velocidadeFlechaYF);
  fprintf(arquivo,"Coordenada catapulta no eixo x: %f\n", coordenadaCatapultaX);
  fprintf(arquivo,"Coordenada catapulta no eixo y: %f\n", coordenadaCatapultaY);
  fprintf(arquivo,"Velocidade pedra no eixo y: %f\n", velocidadePedraY);
  fprintf(arquivo,"Distancia percorrida pela pedra: %f\n", distanciaPedra);
  fprintf(arquivo,"Tempo que levou o movimento da pedra: %f\n", tempoPedra);
  fprintf(arquivo,".s\n");
  fprintf(arquivo,"Massa do barco: %f\n", massa);
  fprintf(arquivo,"Coordenada final do barco no eixo x: %f\n", coordenadaBarcoXF);
  fprintf(arquivo,"Coordenada final do barco no eixo y: %f\n", coordenadaBarcoYF);
  fprintf(arquivo,"Velocidade final do barco no eixo x: %f\n", velocidadeBarcoXF);
  fprintf(arquivo,"Velocidade final do barco no eixo y: %f\n", velocidadeBarcoYF);
  fclose(arquivo);
  /* if(argc == 3 && strcmp(argv[2], "-teste") == 0){
     finalizaTeste();*/
  return 0;
}

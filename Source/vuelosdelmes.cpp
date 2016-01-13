#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "gestionvuelosmes.h"

void TipoGestion::VisualizarVuelosDelMes (TipoVectorVuelos arrayVuelos) {

int precioAux;
  int mesAux, anyoAux, contador;

  printf("\n Mes? ");
  scanf("%d",&mesAux);
  printf("\n Año? ");
  scanf("%d",&anyoAux);

  //VisualizarCalendarioVuelosMes(arrayVuelos, mesAux, anyoAux);
  system("pause"); //Espera una pausa


}

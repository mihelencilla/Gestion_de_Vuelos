#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "gestionvuelosmes.h"
#include "calendario.h"

TipoCalendario calendario;

void TipoGestion::VisualizarVuelosDelMes (TipoVectorVuelos arrayVuelos) {

  int mesAux, anyoAux, dias, bisiestos, anyos;
  TipoDia diaSemana;

  printf("\n Mes? ");
  scanf("%d",&mesAux);
  printf("A�o? ");
  scanf("%d",&anyoAux);

  if (((mesAux>=1)&&(mesAux<=12))&&((anyoAux==2016)||(anyoAux==2017))){
    dias = calendario.CalcularDias(mesAux); // calcula los d�as que tiene el mes escrito
    anyos = anyoAux-2016; // calcula los a�os que hay entre 2016 y el a�o escrito
    if (anyoAux == 2016){
      bisiestos = 1;
    }
    else{
      bisiestos = 0;
    }
    diaSemana = calendario.CalcularDiaSemana(mesAux, anyoAux); //calcula el dia de la semana en la que empieza el mes y a�o escrito
    calendario.VisualizarCalendarioVuelosMes(arrayVuelos, mesAux, anyoAux, diaSemana);
  }
  else{
    printf("\n Los datos introducidos no son correctos");
  }
  system("pause"); //Espera una pausa
}

/**************************************
* NOMBRE: #Jacob#
* PRIMER APELLIDO: #Vicente#
* SEGUNDO APELLIDO: #Lopez#
* DNI: #53045991X#
* EMAIL: #jacobvl@gmail.com#
***************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "gestionvuelosmes.h"

bool TipoGestion::HayVuelosDisponibles(TipoVectorVuelos arrayVuelos, int &diaAux, int &mesAux, int &anyoAux) {

  for (int i=0; i<=numVuelos; i++){
    if (arrayVuelos[i].fecha.anyo==anyoAux && arrayVuelos[i].fecha.dia==diaAux &&
        arrayVuelos[i].fecha.mes==mesAux && arrayVuelos[i].plazasDisponibles<arrayVuelos[i].plazasTotales){
      return (true);
    }
  }
  return (false);
}

int TipoGestion::RecalcularPrecio (int plazasTotalesAux, int plazasDisponiblesAux, int precioInicialAux){
  int porcentaje = (plazasDisponiblesAux * 100) / plazasTotalesAux;
   if (porcentaje >= 50){
      return precioInicialAux;
    }
    else if (porcentaje < 50 && porcentaje >= 30){
      return precioInicialAux * 2;
    }
    else if (porcentaje < 30 && porcentaje >= 15){
      return precioInicialAux * 3;
    }
    else{
      return precioInicialAux * 5;
    }
}

void TipoGestion::MostrarVuelosDisponibles(TipoVectorVuelos arrayVuelos, int &diaAux, int &mesAux, int &anyoAux) {

  int precioAux;
  printf("\n Vuelo  Código  Hora  Plazas  Precio\n\n");
  for (int i=0; i<=numVuelos; i++){
    precioAux = RecalcularPrecio (arrayVuelos[i].plazasTotales, arrayVuelos[i].plazasDisponibles, arrayVuelos[i].precioinicial);
    if (arrayVuelos[i].fecha.anyo==anyoAux && arrayVuelos[i].fecha.dia==diaAux && arrayVuelos[i].fecha.mes==mesAux){
      printf("   %d   %s    %s    %d    %d   \n", i+1, arrayVuelos[i].codigoVuelo, arrayVuelos[i].hora, arrayVuelos[i].plazasTotales, precioAux);
    }
  }
}

bool TipoGestion::RealizarCompra (TipoVectorVuelos arrayVuelos, int numvueloAux, int plazasAux){
  int plazasTotalesAux = arrayVuelos[numvueloAux-1].plazasTotales;
  int plazasDisponiblesAux = arrayVuelos[numvueloAux-1].plazasDisponibles;
  if ((plazasTotalesAux - plazasDisponiblesAux) >= plazasAux){
    plazasDisponiblesAux = plazasDisponiblesAux - plazasAux;
    return 1;
  }
  else{
    return 0;
  }
}

void TipoGestion::ComprarPlazas (TipoVectorVuelos arrayVuelos) { // Procedimiento para comprar una plaza en un vuelo
  int diaAux,mesAux,anyoAux,numvueloAux,plazasAux;

  printf("\n Comprar Plaza:\n\n");

  printf("     Día? ");
  scanf(" %d",&diaAux);

  printf("     Mes? ");
  scanf(" %d",&mesAux);

  printf("     Año? ");
  scanf(" %d",&anyoAux);

  if (HayVuelosDisponibles(arrayVuelos, diaAux, mesAux, anyoAux)){
    MostrarVuelosDisponibles (arrayVuelos, diaAux, mesAux, anyoAux);
    printf("\n\n Elegir Vuelo? ");
    scanf(" %d",&numvueloAux);
    printf("\n Número de Plazas (máximo 5)? ");
    scanf(" %d",&plazasAux);
    if (RealizarCompra (arrayVuelos, numvueloAux, plazasAux)){
      printf("Compra realizada");
    }
    else{
      printf("Lo sentimos. No hay suficientes plazas en el avión");
    }
  }
  else{
    printf("Lo siento, no hay plazas disponibles para ese día");
  }
  system("pause"); //Espera una pausa
}


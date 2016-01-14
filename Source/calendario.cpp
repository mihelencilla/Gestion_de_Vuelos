#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "calendario.h"


int TipoCalendario::CalcularDias(int mes){ //calcula los dias que tiene el mes pasado por parámetro
  switch(mes){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    return 31;
    break;
    case 4:
    case 6:
    case 9:
    case 11:
    return 30;
    break;
    default:
    return 28;
  }
}

TipoDia TipoCalendario::CalcularDiaSemana (int mes, int anyo) { // El calendario español empieza en lunes
  int a, y ,m;
  int aux;
  TipoDia dia;

  a = (14 - mes) / 12;
  y = anyo - a;
  m = mes + 12 * a - 2;

  aux = (1 + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

  if (aux == 0) {
    aux = 6;
    } else {
      aux--;
    }
  dia = TipoDia (aux);
  return dia;
}

TipoSemanas TipoCalendario::CalcularNumSemanas (int dias, int primero) {
  TipoSemanas semanas;
  int cociente, modulo;

  cociente = (dias + primero) / 7;
  modulo = (dias + primero) % 7;

  if (modulo == 0) {
    semanas.semanas = cociente;
  } else {
    semanas.semanas = cociente + 1;
  }
  semanas.resto = (semanas.semanas * 7 - (dias + primero) );    /* dias que faltan para completar la última semana */
  return semanas;
}

void TipoCalendario::ImprimirSeparador (int &columna, int &fila, int semanas) {
  if ( columna == 7 ) {
    if ( fila < semanas) {       /* La última fila no lleva salto de línea */
      printf( "\n" );
    };
    columna = 1;
    fila++;
  } else if ( columna == 5 ) {
    printf( " | " );
    columna++;
  } else {
    printf( "  " );
    columna++;
  };
}

void TipoCalendario::VisualizarCalendarioVuelosMes(TipoVectorVuelos arrayVuelos, int mes, int anyo, TipoDia diaSemana){
  int diaInicial;
  int diaFinal;
  TipoSemanas numSemanas;
  int numEspacios;
  int fila,columna, ind;
  bool hayVuelo = false;
  diaFinal = CalcularDias (mes);
  if (anyo == 2016 && mes == 2){
    diaFinal = diaFinal+1;
  }
  switch (mes){
    case 1:
    printf("ENERO                  ");
    break;
    case 2:
    printf("FEBRERO                ");
    break;
    case 3:
    printf("MARZO                  ");
    break;
    case 4:
    printf("ABRIL                  ");
    break;
    case 5:
    printf("MAYO                   ");
    break;
    case 6:
    printf("JUNIO                  ");
    break;
    case 7:
    printf("JULIO                  ");
    break;
    case 8:
    printf("AGOSTO                 ");
    break;
    case 9:
    printf("SEPTIEMBRE             ");
    break;
    case 10:
    printf("OCTUBRE                ");
    break;
    case 11:
    printf("NOVIEMBRE              ");
    break;
    case 12:
    printf("DICIEMBRE              ");
    break;
  }
  printf("%d",anyo);
  printf("\n");
  printf("===========================\n");
  printf("LU  MA  MI  JU  VI | SA  DO\n");
  printf("===========================\n");

  numEspacios = 0;
  columna = 1;
  fila = 1;
  numSemanas = CalcularNumSemanas(diaFinal, int(diaSemana));

  while (fila <= numSemanas.semanas) {          /* Cada fila es una semana */
      if ( fila == 1 ) {
        for (int i=1; i <= diaSemana; i++) {       /* Primera fila: puntos iniciales*/
          printf( " ." );
          ImprimirSeparador (columna,fila,numSemanas.semanas);
        }
      }
      for ( int i = 1; i <= diaFinal; i++ ) {               /* Días del mes */
        for (int j = 0; j < numVuelos; j++) {
          if ((arrayVuelos[j].fecha.anyo == anyo)
              && (arrayVuelos[j].fecha.mes == mes)
              && (arrayVuelos[j].fecha.dia == i)) {
            ind = j;
            hayVuelo = true;
          }
        }
        if (hayVuelo) {
          printf("%2d", i);           // Si hay vuelo imprime el día y si no hay vuelo imprime --
        } else {
          printf("--");
        }
        hayVuelo = false;
        ImprimirSeparador (columna,fila,numSemanas.semanas);
      }
      if (fila == numSemanas.semanas) {
        for ( int i = 1; i <= numSemanas.resto; i++ ) {     // última fila
          printf (" .");
          ImprimirSeparador (columna, fila, numSemanas.semanas );
        }
      }
    }
    printf("\n");
}

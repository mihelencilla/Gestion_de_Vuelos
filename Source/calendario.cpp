#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "calendario.h"


int CalcularBisiestos(int &mes, int &anyo){
  int numBisiestos;
  numBisiestos=0;
  for (int i=1601;i<anyo;i++){
    if ((i%4==0)&&(i%100!=0)){
      numBisiestos ++;
    }else{
      if (i%400==0){
        numBisiestos++;
      }
    }
  }
  if ((anyo%4==0)&&(anyo%100!=0)){	//cálculo de bisiesto para el año y mes pasados por parámetro
    if(mes>2){
      numBisiestos++;
    }
  }else{
    if ((anyo%400==0)&&(mes>2)){
      numBisiestos++;
    }
  }
return numBisiestos;
}
int CalcularDias(int &mes){ //calcula el incremento de dias
  switch(mes){
    case 1:
    case 10:
    return 0;
    break;
    case 2:
    case 3:
    case 11:
    return 3;
    break;
    case 4:
    case 7:
    return 6;
    break;
    case 5:
    return 1;
    break;
    case 6:
    return 4;
    break;
    case 8:
    return 2;
    break;
    default:
    return 5;
  }
}
void ImprimirCalendario(int &mes, int &anyo, TipoDia diaSemana){
  int indiceFila;
  int indiceMes;
  int diaInicial;
  int diaFinal;
  printf("\n");
  switch (mes){
    case 1:
    printf("ENERO                  ");
    diaFinal=31;
    break;
    case 2:
    printf("FEBRERO                ");
    if ((anyo%4==0)&&(anyo%100!=0)){
      diaFinal=29;
    }else{
      if (anyo%400==0){
        diaFinal=29;
      }else{
        diaFinal=28;
      }
    }
    break;
    case 3:
    printf("MARZO                  ");
    diaFinal=31;
    break;
    case 4:
    printf("ABRIL                  ");
    diaFinal=30;
    break;
    case 5:
    printf("MAYO                   ");
    diaFinal=31;
    break;
    case 6:
    printf("JUNIO                  ");
    diaFinal=30;
    break;
    case 7:
    printf("JULIO                  ");
    diaFinal=31;
    break;
    case 8:
    printf("AGOSTO                 ");
    diaFinal=31;
    break;
    case 9:
    printf("SEPTIEMBRE             ");
    diaFinal=30;
    break;
    case 10:
    printf("OCTUBRE                ");
    diaFinal=31;
    break;
    case 11:
    printf("NOVIEMBRE              ");
    diaFinal=30;
    break;
    case 12:
    printf("DICIEMBRE              ");
    diaFinal=31;
    break;
  }
  printf("%d",anyo);
  printf("\n");
  printf("===========================\n");
  printf("LU  MA  MI  JU  VI | SA  DO\n");
  printf("===========================\n");

  switch (diaSemana){	//Imprime un calendario distinto en funcion del dia de la semana en la que empieza el mes
    case Lunes:
    diaInicial=1;
    printf(" 1   2   3   4   5 |  6   7\n");
    printf(" 8   9  10  11  12 | 13  14\n");
    printf("15  16  17  18  19 | 20  21\n");
    if (diaFinal==28){
      printf("22  23  24  25  26 | 27  28\n");
    }else if (diaFinal==29){
      printf("22  23  24  25  26 | 27  28\n");
      printf("29   .   .   .   . |  .   .\n");
    }else if (diaFinal==30){
      printf("22  23  24  25  26 | 27  28\n");
      printf("29  30   .   .   . |  .   .\n");
    }else{
      printf("22  23  24  25  26 | 27  28\n");
      printf("29  30  31   .   . |  .   .\n");
    }
    break;
    case Martes:
    diaInicial=2;
    printf(" .   1   2   3   4 |  5   6\n");
    printf(" 7   8   9  10  11 | 12  13\n");
    printf("14  15  16  17  18 | 19  20\n");
    printf("21  22  23  24  25 | 26  27\n");
    if (diaFinal==28){
      printf("28   .   .   .   . |  .   .\n");
    }else if (diaFinal==29){
      printf("28  29   .   .   . |  .   .\n");
    }else if (diaFinal==30){
      printf("28  29  30   .   . |  .   .\n");
    }else{
      printf("28  29  30  31   . |  .   .\n");
    }
    break;
    case Miercoles:
    diaInicial=3;
    printf(" .   .   1   2   3 |  4   5\n");
    printf(" 6   7   8   9  10 | 11  12\n");
    printf("13  14  15  16  17 | 18  19\n");
    printf("20  21  22  23  24 | 25  26\n");
    if (diaFinal==28){
      printf("27  28   .   .   . |  .   .\n");
    }else if (diaFinal==29){
      printf("27  28  29   .   . |  .   .\n");
    }else if (diaFinal==30){
      printf("27  28  29  30   . |  .   .\n");
    }else{
      printf("27  28  29  30  31 |  .   .\n");
    }
    break;
    case Jueves:
    diaInicial=4;
    printf(" .   .   .   1   2 |  3   4\n");
    printf(" 5   6   7   8   9 | 10  11\n");
    printf("12  13  14  15  16 | 17  18\n");
    printf("19  20  21  22  23 | 24  25\n");
    if (diaFinal==28){
      printf("26  27  28   .   . |  .   .\n");
    }else if (diaFinal==29){
      printf("26  27  28  29   . |  .   .\n");
    }else if (diaFinal==30){
      printf("26  27  28  29  30 |  .   .\n");
    }else{
      printf("26  27  28  29  30 | 31   .\n");
    }
    break;
    case Viernes:
    diaInicial=5;
    printf(" .   .   .   .   1 |  2   3\n");
    printf(" 4   5   6   7   8 |  9  10\n");
    printf("11  12  13  14  15 | 16  17\n");
    printf("18  19  20  21  22 | 23  24\n");
    if (diaFinal==28){
      printf("25  26  27  28   . |  .   .\n");
    }else if (diaFinal==29){
      printf("25  26  27  28  29 |  .   .\n");
    }else if (diaFinal==30){
      printf("25  26  27  28  29 | 30   .\n");
    }else{
      printf("25  26  27  28  29 | 30  31\n");
    }
    break;
    case Sabado:
    diaInicial=6;
    printf(" .   .   .   .   . |  1   2\n");
    printf(" 3   4   5   6   7 |  8   9\n");
    printf("10  11  12  13  14 | 15  16\n");
    printf("17  18  19  20  21 | 22  23\n");
    if (diaFinal==28){
      printf("24  25  26  27  28 |  .   .\n");
    }else if (diaFinal==29){
      printf("24  25  26  27  28 | 29   .\n");
    }else if (diaFinal==30){
      printf("24  25  26  27  28 | 29  30\n");
    }else{
      printf("24  25  26  27  28 | 29  30\n");
      printf("31   .   .   .   . |  .   .\n");
    }
    break;
    case Domingo:
    diaInicial=7;
    printf(" .   .   .   .   . |  .   1\n");
    printf(" 2   3   4   5   6 |  7   8\n");
    printf(" 9  10  11  12  13 | 14  15\n");
    printf("16  17  18  19  20 | 21  22\n");
    if (diaFinal==28){
      printf("23  24  25  26  27 | 28   .\n");
    }else if (diaFinal==29){
      printf("23  24  25  26  27 | 28  29\n");
    }else if (diaFinal==30){
      printf("23  24  25  26  27 | 28  29\n");
      printf("30   .   .   .   . |  .   .\n");
    }else{
      printf("23  24  25  26  27 | 28  29\n");
      printf("30  31   .   .   . |  .   .\n");
    }
    break;
  }
}

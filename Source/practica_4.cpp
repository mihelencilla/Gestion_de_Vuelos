/**************************************
* NOMBRE: #Jacob#
* PRIMER APELLIDO: #Vicente#
* SEGUNDO APELLIDO: #Lopez#
* DNI: #53045991X#
* EMAIL: #jacobvl@gmail.com#
***************************************/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "vuelos.h"


int main() {

  char opcion;
  TipoVectorVuelos arrayVuelos;
  TipoGestion vuelosMes;

  do {

    vuelosMes.AltaNuevoVuelo(arrayVuelos);

    system("cls"); //Limpiar pantalla

    setlocale(LC_CTYPE, "Spanish");
    system("COLOR F1");

    printf("\n Gestion de Vuelos:\n\n"                    );
    system("COLOR F0");
    printf("       Alta Nuevo Vuelo          (pulsar A)\n");
    printf("       Ofertas del Mes           (pulsar O)\n");
    printf("       Comprar Plazas            (pulsar C)\n");
    printf("       Vuelos de Mes             (pulsar V)\n");
    printf("       Salir                     (pulsar S)\n\n");
    printf(" Teclear una opci�n v�lida (A|O|C|V|S)? ");


    scanf(" %c",&opcion);

    switch (opcion) {

    case 'A':
    case 'a':

      system("cls");
      //vuelosMes.AltaNuevoVuelo();
      break;

    case 'O':
    case 'o':

      system("cls");
      //OfertasDelMes();
      break;

    case 'C':
    case 'c':

      system("cls");
      //ComprarPlazas();
      break;

    case 'V':
    case 'v':

      system("cls");
      //VuelosDelMes();
      break;

    case 'S':
    case 's':

      break;

    default:

      printf("Seleccione una opcion valida,por favor\n");
      system("pause"); //Espera una pausa

    }


  } while (opcion!='S'&&opcion!='s');

}

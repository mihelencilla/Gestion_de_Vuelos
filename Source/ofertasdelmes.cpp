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

void TipoGestion::OfertasMes (TipoVectorVuelos arrayVuelos) {

int precioAux;
  int mesAux, anyoAux, contador;

  printf("\n Mes? ");
  scanf("%d",&mesAux);
  printf("\n A�o? ");
  scanf("%d",&anyoAux);

  if (numVuelos!=0) {

    printf("\n Ofertas del mes\n\n");
    printf("\n Vuelo   C�digo     D�a     Hora    Precio\n\n");
    contador = 0;

    for (int i=0; i<numVuelos; i++) {
      if (arrayVuelos[i].fecha.mes == mesAux && arrayVuelos[i].fecha.anyo == anyoAux){
        precioAux = RecalcularPrecio (arrayVuelos[i].plazasTotales, arrayVuelos[i].plazasDisponibles, arrayVuelos[i].precioinicial);
        printf("   %d   %s      %d       %02d:%02d       %d\n", i+1, arrayVuelos[i].codigoVuelo, arrayVuelos[i].fecha.dia, arrayVuelos[i].hora.horas, arrayVuelos[i].hora.minutos, precioAux);
        contador++;
      }
    }
    if (contador == 0){
      printf ("\n No hay ning�n vuelo este mes");
    }
  }
  else{
    printf ("\n No hay vuelos disponibles");
  }
  system("pause"); //Espera una pausa


}


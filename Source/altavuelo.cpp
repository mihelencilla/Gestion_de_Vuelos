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

void TipoGestion::InicializarVuelo (TipoVuelo &vuelo) { // Procedimiento para inicializar un vuelo
  strcpy(vuelo.codigoVuelo, "" );
  strcpy(vuelo.hora, "" );
  vuelo.dia = 0;
  vuelo.mes = 0;
  vuelo.anyo = 0;
  vuelo.plazasTotales = 0;
  vuelo.plazasCompradas = 0;
  vuelo.precioinicial = 0;
}

void TipoGestion::InicializarArrayVuelos(TipoVectorVuelos arrayVuelos) { // Procedimiento para inicializar el array de vuelos
  TipoVuelo vuelo;
  InicializarVuelo (vuelo);
  for (int i = 0; i < maxVuelos; i++) {
    arrayVuelos[i] = vuelo;
  }
}

bool TipoGestion::VueloExiste(TipoVectorVuelos arrayVuelos, TipoCodigo &codigo) { // Procedimiento para comprobar si el código de un vuelo ya está en el array
  for (int i = 0; i < maxVuelos; i++) {
    if (arrayVuelos[i].codigoVuelo == codigo){
      return(true);
    }
  }
  return (false);
}

bool TipoGestion::ComprobarNumVuelos() { // Procedimiento para comprobar si se ha llegado al máximo de vuelos permitidos en total
  if (numVuelos == maxVuelos){
      return(false);
    }
  return (true);
}

//bool TipoGestion::ComprobarDatos(TipoVuelo vueloAux) { // Procedimiento para comprobar si los datos introducidos son correctos
//  if (vueloAux.CodigoVuelo == ""){
//    printf ("el código introducido no es correcto");
//    return (true);
//  }
//  if (vueloAux.anyo < minAnyo || vueloAux.anyo > maxAnyo){
//    printf ("el año introducido no es correcto");
//    return (true);
//  }
//  return (false);
//}
void TipoGestion::AltaNuevoVuelo(TipoVectorVuelos arrayVuelos) {

  TipoVuelo vueloAux;

  if (ComprobarNumVuelos()){

      system("cls");
      printf("\n Nuevo Vuelo:\n\n");

      printf("       Código de vuelo? ");
      scanf(" %s",vueloAux.codigoVuelo);
      printf("       Día? ");
      scanf(" %d",&vueloAux.dia);
      printf("       Mes? ");
      scanf(" %d",&vueloAux.mes);
      printf("       Año? ");
      scanf(" %d",&vueloAux.anyo);
      printf("       Hora? ");
      scanf(" %s",vueloAux.hora);
      printf("       Plazas del Vuelo? ");
      scanf(" %d",&vueloAux.plazasTotales);
      printf("       Precio Inicial? ");
      scanf(" %d",&vueloAux.precioinicial);

    if (VueloExiste(arrayVuelos, vueloAux.codigoVuelo)){ // comprobamos si el código de vuelo ya existe en el array
      printf("El vuelo ya existe");
    }
    else{
      IntroducirDatos (arrayVuelos, vueloAux);
    }
  }
  else{
    printf("No se pueden dar de alta más vuelos");
  }
  system("pause");
}

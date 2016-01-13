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

int numVuelos = 0;

void TipoGestion::InicializarVuelo (TipoVuelo & vuelo) { // Procedimiento para inicializar un vuelo
  strcpy(vuelo.codigoVuelo, "" );
  vuelo.fecha.dia = 0;
  vuelo.fecha.mes = 0;
  vuelo.fecha.anyo = 0;
  vuelo.hora.horas = 0;
  vuelo.hora.minutos = 0;
  vuelo.plazasTotales = 0;
  vuelo.plazasDisponibles = 0;
  vuelo.precioinicial = 0;
}

void TipoGestion::InicializarArrayVuelos(TipoVectorVuelos & arrayVuelos) { // Procedimiento para inicializar el array de vuelos
  TipoVuelo vuelo;
  InicializarVuelo (vuelo);
  for (int i = 0; i < maxVuelos; i++) {
    arrayVuelos[i] = vuelo;
  }
}

bool TipoGestion::VueloExiste(TipoVectorVuelos arrayVuelos, TipoCodigo codigo) { // Procedimiento para comprobar si el código de un vuelo ya está en el array
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

void TipoGestion::AltaNuevoVuelo(TipoVectorVuelos & arrayVuelos) {

  TipoVuelo vueloAux;
  int error = 0;

  if (ComprobarNumVuelos()){  // comprueba si se ha llegado al número máximo de vuelos permitidos
    do{
      try {
        system("cls");
        InicializarVuelo (vueloAux);
        printf("\n Nuevo Vuelo:\n\n");
        fflush (stdin);
        printf("       Código de vuelo? ");
        fflush (stdin);
        scanf("%s",vueloAux.codigoVuelo);
        printf("       Día? ");
        fflush (stdin);
        scanf("%d",&vueloAux.fecha.dia);
        printf("       Mes? ");
        fflush (stdin);
        scanf("%d",&vueloAux.fecha.mes);
        printf("       Año? ");
        fflush (stdin);
        scanf("%d",&vueloAux.fecha.anyo);
        printf("       Hora? ");
        fflush (stdin);
        scanf("%02d:%02d",&vueloAux.hora.horas, &vueloAux.hora.minutos);
        printf("       Plazas del Vuelo? ");
        fflush (stdin);
        scanf("%d",&vueloAux.plazasTotales);
        printf("       Precio Inicial? ");
        fflush (stdin);
        scanf("%d",&vueloAux.precioinicial);
        if ((vueloAux.fecha.dia < 1) || (vueloAux.fecha.dia > 31)
          || (vueloAux.fecha.mes < 1) || (vueloAux.fecha.mes > 12)
          || (vueloAux.fecha.anyo < minAnyo) || (vueloAux.fecha.anyo > maxAnyo)
          || (vueloAux.codigoVuelo == "") || (vueloAux.plazasTotales < 1) || (vueloAux.precioinicial<1)
          || ((vueloAux.fecha.dia > 29) && (vueloAux.fecha.mes == 2)) || ((vueloAux.fecha.dia > 30) && (vueloAux.fecha.mes == 4))
          || ((vueloAux.fecha.dia > 30) && (vueloAux.fecha.mes == 6)) || ((vueloAux.fecha.dia > 30) && (vueloAux.fecha.mes == 9))
          || ((vueloAux.fecha.dia > 30) && (vueloAux.fecha.mes == 11)) || (vueloAux.hora.horas<0) || (vueloAux.hora.horas>23)
          || (vueloAux.hora.minutos<0) || (vueloAux.hora.minutos>59)) {       // Comprueba si los datos introducidos son correctos
        throw 1;
        }
        if (VueloExiste(arrayVuelos, vueloAux.codigoVuelo)){ // comprobamos si el código de vuelo ya existe en el array
          throw 2;
        }
     }
     catch (int error){
       printf ("-ERROR!!!-");
       if (error == 1) {
        printf ("Introduzca valores correctos\n");
        }
       if (error == 2){
         printf("El vuelo ya existe");
       }
     }
    }
    while (error != 0);
    vueloAux.plazasDisponibles = vueloAux.plazasTotales;
    arrayVuelos[numVuelos] = vueloAux; // insertamos el vuelo en el último hueco libre del array
    system("pause"); //Espera una pausa
    OrdenarArrayVuelos (arrayVuelos, numVuelos);
    numVuelos++;
     }
  else{
    printf("No se pueden dar de alta más vuelos");
  }
}

void TipoGestion::OrdenarArrayVuelos (TipoVectorVuelos & arrayVuelos, int auxIndice) {
  TipoVuelo auxVuelo;
  int aux = auxIndice-1;
  while ((auxIndice>0) && (EsPosterior(arrayVuelos[aux],arrayVuelos[auxIndice]))) {
    auxVuelo = arrayVuelos[aux];
    arrayVuelos[aux] = arrayVuelos[auxIndice];
    arrayVuelos[auxIndice] = auxVuelo;
    auxIndice --;
    aux --;
  }
}


bool TipoGestion::EsPosterior(TipoVuelo v1, TipoVuelo v2) { // Devuelve true si el vuelo 1 tiene fecha posterior al vuelo 2
  if (v1.fecha.anyo != v2.fecha.anyo) {
    return (v1.fecha.anyo > v2.fecha.anyo);
  }
  else if (v1.fecha.mes != v2.fecha.mes) {
      return (v1.fecha.mes > v2.fecha.mes);
    }
    else if (v1.fecha.dia != v2.fecha.dia) {
        return (v1.fecha.dia > v2.fecha.dia);
      }
      else if (v1.hora.horas != v2.hora.horas){
        return (v1.hora.horas > v2.hora.horas);
      }
      else if (v1.hora.minutos != v2.hora.minutos){
        return (v1.hora.minutos > v2.hora.minutos);
      }
      else{
         return (v1.precioinicial > v2.precioinicial); // si los dos vuelos son iguales ordena por el precio
      }
}


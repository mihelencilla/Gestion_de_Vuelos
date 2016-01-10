/**************************************
* NOMBRE: #Jacob#
* PRIMER APELLIDO: #Vicente#
* SEGUNDO APELLIDO: #Lopez#
* DNI: #53045991X#
* EMAIL: #jacobvl@gmail.com#
***************************************/
#pragma once

const int maxVuelos = 1200;
const int maxVuelosMes = 50;
const int minAnyo = 2016;
const int maxAnyo = 2017;

extern int numVuelos;

typedef char TipoCodigo[6];
typedef char TipoHora[5];

typedef struct TipoVuelo {
    TipoCodigo codigoVuelo;
    TipoHora hora;
    int dia;
    int mes;
    int anyo;
    int plazasTotales;
    int plazasCompradas;
    int precioinicial;
  };

typedef TipoVuelo TipoVectorVuelos[maxVuelos];

typedef struct TipoGestion{

  void InicializarArrayVuelos (TipoVectorVuelos arrayVuelos);
  void InicializarVuelo (TipoVuelo &vuelo);
  void AltaNuevoVuelo(TipoVectorVuelos arrayVuelos);
  void OfertasMes(TipoVectorVuelos arrayVuelos);

  private:
    bool ComprobarNumVuelos();
    bool VueloExiste(TipoVectorVuelos arrayVuelos, TipoCodigo &codigo);
    //bool ComprobarDatos(TipoVuelo vueloAux);
 };


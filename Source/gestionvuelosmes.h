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

typedef char TipoCodigo[7];
typedef struct TipoHora{
  int horas;
  int minutos;
  };

typedef struct TipoFecha{
    int dia;
    int mes;
    int anyo;
};

typedef struct TipoVuelo {
    TipoCodigo codigoVuelo;
    TipoHora hora;
    TipoFecha fecha;
    int plazasTotales;
    int plazasDisponibles;
    int precioinicial;
  };

typedef TipoVuelo TipoVectorVuelos[maxVuelos];

typedef struct TipoGestion{

  void InicializarArrayVuelos (TipoVectorVuelos & arrayVuelos);
  void InicializarVuelo (TipoVuelo & vuelo);
  void AltaNuevoVuelo(TipoVectorVuelos & arrayVuelos);
  void OfertasMes(TipoVectorVuelos arrayVuelos);
  void ComprarPlazas (TipoVectorVuelos & arrayVuelos);
  void OrdenarArrayVuelos (TipoVectorVuelos & arrayVuelos, int numero);
  void VisualizarVuelosDelMes (TipoVectorVuelos arrayVuelos);

  private:
    bool ComprobarNumVuelos();
    bool VueloExiste(TipoVectorVuelos arrayVuelos, TipoCodigo codigo);
    bool RealizarCompra (TipoVectorVuelos & arrayVuelos, int vueloAux, int plazasAux);
    bool HayVuelosDisponibles(TipoVectorVuelos arrayVuelos, int diaAux, int mesAux, int anyoAux);
    void MostrarVuelosDisponibles(TipoVectorVuelos arrayVuelos, int diaAux, int mesAux, int anyoAux);
    void MostrarOfertasDisponibles(TipoVectorVuelos arrayVuelos);
    bool EsPosterior(TipoVuelo v1, TipoVuelo v2);
    int RecalcularPrecio (int plazasTotalesAux, int plazasDisponiblesAux, int precioInicialAux);
 };


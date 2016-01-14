#pragma once

#include "gestionvuelosmes.h"

typedef enum TipoDia{
  Lunes,Martes,Miercoles,Jueves,Viernes,Sabado,Domingo
};
typedef struct TipoSemanas {
  int semanas;
  int resto;
};
typedef struct TipoCalendario {
  void VisualizarCalendarioVuelosMes(TipoVectorVuelos arrayVuelos, int mesAux, int anyoAux, TipoDia diaSemana);
  int CalcularDias(int mes);
  TipoDia CalcularDiaSemana (int mes, int anyo);

  private:
    void ImprimirSeparador (int &columna, int &fila, int semanas);
    TipoSemanas CalcularNumSemanas (int dias, int primero);
};

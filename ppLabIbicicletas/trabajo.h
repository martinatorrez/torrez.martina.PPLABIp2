#include "fechas.h"
#include "servicio.h"
#include "bicicleta.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

void inicializarTrabajos(eTrabajo lista[],int tam);
int buscarTrabajo(eTrabajo lista[], int tam,int idBicicleta);
int buscarLibreTrabajo(eTrabajo lista[], int tam);
int altaTrabajo(eTrabajo listaTrabajo[], int tamtr, eServicio servicios[], int tams, eBicicletas bicicletas[], eTipo tipos[], int tamt, eColor colores[], int tamc,  int tamb, int idBicicleta, eCliente clientes[], int tamcl, int* nextID);
void mostrarTrabajo(eTrabajo trabajo, int tamtr, eServicio servicio, int tams, eBicicletas bicicleta, int tamb);
void mostrarTrabajos(eTrabajo trabajos[], int tamtr, eServicio servicios[], int tams, eBicicletas listaBicicletas[], int tamb);

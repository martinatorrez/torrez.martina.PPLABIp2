#include "tipo.h"
#include "color.h"
#include "cliente.h"
#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
typedef struct
{
 int id;
 char marca[20];
 int idTipo;
 int idColor;
 int rodado;
 int isEmpty;
 int idCliente;
} eBicicletas;

#endif // BICICLETA_H_INCLUDED
int menuBicicleta();
void inicializarBicicletas(eBicicletas lista[],int tam);
int buscarLibre(eBicicletas lista[], int tam);
int altaBicicleta(eBicicletas lista[],int tam, eTipo tipos[], int tamt, eColor color[],int tamc, eCliente clientes[], int tamcl,  int* pIdBicicleta);
void mostrarStructBicicletas(eBicicletas bicicleta, int tamb, eTipo tipos[], int tamt, eColor color[], int tamc, eCliente clientes[], int tamcl);
int mostrarBicicletas(eBicicletas lista[], int tamb, eTipo tipos[], int tamt, eColor colores[], int tamc,eCliente clientes[], int tamcl);
int modificarBicicleta(eBicicletas lista[], int tam, int idBicicleta, eTipo tipos[],int tamt, eColor colores[], int tamc,eCliente clientes[], int tamcl);
int buscarBicicleta(eBicicletas lista[], int tam, int idBicicleta);
int bajaBicicleta(eBicicletas lista[], int tamb, eTipo tipos[], int tamt, eColor colores[], int tamc,eCliente clientes[], int tamcl);
void ordenarBicicletas(eBicicletas lista[], int tam);

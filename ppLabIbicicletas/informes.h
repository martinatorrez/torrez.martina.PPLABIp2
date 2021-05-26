#include "bicicleta.h"
#include "color.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

void mostrarBicicletasColor(eBicicletas lista[], eTipo tipos[], int tamt, int tamb, eColor colores[], int tamc, eCliente clientes[], int tamcl);
char menuInformes();
void mostrarBicicletasTipo(eBicicletas lista[], int tamb, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[],int tamcl);
void bicicletasSegunTipo(eBicicletas lista[], int tamb, eTipo tipos[], int tamt,eColor colores[], int tamc, eCliente clientes[],int tamcl);
void bicicletasColorTipo(eBicicletas lista[], int tamb, eTipo tipos[], int tamt, eColor colores[], int tamc);
void trabajosBicicleta(eTrabajo trabajo[], int tamtr, eServicio servicios[],int tams, eBicicletas bicicletas[], int tamb, eColor colores[], int tamc, eTipo tipos[], int tamt, eCliente clientes[], int tamcl);
void totalTrabajoBicicleta(eTrabajo trabajo[],int tamtr, eServicio servicios[], int tams, eBicicletas bicicletas[], int tamb, eColor colores[], int tamc, eTipo tipos[], int tamt, eCliente clientes[], int tamcl);
int totalListarServiciosFecha(eTrabajo trabajos[],int tamtr, eServicio servicios[],int tams);
void bicicletaMenorRodado(eBicicletas lista[],int tamb, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[],int tamcl);
void colorMasElegido(eBicicletas lista[],int tamb, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[],int tamcl);
void servicioBicicletas(eTrabajo trabajo[],int tamtr, eServicio servicios[], int tams, eBicicletas bicicletas[], int tamb, eColor colores[], int tamc);

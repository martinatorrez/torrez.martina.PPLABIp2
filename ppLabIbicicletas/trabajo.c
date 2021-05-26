#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"

/** \brief indica que todas las posiciones en el array estan vacias, deja la bandera isEmpty en 1
 *
 * \param lista[] eTrabajo
 * \param tam int
 * \return void
 *
 */
void inicializarTrabajos(eTrabajo lista[],int tam)
{
    for(int i=0; i<tam;i++)
    {
        lista[i].isEmpty=1;
    }
}
/** \brief
 *
 * \param lista[] eTrabajo
 * \param tam int
 * \param idBicicleta int
 * \return int
 *
 */
int buscarTrabajo(eTrabajo lista[], int tam,int idBicicleta)
{   int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].idBicicleta==idBicicleta && !lista[i].isEmpty)
        {
            indice = i;
            break;
        }

    }
    return indice;
}
/** \brief busca un lugar libre en el array de trabajos
 *
 * \param lista[] eTrabajo
 * \param tam int
 * \return int
 *
 */
int buscarLibreTrabajo(eTrabajo lista[], int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief agrega un trabajo en la primera posicion vacia en el array que encuentre
 *
 * \param listaTrabajo[] eTrabajo
 * \param tamtr int
 * \param servicios[] eServicio
 * \param tams int
 * \param bicicletas[] eBicicletas
 * \param tamb int
 * \param idBicicleta int
 * \param nextID int*
 * \return int
 *
 */
int altaTrabajo(eTrabajo listaTrabajo[], int tamtr, eServicio servicios[], int tams, eBicicletas bicicletas[], eTipo tipos[], int tamt, eColor colores[], int tamc,  int tamb, int idBicicleta, eCliente clientes[], int tamcl, int* nextID)
{
    int todoOk=0;
    int indice;
    eTrabajo nuevoTrabajo;
    int idServicio;

        if(listaTrabajo!=NULL&& servicios!=NULL && bicicletas!=NULL && nextID!=NULL)
        {
                printf("Alta trabajo\n");
                indice=buscarLibreTrabajo(listaTrabajo,tamtr);
        }
        if(indice==-1)
        {
            printf("No hay lugar para trabajos\n");
        }
        else
        {
            mostrarBicicletas(bicicletas,tamb,tipos,tamt, colores,tamc, clientes, tamcl);
            printf("Ingrese el ID de la bicicleta para realizar el trabajo: ");
            scanf("%d", &idBicicleta);
            while(buscarBicicleta(bicicletas,tamb, idBicicleta)==-1)
            {
                printf("No existe esa bicicleta. Reingrese: ");
                scanf("%d", &idBicicleta);
            }
            nuevoTrabajo.idBicicleta=idBicicleta;
            mostrarServicios(servicios, tams);
            printf("Ingrese el ID del servicio a hacerle a la bicicleta: ");
            scanf("%d", &idServicio);
            while(buscarServicio(servicios,tams, idServicio)==-1)
            {
              printf("No existe ese servicio. Reingrese: ");
              scanf("%d", &idServicio);
            }
            nuevoTrabajo.idServicio= idServicio;

            printf("Ingrese la fecha en la que se hizo el servicio (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);

            nuevoTrabajo.id = *nextID;
            (*nextID)++;
            nuevoTrabajo.isEmpty=0;
            listaTrabajo[indice]=nuevoTrabajo;
            todoOk=1;

        }
        return todoOk;

}

/** \brief muestra ID, bicicletas, servicios y fechas de los trabajos
 *
 * \param trabajos[] eTrabajo
 * \param tamtr int
 * \param servicios[] eServicio
 * \param tams int
 * \param listaBicicletas[] eBicicletas
 * \param tamb int
 * \return void
 *
 */
void mostrarTrabajos(eTrabajo trabajos[], int tamtr, eServicio servicios[], int tams, eBicicletas listaBicicletas[], int tamb)
{
    int flag=1;
    printf("***Listado de trabajos***\n");
    printf("ID  Bicicleta  Servicio  Fecha\n\n");

    for(int i=0; i<tamtr; i++)
    {
        if(!trabajos[i].isEmpty)
        {
            mostrarTrabajo(trabajos[i],tamtr, servicios[i], tams, listaBicicletas[i], tamb);

            flag=0;
        }
    }
    if(flag)
    {
        printf("No hay trabajos que mostrar: ");
    }
}
/** \brief muestra el id, la bicicleta, el servicio y la fecha en la que se hizo un trabajo
 *
 * \param trabajo eTrabajo
 * \param tamtr int
 * \param servicio eServicio
 * \param tams int
 * \param bicicleta eBicicletas
 * \param tamb int
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajo, int tamtr, eServicio servicio, int tams, eBicicletas bicicleta, int tamb)
{
    printf("%d  %d  %d  %02d/%02d/%d\n", trabajo.id, trabajo.idBicicleta, trabajo.idServicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
}


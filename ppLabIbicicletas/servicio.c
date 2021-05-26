#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

/** \brief muestra el id, la descripcion y el precio de un servicio
 *
 * \param servicio eServicio
 * \return void
 *
 */
void mostrarServicio(eServicio servicio)
{
    printf("%d  %s  %.2f\n", servicio.id, servicio.descripcion, servicio.precio);
}

/** \brief muestra los id, las descripciones y los precios de todos los servicios
 *
 * \param servicios[] eServicio
 * \param tam int
 * \return void
 *
 */
void mostrarServicios(eServicio servicios[], int tam)
{
     printf("Servicios disponibles\n");
    printf("  id   Descripcion  Precio\n");
    for(int i=0;i<tam;i++)
    {
        mostrarServicio(servicios[i]);
    }
}

/** \brief busca un servicio por su ID
 *
 * \param lista[] eServicio
 * \param tam int
 * \param idServicio int
 * \return int devuelve -1 si hubo algun error
 *
 */
int buscarServicio(eServicio lista[], int tam, int idServicio)
{
    int indice=-1;
    for(int i=0; i<tam;i++)
    {
        if(lista[i].id == idServicio)
        {
           indice = i;
           break;
        }

    }
    return indice;
}


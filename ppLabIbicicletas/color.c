#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"


/** \brief muestra el ID y la descripcion de un color
 *
 * \param color eColor
 * \return void
 *
 */
void mostrarColor(eColor color)
{
    printf("%d  %10s\n", color.id, color.nombreColor);
}

/** \brief muestra los ID y las descripciones de todos los colores
 *
 * \param colores[] eColor
 * \param tam int
 * \return void
 *
 */
void mostrarColores(eColor colores[], int tam)
{
     printf("Colores de bicicleta\n");
    printf("  id   Descripcion\n");
    for(int i=0;i<tam;i++)
    {
        mostrarColor(colores[i]);
    }
}

int cargarDescripcionColor(int id, eColor colores [], int tam, char desc[])
{
    int todoOk=0;
    if(id>=5000 && id<=5004 && colores!=NULL&& tam>0 && desc!=NULL)
    {
        for(int i=0; i<tam;i++)
        {
            if(colores[i].id==id)
            {
             strcpy(desc,colores[i].nombreColor);
             todoOk=1;
             break;
            }

        }
    }
    return todoOk;
}

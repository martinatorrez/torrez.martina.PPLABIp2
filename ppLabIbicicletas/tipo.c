#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

/** \brief muestra los datos de un tipo de bibicleta
 *
 * \param tipo eTipo
 * \return void
 *
 */
void mostrarTipo(eTipo tipo)
{
    printf("%d  %10s\n", tipo.id, tipo.descripcion);
}

/** \brief muestra todos los datos de los tipos de bicicleta
 *
 * \param tipos[] eTipo
 * \param tam int
 * \return void
 *
 */
void mostrarTiposBicicleta(eTipo tipos[], int tam)
{
     printf("Tipos de bicicleta\n");
    printf("  id   Descripcion\n");
    for(int i=0;i<tam;i++)
    {
        mostrarTipo(tipos[i]);
    }
}
int cargarDescripcionTipo(int id, eTipo tipos[], int tam, char desc[])
{
    int todoOk=0;
    if(id>=1000 && id<=1003 && tipos!=NULL&& tam>0 && desc!=NULL)
    {
        for(int i=0; i<tam;i++)
        {
            if(tipos[i].id==id)
            {
             strcpy(desc,tipos[i].descripcion);
             todoOk=1;
             break;
            }

        }
    }
    return todoOk;
}

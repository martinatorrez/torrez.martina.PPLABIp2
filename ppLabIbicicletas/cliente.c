#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

int cargarDescripcionNombre(int id, eCliente nombres[], int tam, char desc[])
{
    int todoOk=0;
    if(id>=9000 && id<=9004 && nombres!=NULL&& tam>0 && desc!=NULL)
    {
        for(int i=0; i<tam;i++)
        {
            if(nombres[i].id==id)
            {
             strcpy(desc,nombres[i].nombre);
             todoOk=1;
             break;
            }

        }
    }
    return todoOk;
}

/** \brief muestra los datos de un cliente
 *
 * \param cliente eCliente
 * \return void
 *
 */
void mostrarCliente(eCliente cliente)
{
    printf("%d  %10s  %c\n", cliente.id, cliente.nombre, cliente.sexo);
}

/** \brief muestra los datos de todos los clientes
 *
 * \param clientes[] eCliente
 * \param tam int
 * \return void
 *
 */
void mostrarClientes(eCliente clientes[], int tam)
{
     printf("Clientes\n");
    printf("  Id   Nombre Sexo\n");
    for(int i=0;i<tam;i++)
    {
        mostrarCliente(clientes[i]);
    }
}

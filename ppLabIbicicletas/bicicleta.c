#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "validaciones.h"
#include "cliente.h"
int menuBicicleta()
{
    int opcion;

        system("cls");
        printf("Menu de opciones\n\n");
        printf("1. Alta bicicleta\n");
        printf("2. Modificar bicicleta\n");
        printf("3. Baja bicicleta\n");
        printf("4. Listar bicicleta\n");
        printf("5. Listar tipo\n");
        printf("6. Listar colores\n");
        printf("7. Listar servicios\n");
        printf("8. Alta trabajo\n");
        printf("9.Listar trabajos\n");
        printf("10. Informes\n");
        printf("11. Salir\n");

        printf("\nIngrese opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
        return opcion;
}

/** \brief indica que todas las posiciones en el array estan vacias, pone la bandera isEmpty como verdadera
 *
 * \param lista[] eBicicletas array de bicicletas
 * \param tam int tamaño del array
 * \return void
 *
 */
void inicializarBicicletas(eBicicletas lista[],int tam)
{
    for(int i=0; i<tam;i++)
    {
        lista[i].isEmpty=1;
    }
}

/** \brief agrega una bicicleta en la primera posiscion vacia en el array que encuentra
 *
 * \param lista[] eBicicletas
 * \param tam int
 * \param tipos[] eTipo
 * \param tamt int
 * \param color[] eColor
 * \param tamc int
 * \param pIdBicicleta int* asigna un ID a la bicicleta ingresada
 * \return int devuelve -1 si no encontro ninuga posicion vacia en el array o 1 si se dio el alta con exito
 *
 */
int altaBicicleta(eBicicletas lista[],int tam, eTipo tipos[], int tamt, eColor color[],int tamc, eCliente clientes[], int tamcl,  int* pIdBicicleta)
{
   int todoOk=0;
   eBicicletas nuevaBicicleta;
   int indice;
   int idTipo;
   int idColor;
   int rodado;
   int idCliente;
   if(lista!=NULL&& tam>0&& pIdBicicleta!=NULL)
   {
       indice=buscarLibre(lista,tam);

       if(indice==-1)
        {
            printf("No hay lugar para mas bicicletas\n");
        }
       else
        {

        printf("Ingrese marca de la bicicleta: ");
        fflush(stdin);
        gets(nuevaBicicleta.marca);

        mostrarTiposBicicleta(tipos, tamt);
        printf("Ingrese id del tipo: ");
        scanf("%d", &idTipo);
        while(validarTipo(idTipo)==0)
        {
            printf("Tipo invalido. Reingrese: ");
            scanf("%d", &idTipo);
        }

        mostrarColores(color, tamc);
        printf("Ingrese id del color: ");
        scanf("%d", &idColor);
        while(validarColor(idColor)==0)
        {
            printf("Color Invalido. Reingrese: ");
            scanf("%d", &idColor);
        }

        printf("Ingrese el rodado (puede ser 20, 26, 27.5 y 29): ");
        scanf("%d", &rodado);
        while(validarRodado(rodado)==0)
        {
            printf("ERROR. Reingrese el rodado (puede ser 20, 26, 27.5 y 29): ");
            scanf("%d", &rodado);
        }
        mostrarClientes(clientes,tamcl);
        printf("Ingrese el ID del cliente: ");
        scanf("%d", &idCliente);


        nuevaBicicleta.rodado=rodado;
        nuevaBicicleta.idTipo=idTipo;
        nuevaBicicleta.idColor=idColor;
        nuevaBicicleta.idCliente=idCliente;
        nuevaBicicleta.id= *pIdBicicleta;
        nuevaBicicleta.isEmpty=0;
        *pIdBicicleta=*pIdBicicleta+1;
        lista[indice]=nuevaBicicleta;
        todoOk=1;

    }
        }
        return todoOk;
  }

/** \brief busca una posicion vacia en el array
 *
 * \param lista[] eBicicletas
 * \param tam int
 * \return int devuelve -1 si hubo un error
 *
 */
int buscarLibre(eBicicletas lista[], int tam)
{   int indice=-1;
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

/** \brief muestra los datos de una bicicleta
 *
 * \param bicicleta eBicicletas
 * \param tam int
 * \return void
 *
 */
void mostrarStructBicicletas(eBicicletas bicicleta, int tamb, eTipo tipos[], int tamt, eColor color[], int tamc, eCliente clientes[], int tamcl)
{
    char descripcionTipo[20];
    char descripcionColor[20];
    char descripcionNombre[20];
    if(cargarDescripcionTipo(bicicleta.idTipo, tipos, tamt,descripcionTipo)&& cargarDescripcionColor(bicicleta.idColor,color, tamc,descripcionColor) && cargarDescripcionNombre(bicicleta.idCliente, clientes,tamcl,descripcionNombre))
    {
        printf("%d %s %s %s %d %s\n", bicicleta.id, bicicleta.marca, descripcionTipo, descripcionColor, bicicleta.rodado, descripcionNombre);
    }




}


/** \brief muestra el contenido del array de bicicletas
 *
 * \param lista[] eBicicletas
 * \param tam int
 * \return int
 *
 */
int mostrarBicicletas(eBicicletas lista[], int tamb, eTipo tipos[], int tamt, eColor colores[], int tamc,eCliente clientes[], int tamcl)
{
    printf("***Lista de bicicletas***\n");
    printf("ID  Marca  Tipo  Color  Rodado  NombreCliente\n\n");

    for(int i=0; i<tamb; i++)
    {
        if(!lista[i].isEmpty)
        {
            mostrarStructBicicletas(lista[i], tamb,tipos,tamt,colores,tamc, clientes,tamcl);
        }
    }

    return 0;
}

/** \brief ordena las bicicletas por tipo y por rodado de forma ascendente
 *
 * \param lista[] eBicicletas
 * \param tam int
 * \return void
 *
 */
void ordenarBicicletas(eBicicletas lista[], int tam)
{
    eBicicletas aux;

    for(int i=0; i<tam;i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(lista[i].idTipo>lista[j].idTipo||(lista[i].idTipo==lista[j].idTipo && lista[i].rodado>lista[j].rodado))
            {
                    aux=lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux;

            }
        }
    }
}
/** \brief busca una bicicleta a traves de su ID
 *
 * \param lista[] eBicicletas
 * \param tam int
 * \param idBicicleta int
 * \return int devuelve la posicion o -1 si no encontró a la bicicleta
 *
 */
int buscarBicicleta(eBicicletas lista[], int tam, int idBicicleta)
{
    int indice=-1;
    for(int i=0; i<tam;i++)
    {
        if(lista[i].id == idBicicleta)
        {
           indice = i;
           break;
        }

    }
    return indice;
}
/** \brief despues de ingresar un ID abre un submenu para que el usuario elija si quiere modificar el tipo o el rodado
 *
 * \param lista[] eBicicletas
 * \param tam int
 * \param idBicicleta int
 * \return int
 *
 */
int modificarBicicleta(eBicicletas lista[], int tam, int idBicicleta, eTipo tipos[],int tamt, eColor colores[], int tamc,eCliente clientes[], int tamcl)
{
    int indice;
    char confirma;
    int opcion;
    eBicicletas aux;
    if(lista!=NULL&& tam>0)
    {
        mostrarBicicletas(lista,tam, tipos, tamt,colores,tamc,clientes,tamcl);
        printf("Ingrese el ID de la bicicleta que quiere modificar: ");
        scanf("%d", &idBicicleta);

        indice=buscarBicicleta(lista, tam, idBicicleta);

        if(indice==-1)
        {
            printf("No existe esta bicicleta\n");
        }
        else
        {

            system("pause");
            printf("Ingrese 1 si quiere modificar el tipo\n");
            printf("Ingrese 2 si quiere modificar el rodado\n");

            scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:
                mostrarTiposBicicleta(tipos,tamt);
                printf("Ingrese el id del tipo de bicicleta: ");
                scanf("%d", &aux.idTipo);
                printf("Confirma el cambio? Presione s");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma=='s')
                {
                    lista[indice].idTipo=aux.idTipo;
                }
                else
                {
                    printf("Cambio cancelado");
                }
                break;
            case 2:
                printf("Ingrese el rodado de la bicicleta(puede ser 20, 26, 27.5 y 29): ");
                scanf("%d", &aux.rodado);
                printf("Confirma el cambio? Presione s");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma=='s')
                {
                    lista[indice].rodado= aux.rodado;
                }
                else
                {
                    printf("Cambio cancelado");
                }
                break;
                }

        }
    }
    return 0;
}

/** \brief da de baja una bicicleta por ID (deja la bandera isEmpty en 1)
 *
 * \param lista[] eBicicletas
 * \param tamb int
 * \return int
 *
 */
int bajaBicicleta(eBicicletas lista[], int tamb, eTipo tipos[], int tamt, eColor colores[], int tamc,eCliente clientes[], int tamcl)
{
int todoOk=0;
    int indice;
    int idBicicleta;
    char confirma;
    if(lista!=NULL&& tamb>0)
   {
       mostrarBicicletas(lista,tamb,tipos,tamt,colores,tamc, clientes,tamcl);
       printf("Ingrese el id de la bicicleta que quiere dar de baja: ");
       scanf("%d", &idBicicleta);

       indice=buscarBicicleta(lista, tamb ,idBicicleta);

       if(indice==-1)
        {
            printf("La bicicleta no existe\n");
        }
       else
        {
             mostrarStructBicicletas(lista[indice],tamb,tipos,tamt,colores,tamc, clientes,tamcl);
             printf("Confirma baja?");
             fflush(stdin);
             scanf("%c", &confirma);
             if(confirma== 's'){
             lista[indice].isEmpty=1;
             todoOk=1;

             }
             else
            {
                printf("Baja cancelada");
            }

        }
   }
        return todoOk;
}



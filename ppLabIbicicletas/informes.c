#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "validaciones.h"
#include "fechas.h"

char menuInformes()
{
    char opcion;
    system("cls");
    printf("Elija que informe quiere ver: \n\n");
    printf("a. Mostrar bicicletas del color seleccionado por el usuario\n");
    printf("b. Mostrar bicicletas de un tipo seleccionado\n");
    printf("c. Informar la o las bicicletas de menor rodado\n");
    printf("d. Mostrar un listado de las bicicletas separadas por tipo\n");
    printf("e. Elegir un color y un tipo y contar cuantas bicicletas hay de ese color y ese tipo\n");
    printf("f.  Mostrar el o los colores mas elegidos por los clientes\n");
    printf("g. Pedir una bicicleta y mostrar todos los trabajos que se le hicieron a la misma\n");
    printf("h. Pedir una bicicleta e informar la suma de los importes de los servicios que se le hicieron a la misma\n");
    printf("i.  Pedir un servicio y mostrar las bicicletas a las que se les realizo ese servicio y la fecha\n");
    printf("j. Pedir una fecha y mostrar todos los servicios realizados en la misma\n");
    printf("k. Salir\n");


    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    return opcion;
}
void mostrarBicicletasColor(eBicicletas lista[], eTipo tipos[], int tamt, int tamb, eColor colores[], int tamc, eCliente clientes[], int tamcl)
{
    int idColor;
    int flag=0;
    system("cls");
    printf("Bicicletas de un color\n");
    mostrarColores(colores, tamc);
    printf("Elija el id de un color para mostrar las bicicletas: ");
    scanf("%d", &idColor);

    while(validarColor(idColor)==0)
    {
        printf("Color Invalido. Reingrese: ");
        scanf("%d", &idColor);
    }
    printf("***Listado de bicicletas***\n");
    printf("ID  Marca  Tipo  Color  Rodado  NombreCliente\n\n");
    for(int i=0; i<tamb; i++)
    {
        if(lista[i].isEmpty==0 && lista[i].idColor==idColor)
        {
            mostrarStructBicicletas(lista[i], tamb,tipos,tamt,colores,tamc, clientes,tamcl);
            flag=1;
        }

    }
    if(flag==0)
    {
        printf("No hay bicicletas de ese color\n");
    }
}

void mostrarBicicletasTipo(eBicicletas lista[], int tamb, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[],int tamcl)
{
    int idTipo;
    int flag=0;
    system("cls");
    printf("Bicicletas de un tipo\n");
    mostrarTiposBicicleta(tipos,tamt);
    printf("Elija el id de un tipo para mostrar las bicicletas: ");
    scanf("%d", &idTipo);

    while(validarTipo(idTipo)==0)
    {
        printf("Tipo Invalido. Reingrese: ");
        scanf("%d", &idTipo);
    }
    printf("***Listado de bicicletas***\n");
    printf("ID    Marca    Tipo    Color   Rodado    NombreCliente\n\n");
    for(int i=0; i<tamb; i++)
    {
        if(lista[i].isEmpty==0 && lista[i].idTipo==idTipo)
        {
            mostrarStructBicicletas(lista[i], tamb,tipos,tamt,colores,tamc, clientes,tamcl);
            flag=1;
        }

    }
    if(flag==0)
    {
        printf("No hay bicicletas de ese tipo\n");
    }

}


void bicicletaMenorRodado(eBicicletas lista[],int tamb, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[],int tamcl)
{
    int menor;
    system("cls");
    printf("  Bicicletas con menor rodado\n\n");
    for(int i=0; i<tamb; i++)
    {
        for(int j = i + 1; j < tamb; j++)
        {
            if(lista[j].isEmpty==0)
            {
                if(lista[j].rodado<menor)
                {
                    menor=lista[j].rodado;
                    printf("La/s bicicleta de menor rodado: %d\n", lista[j].id);
                }
            }

        }
    }


}
void bicicletasSegunTipo(eBicicletas lista[], int tamb, eTipo tipos[], int tamt,eColor colores[], int tamc, eCliente clientes[],int tamcl)
{
    system("cls");
    printf("  Listado de bicicletas por tipo\n\n");
    for(int i=0; i<tamt; i++)
    {
        printf("Tipo: %s\n\n",tipos[i].descripcion);
        printf("ID  Marca  Tipo  Color  Rodado  NombreCliente\n\n");
        for(int j=0; j<tamb; j++)
        {
            if(lista[j].isEmpty==0 && lista[j].idTipo== tipos[i].id)
            {
                mostrarStructBicicletas(lista[j], tamb, tipos, tamt, colores, tamc,clientes,tamcl);
            }
        }
    }
}

void bicicletasColorTipo(eBicicletas lista[], int tamb, eTipo tipos[], int tamt, eColor colores[], int tamc)
{
    int idColor;
    int idTipo;
    int contadorBicicletas=0;
    mostrarTiposBicicleta(tipos,tamt);
    printf("Elija el id de un tipo para mostrar las bicicletas: ");
    scanf("%d", &idTipo);

    while(validarTipo(idTipo)==0)
    {
        printf("Tipo Invalido. Reingrese: ");
        scanf("%d", &idTipo);
    }
    mostrarColores(colores, tamc);
    printf("Elija el id de un color para mostrar las bicicletas: ");
    scanf("%d", &idColor);

    while(validarColor(idColor)==0)
    {
        printf("Color Invalido. Reingrese: ");
        scanf("%d", &idColor);
    }
    for(int i=0; i<tamb; i++)
    {
        if(lista[i].isEmpty==0 && lista[i].idColor==idColor&& lista[i].idTipo==idTipo)
        {
            contadorBicicletas++;
        }
    }
    printf("Hay %d bicicletas de ese tipo y color\n", contadorBicicletas);

}
void colorMasElegido(eBicicletas lista[],int tamb, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[],int tamcl)
{
    int masElegido;
    int contadorColor=0;
    system("cls");
    printf("  Color mas elegido\n\n");
    for(int i=0; i<tamb; i++)
    {
        contadorColor++;
        for(int j = i + 1; j < tamc; j++)
        {
            if(lista[j].isEmpty==0 && lista[j].idColor==colores[i].id)
            {
                if(contadorColor>masElegido)
                {
                    masElegido=lista[j].idColor;
                    printf(" El color mas elegido es %s\n", colores[j].nombreColor);
                }
            }

        }
    }


}




void trabajosBicicleta(eTrabajo trabajo[], int tamtr, eServicio servicios[],int tams, eBicicletas bicicletas[], int tamb, eColor colores[], int tamc, eTipo tipos[], int tamt, eCliente clientes[], int tamcl)
{
    int idBicicleta;
    int flag=1;
    printf("Informe trabajos en una bicicleta");
    mostrarBicicletas(bicicletas,tamb, tipos,tamt,colores,tamc, clientes,tamcl);
    printf("Ingrese id de una bicicleta: ");
    scanf("%d", &idBicicleta);
    while(buscarBicicleta(bicicletas,tamb,idBicicleta)==-1)
    {
        printf("No existe esa bicicleta. Reingrese:");
        scanf("%d", &idBicicleta);
    }
    for(int i=0; i<tamtr; i++)
    {
        if(trabajo[i].isEmpty==0 &&  trabajo[i].idBicicleta==idBicicleta)
        {
            mostrarTrabajo(trabajo[i],tamtr,servicios[i],tams,bicicletas[i],tamb);
            flag=0;
        }
        if(flag)
        {
            printf("La bicicleta no tiene trabajos registrados");
        }
    }
    printf("\n\n");


}

void totalTrabajoBicicleta(eTrabajo trabajo[],int tamtr, eServicio servicios[], int tams, eBicicletas bicicletas[], int tamb, eColor colores[], int tamc, eTipo tipos[], int tamt, eCliente clientes[], int tamcl)
{
    int idBicicleta;
    int flag=1;
    float totalAPagar=0;
    printf("Informe trabajos en una bicicleta");
    mostrarBicicletas(bicicletas,tamb, tipos,tamt,colores,tamc, clientes,tamcl);
    printf("Ingrese id de una bicicleta: ");
    scanf("%d", &idBicicleta);
    while(buscarBicicleta(bicicletas,tamb,idBicicleta)==-1)
    {
        printf("No existe esa bicicleta. Reingrese:");
        scanf("%d", &idBicicleta);
    }
    for(int i=0; i<tamtr; i++)
    {
        if(trabajo[i].isEmpty==0 && trabajo[i].idBicicleta==idBicicleta)
        {
            for(int j=0; j<tams; j++)
            {
                if(servicios[j].id==trabajo[i].idServicio)
                {
                    totalAPagar+=servicios[j].precio;
                }
            }

            flag=0;
        }
        if(flag)
        {
            printf("La bicicleta no tiene trabajos registrados");
        }

        else
        {
            printf("El total a pagar es: %f", totalAPagar);
        }
        printf("\n\n");
    }
}
int totalListarServiciosFecha(eTrabajo trabajos[],int tamtr, eServicio servicios[],int tams)
{
    int todoOk=0;
    eFecha fechaBuscar;
    int contador;

    if(trabajos!=NULL && tamtr>0 && servicios!=NULL && tams>0)
    {
        printf("Ingrese la fecha que quiere ver los trabajos(dd/mm/aaaa): ");
        scanf("%d/%d/%d",&fechaBuscar.dia,&fechaBuscar.mes,&fechaBuscar.anio);
        printf("\n");

        for(int s=0; s<tams; s++)
        {
            contador=0;
            for(int t=0; t<tamtr; t++)
            {
                if(servicios[s].id==trabajos[t].idServicio&&trabajos[t].isEmpty==0&&comparaFechas(fechaBuscar,trabajos[t].fecha))
                {
                    contador++;
                }
            }
            printf("En la fecha ingresada se registraron: %d  %s\n",contador,servicios[s].descripcion);
        }
        printf("\n");
        todoOk=1;
    }
    return todoOk;
}

void servicioBicicletas(eTrabajo trabajo[],int tamtr, eServicio servicios[], int tams, eBicicletas bicicletas[], int tamb, eColor colores[], int tamc)
{
    int idServicio;
    int flag=0;
    mostrarServicios(servicios,tams);
    printf("Ingrese el ID del servicio que quiere ver: ");
    scanf("%d", &idServicio);
    printf("***Listado de trabajos***\n");
    printf("ID  Bicicleta  Servicio  Fecha\n\n");
     for(int i=0; i<tamb; i++)
    {
        if(trabajo[i].isEmpty==0&& trabajo[i].idServicio==idServicio)
        {
            mostrarTrabajo(trabajo[i],tamtr,servicios[i],tams,bicicletas[i],tamb);
            flag=1;
        }

    }
    if(flag==0)
    {
        printf("No hay servicios registrados\n");
    }
}



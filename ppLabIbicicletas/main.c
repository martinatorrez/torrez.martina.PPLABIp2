#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "informes.h"
#include "cliente.h"
#define TAMB 10
#define TAMT 4
#define TAMC 5
#define TAMS 4
#define TAMTR 8
#define TAMCL 5

int main()
{
    eBicicletas bicicletas[TAMB];
    int idBicicleta=3000;
    int idTrabajos=4000;
    int respuesta=1;
    eTrabajo trabajos[TAMTR];
    eTipo tipos[TAMT]=
    {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"}
    };
    eColor colores[TAMC]=
    {
        {5000, "Gris"},
        {5001, "Negro"},
        {5002, "Blanco"},
        {5003, "Azul"},
        {5004, "Rojo"}
    };
    eServicio servicios[TAMS]=
    {
        {20000, "Limpieza", 250},
        {20001, "Parche", 300},
        {20002, "Centrado", 400},
        {20003, "Cadena", 350}
    };
    eCliente clientes[TAMCL]=
     {
        {9000, "Juan", 'm'},
        {9001, "Luisa", 'f'},
        {9002, "Mauro", 'm'},
        {9003, "Laura", 'f'},
        {9004, "Ruben", 'm'}
     };
    char salir='n';
    int flag=0;
    inicializarBicicletas(bicicletas,TAMB);
    inicializarTrabajos(trabajos, TAMT);
    do
    {

        switch(menuBicicleta())
        {
        case 1:
            if(altaBicicleta(bicicletas, TAMB, tipos,TAMT,colores, TAMC, clientes, TAMCL, &idBicicleta))
            {
                printf("Bicicleta ingresada con exito\n");
                flag=1;
            }
            else
            {
                printf("Hubo un error en el alta\n");
            }

            system("pause");
            break;
        case 2:
            if(flag==0)
            {
                printf("Todavia no puede modificar nada debido a que no ingreso ninguna bicicleta\n");
            }
            else
            {
                modificarBicicleta(bicicletas, TAMB,idBicicleta, tipos,TAMT, colores, TAMC,clientes,TAMCL);
            }
            system ("pause");
            break;
        case 3:
            if(flag==0)
            {
                printf("Todavia no puede dar de baja debido a que no ingreso ninguna bicicleta\n");
            }
            else
            {
                bajaBicicleta(bicicletas,TAMB,tipos,TAMT,colores,TAMC,clientes,TAMCL);
            }
            system ("pause");
            break;
        case 4:
            if(flag==0)
            {
                printf("Todavia no puede listar las bicicletas debido a que no ingreso ninguna\n");
            }
            else
            {
                ordenarBicicletas(bicicletas,TAMB);
                mostrarBicicletas(bicicletas, TAMB,tipos,TAMT,colores,TAMC,clientes,TAMCL);
            }

            system("pause");
            break;
        case 5:

            mostrarTiposBicicleta(tipos,TAMT);

            system ("pause");
            break;
        case 6:

            mostrarColores(colores, TAMC);

            system ("pause");
            break;
        case 7:

            mostrarServicios(servicios, TAMS);

            system ("pause");
            break;
        case 8:

            altaTrabajo(trabajos,TAMTR,servicios,TAMS,bicicletas,tipos,TAMT,colores,TAMC,TAMB,idBicicleta,clientes,TAMCL, &idTrabajos);

            system ("pause");
            break;
        case 9:

            mostrarTrabajos(trabajos, TAMTR, servicios, TAMS, bicicletas, TAMB);

            system ("pause");
            break;
        case 10:
            do
            {
                switch(menuInformes())
                {
                    case 'a':
                    mostrarBicicletasColor(bicicletas,tipos,TAMT,TAMB,colores,TAMC,clientes,TAMCL);
                    system("pause");
                    break;
                    case 'b':
                    mostrarBicicletasTipo(bicicletas,TAMB,tipos, TAMT, colores, TAMC,clientes,TAMCL);
                    system("pause");
                    break;
                    case 'c':
                    bicicletaMenorRodado(bicicletas,TAMB,tipos,TAMT,colores,TAMC,clientes,TAMCL);
                     system("pause");
                    break;
                    case 'd':
                    bicicletasSegunTipo(bicicletas,TAMB, tipos,TAMT,colores,TAMC,clientes,TAMCL);
                     system("pause");
                    break;
                    case 'e':
                    bicicletasColorTipo(bicicletas,TAMB,tipos,TAMT,colores,TAMC);
                    system("pause");
                    break;
                    case 'f':
                    colorMasElegido(bicicletas,TAMB,tipos,TAMT,colores,TAMC,clientes,TAMCL);
                     system("pause");
                    break;
                    case 'g':
                    trabajosBicicleta(trabajos,TAMTR,servicios,TAMS,bicicletas,TAMB,colores,TAMC,tipos,TAMT,clientes,TAMCL);
                     system("pause");
                    break;
                    case 'h':
                    totalTrabajoBicicleta(trabajos,TAMTR,servicios,TAMS,bicicletas,TAMB,colores,TAMC,tipos,TAMT,clientes,TAMCL);
                    system("pause");
                    break;
                    case 'i':
                    servicioBicicletas(trabajos,TAMTR,servicios,TAMS,bicicletas,TAMB,colores,TAMC);
                    system("pause");
                    break;
                    case 'j':
                    totalListarServiciosFecha(trabajos,TAMTR,servicios,TAMS);
                    system("pause");
                    break;
                    case 'k':
                    printf("Seguro que desea salir? (Si no desea salir presione 1) ");
                    fflush(stdin);
                    scanf("%d",&respuesta);
                     break;
                }

            }while(respuesta==1);

            system ("pause");
        break;
        case 11:
            printf("Seguro que desea salir? (Si no desea salir presione 'n') ");
            fflush(stdin);
            scanf("%c",&salir);
            break;

        }

    }
    while(salir =='n');

    return 0;
}

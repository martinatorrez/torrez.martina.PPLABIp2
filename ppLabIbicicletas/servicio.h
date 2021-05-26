#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[25];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED
void mostrarServicio(eServicio servicio);
void mostrarServicios(eServicio servicios[], int tam);
int buscarServicio(eServicio lista[], int tam, int idServicio);


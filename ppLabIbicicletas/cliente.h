#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct{
    int id;
    char nombre[20];
    char sexo;
}eCliente;


#endif // CLIENTE_H_INCLUDED
int cargarDescripcionNombre(int id, eCliente nombres[], int tam, char desc[]);
void mostrarClientes(eCliente clientes[], int tam);
void mostrarCliente(eCliente cliente);

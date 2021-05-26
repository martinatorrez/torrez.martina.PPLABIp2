#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int validarTipo(int tipo)
{
    int tipoValido=1;
    if(tipo<1000||tipo>1004)
    {
        tipoValido=0;
    }
    return tipoValido;
}

int validarColor(int color)
{
    int colorValido=1;
    if(color<5000 || color>5005)
    {
        colorValido=0;
    }
    return colorValido;
}

int validarRodado(int rodado)
{
    int rodadoValido=1;
    if(rodado!=20 && rodado!=26 && rodado!=27.5 && rodado!=29)
    {
            rodadoValido=0;
    }
    return rodadoValido;
}

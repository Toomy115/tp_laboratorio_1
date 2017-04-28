#include <ctype.h>
#include "funciones.h"

void IniciarEstructura (EPersona personas[], int c, char cod[][6],int filas)
{
    cod [filas][6];

    for (int i=0; i<c; i++)
    {
        personas[i].estado=0;
        personas[i].edad=0;
    }
    for (int i=0; i<=filas; i++)
    {
        cod[0][i]=' ';
        cod[1][i]=' ';
        cod[2][i]=' ';
    }

}

int validarNombre (char nom[],int cant)
{
    int retorno=0;
    for (int i=0; i<cant; i++)
    {
        if (isdigit(nom[i])==1)
        {
            retorno=1;
            break;
        }
    }

    if (strlen(nom) >= 30)
    {
        printf ("El nombre no puede tener mas de 30 caracteres.\n");
        retorno=1;
    }

    return retorno;
}

int validarEdad(int edad)
{
    int aux;
    int retorno=0;
    int verdad=0;

    if (edad <= 0 || edad >110)
    {
        printf ("Edad valida 1 a 110.\n");
        verdad=1;
    }

    if (isdigit(edad)!=0 || verdad ==1)
    {
        retorno=1;
    }

    return retorno;
}

int validarDNI (int dni)
{
    int retorno=0;
    int verdad=0;
    if (dni <10000000 || dni > 100000000)
    {
        verdad=1;
    }

    if (isdigit(dni)!=0 || verdad==1)
    {
        retorno=1;
    }
    return retorno;
}

int obtenerEspacioLibre(EPersona personas[], int c)
{
    int cont=0;
    for (int i=0; i<c; i++)
    {
        if (personas[i].estado==0)
        {
            cont++;
        }
    }
    return cont;
}

int buscarPorDni(EPersona personas[], int dni, int c)
{
    int indice;
    for (int i=0; i<c; i++)
    {
        if (personas[i].dni == dni)
        {
            indice = i;
        }
        else
        {
            indice = -1;
        }
    }
    return indice;
}

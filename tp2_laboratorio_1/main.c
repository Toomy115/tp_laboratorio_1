#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


#define C 20


int main()
{
    char seguir='s',opc,codigo[3][C],auxNombre[100],buscarDeNuevo='n';
    int opcion=0,flag, flag2, cont1=0,cont2=0,cont3=0,tot=0,flag43,flag42,flag41,letras,cant=0,valpers=0, valedad=0, valdni=0,espacio,indiceBuscDNI=0,dni;
    EPersona persona[C], auxPersona;


    IniciarEstructura(persona,C,codigo,3);
    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Obtener espacio libre\n");
        printf("6- Buscar por DNI\n\n");
        printf("7- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            flag=0;

            system("cls");

            for (int i=0; i<C; i++)
            {
                if (persona[i].estado==0)
                {

                    printf("Ingrese la siguiente informacion: \n");
                    printf("Nombre: ");
                    while(getchar()!='\n');
                    fgets(auxNombre,100,stdin);
                    auxNombre[strlen(auxNombre)-1]='\0';
                    cant = strlen(auxNombre);
                    valpers = validarNombre(auxNombre,cant);

                    while (valpers==1)
                    {
                        printf("El nombre ingresado no es correcto. Reingrese: ");
                        //while(getchar()!='\n');
                        fgets(auxNombre,100,stdin);
                        auxNombre[strlen(auxNombre)-1]='\0';
                        cant = strlen(auxNombre);
                        valpers = validarNombre(auxNombre,cant);
                    }
                    strcpy(persona[i].nombre,auxNombre);

                    printf("Edad: ");
                    scanf("%d",&persona[i].edad);

                    valedad = validarEdad(persona[i].edad);
                    while(valedad==1)
                    {
                        while(getchar()!='\n');
                        printf("Error, ingrese una edad valida: ");

                        scanf("%d",&persona[i].edad);
                        valedad = validarEdad(persona[i].edad);
                    }

                    printf("DNI: ");
                    scanf("%d",&persona[i].dni);
                    valdni = validarDNI(persona[i].dni);
                    while (valdni == 1)
                    {
                        while(getchar()!='\n');
                        printf ("Ingrese un DNI valido: ");
                        scanf("%d",&persona[i].dni);
                        valdni = validarDNI(persona[i].dni);
                    }
                    persona[i].estado=1;
                    flag=1;
                    break;
                }
            }
            if (flag==0)
            {
                system("cls");
                printf("\nNo hay mas espacio para agregar otra persona!\n\n");
                system("pause");
            }

            break;

        case 2:
            flag2=0;
            int num;
            system("cls");
            printf ("Ingrese numero de dni de la persona a eliminar: ");

            printf("\n\nNombre \t Edad \t DNI");
            for (int i=0; i<C; i++)
            {

                if (persona[i].estado==1)
                {

                    printf("\n%s \t %d \t %d \n",persona[i].nombre,persona[i].edad,persona[i].dni);
                }
            }
            while(getchar()!='\n');
            scanf("%d",&num);

            for (int i=0; i<C; i++)
            {

                if (num==persona[i].dni && persona[i].estado==1)
                {
                    printf("¿Seguro que desea eliminar la siguiente persona? s/n \n Nombre: %s DNI: %d \n",persona[i].nombre,persona[i].dni);
                    scanf (" %c",&opc);
                    opc = tolower(opc);

                    if (opc=='s')
                    {
                        persona[i].estado=0;
                        flag=1;
                        printf("La persona ha sido eliminada exitosamente\n\n");
                        system("pause");
                    }
                    else
                    {
                        printf("Accion cancelada\n\n");
                        system("pause");
                    }

                    break;

                }
                else if (flag==0)
                {
                    printf("No existe el DNI especificado \n\n");
                    system("pause");
                }
            }


            break;

        case 3:
            system("cls");
            for(int i=0; i<C-1; i++)
            {
                for(int j=i+1; j<C; j++)
                {
                    if(persona[i].estado==1 && persona[j].estado==1)
                    {
                        if(strcmp(persona[i].nombre,persona[j].nombre)>0)
                        {
                            auxPersona=persona[i];
                            persona[i]=persona[j];
                            persona[j]=auxPersona;

                        }
                        else
                        {
                            if(strcmp(persona[i].nombre,persona[j].nombre)==0)
                            {
                                if(persona[i].dni>persona[j].dni)
                                {
                                    auxPersona=persona[i];

                                    persona[i]=persona[j];
                                    persona[j]=auxPersona;
                                }
                            }
                        }
                    }
                }
            }

            for (int i=0; i<C; i++)
            {
                if (persona[i].estado==1)
                {
                    printf("\nNombre: %s\t Edad: %d\t DNI: %d\n",persona[i].nombre,persona[i].edad,persona[i].dni);
                }

            }
            system("pause");


            break;

        case 4:
            flag41=0;
            flag42=0;
            flag43=0;

            for (int i=0; i<C; i++)
            {
                if (persona[i].estado==1)
                {

                    if (persona[i].edad <= 18 )
                    {
                        codigo[0][flag41]='*';
                        flag41++;
                    }
                    else if (persona[i].edad <35  )
                    {
                        codigo[1][flag42]='*';
                        flag42++;

                    }
                    else
                    {
                        codigo[2][flag43]='*';
                        flag43++;
                    }
                }
            }

            for (int i=C; i>=0; i--)
            {
                if (persona[i].estado==1)
                {
                    printf("%c \t %c \t %c\n",codigo[0][i],codigo[1][i],codigo[2][i]);
                }

            }

            printf("18< \t 19-35 \t <35\n");
            system("pause");

            break;

        case 5:
            system("cls");
            espacio = obtenerEspacioLibre(persona,C);
            printf("El espacio libre es de %d lugares.\n\n",espacio);
            system("pause");

            break;

        case 6:
            do
            {
                system("cls");
                printf("Ingrese el DNI a buscar: ");
                scanf("%d",&dni);
                indiceBuscDNI=buscarPorDni(persona,dni,C);
                if (indiceBuscDNI != -1)
                {
                    printf("El DNI %d pertenece a %s de %d anios de edad.\n\n",dni,persona[indiceBuscDNI].nombre, persona[indiceBuscDNI].edad);
                    printf(" Quiere volver a buscar? s/n");
                    while(getchar()!='\n');
                    scanf("%c",&buscarDeNuevo);
                    buscarDeNuevo = tolower(buscarDeNuevo);
                }
                else
                {
                    printf("El DNI %d no ha sido encontrado. Quiere volver a buscar? s/n",dni);
                    while(getchar()!='\n');
                    scanf("%c",&buscarDeNuevo);
                    buscarDeNuevo = tolower(buscarDeNuevo);
                }
            }
            while(buscarDeNuevo=='s');

            break;

        case 7:
            seguir = 'n';
            break;
        }
    }
    return 0;
}

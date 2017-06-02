#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0,ok;
    eMovie peliculas;

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1: system("cls");
                    ok = agregarPelicula(&peliculas);
                    if (ok == 1)
                    {
                        system("cls");
                        printf("La pelicula ha sido cargada con exito!\n");
                        system("pause");
                    }
                break;
            case 2:
                    system("cls");
                    ok = borrarPelicula(&peliculas);
                    if (ok==1)
                    {
                        system("cls");
                        printf("La pelicula se elimino con exito!\n");
                        system("pause");
                    }
                    else if (ok==0)
                    {
                        system("cls");
                        printf("No se ha encontrado coincidencia.");
                        system("pause");
                    }
                break;
            case 3: system("cls");
                    ok = modificarPeliculas(&peliculas);
                    if (ok==1)
                    {
                        system("cls");
                        printf("Se guardaron los cambios con exito.\n\n");
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        printf("No se pudo modificar.\n\n");
                        system("pause");
                    }
               break;
            case 4: generarPagina(&peliculas);
                    printf("Se a generado la pagina en la carpeta template.\n\n");
                    system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

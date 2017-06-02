#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Funciones.h"


int agregarPelicula(eMovie* pelicula)
{
    int ok;
    pelicula->estado=0;
    char numero[5];

    printf("Ingrese el titulo de la Pelicula: ");
    while(getchar()!='\n');
    fgets(pelicula->titulo,30,stdin);
    pelicula->titulo[strlen(pelicula->titulo)-1]='\0';

    while (strlen(pelicula->titulo)>30)
    {
        system("cls");
        printf("\nError, el titulo no puede contener mas de 30 caracteres. Reingrese: ");
        fgets(pelicula->titulo,30,stdin);
        pelicula->titulo[strlen(pelicula->titulo)-1]='\0';

    }
    todoAminuscula(pelicula->titulo,strlen(pelicula->titulo));

    system("cls");
    printf("Ingrese el genero de la Pelicula: ");

    fgets(pelicula->genero,15,stdin);
    pelicula->genero[strlen(pelicula->genero)-1]='\0';
    while (strlen(pelicula->genero)>15)
    {
        system("cls");
        printf("Error, el genero no puede contener mas de 15 caracteres. Reingrese: ");
        fgets(pelicula->titulo,15,stdin);
        pelicula->genero[strlen(pelicula->genero)-1]='\0';
    }

    system("cls");
    printf("Ingrese una descripcion para la pelicula \'%s\': ",pelicula->titulo);
    fgets(pelicula->descripcion,100,stdin);
    while (strlen(pelicula->titulo)>100)
    {
        system("cls");
        printf("Error, la descripcion no puede contener mas de 100 caracteres. Reingrese: ");
        fgets(pelicula->titulo,100,stdin);
    }

    system("cls");
    printf("Ingrese puntaje: ");
    gets(numero);
    while(validarQueSeaNum(numero,strlen(numero))==1)
    {
        system("cls");
        printf("El puntaje no puede contener letras. Reingrese: ");
        gets(numero);
    }
    pelicula->puntaje = atoi(numero);

    system("cls");
    printf("Ingrese duracion en minutos: ");
    gets(numero);
    while(validarQueSeaNum(numero,strlen(numero))==1)
    {
        system("cls");
        printf("La duracion no puede contener letras. Reingrese: ");
        gets(numero);
    }
    pelicula->duracion = atoi(numero);

    system("cls");
    printf("Ingrese el link de la portada de la pelicula: ");
    fgets(pelicula->linkImagen,100,stdin);
    while(strlen(pelicula->linkImagen) > 100)
    {
        system("cls");
        printf("Error, el link no puede contener mas de 100 caracteres. Reingrese: ");
        fgets(pelicula->linkImagen,100,stdin);
    }
    pelicula->estado = 1;

    ok = escribirPeliculaEnArchivo(pelicula);

    return ok;
}

int escribirPeliculaEnArchivo (eMovie* pelicula)
{
    int ok=0;
    FILE* file;
    if ((file = fopen("peliculas.dat","rb+"))== NULL)
    {
        if ((file = fopen("peliculas.dat","wb+"))!=NULL)
        {
            fwrite(pelicula,sizeof(eMovie),1,file);
            ok=1;
        }
        else
        {
            system("cls");
            printf("Sucedio un error en el guardado de los datos.\n\n");
            system("pause");
        }
    }
    else
    {
        fseek(file,sizeof(eMovie),SEEK_END);
        fwrite(pelicula,sizeof(eMovie),1,file);
        ok=1;
    }
    fclose(file);

    return ok;
}

int borrarPelicula(eMovie* pelicula)
{
    FILE* archivo;
    int ok=0;
    int cant;
    char ingreso[30],opc;
    while(getchar()!='\n');
    if((archivo=fopen("peliculas.dat","rb+"))!=NULL)
    {
        mostrarPeliculas(pelicula);
        printf("\nIngrese el nombre de la pelicula que desea eliminar: ");
        fgets(ingreso,30,stdin);
        ingreso[strlen(ingreso)-1]='\0';
        todoAminuscula(ingreso,strlen(ingreso));
        rewind(archivo);
        while(!feof(archivo))
        {
            cant=fread(pelicula,sizeof(eMovie),1,archivo);
            if (cant!=1)
            {
                if(feof(archivo))
                    break;
            }
            if (strcmp(pelicula->titulo,ingreso)==0 && pelicula->estado==1)
            {
                mayusculasCorrectas(pelicula->titulo,strlen(pelicula->titulo));
                printf("\nEsta seguro que desea eliminar la pelicula \'%s\'? s/n ",pelicula->titulo);
                gets(&opc);
                opc = tolower(opc);
                if (opc=='s')
                {
                    fseek(archivo,(-1)*sizeof(eMovie),SEEK_CUR);
                    pelicula->estado=0;
                    fwrite(pelicula,sizeof(eMovie),1,archivo);
                    ok=1;
                    break;
                }
                else
                {
                    printf("\n\nSe ha cancelado la accion.\n\n");
                    system("pause");
                    ok=2;
                }
            }

        }
    }

    if(fclose(archivo)==1)
    {
        system("cls");
        printf("Error al cerrar el archivo, no se ha realizado la operacion.\n\n");
        system("pause");
        return 0;
    }

    return ok;
    system("pause");
}

int modificarPeliculas (eMovie* pelicula)
{
    FILE* archivo;
    int cant,ok=0;
    char ingreso[30],opc,numero[5];

    mostrarPeliculas(pelicula);
    fflush(stdin);
    printf("Ingrese el nombre de la pelicula que quiere modificar: ");
    fgets(ingreso,30,stdin);
    ingreso[strlen(ingreso)-1]='\0';
    todoAminuscula(ingreso,strlen(ingreso));

    if((archivo=fopen("peliculas.dat","rb+"))!=NULL)
    {
        while(!feof(archivo))
        {
            cant=fread(pelicula,sizeof(eMovie),1,archivo);
            if (cant!=1)
            {
                if(feof(archivo))
                    break;
            }
            if(strcmp(ingreso,pelicula->titulo)==0 && pelicula->estado==1)
            {
                system("cls");
                printf("a- Titulo\n");
                printf("b- Genero\n");
                printf("c- Descripcion\n");
                printf("d- Puntaje\n");
                printf("e- Duracion\n");
                printf("f- Link de Imagen\n");

                printf("\n\nElija una opcion de modificacion: ");
                gets(&opc);
                opc=tolower(opc);
                switch(opc)
                {
                case 'a' :
                    system("cls");
                    printf("Ingrese un nuevo titulo: ");
                    fgets(pelicula->titulo,30,stdin);
                    pelicula->titulo[strlen(pelicula->titulo)-1]='\0';

                    while (strlen(pelicula->titulo)>30)
                    {
                        system("cls");
                        printf("\nError, el titulo no puede contener mas de 30 caracteres. Reingrese: ");
                        fgets(pelicula->titulo,30,stdin);
                        pelicula->titulo[strlen(pelicula->titulo)-1]='\0';
                    }
                    todoAminuscula(pelicula->titulo,strlen(pelicula->titulo));
                    ok=1;
                    break;
                case 'b':
                    system("cls");
                    printf("Ingrese el genero de la Pelicula: ");

                    fgets(pelicula->genero,15,stdin);
                    pelicula->genero[strlen(pelicula->genero)-1]='\0';
                    while (strlen(pelicula->genero)>15)
                    {
                        system("cls");
                        printf("Error, el genero no puede contener mas de 15 caracteres. Reingrese: ");
                        fgets(pelicula->titulo,15,stdin);
                        pelicula->genero[strlen(pelicula->genero)-1]='\0';
                    }
                    ok=1;
                    break;
                case 'c':
                    system("cls");
                    printf("Ingrese una descripcion para la pelicula \'%s\': ",pelicula->titulo);
                    fgets(pelicula->descripcion,100,stdin);
                    while (strlen(pelicula->titulo)>100)
                    {
                        system("cls");
                        printf("Error, la descripcion no puede contener mas de 100 caracteres. Reingrese: ");
                        fgets(pelicula->titulo,100,stdin);
                    }
                    ok=1;
                    break;
                case 'd':
                    system("cls");
                    printf("Ingrese puntaje: ");
                    gets(numero);
                    while(validarQueSeaNum(numero,strlen(numero))==1)
                    {
                        system("cls");
                        printf("El puntaje no puede contener letras. Reingrese: ");
                        gets(numero);
                    }
                    pelicula->puntaje = atoi(numero);
                    ok=1;
                    break;
                case 'e':
                    system("cls");
                    printf("Ingrese duracion en minutos: ");
                    gets(numero);
                    while(validarQueSeaNum(numero,strlen(numero))==1)
                    {
                        system("cls");
                        printf("La duracion no puede contener letras. Reingrese: ");
                        gets(numero);
                    }
                    pelicula->duracion = atoi(numero);
                    ok=1;
                    break;
                case 'f':
                    system("cls");
                    printf("Ingrese el link de la portada de la pelicula: ");
                    fgets(pelicula->linkImagen,100,stdin);
                    while(strlen(pelicula->linkImagen) > 100)
                    {
                        system("cls");
                        printf("Error, el link no puede contener mas de 100 caracteres. Reingrese: ");
                        fgets(pelicula->linkImagen,100,stdin);
                    }
                    ok=1;
                    break;

                default:
                    printf("\n\nNo existe la opcion solicitada.");
                    break;

                }
            }
            if (ok==1)
            {
                fseek(archivo,(-1)*sizeof(eMovie),SEEK_CUR);
                fwrite(pelicula,sizeof(eMovie),1,archivo);
                break;
            }
        }
    }
    if(fclose(archivo)==1)
    {
        system("cls");
        printf("Error al cerrar el archivo, no se ha realizado la operacion.\n\n");
        system("pause");
        return 0;
    }
    return ok;
}

void generarPagina (eMovie* pelicula)
{
    FILE* html;
    FILE* archivo;

    if ((archivo = fopen("peliculas.dat","rb"))!=NULL)
    {
        if ((html = fopen("./template/movieList.html","wb"))!=NULL)
        {
            fprintf(html,
                    "<!DOCTYPE html>\n"
                    "<html lang='en'>"
                    "<head>"
                    "<meta charset='utf-8'>"
                    "<meta http-equiv='X-UA-Compatible' content='IE=edge'>"
                    "<meta name='viewport' content='width=device-width, initial-scale=1'>"
                    "<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->"
                    "<title>Lista peliculas</title>"
                    "<!-- Bootstrap Core CSS -->"
                    "<link href='css/bootstrap.min.css' rel='stylesheet'>"
                    "<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->"
                    "<link href='css/custom.css' rel='stylesheet'>"
                    "<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->"
                    "<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->"
                    "<!--[if lt IE 9]>"
                    "<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>"
                    "<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>"
                    "<![endif]-->"
                    "</head>"
                    "<body>"
                    "<div class='container'>"
                    "<div class='row'>");

            while((fread(pelicula,sizeof(eMovie),1,archivo))!=0)
            {
                if(pelicula->estado==1)
                {
                    fprintf(html,"<article class='col-md-4 article-intro'>"
                            "<a href='#'>"
                            "<img class='img-responsive img-rounded' src='%s' alt=''>"
                            "</a>"
                            "<h3>"
                            "<a href='#'>%s</a>"
                            "</h3>"
                            "<ul>"
                            "<li>Género:%s</li>"
                            "<li>Puntaje:%d</li>"
                            "	<li>Duración:%d</li>",pelicula->linkImagen,pelicula->titulo,pelicula->genero,pelicula->puntaje,pelicula->duracion);
                    fprintf(html,"</ul>"
                            "<p>%s</p>"
                            "</article>",pelicula->descripcion);
                }
            }
            fprintf(html,"</div>"
                    "<!-- /.row -->"
                    "</div>"
                    "<!-- /.container -->"
                    "<!-- jQuery -->"
                    "<script src='js/jquery-1.11.3.min.js'></script>"
                    "<!-- Bootstrap Core JavaScript -->"
                    "<script src='js/bootstrap.min.js'></script>"
                    "<!-- IE10 viewport bug workaround -->"
                    "<script src='js/ie10-viewport-bug-workaround.js'></script>"
                    "<!-- Placeholder Images -->"
                    "<script src='js/holder.min.js'></script>"
                    "</body>"
                    "</html>");
        }

    }
    fclose(html);
    fclose(archivo);
}
void mostrarPeliculas (eMovie* pelicula)
{
    FILE* archivo;
    int cant;
    if((archivo=fopen("peliculas.dat","rb+"))!=NULL)
    {
        rewind(archivo);
        while(!feof(archivo))
        {
            cant=fread(pelicula,sizeof(eMovie),1,archivo);
            if (cant!=1)
            {
                if(feof(archivo))
                    break;
            }
            if (pelicula->estado == 1)
            {
                mayusculasCorrectas(pelicula->titulo,strlen(pelicula->titulo));
                printf("%s\n",pelicula->titulo);
            }
        }
    }
}

void todoAminuscula (char vec[],int cant)
{
    for (int i=0; i<cant; i++)
    {
        vec[i] =tolower(vec[i]);
    }
}

void mayusculasCorrectas (char vec[],int cant)
{
    for (int i=0; i<cant; i++)
    {
        vec[i] =tolower(vec[i]);
    }
    vec[0]=toupper(vec[0]);

    for (int i=0; i<cant; i++)
    {
        if (vec[i]==' ')
        {
            vec[i+1]=toupper(vec[i+1]);
        }
    }
}

int validarQueSeaNum(char num[], int cant)
{
    int retorno=0;

    for (int i=0; i<cant; i++)
    {
        if (!isdigit(num[i]))
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}


#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char titulo[30];
    char genero[15];
    char descripcion[100];
    char linkImagen[100];
    int duracion;
    int puntaje;
    int estado;
} eMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie*);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(eMovie*);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */

/** \brief Escribe una estructura de datos en un archivo
 *
 * \param Puntero de estructura cargada para escribir el archivo
 * \return Retorna 1 si se escribio correctamente
 *
 */
int escribirPeliculaEnArchivo (eMovie*);

/** \brief Modifica una pelicula seleccionada
 *
 * \param Puntero de estructura de pelicula
 * \return Retorna 1 si se modifico correctamente
 *
 */
int modificarPeliculas (eMovie*);

/** \brief Genera una pagina web con los datos de un archivo
 *
 * \param Puntero de estructura de pelicula
 * \return
 *
 */
void generarPagina (eMovie*);

/** \brief Muestra una lista de peliculas cargadas
 *
 * \param Puntero de estructura de pelicula
 * \return
 *
 */
void mostrarPeliculas (eMovie*);

/** \brief Pasa una cadena a minuscula
 *
 * \param Cadena
 * \param El tamaño de la cadena
 *
 */
void todoAminuscula (char [],int);

/** \brief Coloca mayusculas y minusculas correctamente a una cadena
 *
 * \param Cadena
 * \param El tamaño de la cadena
 * \return
 *
 */
void mayusculasCorrectas (char [],int);

/** \brief Valida que lo que se ingreso sea un numero
 *
 * \param Cadena a validar
 * \param Tamaño de la cadena
 * \return 1 si es numero
 *
 */
int validarQueSeaNum(char [], int);
#endif // FUNCIONES_H_INCLUDED

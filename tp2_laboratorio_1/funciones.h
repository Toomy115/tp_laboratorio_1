#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[30];
    int edad;
    int estado;
    int dni;

}EPersona;

/** \brief Inicializa la estructura y la matriz
 *
 * \param Estructura que recibe
 * \param Tamaño del vector de estructura
 * \param La matriz usada para el grafico
 * \param El tamaño de filas de la matriz
 * \return
 *
 */
void IniciarEstructura (EPersona [], int, char [][6],int);

/** \brief Valida el nombre ingresado por el usuario
 *
 * \param Nombre ingresado
 * \param Cantidad de letras del nombre
 * \return 0 si es un nombre correcto, 1 si no
 *
 */
int validarNombre (char[],int);

/** \brief Valida la edad ingresada por el usuario
 *
 * \param Recibe la edad ingresada
 * \return 0 si es una edad correcta, 1 si no
 *
 */
int validarEdad(int );

/** \brief Valida si el DNI es correcto
 *
 * \param Recibe el DNI ingresado
 * \return 0 si es un DNI correcto, 1 si no
 *
 */
int validarDNI (int);


/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona [],int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni, int);

#endif // FUNCIONES_H_INCLUDED

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
int menu();

typedef struct
{

    char nombre[50];
    int edad;
    int estado;
    int dni;

} EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[],int tam, int dni);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void inicializadorPersonas( EPersona vec[], int tam );

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void altaPersona(EPersona lista[], int tam);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarPersonas(EPersona lista[], int tam);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void bajaPersona(EPersona lista[], int tam);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void ordenarPersonas(EPersona lista[], int tam);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void graficosEdades(EPersona lista[], int tam);






#endif // FUNCIONES_H_INCLUDED

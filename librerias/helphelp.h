typedef struct
{
    int id;
    char descripcion[20];

} eComida;

typedef struct
{
    int dia;
    int mes;
    int anio;

} efecha;

typedef struct
{
    int id;
    int idComida;
    int idEmp;
    efecha fecha;
    int isEmpty;

} eAlmuerzo;

int menu();
void cargarSectores(eSector sectores[]);
void cargarComidas(eComida comidas[]);
void listarComidas(eComida c[], int tam);
void altaAlmuerzo(eAlmuerzo a[], int tama, eComida c[], int tamc, eEmpleado e[], int tame, eSector s[], int tams, int* pId);
int buscarLibreAlmuerzo(eAlmuerzo lista[], int tam);
void inicializarAlmuerzos(eAlmuerzo lista[], int tam);
void obtenerDescComida(eComida c[], int tamc, int idComida, char* cadena);
void mostrarAlmuerzo(eAlmuerzo unAlmuerzo, eComida c[], int tamc, eEmpleado e[], int tame);
void mostrarAlmuerzos(eAlmuerzo a[], int tama, eComida c[], int tamc, eEmpleado e[], int tame);




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


/**\brief Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[],int tam, int dni);


/** \brief inicializa a las personas
 * \param lista es el vector de estructura a ser explorado
 * \param   tam es tamaño del vector lista
 * \return  void
 *
 */
void inicializadorPersonas( EPersona vec[], int tam );


/** \brief permite dar el alta a una persona
 * \param lista es el vector de estructura a ser explorado
 * \param tam es tamaño del vector lista
 * \return void
 *
 */
void altaPersona(EPersona lista[], int tam);


/** \brief mustra los datos de las persona dado de alta
 * \param  lista es el vector de estructura donde se guarda
 * \param   tam es tamaño del vector lista
 * \return  void
 *
 */
void mostrarPersonas(EPersona lista[], int tam);


/** \brief permite dar de baja a una persona
 * \param lista es el vector de estructura a ser explorado
 * \param tam es tamaño del vector lista
 * \return void
 *
 */
void bajaPersona(EPersona lista[], int tam);


/** \brief muestra la lista en forma ordenada alfabeticamente
 * \param lista es el vector de estructura a ser explorado
 * \param tam es tamaño del vector lista
 * \return void
 *
 */
void ordenarPersonas(EPersona lista[], int tam);


/** \brief graico donde se muestra las edades de las personas de altas
 * \param   lista es el vector de estructura a ser explorado
 * \param tam es tamaño del vector lista
 * \return  void
 *
 */
void graficosEdades(EPersona lista[], int tam);


 /** \brief solicita un numero al usuario y lo devuleve
  * \param cadena es el mensaje a ser mostrado
  * \return numero ingresado por el usuario
  *
  */

int esNumerico(char cadena[]);

/** \brief solicita un texto numerico y lo devuelve
 * \param mensaje a ser mostrado
 * \param lugar donde quedara guardado el mensaje
 * \return
 *
 */

int getsStringsSoloNumeros(char mensaje[],  char lugar[]);

/** \brief solicita un texto numerico y lo devuelve
 * \param mensaje a ser mostrado
 * \param lugar donde quedara guardado el mensaje
 * \return void
 *
 */

void getString(char mensaje[], char lugar[]);



#endif // FUNCIONES_H_INCLUDED


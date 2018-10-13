
typedef struct
{
    int codigoJuego;
    char descripcion[51];
    int importe;
    int codigoCate;
    int isEmpty;
} eJuegos;

typedef struct
{
    int id;
    char descripcion[51];
} eCategoria;


typedef struct
{
    int codigoCliente;
    char nombre[51];
    char sexo;
    int telefono;
    int isEmpty;
} eClientes;

typedef struct
{
    int dia,mes,anio;
} eFecha;

typedef struct
{
    int CodigoAlquiler;
    int CodigoJuego;
    int CodigoCliente;
    int isEmpty;
    eFecha fecha;
} eAlquileres;

int buscarLibre(eClientes lista[], int tam);
int buscarEmpleado(eClientes lista[], int tam, int codigo);
int buscarCliente(eClientes lista[], int tam, int codigo);
void altaCliente(eClientes lista[], int tam, int* pId);
void mostrarCliente(eClientes unCliente);
void mostrarClientes(eClientes lista[], int tam);
void bajaCliente(eClientes lista[], int tam);
void modificacionCliente(eClientes lista[], int tam);
void inicializarClientes(eClientes lista[], int tam);
void ordenarEmpleados(eClientes lista[], int tam);
int menu();
int menuClientes();


// ----- alquileres----

void cargarCategorias(eCategoria categorias[]);
void cargarJuegos(eJuegos juegos[]);
int buscarAlquiler(eAlquileres lista[], int tam, int codigoAlq);
void inicializarAlquiler(eAlquileres lista[], int tam);
void altaAlquiler(eAlquileres* alquiler, int tamAl, eJuegos juego[], int tamj, eClientes cliente[], int tamCl, eCategoria cat[], int tamcat, int* pId);
int buscarLibreAlquiler(eAlquileres lista[], int tam);
void mostrarAlquiler(eAlquileres unAlquiler, eJuegos j[], int tamj, eClientes c[], int tame, eCategoria unaCateg[], int tamC);
void obtenerDescAlquiler(eJuegos juego[], int tamj, int codigoJuego, char* cadena);
int menuAlquileres();
void listarJuegos(eJuegos juegoss[], int tam);
void mostrarAlquileres(eAlquileres alquiler[], int tamAl, eJuegos juego[], int tamJue, eClientes clien[], int tamClien, eCategoria cat[], int tamC);
void obtenerCategoria(eCategoria categorias[], int tam, int idCategoria, char cadena[]);
void listarCategorias(eCategoria categorias[], int tam);
void listarJuegosXcategotias(eJuegos juego[],int tamJ, eCategoria categorias[], int tamC);
void mostrarJuego(eJuegos unJuego, eCategoria categorias[], int tam);
void mostrarJuegos(eJuegos lista[], int tamJ, eCategoria categotias[], int tamC);




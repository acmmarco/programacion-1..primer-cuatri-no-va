#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int codigoProveedor;
    char descripcionProducto[50];

} eProveedor;

typedef struct
{
    int codigoProducto;
    char descripcionProduto[50];
    float importe;
    int cantidad;
    int idProveedor;
    int estado;

} eProducto;

int menu();
int obtenerEspacioLibre(eProducto lista[], int tam);
void inicializadorPersonas(eProducto lista[], int tam );
int buscarProducto(eProducto lista[], int tam, int codigo);
void mostrarProducto(eProducto prod, eProveedor proveedores[], int tam);
void mostrarProductos(eProducto lista[], int tamProduc, eProveedor proveedores[],int tamProv);
void altaProducto(eProducto lista[], int tamProduc, eProveedor proveedores[], int tamProveed);
void bajaProducto(eProducto vec[], int tam, eProveedor proveedores[], int tamProv);
void modificacionProducto(eProducto vec[], int tamProduc, eProveedor proveedores[], int tamProv);
int pedirProveedor(eProveedor proveedores[], int tam);
int menuInformar();
int cantidadDeProductos( eProducto product[], int tam);
int totalImportes( eProducto product[], int tam);


































#endif // FUNCIONES_H_INCLUDED

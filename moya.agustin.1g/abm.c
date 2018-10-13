#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abm.h"


int menu()
{

    int opcion;

    system("cls");
    printf("\n*** Menu***\n\n");
      printf(" 1- Alta\n");
    printf(" 2- Baja\n");
    printf(" 3- Modificacion\n");
    printf(" 4- Listar clientes\n");
    printf(" 5- Ordenar clientes\n");
    printf(" Ingrese opcion: ");
    while(scanf("%d", &opcion) !=1)
    {
        printf(" reingrese  un numero: ");
        scanf("%d", &opcion);
        fflush(stdin);
    }

    return opcion;
}
int menuClientes()
{

    int opcion;

    system("cls");
    printf("\n*** Menu de Clientes ***\n\n");
    printf(" 1- Alta\n");
    printf(" 2- Baja\n");
    printf(" 3- Modificacion\n");
    printf(" 4- Listar clientes\n");
    printf(" 5- Ordenar clientes\n");
      printf(" 6- AltaAlquilres\n");
    printf(" 7- Listar alquilers\n");
    printf(" 8- Listar juegos\n");
    printf(" 9- Listar juegos de mesa\n");
    printf(" 12- Salir\n\n");
    printf(" Ingrese opcion: ");
    while(scanf("%d", &opcion) !=1)
    {
        printf(" reingrese  un numero: ");
        scanf("%d", &opcion);
        fflush(stdin);
    }

    return opcion;
}

int menuAlquileres()
{

    int opcion;

    system("cls");
    printf("\n*** Menu de alquiler ***\n\n");
    printf(" 1- AltaAlquilres\n");
    printf(" 2- Listar alquilers\n");
    printf(" 3- Salir\n\n");
    printf(" Ingrese opcion: ");
    while(scanf("%d", &opcion) !=1)
    {
        printf(" reingrese  un numero: ");
        scanf("%d", &opcion);
        fflush(stdin);
    }

    return opcion;
}

int menuModificar()
{

    int opcion;

    system("cls");
    printf("\n*** Menu de modificacion ***\n\n");
    printf(" 1- cambiar nombre \n");
    printf(" 2- cambiar sexo\n");
    printf(" 3- cambiar telefono\n");
    printf(" 4- terminar modificacion \n\n");
    printf(" Ingrese opcion: ");
    while(scanf("%d", &opcion) !=1)
    {
        printf(" reingrese  un numero: ");
        scanf("%d", &opcion);
        fflush(stdin);
    }

    return opcion;
}
void inicializarClientes(eClientes lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}


void altaCliente(eClientes lista[], int tam, int* pId)
{
    eClientes nuevoCliente;
    int idCliente = *pId;
    int indice;
    indice= buscarLibre(lista, tam);

    if(indice== -1 )
    {
        printf("\n el sistema esta completo. no se puede dar de alta a mas clientes.\n\n");
    }
    else
    {
        nuevoCliente.codigoCliente = idCliente;


        nuevoCliente.isEmpty=0;


        printf("ingrese nombre\n");
        fflush(stdin);
        gets(nuevoCliente.nombre);
        printf("ingrese sexo\n");
        scanf("%c", &nuevoCliente.sexo);
        printf("ingrese telefono\n");
        while(scanf("%d", &nuevoCliente.telefono) !=1)
        {
            printf(" reingrese  un numero: ");
            scanf("%d", &nuevoCliente.telefono);
            fflush(stdin);
        }


        lista[indice] = nuevoCliente;



        *pId = idCliente +1;

        nuevoCliente.isEmpty = 0;

        lista[indice] = nuevoCliente;

    }
}

int buscarCliente(eClientes lista[], int tam, int codigo)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == 0 && lista[i].codigoCliente == codigo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarLibre(eClientes lista[], int tam)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eClientes lista[], int tam, int codigo)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == 0 && lista[i].codigoCliente == codigo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarCliente(eClientes unCliente)
{

    printf("%d------%s---- %c---- %d\n", unCliente.codigoCliente,unCliente.nombre,unCliente.sexo,unCliente.telefono);

}

void mostrarClientes(eClientes lista[], int tam)
{

    system("cls");
    printf("id-----nombre------ Sexo -------- telefono\n\n");

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            mostrarCliente(lista[i]);
        }
    }
    system("pause");
}

void bajaCliente(eClientes lista[], int tam)
{
    int codigo;
    int esta;
    char confirma;

    system("cls");
    printf("-----baja de cliente-----\n\n");

    mostrarClientes(lista, tam);

    printf("ingrese codigo de cliente\n");
    while(scanf("%d", &codigo) !=1)
    {
        printf(" reingrese  un numero: ");
        scanf("%d", &codigo);
        fflush(stdin);
    }

    esta = buscarCliente(lista,tam, codigo);

    if(esta== -1)
    {
        printf("\n el codigo %d no se encuentra en el sistema\n\n", codigo);
    }
    else
    {
        mostrarCliente(lista[esta]);

        printf("\n confirma la baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma== 's')
        {
            lista[esta].isEmpty=1;
            printf("\n se ha realizado la baja \n\n");
        }
        else
        {
            printf("\n se ha cancelado la baja\n\n");
        }

    }
}


void modificacionCliente(eClientes lista[], int tam)
{

    char seguir = 's';
    int codigo;
    int esta;
    char confirma;
    char nuevoNombre[51];
    char nuevoSexo;
    int nuevoTelefono;

    system("cls");
    printf("---Modificacion cliente---\n\n");

    mostrarClientes(lista, tam);

    printf("Ingrese codigo de cliente: ");
    while(scanf("%d", &codigo) !=1)
    {
        printf(" reingrese  un numero: ");
        scanf("%d", &codigo);
        fflush(stdin);
    }

    esta = buscarCliente(lista, tam, codigo);

    if(esta == -1)
    {
        printf("\nEl codigo %d no se encuentra en el sistema\n\n", codigo);

    }
    else
    {

        mostrarCliente(lista[esta]);

            do
            {
                switch(menuModificar())
                {

                case 1:
                    printf("\nIngrese nuevo nombre: ");
                    fflush(stdin);
                    gets(nuevoNombre);
                    strcpy(lista[esta].nombre, nuevoNombre);

                    break;
                case 2:
                     printf("ingrese nuevo sexo: ");
                     fflush(stdin);
                    scanf("%c", &nuevoSexo);
                    lista[esta].sexo = nuevoSexo;

                    break;
                    case 3:
                     printf("ingrese nuevo telefono: ");
                    scanf("%d", &nuevoTelefono);
                    lista[esta].telefono = nuevoTelefono;

                    break;
                case 4:
                    seguir = 'n';
                    break;

                }
            }
            while(seguir == 's');


        printf("\nConfirma Modificacion?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {




            printf("\nSe ha modificado lo pedido\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la modificacion\n\n");
        }

    }
}

void ordenarEmpleados(eClientes lista[], int tam)
{

    eClientes auxCliente;

    for(int i=0; i< tam-1; i++)
    {
        for(int j=i +1; j< tam; j++)
        {
            if(lista[i].sexo > lista[j].sexo)
            {
                auxCliente = lista[i];
                lista[i] = lista[j];
                lista[j] = auxCliente;
            }
            else
            {
                if(lista[i].sexo == lista[j].sexo)
                {
                    if(strcmp(lista[i].nombre, lista[j].nombre)>0)
                    {
                        auxCliente = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxCliente;
                    }

                }

            }
        }
    }
    printf("\nSistema Ordenado\n\n");
}

// ----- alquileres------



void cargarCategorias(eCategoria categorias[])
{
    eCategoria cat[]=
    {
        {1, "mesa"},
        {2, "azar"},
        {3, "estrategia"},
        {4, "salon"},
        {5, "magia"}
    };

    for(int i=0; i < 5; i++)
    {
        categorias[i] = cat[i];
    }
}

void cargarJuegos(eJuegos juegos[])
{
    eJuegos jueg[]=
    {
        {1, "ludo",500,1,0},
        {2, "vivorita",770,3,0},
        {3, "batalla",400,1,0},
        {4, "baile",900,1,0},
        {5, "magos",400,3,0},
        {6, "ludo",90,4,0},
        {7, "rayman",4500,2,0},
        {8, "pes",3500,1,0},
        {9, "carreras",2300,2,0},
        {10, "ajedrez",200,4,0}
    };

    for(int i=0; i < 10; i++)
    {
        juegos[i] = jueg[i];
    }
}

void inicializarAlquiler(eAlquileres lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}



void altaAlquiler(eAlquileres* alquiler, int tamAl, eJuegos juego[], int tamj, eClientes cliente[], int tamCl, eCategoria cat[], int tamcat, int* pId)
{
    int idAlquiler = *pId;
    int idcategoria;
    int idjuego;
    int idCliente;
    eFecha fecha;
    eAlquileres nuevoAlquiler;
    int indice;

    indice = buscarLibreAlquiler(alquiler, tamAl);

    if(indice == -1)
    {
        printf("No se pueden cargar mas alquileres\n\n");
    }
    else
    {
        nuevoAlquiler.CodigoAlquiler = idAlquiler;

        mostrarClientes(cliente, tamCl);

        printf("Ingrese codigo de cliente: ");
        while(scanf("%d", &idCliente) !=1)
        {
            printf(" reingrese  un numero: ");
            scanf("%d", &idCliente);
            fflush(stdin);
        }

        nuevoAlquiler.CodigoCliente = idCliente;

        listarJuegos(juego, tamj );

        printf("Ingrese juego: ");
        scanf("%d", &idjuego);

        nuevoAlquiler.CodigoJuego = idjuego;

        printf("\nIngrese dia: ");
        while(scanf("%d", &fecha.dia) !=1)
        {
            printf(" reingrese  un numero: ");
            scanf("%d", &fecha.dia);
            fflush(stdin);
        }

        printf("Ingrese mes: ");
        while(scanf("%d", &fecha.mes) !=1)
        {
            printf(" reingrese  un numero: ");
            scanf("%d", &fecha.mes);
            fflush(stdin);
        }


        printf("Ingrese anio: ");
        while(scanf("%d", &fecha.anio) !=1)
        {
            printf(" reingrese  un numero: ");
            scanf("%d", &fecha.anio);
            fflush(stdin);
        }

        listarCategorias(cat, tamcat);
        printf("\nIngrese categoria: ");
        scanf("%d", &idcategoria);

        nuevoAlquiler.CodigoJuego = idcategoria;


        nuevoAlquiler.fecha = fecha;

        *pId = idAlquiler +1;

        nuevoAlquiler.isEmpty = 0;

        alquiler[indice] = nuevoAlquiler;

    }
}

int buscarAlquiler(eAlquileres lista[], int tam, int codigoAlq)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == 0 && lista[i].CodigoAlquiler == codigoAlq)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarLibreAlquiler(eAlquileres lista[], int tam)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void mostrarAlquiler(eAlquileres unAlquiler, eJuegos j[], int tamj, eClientes c[], int tame, eCategoria unaCateg[], int tamC)
{
    char descAlquiler[20];
    char descCat[20];
    int indice;
    eClientes cliente;

    obtenerDescAlquiler(j, tamj, unAlquiler.CodigoJuego, descAlquiler);
    obtenerCategoria(unaCateg,tamC,unAlquiler.CodigoJuego,descCat);
    indice = buscarCliente(c, tame, unAlquiler.CodigoCliente);

    cliente = c[indice];

    printf("%4d %02d/%02d/%d     %d           %10s         %10s     %10s\n", unAlquiler.CodigoAlquiler, unAlquiler.fecha.dia, unAlquiler.fecha.mes, unAlquiler.fecha.anio, cliente.codigoCliente, cliente.nombre, descAlquiler, descCat);
}



void obtenerDescAlquiler(eJuegos juego[], int tamj, int codigoJuego, char* cadena)
{
    for(int i=0; i < tamj; i++)
    {
        if( juego[i].codigoJuego == codigoJuego)
        {
            strcpy(cadena, juego[i].descripcion);
        }
    }
}


void listarJuegos(eJuegos juegoss[], int tam)
{
    printf("\nLista de juegos\n\n");

    for(int i=0; i < tam; i++)
    {
        printf(" %d  %10s   %d  \n",juegoss[i].codigoJuego, juegoss[i].descripcion, juegoss[i].importe);
    }
    printf("\n\n");
}

int menuAlquilers()
{

    int opcion;

    system("cls");
    printf("\n*** Menu de alquileres ***\n\n");
    printf(" 1- Alta\n");
    printf(" 2- Listar alquilers\n");
    printf(" 3- Salir\n\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarAlquileres(eAlquileres alquiler[], int tamAl, eJuegos juego[], int tamJue, eClientes clien[], int tamClien, eCategoria cat[], int tamC)
{
    int flag = 0;

    system("cls");
    printf("id   fecha   codigo cliente    Nombre cliente    juego     categoria\n\n");

    for(int i=0; i < tamAl; i++)
    {
        if( alquiler[i].isEmpty == 0)
        {
            mostrarAlquiler(alquiler[i], juego, tamJue, clien, tamClien,cat,tamC);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay alquileres cargados");
    }
    printf("\n\n");
}


/*
void listarJuegosXcategotias(eJuegos juego[],int tamJ, eCategoria categorias[], int tamC)
{
    int idCategoria;
    char descripcion[20];
    int flag = 0;

    system("cls");

    obtenerCategoria(categorias, tamC, idCategoria, descripcion);

    system("cls");
    printf("juegos de categorias %s\n\n", descripcion);
    for(int i=0; i< tamC; i++)
    {
        if(juego[i].isEmpty == 0 && juego[i].codigoJuego == idCategoria)
        {
            mostrarJuego(juego[i],categorias, tamC);
            flag = 1;
        }
    }

    printf("\n\n");

    if(flag == 0)
    {
        printf("No hay juegos que mostrar\n\n");
    }

}

*/
void listarCategorias(eCategoria categorias[], int tam)
{

    printf("Id  Descripcion\n\n");
    for(int i=0; i< tam; i++)
    {
        printf("%d   %10s\n", categorias[i].id, categorias[i].descripcion);

    }
    printf("\n\n");
}

void obtenerCategoria(eCategoria categorias[], int tam, int idCategoria, char cadena[])
{

    for(int i=0; i < tam; i++)
    {

        if( categorias[i].id == idCategoria)
        {
            strcpy(cadena, categorias[i].descripcion);
        }
    }

}


void mostrarJuegos(eJuegos lista[], int tamJ, eCategoria categotias[], int tamC)
{

    system("cls");
    printf("Legajo   Nombre     importe     categoria\n\n");

    for(int i=0; i < tamJ; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            mostrarJuego(lista[i], categotias, tamC);
        }
    }

    printf("\n\n");


}

void mostrarJuego(eJuegos unJuego, eCategoria categorias[], int tam)
{
    char desCat[20];

    obtenerCategoria(categorias, tam, unJuego.codigoJuego, desCat);

    printf("%4d %10s  %d %10s\n", unJuego.codigoJuego, unJuego.descripcion,unJuego.importe, desCat);
}

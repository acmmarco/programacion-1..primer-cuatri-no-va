#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAM 20

typedef struct
{
    int CodigoProveedor;
    char descripcionProveedor[50];
    int estado;//nombre empresa

}eProveedores;

int menu();
void bajaPersona(eProveedores lista[], int tam);
void altaPersona(eProveedores lista[], int tam);
void inicializadorPersonas(eProveedores vec[], int tam );
void mostrarPersona(eProveedores prove);
void mostrarPersonas(eProveedores lista[], int tam);
int buscarPorCodigo(eProveedores lista[], int tam, int codigo);

int main()
{
    char seguir='s';
    eProveedores proveedor[TAM];
    inicializadorPersonas(proveedor,TAM);

    while(seguir=='s')
    {
        switch(menu())
        {
        case 1:
            altaPersona(proveedor, TAM);
            system("pause");
            system("cls");
            break;
        case 2:
            bajaPersona(proveedor, TAM);
            system("pause");
            system("cls");
            break;
        case 3:
            mostrarPersonas(proveedor, TAM);
            system("pause");
            system("cls");
            break;
        case 4:

            system("pause");
            system("cls");
            break;
        case 5:
            seguir = 'n';
            system("pause");
            break;
        default:
            printf("elija opcion del 1 al 5\n");
            system("pause");
            system("cls");
        }
    }

    return 0;
}

int menu()
{
    int opcion;
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n\n");
    printf("5- Salir\n");


    scanf("%d",&opcion);
    return opcion;
}

void inicializadorPersonas(eProveedores vec[], int tam )
{
    for(int i = 0; i<tam ; i++ )
    {
        vec[i].estado=1;
    }

}

void mostrarPersona(eProveedores persona)
{

    printf("%d              %s       % \n", persona.CodigoProveedor, persona.descripcionProveedor);

}


void mostrarPersonas(eProveedores lista[], int tam)
{
    printf("-------- lista de personas ordenadas por nombre------\n\n");
    printf(" CODIGO       DESCRIPCIOn  \n\n");

    for(int i =0; i<tam ; i++)
    {
        if(lista[i].estado == 0)
        {
            mostrarPersona(lista[i]);
        }
    }
    printf("\n-----------------------------------------------------------\n");

}

int obtenerEspacioLibre(eProveedores lista[], int tam)
{

    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            indice=i;
            break;
        }

    }
    return indice;
}

int buscarPorCodigo(eProveedores lista[], int tam, int codigo)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==0 && lista[i].CodigoProveedor == codigo)
        {
            indice=i;
            break;
        }

    }
    return indice;
}
void altaPersona(eProveedores lista[], int tam)
{
    eProveedores nuevoProveedor;
    int indice;
    int codigo;
    int esta;

    system("cls");
    printf("---- alta de personas----\n");

    indice= obtenerEspacioLibre(lista, tam);

    if(indice== -1)
    {
        printf("\n el sistema esta completo. no se puede dar de alta a mas personas.\n\n");
    }
    else
    {
        printf("ingrese codigo: \n");
        scanf("%d", &codigo);

        esta= buscarPorCodigo(lista, tam, codigo);

        if(esta != -1)
        {
            printf("\nel legajo %d ya esta dado de alta en el sistema\n", codigo);
            mostrarPersona(lista[esta]);

        }
        else
        {
            nuevoProveedor.estado=0;
            nuevoProveedor.estado=codigo;


            printf("ingrese nombre de empresa\n");
            fflush(stdin);
            gets(nuevoProveedor.descripcionProveedor);

            lista[indice] = nuevoProveedor;

            printf("\nalta exitosa !!!! \n\n");


        }
    }
}

void bajaPersona(eProveedores lista[], int tam)
{
    int codigo;
    int esta;
    char confirma;

    system("cls");
    printf("-----baja de persona-----\n\n");

    printf("ingrese codigo\n");
    scanf("%d", &codigo);

    esta = buscarPorCodigo(lista,tam, codigo);

    if(esta== -1)
    {
        printf("\n el dni %d no se encuentra en el sistema\n\n", codigo);
    }
    else
    {
        mostrarPersona(lista[esta]);

        printf("\n confirma la baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma== 's')
        {
            lista[esta].estado=1;
            printf("\n se ha realizado la baja \n\n");
        }
        else
        {
            printf("\n se ha cancelado la baja\n\n");
        }

    }
}


















































/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20
#define TAMPROD 20

typedef struct
{
    int CodigoProveedor;
    char descripcionProveedor[50];
    int estado;//nombre empresa

}eProveedores;

typedef struct
{

    int codigoProducto;
    char descripcionProducto;
    int importeProducto;
    int cantidadProducto;
    int idProovedor;

}eproducto;

void inicializadorProveedor(eProveedores lista[], int tam );
void mostrarProveedor(eProveedores provedor, int tam);
void mostrarPersonas(eProveedores lista[], int tam);
int obtenerEspacioLibre(eProveedores lista[], int tam);
int buscarPorCodigo(eProveedores lista[], int tam, int codigo);
void altaPersona(eProveedores lista[], int tam);
void bajaPersona(eProveedores lista[], int tam);


int main()
{
    char seguir='s';
    eProveedores proveedores[TAM];
    eproducto productos[TAMPROD];
    inicializadorProveedor(proveedores,TAM);

    while(seguir=='s')
    {
        switch(menu())
        {
        case 1:
           altaPersona(proveedores, TAM );
            system("pause");
            system("cls");
            break;
        case 2:
           bajaPersona(productos, TAM);
            system("pause");
            system("cls");
            break;
        case 3:
           mostrarPersonas(productos, TAM);
            system("pause");
            system("cls");
            break;
        case 4:
           // graficosEdades(persona, TAM);
            system("pause");
            system("cls");
            break;
        case 5:
            seguir = 'n';
            system("pause");
            break;
        default:
            printf("elija opcion del 1 al 5\n");
            system("pause");
            system("cls");
        }
    }

    return 0;
}

int menu()
{
    int opcion;
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n\n");
    printf("5- Salir\n");


    scanf("%d",&opcion);
    return opcion;
}

void inicializadorProveedor(eProveedores lista[], int tam )
{
    for(int i = 0; i<tam ; i++ )
    {
        lista[i].estado=1;
    }

}

void mostrarProveedor(eProveedores lista[], int tam)
{
    int indice;
    for(int i=0; i< tam; i++)
    {
        if(lista[i].estado == 0)
        {
            indice = i;
            break;
        }
    }


    printf("%d            %s           \n", lista.CodigoProveedor, lista.descripcionProveedor);

}

void mostrarPersonas(eProveedores lista[], int tam)
{

    printf("codigo proveedor ---  descripcion --- producto trabajado \n\n");


    for(int i =0; i<tam ; i++)
    {
        if(lista[i].estado == 0)
        {
            mostrarProveedor(lista[i]);
        }
    }
    printf("\n-----------------------------------------------------------\n");

}

int obtenerEspacioLibre(eProveedores lista[], int tam)
{

    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            indice=i;
            break;
        }

    }
    return indice;
}

int buscarPorCodigo(eProveedores lista[], int tam, int codigo)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==0 && lista[i].CodigoProveedor == codigo)
        {
            indice=i;
            break;
        }

    }
    return indice;
}
void altaPersona(eProveedores lista[], int tam )
{
    eProveedores nuevoProveedor;
    int indice;
    int codigo;
    int esta;

    system("cls");
    printf("---- alta de personas----\n");

    indice= obtenerEspacioLibre(lista, tam);

    if(indice== -1)
    {
        printf("\n el sistema esta completo. no se puede dar de alta a mas personas.\n\n");
    }
    else
    {
        printf("ingrese su codigo: \n");
        scanf("%d", &codigo);

        esta= buscarPorCodigo(lista, tam, codigo);

        if(esta != -1)
        {
            printf("\nel codigo %d ya esta dado de alta en el sistema\n", codigo);
            mostrarProveedor(lista[esta]);

        }
        else
        {
            nuevoProveedor.estado=0;
            nuevoProveedor.CodigoProveedor=codigo;

            printf("ingrese descripcion de su empresa\n");
            fflush(stdin);



            lista[indice] = nuevoProveedor;

            printf("\nalta exitosa !!!! \n\n");

        }
    }
}

void bajaPersona(eProveedores lista[], int tam)
{
    int codigo;
    int esta;
    char confirma;

    system("cls");
    printf("-----baja de persona-----\n\n");

    printf("ingrese codigo\n");
    scanf("%d", &codigo);

    esta = buscarPorCodigo(lista,tam, codigo);

    if(esta== -1)
    {
        printf("\n el codigoProveedor %d no se encuentra en el sistema\n\n", codigo);
    }
    else
    {
        mostrarProveedor(lista[esta]);

        printf("\n confirma la baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma== 's')
        {
            lista[esta].estado=1;
            printf("\n se ha realizado la baja \n\n");
        }
        else
        {
            printf("\n se ha cancelado la baja\n\n");
        }

    }*/

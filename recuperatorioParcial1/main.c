#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

#define TAM 50
#define TAMPROV 6

void ordenar(eProducto prod[], int tam);
void mostrarProductosordenados(eProducto lista[], int tamProduc, eProveedor proveedores[],int tamProv);
void proveedoresXproductos(eProducto prod[], int tampro, eProveedor provee[], int tamprov);

int main()
{
    eProducto producto[TAM];
    eProveedor proveedores[]= {{1, "coto"}, {2,"morres"}, {3, "fravega"}, {4, "nicart"}, {5, "potable"}, {6, "alectro"}};
    inicializadorPersonas(producto, TAM);
    char seguir= 's';

    while(seguir=='s')
    {
        switch(menu())
        {
        case 1:
            altaProducto(producto, TAM, proveedores, TAMPROV);
            system("pause");
            system("cls");
            break;
        case 2:
            bajaProducto(producto, TAM, proveedores, TAMPROV);
            system("pause");
            system("cls");
            break;
        case 3:
            modificacionProducto(producto, TAM, proveedores, TAMPROV);
            system("pause");
            system("cls");
            break;
        case 4:
            mostrarProductos(producto, TAM, proveedores, TAMPROV);
            system("pause");
            system("cls");
            break;
        case 5:
            switch(menuInformar())
            {
            case 1:
                totalImportes(producto,TAM);
                system("pause");
                system("cls");
                break;
            case 2:
                cantidadDeProductos(producto,TAM);
                system("pause");
                system("cls");
                break;
            case 3:
                seguir = 'n';
                system("pause");
                system("cls");
                break;
            default:
                printf("elija opcion del 1 al 5\n");
                system("pause");
                system("cls");
                break;
            }
            system("pause");
            break;
        case 6:
            mostrarProductosordenados(producto,TAM,proveedores,TAMPROV);
            cantidadDeProductos(producto,TAM);
            totalImportes(producto,TAM);
            proveedoresXproductos(producto,TAM,proveedores,TAMPROV);
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



void ordenar(eProducto prod[], int tam)
{

    eProducto aux;

    for(int i=0; i< tam-1; i++)
    {
        for(int j=i +1; j< tam; j++)
        {

            if(strcmp(prod[i].descripcionProduto, prod[j].descripcionProduto)>0)
            {
                aux = prod[i];
                prod[i]= prod[j];
                prod[j]= aux;
            }

        }
    }
}

void mostrarProductosordenados(eProducto lista[], int tamProduc, eProveedor proveedores[],int tamProv)
{
    system("cls");
    printf("      ---Lista de productos ordenados---\n\n");
    ordenar(lista,tamProduc);
    printf("  codigo    descripcion    cantidad    importe ----  proveedores \n\n");
    for(int i=0; i< tamProduc; i++)
    {
        if(lista[i].estado ==0)
        {
            mostrarProducto(lista[i], proveedores, tamProv);
        }
    }
}

void proveedoresXproductos(eProducto prod[], int tampro, eProveedor provee[], int tamprov)
{

    system("cls");
    printf("---Listado productos por proveedores---\n\n");

    for(int i=0; i< tamprov; i++)
    {
        printf("-- %s --\n\n", provee[i].descripcionProducto);

        for(int j=0; j < tampro; j++)
        {
            if(prod[j].codigoProducto == provee[i].codigoProveedor)
            {
                mostrarProducto(prod[j], provee, tamprov);
            }
        }
        printf("\n-----------------------------------------------------------\n");
    }

    printf("\n\n");
    system("pause");

}

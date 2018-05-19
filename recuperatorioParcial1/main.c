#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

#define TAM 50
#define TAMPROV 6

void ordenar(eProducto prod[], int tam);
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
            ordenar(producto,TAM);
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
    char aux[50];
    for(int i=0; i<tam; i++)
    {
        for(int j=0; i<tam; i++)
        {
            if((strcmp(prod[i].descripcionProduto, prod[j].descripcionProduto))>0)
            {
                strcpy(aux, prod[i].descripcionProduto);
                strcpy(prod[i].descripcionProduto,prod[j].descripcionProduto );
                strcpy(prod[j].descripcionProduto, aux);
            }
        }
    }

    printf("lista de productos ordenas");

for(int i =0; i<tam; i++)
    {
        printf("%s ----------- %d----$%.2f\n\n", prod[i].descripcionProduto,prod[i].cantidad, prod[i].importe);
        break;
    }
}


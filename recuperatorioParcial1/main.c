#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

#define TAM 50
#define TAMPROV 6

int cantidadDeProductos( eProducto product[], int tam);
int totalImportes( eProducto product[], int tam);
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

int cantidadDeProductos( eProducto product[], int tam)
{
    int cantidad = 0;
    int acumulador=0;

    for (int i =0; i< tam; i++)
    {
        if (product[i].estado==0)
        {
            acumulador = product[i].cantidad+ acumulador;
        }
    }
    printf("\nla cantidad de productos es : %d\n", acumulador);


    for (int i =0; i< tam; i++)
    {
        if (product[i].estado==0 && product[i].cantidad>10)//mayor
        {
            printf("productos con stock mayores a 10\n");
            printf("%s ----------- %d----$%.2f\n\n", product[i].descripcionProduto,product[i].cantidad, product[i].importe);
        }
        if (product[i].estado==0 && product[i].cantidad<11)
        {
            printf("productos con stock menor a 11\n");
            printf("%s ----------- %d----$%.2f\n\n", product[i].descripcionProduto,product[i].cantidad, product[i].importe);
        }
    }


    return cantidad;
}

int totalImportes( eProducto product[], int tam)
{
    int cantidad=0;
    int acumulador=0;
    float promedio;

    for (int i =0; i< tam; i++)
    {
        if (product[i].estado==0)
        {
            cantidad++;
            acumulador = product[i].importe+ acumulador;
        }
    }
    promedio= acumulador/ cantidad;
    printf("\nla cantidad de productos es : %d\n", acumulador);
    printf("\nel promedio de los productos es : %.2f\n", promedio);

    for (int i =0; i< tam; i++)
    {
        if (product[i].estado==0 && product[i].importe>promedio)
        {
            printf("productos mayores al promedio\n");
            printf("%s ----------- %d----$%.2f\n\n", product[i].descripcionProduto,product[i].cantidad, product[i].importe);
        }
        if (product[i].estado==0 && product[i].importe<promedio)
        {
            printf("productos menores al promedio\n");
            printf("%s ----------- %d----$%.2f\n\n", product[i].descripcionProduto,product[i].cantidad, product[i].importe);
        }
    }

    return cantidad;
}

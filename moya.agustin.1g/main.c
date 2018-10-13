#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abm.h"
#define TAMC 15

void juegosDeMesa(eJuegos juegos[], int tamJ, eCategoria cat[], int tam);
void JuegosMenosAlquilados(eJuegos*juegos,eAlquileres*alquileres,int len);
void mostrarJuegosMesa(eJuegos juegos[], int tamJ, eCategoria cat[], int tamc);
void cargarAquileres(eAlquileres alquileres[]);

void cargarClientes(eClientes clientes[]);
int menuInformes();


int main()
{


    char seguir = 's';
    eClientes clientes[TAMC];
    eCategoria categoias[5];
    eJuegos juegos[10];
    eAlquileres alquileres[20];
    inicializarClientes(clientes,TAMC);
    inicializarAlquiler(alquileres,20);
    cargarCategorias(categoias);
    cargarJuegos(juegos);
    cargarClientes(clientes);


    int idAlquiler = 1000;
    int idCliente = 1;

    do
    {
        switch(menuClientes())
        {

        case 1:
            altaCliente(clientes, TAMC, &idCliente);
            system("pause");
            break;
        case 2:
            bajaCliente(clientes, TAMC);
            system("pause");
            break;
        case 3:
            modificacionCliente(clientes, TAMC);
            system("pause");
            break;
        case 4:
            mostrarClientes(clientes, TAMC);
            system("pause");
            break;
        case 5:
            ordenarEmpleados(clientes, TAMC);
            system("pause");
            break;
        case 6:
            altaAlquiler(alquileres, 20, juegos,10,clientes,TAMC,categoias,5, &idAlquiler);
            system("pause");
            break;
        case 7:
            mostrarAlquileres(alquileres,20,juegos, 10, clientes,TAMC,categoias,5);
            system("pause");
            break;
        case 8:
            mostrarJuegos(juegos,10,categoias,5);
            system("pause");
            break;
        case 9:
            mostrarJuegosMesa(juegos,10,categoias,5);
            system("pause");
            break;

        case 11:
            printf("Salir");
            system("pause");
            seguir = 'n';
            break;

        }
    }

    while(seguir == 's');


    return 0;
}


int menuInformes()
{

    int opcion;

    system("cls");
    printf("\n*** Menu informes***\n\n");
    printf(" 1- mostrar alquileres efectuados por un cliente\n");
    printf(" 2- Menu de alquileres\n");
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

void cargarClientes(eClientes clientes[])
{
    eClientes clien[]=
    {
        {1200, "lara",'f',156461651,0},
        {1300, "juan",'m',53453543,0},
        {1400, "mia",'f',4045345,0},
        {1500, "agus",'m',9453540,0},
        {1600, "cris",'f',40453540,0},
        {1700, "hugo",'m',453453453,0},
        {1800, "nelson",'m',4545345,0},
        {1900, "omar",'m',453453,0},
        {1980, "leo",'m',2304534,0},
        {1880, "marcela",'f',453453,0}
    };

    for(int i=0; i < 10; i++)
    {
        clientes[i] = clien[i];
    }
}



void mostrarJuegosMesa(eJuegos juegos[], int tamJ, eCategoria cat[], int tamc)
{
    for(int i = 0; i<tamJ ; i++)
    {

        if(juegos[i].codigoCate == 1 && juegos[i].isEmpty==0)
        {

            printf("los juegos de mesa son  %s    \n", juegos[i].descripcion);

        }


    }//primer for alumnos,, final
}


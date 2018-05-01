#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 2


void inicializadorPersonas( EPersona vec[], int tam );
void altaEmpleado(EPersona lista[], int tam);
void mostrarPersonas(EPersona lista[], int tam);


int main()
{
    char seguir='s';
    EPersona persona[TAM];
    inicializadorPersonas(persona,TAM);

    while(seguir=='s')
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(persona, TAM);
            system("pause");
            system("cls");
            break;
        case 2:
            printf("borrar persona\n");
            system("pause");
            system("cls");
            break;
        case 3:
            mostrarPersonas(persona, TAM);
            system("pause");
            system("cls");
            break;
        case 4:
            system("pause");
            break;
        case 5:
            seguir = 'n';
            system("pause");
            break;
        default:
            printf("elija opcion del 1 al 5\n");
            system("pause");
        }
    }

    return 0;
}

void inicializadorPersonas(EPersona vec[], int tam )
{
    for(int i = 0; i<tam ; i++ )
    {
        vec[i].isEmpty=1;
    }

}

void mostrarPersona(EPersona persona)
{

    printf("  %2d %6s %2d", persona.dni, persona.nombre, persona.edad);

}

void mostrarPersonas(EPersona lista[], int tam)
{
    printf("-------- lista de empleados------\n\n");
    printf(" dni    nombre    edad  \n\n");

    for(int i =0; i<tam ;i++)
        {
            if(lista[i].isEmpty == 0)
                {
                    mostrarPersona(lista[i]);
                }
        }
  printf("\n-----------------------------------------------------------\n");

}

int obtenerEspacioLibre(EPersona lista[], int tam)
{

    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==1)
        {
            indice=1;
            break;
        }

    }
    return indice;
}

int buscarPorDni(EPersona lista[], int tam, int dni)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==0 && lista[i].dni == dni)
        {
            indice=i;
            break;
        }

    }
    return indice;
}
void altaEmpleado(EPersona lista[], int tam)
{
    EPersona nuevoEmpleado;
    int indice;
    int dni;
    int esta;

    system("cls");
    printf("---- alta de empleado----\n");

    indice= obtenerEspacioLibre(lista, tam);

    if(indice== -1)
    {
        printf("\n el sistema esta completo. no se puede dar de alta a mas personas.\n\n");
    }
    else
    {
        printf("ingrese dni: \n");
        scanf("%d", &dni);

        esta= buscarPorDni(lista, tam, dni);

        if(esta != -1)
        {
            printf("\nel legajo %d ya esta dado de alta en el sistema\n", dni);
            mostrarPersona(lista[esta]);

        }
        else
        {
            nuevoEmpleado.isEmpty=0;
            nuevoEmpleado.dni=dni;


            printf("ingrese nombre\n");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            printf("ingrese edad\n");
            scanf("%d", &nuevoEmpleado.edad);

            lista[indice] = nuevoEmpleado;

            printf("\nalta exitosa !!!! \n\n");

        }
    }
}





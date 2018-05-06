#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 20

int buscarPorDni(EPersona lista[],int tam, int dni);
void inicializadorPersonas( EPersona vec[], int tam );
void altaEmpleado(EPersona lista[], int tam);
void mostrarPersonas(EPersona lista[], int tam);
void bajaPersona(EPersona lista[], int tam);
void mostrarAterisco(EPersona lista[], int tam);
void graficosEdades(EPersona lista[], int tam);


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
            bajaPersona(persona, TAM);
            system("pause");
            system("cls");
            break;
        case 3:
            mostrarPersonas(persona, TAM);
            system("pause");
            system("cls");
            break;
        case 4:
            graficosEdades(persona, TAM);
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
        vec[i].estado=1;
    }

}

void mostrarPersona(EPersona persona)
{

    printf("%d      %s       %d \n", persona.dni, persona.nombre, persona.edad);

}

void mostrarPersonas(EPersona lista[], int tam)
{
    printf("-------- lista de empleados------\n\n");
    printf(" dni    nombre    edad  \n\n");

    for(int i =0; i<tam ; i++)
    {
        if(lista[i].estado == 0)
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
        if(lista[i].estado==1)
        {
            indice=i;
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
        if(lista[i].estado==0 && lista[i].dni == dni)
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
            nuevoEmpleado.estado=0;
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

void bajaPersona(EPersona lista[], int tam)
{
    int dni;
    int esta;
    char confirma;

    system("cls");
    printf("-----baja de persona-----\n\n");

    printf("ingrese dni\n");
    scanf("%d", &dni);

    esta = buscarPorDni(lista,tam, dni);

    if(esta== -1)
    {
        printf("\n el dni %d no se encuentra en el sistema\n\n", dni);
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


/*void mostrarAterisco(EPersona lista[], int tam)
{
    int contador18=0;
    int contador19a35=0;
    int contador35=0;

    for(int i = 0; i<tam; i++ )
    {
        if(lista[i].edad >19)
        {
            contador18++;
            printf("*\n");
        }
        else if(lista[i].edad <18 && lista[i].edad >36)
        {
            contador19a35++;
            printf("*\n");
        }
        else if(lista[i].edad <35)
        {
            contador35++;
            printf("*\n");
        }
    }
    printf(" <18    19-35    >35 \n\n");


    printf("%d      %d       %d \n", contador18,contador19a35,contador35);

}
*/
void graficosEdades(EPersona lista[], int tam)
{
    int contador18=0;
    int contador19a35=0;
    int contador35=0;

    for(int i = 0; i<tam; i++ )
        {
            if(lista[i].edad <19)
                {
                    contador18++;
                    printf("*\n");
                }
            else if(lista[i].edad >18 || lista[i].edad <36)
                {
                    contador19a35++;
                    printf("*\n");
                }else
                {
                    contador35++;
                    printf("*\n");
                }
        }



}

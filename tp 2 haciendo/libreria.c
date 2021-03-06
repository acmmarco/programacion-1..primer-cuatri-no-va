#include <stdio.h>
#include "funciones.h"
#include <string.h>

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
    printf("-------- lista de personas ordenadas por nombre------\n\n");
    printf(" dni    nombre    edad  \n\n");
    ordenarPersonas(lista,tam);

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
void altaPersona(EPersona lista[], int tam)
{
    EPersona nuevoEmpleado;
    int indice;
    int dni;
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

void ordenarPersonas(EPersona lista[], int tam)
{

    EPersona auxpersona;

    for(int i=0; i< tam-1; i++)
    {
        for(int j=i +1; j< tam; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre)>0)
            {
                auxpersona = lista[i];
                lista[i] = lista[j];
                lista[j] = auxpersona;
            }
        }
    }
}

void graficosEdades(EPersona lista[], int tam)
{
    int contador18=0;
    int contador19a35=0;
    int contador35=0;
    char item = '*';

    printf("------grafico de edades -------");

    system("cls");

    for(int i = 0; i<tam; i++ )
    {
        if(lista[i].edad <19 && lista[i].estado==0)
        {
            contador18++;
            printf("%c\n", item);
        }
        else if(lista[i].edad >18 && lista[i].edad <36 && lista[i].estado==0)
        {
            contador19a35++;
            printf("          %c\n",item);
        }
        else if(lista[i].edad>35 && lista[i].estado==0)
        {
            contador35++;
            printf("                     %c\n",item);
        }
    }

    printf("<18      19-35      >35\n");

}


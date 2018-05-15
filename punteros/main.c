#include <stdio.h>
#include <stdlib.h>
void primeraFuncion(int vec[], int tam);
void segundaFuncion( int vec[], int tam);
int main()
{
    int vec[5];

    for(int i =0 ; i<5; i ++ )
    {
        printf("ingrese 5 numeros");
        scanf("%d",vec+i);
    }

    //printf("los numero ingresados es:");

    primeraFuncion(vec, 5);
    segundaFuncion(vec, 5);
    terceraFuncion(vec, 5);
    cuartaFuncion(vec, 5);
    return 0;
}
void primeraFuncion( int vec[], int tam)
{
    for(int i =0 ; i<tam; i ++ )
    {
        printf("%d\n ", vec[i]);
    }
}

void segundaFuncion( int vec[], int tam)
{
    for(int i =0 ; i<tam; i ++ )
    {
        printf("%d\n", (*vec+i));
    }
    printf("----------------- ");
}
void terceraFuncion( int* vec[], int tam)
{
    for(int i =0 ; i<tam; i ++ )
    {
        printf("%d\n", vec[i]);
    }
    printf("----------------- ");
}
void cuartaFuncion( int *vec[], int tam)
{
    for(int i =0 ; i<tam; i ++ )
    {
        printf("%d\n", *(vec+i));
    }
    printf("----------------- ");
}


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vector;
    int* aux;

    vector = (int*) malloc(sizeof(int)*5);//vector de 5 enteros 20 bts

    if(vector== NULL)
    {
        printf("no se pudo asignar memoria\n");
        exit(1);
    }

    for(int i=0; i<5 ; i++)
    {
        printf("ingrese un numero\n");
        scanf("%d", vector+i);
    }
    for(int i=0; i<5 ; i++)
    {
        printf("el numero ingresado es %d\n", *(vector+i));
    }

    aux= (int*)realloc(vector, 10*sizeof(int));//pide mas espacio ..devuleve la direccion de memoria del primer elemnto..
    if(aux!= NULL)
    {
        vector=aux;
        printf("se agrando el array con exito\n");
    }
    else
    {
        printf("no se puede agrandar el array");
    }

    for(int i=5; i<10 ; i++)
    {
        printf("ingrese un numero\n");
        scanf("%d", vector+i);
    }

    for(int i=0; i<10; i++)
    {
        printf("el numero ingresado es %d\n", *(vector+i));
    }


    vector = (int*)realloc(vector,6*sizeof(int));
      printf("achico el array a 6 elemntos");

      for(int i=0; i<10 ; i++)
    {
        printf("ingrese un numero\n");
        scanf("%d", vector+i);
    }
    printf("\n\n");

    return 0;
}

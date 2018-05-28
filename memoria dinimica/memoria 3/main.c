#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vector;
    int* aux;

    vector = (int*) calloc(5,sizeof(int));//inicializa en 0

    if(vector== NULL)
    {
        printf("no se pudo asignar memoria\n");
        exit(1);
    }
    for(int i=0; i<5 ; i++)
    {
        printf("el numero ingresado es %d\n", *(vector+i));
    }


    return 0;
}

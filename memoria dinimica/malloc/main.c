#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* x;
    x = malloc(sizeof(int));

    if(x == NULL)
        {
        printf("no se pudo asignar memoria\n");
        exit(1);
        }
    printf("ingrese un numero\n");
    scanf("%d", x);

    printf("el numero ingresado es %d\n", *x);

    free(x);
    return 0;
}

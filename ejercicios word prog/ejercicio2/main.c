#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;
    float resultado;

    printf("perdir primer numero\n");
    scanf("%d", &numero1);
    printf("perdir segundo numero\n");
    scanf("%d", &numero2);

    resultado= numero1 + numero2;

    printf("la suma de los numeros es %.2f", resultado);
}

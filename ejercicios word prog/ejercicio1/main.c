#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int acumulador=0;
    float mitadTotal;

    for(int contador=0; contador<5; contador++)
        {
            printf("ingresar numero\n");
            scanf("%d", &numero);

            acumulador=acumulador+numero;
            mitadTotal=(float)acumulador/2;

        }
        printf("la mitad de los numeros es: %.2f", mitadTotal);

    return 0;
}
/*1.	Ingresar 5 números y calcular su media
*/

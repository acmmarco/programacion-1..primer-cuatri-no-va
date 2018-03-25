#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numero1;
    float numero2;
    float cuadradoN1;

    printf("ignrese primer numero\n");
    scanf("%f", &numero1);
    printf("ignrese segundo numero\n");
    scanf("%f", &numero2);

    if(numero1<1 && numero2<1)
        {
            printf("ERROR ignrese primer numero\n");
            scanf("%f", &numero1);
            printf("ERRORignrese segundo numero\n");
            scanf("%f", &numero2);
        }

    cuadradoN1= numero1 * numero1;

    printf("el cuadrado de numero 1 es: %.2f\n", cuadradoN1);
    return 0;
}
/*
3.	Escribir  un programa que realice las siguientes acciones
•	Limpie la pantalla
•	Asigne a 2 variables numero1 y numero2 valores distintos de cero
•	Efectúe el producto de dichas variables
•	Muestre el resultado pos pantalla
•	Obtenga el cuadrado de numero1 y lo muestre par pantalla

*/

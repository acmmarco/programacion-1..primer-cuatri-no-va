#include <stdio.h>
#include <stdlib.h>

int main()
{
    float circunferencia;
    float radio;
    float area;

    printf("pedir radio del circulo\n");
    scanf("%f", &radio);

    circunferencia=2 * 3.14 * radio;
    area= radio*radio*3.14;


    printf("circuferencia es: %.2f\n", circunferencia);
    printf("area es: %.2f\n", area);
    return 0;
}
/*
9.Dise�ar un programa que calcule la longitud de la circunferencia y el �rea del c�rculo de radio dado.
*/

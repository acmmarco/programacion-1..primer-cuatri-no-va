#include <stdio.h>
#include <stdlib.h>

int main()
{
    float base;
    float altura;
    float superficie;

    printf("ingrese base\n");
    scanf("%f", &base);
    printf("ingrese altura\n");
    scanf("%f", &altura);

    superficie=altura * base;

    printf("la superficie del triangulo es: %.2f\n",superficie);
    return 0;
}
/*
10.  	Diseñar un programa que calcule
la superficie de un triángulo a partir del ingreso de su base y altura y
muestre el resultado.
*/

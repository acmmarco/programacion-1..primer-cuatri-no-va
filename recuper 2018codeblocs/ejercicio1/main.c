#include <stdio.h>
#include <stdlib.h>

int main()
{
    float base;
    float altura;
    float superficie;

    printf("ingrese base triangulo");
    scanf("%f", &base);
    printf("ingrese altura triangulo");
    scanf("%f", &altura);

    superficie= base * altura;

    printf("la superficie del triangulo es : %.3f",superficie);

    return 0;
}

/*Bienvenidos.
Realizar el algoritmo que pida la base
 y la altura de un tri�ngulo equil�tero,
 informar la superficie y el per�metro en una sola ventana alert.
*/

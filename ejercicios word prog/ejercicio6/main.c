#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;
    float resultado;

    printf("ingrese primer numero\n");
    scanf("%d", &numero1);
    printf("ingrese segundo numero\n");
    scanf("%d", &numero2);

    resultado= numero1 - numero2;

    if(resultado>0)
        {
            printf("resultador positivo");
        }else if(resultado<0)
        {
            printf("resultado negativo");
        }else
        {
            printf("cero");
        }



    return 0;
}
/*
6.  	Escribir un programa que realice las siguientes acciones:
•	Limpie la pantalla
•	Declare 2 variables y les asigne sendos valores
•	Realice la resta de dichas variables y muestre por pantalla la leyenda "Resultado positivo"
en caso de ser mayor que cero o "Resultado negativo" si es menor que cero

*/

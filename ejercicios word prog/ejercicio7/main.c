#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    float numeroCuadrado;

    printf("ingresar numero\n");
    scanf("%d", &numero);

    if(numero<0)
        {
            printf("ERORR NUMERO MAYOR A 0 ingresar numero\n");
            scanf("%d", &numero);
        }

    numeroCuadrado=numero * numero;

    printf("el cuadrado del numero es. %.2f", numeroCuadrado);



    return 0;
}
/*
7.  	Escribir el programa necesario para calcular y mostrar el cuadrado de un número.
 El número debe ser mayor que cero,
  en caso de error que aparezca el mensaje "ERROR, e
  l número debe ser mayor que cero"
*/

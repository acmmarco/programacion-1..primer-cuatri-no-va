#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contadorNmayor=0;
    int contadorNmenor=0;

    for(int contador=0; contador<10; contador++)
        {
            printf("ingrese 10 numero\n");
            scanf("%d", &numero);

            if(numero>0)
                {
                    contadorNmayor++;
                }
            if(numero<0)
                {
                    contadorNmenor++;
                }
        }//final for


    printf("numeros mayores a 0: %d\nnumeros menores a 0: %d",contadorNmayor, contadorNmenor);

    return 0;
}
/*
  	De 10 números ingresadas indicar cuantos son mayores a cero y cuantos son menores a cero
*/

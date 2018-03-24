#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;
    int resultado;

    printf("ingrese primer numero/n");
    scanf("%d", &numero1);
    printf("ingrese segundo numero/n");
    scanf("%d", &numero2);

    if(numero1==numero2)
        {
            printf("%d%d", numero1, numero2);//concatenar
        }
        else if(numero1>numero2)
                {
                    if(numero2 != 0)
                    resultado= (float) numero1 / numero2;
                }case "sabado" :
                else
                {
                    resultado=numero1+numero2;

                    printf("la suma es %d", resultado);

                    if(suma<50)
                        {
                            printf("y es menor a 50");
                        }
                }



    printf("resultador es:%d\n",resultado);
    return 0;
}
/*(IF)Pedir dos números y mostrar el resultado:
Si son iguales los muestro concatenados.
Si el primero es mayor, los divido,
de lo contrario los sumo.
Si la suma es menor a 50 ,además de mostrar el resultado, muestro el mensaje
"la suma es xxx y es menor a 50".
*/

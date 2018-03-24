#include <stdio.h>
#include <stdlib.h>


int main()
{
    char sexo;
    int edad;
    float nota;
    float acumulador=0;
    float contador;
    float promedio;
    float maximo;
    float minimo;
    float contadorNotaMayor6=0;

    for(contador=0; contador<5; contador++)
        {
            printf("ingrese nota");
            scanf("%d", &nota);
            acumulador=acumulador+nota;

            while(nota<0 || nota>10)
                {
                    printf("ERROR ingrese nota");
                    scanf("%f", &nota);
                }
            printf("ingrese edad");
            scanf("%d", &edad);
            while(edad<=0)
                {
                    printf("ERROR ingrese edad");
                    scanf("%d", &edad);
                }

            printf("ingrese sexo f o m");
            scanf("%c", &sexo);

            while(sexo!='f' && sexo!='m')
                {
                    printf("ERROR ingrese sexo f o m");
                    scanf("%c", &sexo);
                }

    if(contador==1)
        {
            maximo=nota;
            minimo=nota;
        }
        else
        {
            if(nota>maximo)
            {
                maximo=nota;
            }
            if(nota<minimo)
            {
                minimo=nota;
            }
        }
        if(nota>6)
            {
                contadorNotaMayor6++;
            }
        }//final for
    promedio=acumulador/contador;
    printf("el promedio de las notas es:%.2f\n el minimo es:%.2f /n el maximo es: %.2f /n cantidad de var mayor 6 es:%.2f",promedio, minimo , maximo,contadorNotaMayor6);
    return 0;
}
/*Realizar el algoritmo que permita el ingreso por prompt de las notas
(validar entre 0 y 10),la edad y el sexo (validar el sexo “f” o “m”) de 5 alumnos,
informar por alert:
a) El promedio de las notas totales.
b) La nota más baja y el sexo de esa persona.
c) La cantidad de varones mayores a 18, que su nota haya sido mayor o igual a 6.
d) El sexo y la nota del más joven
d) La edad y la nota de la primera mujer ingresada o informar si no hubo ninguna mujer.
*/

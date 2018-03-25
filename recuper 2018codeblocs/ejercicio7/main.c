#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sexo;
    int edad;
    int nota;
    int acumuladorNotas=0;
    int contador;
    float promedio;
    int contadorNotaMayor6=0;
    int notaMasBaja;
    int flag=0;
    char sexoMasBajo;
    int varMayor18Aprobado6=0;
    char EdadMasJoven;
    int notaMasJoven;
    char sexoMasjoven;
    int flagMasJoven=0;

    for(contador=0; contador<3; contador++)
        {
            printf("ingrese nota\n");
            scanf("%d", &nota);
            while(nota<0 || nota>10)
                {
                    printf("ingrese nota\n");
                    scanf("%d", &nota);
                }

            printf("ingresar edad\n");
            scanf("%d", &edad);
            while(edad<0)
                {
                    printf("ERRORingresar edad\n");
                    scanf("%d", &edad);
                }

            printf("ingrese sexo f o m\n");
            scanf("%c", &sexo);
            sexo=tolower(sexo);
            while(sexo!='f' && sexo!= 'm')
                {
                    scanf("%c", &sexo);
                    sexo=tolower(sexo);
                }
            if(nota<notaMasBaja || flag==0)
                {
                    notaMasBaja=nota;
                    sexoMasBajo=sexo;
                    flag=1;
                }
            if(nota>5&& edad>18 && sexo== 'm')
                {
                    varMayor18Aprobado6++;
                }
            if(edad<EdadMasJoven || flagMasJoven==0)
                {
                    EdadMasJoven=edad;
                    notaMasJoven=nota;
                    sexoMasjoven=sexo;
                    flagMasJoven=1;

                }


            acumuladorNotas=acumuladorNotas+nota;





        }//final for
        promedio=(float)acumuladorNotas/contador;
        printf("el promedio de las notas es: %.2f\n", promedio);
        printf("la nota mas baja es: %d\n y el sexo es: %c\n",notaMasBaja,sexoMasBajo);
        printf("la cantidad de varones mayores 18 y aprobados con 6 o mas : %d \n",varMayor18Aprobado6);
        printf("El sexo y la nota del más joven: %d &d &c",EdadMasJoven,notaMasJoven,sexoMasjoven);
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

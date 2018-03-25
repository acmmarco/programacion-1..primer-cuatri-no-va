#include <stdio.h>
#include <stdlib.h>

int main()
{
    //strcpy
    char diaSemana[100];

    printf("ingrese un dia de semana");
    scanf("%s", diaSemana);

    switch(diaSemana)
    {
        case "sabado" :
        case "domingo" :
            printf("buen finde");
            break;
        case "lunes" :
        case "martes" :
        case "miercoles" :
        case "jueves" :
        case "viernes" :
            printf("a trabajar");
            break;
        default:
            printf("no es valido");
    }

    return 0;
}
/*Bienvenidos.
(SWITCH)pedir el ingreso de un día de la semana,
si es fin de semana mostrar " buen finde",
si es día hábil “ a trabajar”,
si no es un día valido, también informarlo,
usar una sola ventana alert.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota;

    printf("ingrse nota");
    scanf("%d", &nota);

    switch(nota)
    {
        case 0 :
        case 1 :
        case 2 :
        case 3 :
            printf("la proxima se puede");
            break;
        case 4 :
        case 5 :
        case 6 :
            printf("raspando");
            if(nota>5)
                {
                 printf("debes esforzarte mas.\n");
                }
                break;
        case 7 :
        case 8 :
        case 9 :
        case 10 :
            printf("aprobo");
            if(nota>8)
                {
                    printf("muy bien\n");
                }
                break;
        default:
            printf("no es valido");
    }



    return 0;
}
/*
Bienvenidos.
Se ingresa una nota.
Si est� entre las 0 y las 3 mostrar: "la pr�xima se puede",
si es desde las 4 a las 6: "raspando", de lo contrario informar que aprob�.
Informar si la nota no es v�lida.
Si es aprob� y la nota es mayor a 8 se debe agregar el mensaje: "muy bien".
Si es nota para �raspando� y la nota es menor a 5 se debe agregar el mensaje: "debes preocuparte m�s".
Aclaraci�n: hacer un switch y dentro toda la l�gica incluyendo los if y con una sola ventana alert.
*/

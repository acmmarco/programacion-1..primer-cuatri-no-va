#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[20];
    char localidad[20];

    printf("ingrese su nombre/n");
    scanf("%s", nombre);//gets(nombre);
    printf("ingrese su localidad/n");
    scanf("%s", localidad);

    printf("usted es %s /n y vive en:%s" , nombre , localidad);


    return 0;
}
/*Bienvenidos.
Mostrar * en un solo alert *
 el mensaje "usted es xxxxx
 y vive en la localidad de xxxxxxxx".

*/

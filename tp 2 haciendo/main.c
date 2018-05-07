#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

#define TAM 20

int main()
{
    char seguir='s';
    EPersona persona[TAM];
    inicializadorPersonas(persona,TAM);

    while(seguir=='s')
    {
        switch(menu())
        {
        case 1:
            altaPersona(persona, TAM);
            system("pause");
            system("cls");
            break;
        case 2:
            bajaPersona(persona, TAM);
            system("pause");
            system("cls");
            break;
        case 3:
            mostrarPersonas(persona, TAM);
            system("pause");
            system("cls");
            break;
        case 4:
            graficosEdades(persona, TAM);
            system("pause");
            break;
        case 5:
            seguir = 'n';
            system("pause");
            break;
        default:
            printf("elija opcion del 1 al 5\n");
            system("pause");
        }
    }

    return 0;
}

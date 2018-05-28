#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    int estado;
} Eempleado;


void empleadoSetLegajo(Eempleado* empleado, int legajo);

int main()
{
    Eempleado* unEmpleado;

    unEmpleado= (Eempleado*)malloc(sizeof(Eempleado));

    if(unEmpleado== NULL)
    {
        printf("no se pudo reservar espacion en la memoria\n\n");
        exit(1);
    }

    unEmpleado->legajo =1234;
    strcpy(unEmpleado->nombre, "juan");
    unEmpleado->sueldo=20000;
    unEmpleado->estado=1;

    printf("%d %s %.2f \n\n", unEmpleado->legajo,unEmpleado->nombre,unEmpleado->sueldo),

           free(unEmpleado);


    return 0;
}

void empleadoSetLegajo(Eempleado* empleado, int legajo)
{
    if(empleado!= NULL && legajo>0)
    {
        empleado->legajo = legajo;//proteccion para no agragar cualquier legajo
    }
}

int empleadoGetLegajo(Eempleado* empleado)
{
    int legajo = -1;

    if(empleado != NULL)
        {
            legajo= empleado->legajo;
        }


    return legajo;
}

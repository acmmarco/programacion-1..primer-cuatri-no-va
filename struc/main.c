#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;

} eEmpleado;

void mostrarEmpleado(eEmpleado);
eEmpleado cargarEmpleado();

int main()
{
    eEmpleado unEmpleado = {1234, "juan", 'm', 25000.50};
    eEmpleado otroEmpleado;
    eEmpleado emp3;

    mostrarEmpleado(unEmpleado);

    otroEmpleado.legajo=4321;
    strcpy(otroEmpleado.nombre, "jose");
    otroEmpleado.sexo='m';
    otroEmpleado.sueldo=3000.22;

    printf("\n\n");

    mostrarEmpleado(otroEmpleado);

    printf("\n\n");


    emp3= cargarEmpleado();
    mostrarEmpleado(emp3);

    return 0;
}
void mostrarEmpleado(eEmpleado emp)
{
    printf("legajos: %d\n", emp.legajo);
    printf("nombre: %s\n", emp.nombre);
    printf("sexo: %c\n", emp.sexo);
    printf("sueldo: %.2f \n", emp.sueldo);
}

eEmpleado cargarEmpleado()
{
    eEmpleado emp;

    printf("ingrese legajo\n");
    scanf("%d", &emp.legajo);

    printf("ingrese nombre\n");
    fflush(stdin);
    gets(emp.nombre);

    printf("ingrese sexo\n");
    fflush(stdin);
    scanf("%c", &emp.sexo);

    printf("ingrese sueldo\n");
    scanf("%f", &emp.sueldo);


    return emp;
}

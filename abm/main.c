#include <stdio.h>
#include <stdlib.h>

#define TAM 2

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaDeIngreso;
    int isEmpty;
} eEmpleado;


void altaEmpleado(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajos);
int buscarLibre(eEmpleado vec[], int tam);
void mostrarEmpleado(eEmpleado);
void mostrarEmpleado(eEmpleado);
eEmpleado cargarEmpleado();
void mostrarEmpleados(eEmpleado gente[], int tam);


int menu();

void inicializarEmpleados(eEmpleado vec[], int tam);

int main()
{
    int salir=0;

    eEmpleado gente[TAM];

    inicializarEmpleados(gente, TAM);

    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(gente,TAM);
            system("pause");
            break;
        case 2:
            //baja
            system("pause");
            break;
        case 3:
            printf("ingreso 3\n");
            system("pause");
            break;
        case 4:
            mostrarEmpleados(gente,TAM);
            system("pause");
            break;
        case 5:
            printf("ingreso 5\n");
            system("pause");
            break;
        case 6:
            printf("ingreso 6\n");
            salir=1;
            system("pause");

            break;
        default:
            printf("ingrese numeros del 1 al 6");
            system("pause");

        }
    }
    while(salir!=1);



    return 0;
}

int menu()
{
    int opcion;



    system("cls");

    printf("********* abm empleados **********\n\n");

    printf("elegir opcion\n");
    printf("1-alta\n");
    printf("2-bajas\n");
    printf("3-modificacion\n");
    printf("4-listar\n");
    printf("5-ordenar\n");
    printf("6-salir\n");



    scanf("%d",&opcion );





    return opcion;

}
void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for (int i =0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }

}
void mostrarEmpleado(eEmpleado emp)
{
    printf("legajos: %d\n", emp.legajo);
    printf("nombre: %s\n", emp.nombre);
    printf("sexo: %c\n", emp.sexo);
    printf("sueldo: %.2f \n", emp.sueldo);
    printf("\n\n");
}



eEmpleado cargarEmpleado()
{
    eEmpleado emp;

    printf("ingrese legajo\n");
    fflush(stdin);
    scanf("%d", &emp.legajo);

    printf("ingrese nombre\n");
    fflush(stdin);
    gets(emp.nombre);

    printf("ingrese sexo\n");
    fflush(stdin);
    scanf("%c", &emp.sexo);

    printf("ingrese sueldo\n");
    scanf("%f", &emp.sueldo);

    printf("\n\n");
    fflush(stdin);


    return emp;
}
void mostrarEmpleados(eEmpleado gente[], int tam)
{
    for (int i =0; i<tam; i++)
    {
        mostrarEmpleado(gente[i]);
    }
}

int buscarLibre(eEmpleado vec[], int tam)
{

    int indice= -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            indice=1;
            break;
        }

    }
    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{
    int indice= -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0 && vec[i].legajo == legajo)
        {
            indice=1;
            break;
        }
    }
    return indice;
}

void altaEmpleado(eEmpleado vec[], int tam)
{

    eEmpleado nuevoEmpleado;
    int indice;
    int esta;
    int legajo;

    system("cls");
    printf("---- alta empleado----\n\n");

    indice =buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta a empleados nuevos.\n\n");
    }
    else
    {
        printf("ingrese legajo");
        scanf("%d", &legajo);

        esta=buscarEmpleado(vec, tam, legajo);

        if(esta !=-1)
        {
            printf("el legajo %d ya esta dado de alta en el sistema", legajo);
            mostrarEmpleado(vec[esta]);
        }
        else
        {
            nuevoEmpleado.isEmpty=0;
            nuevoEmpleado.legajo=legajo;

            printf("ingrese legajo\n");
            fflush(stdin);
            scanf("%d", &nuevoEmpleado.legajo);

            printf("ingrese nombre\n");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("ingrese sexo\n");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);

            printf("ingrese sueldo\n");
            scanf("%f", &nuevoEmpleado.sueldo);

            printf("ingrese fecha de ingreso d m a :\n");
            scanf("%d %d %d", &nuevoEmpleado.fechaDeIngreso.dia,&nuevoEmpleado.fechaDeIngreso.mes,&nuevoEmpleado.fechaDeIngreso.anio);

            vec[indice] = nuevoEmpleado;
            printf("alta exitosa !!! \n\n");

        }


        }

    }




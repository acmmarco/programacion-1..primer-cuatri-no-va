#include <stdio.h>
#include <stdlib.h>

void mostrarEmpleados(char x[][20], int cant, int l);
int main()
{
    char nombres[5][20];
    int legajos;
    char sexo;
    float sueldos;


    for (int i = 0 ; i <5; i++)
        {
            fflush(stdin);
            printf("ingrese  nombres\n");
            gets(nombres[i]);
            printf("ingrese  legajos\n");
            scanf("%d",&legajos);

        }

    mostrarEmpleados(nombres,legajos, 5);
    return 0;
}
void mostrarEmpleados(char x[][20], int cant, int l)
{
    printf("\n\n");
    for (int i = 0 ; i <cant; i++)
        {
            mostrarNombre(x[i], l[i]);
        }
    printf("\n\n");
}
void mostrarNombre(char nombre[], int le)
{
    printf("%s %d\n", nombre, le);
}

/*

            printf("ingrese  sexo\n 'm' o 'f'");
            fflush(stdin);
            scanf("%c", &sexo);
            printf("ingrese  sueldos\n");
            scanf("%f",&sueldos);


*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombreLibro[20];
    int cantidadPaginas;
    int cantidadVentas;
    char temaLibro[20];
    char respuesta='s';
    int contador=0;

    while(respuesta!='n')
    {
        printf("ingrese nombre del libro\n");
        scanf("%s", nombreLibro);


        contador++;
        printf("desea continuar ? s=si n=no");
        scanf("%c", &respuesta);
    }//final for

    return 0;
}
/*
Realizar el algoritmo que permita iterar el ingreso de varios libros
con cuatro datos por cada libro, nombre, cantidad de p�ginas, cantidad de ventas (0 o m�s)
y tema (posibles temas: �rob�tica", "programaci�n", "patrones", "base de datos�)
validar e ingresar datos hasta que el usuario quiera e informar al terminar el ingreso por document.write:
a) La cantidad de libros con p�ginas pares.
b) La cantidad de libros con p�ginas impares.
c) La cantidad de ceros ventas.
d) El promedio de todas las ventas ingresadas.
e) La suma de todas las p�ginas de los de "programaci�n".
*/

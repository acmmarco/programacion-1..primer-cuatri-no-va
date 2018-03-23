#include <stdio.h>
#include <stdlib.h>

int main()
{
    float precio;
    float descuento;
    float precioDescuento;
    float precioIva;
    int iva;
    float precioTotal;

    printf("ingrese precio/n");
    scanf("%f", &precio);
    printf("ingrese porcentaje descuento/n");
    scanf("%f", &descuento);

    descuento=(precio * descuento)/100;
    precioDescuento=precio - descuento;
    iva= 21;
    precioIva= (precioDescuento * 21) /100;
    precioTotal=precioDescuento-precioIva;


    printf("el descuento es de: %.0f\n , el precio con el descuento es:%.0f , el iva es:%d y el precio total es:%.0f",descuento, precioDescuento, iva , precioTotal );
    return 0;
}
/*Bienvenidos.
Pedir por prompt el precio
y el porcentaje de descuento, mostrar:
1-El descuento en dinero,
2-El precio con el descuento ,
3-El IVA
todos los anteriores e un solo alert
4-Y solo el precio con descuento más el IVA por id .
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idTipo;
    char descripcion[20];
} eTipo;

typedef struct
{
    int id;
    char nombre[20];
    int edad;
    eTipo tipo;
    int estado; // 1 lleno 0 vacio

} eMascota;

void modificarEdad(eMascota* x, int edad);
void mostrarMascota( eMascota* mascota);
void mostrarMascotas(eMascota*  mascota, int);
 void cargarMascota(eMascota* mascota);

int main()
{
    //eMascota unaMascota;

    eMascota grupoMascota[3]= {{1111,"leilol",3,{1,"ave"},1},{2222,"zapallo",4,{2,"conejo"},1},{3333,"goku",3,{3,"tortuga"},1},{1111,"wachi",3,{1,"lombis"},1},{2222,"pera",4,{2,"cangrejo"},1}};

    //(grupoMascota)->estado=0;
    (grupoMascota+3)->estado=0;
    (grupoMascota+4)->estado=0;
    mostrarMascotas(grupoMascota,3);
    cargarMascota(grupoMascota);



    /*
        unaMascota.id =1234;
        strcpy(unaMascota.nombre, "colita"),

        modificarEdad(&unaMascota,20);

        printf("%d-- %s-- %d-- %s\n\n",unaMascota.id, unaMascota.nombre, unaMascota.edad, unaMascota.tipo.descripcion);
    */
    return 0;
}
void modificarEdad(eMascota* x, int edad)
{
    x->edad=edad;

    strcpy(x->tipo.descripcion, "ave");
}
void mostrarMascota( eMascota* mascota)
{
    printf("la moscotas son : %d-- nombre:%s-- edad:%d-- %d-- descripcion:%s\n\n", mascota->id, mascota->nombre, mascota->edad, mascota->tipo.idTipo, mascota->tipo.descripcion);
}
void mostrarMascotas(eMascota*  mascota, int tam)
{
    if(mascota != NULL)
    {
        for(int i=0; i< tam; i++)
        {
            if((mascota+i)->estado ==1)
            {
                mostrarMascota(mascota+i);
            }
        }
    }
}

void cargarMascota(eMascota* mascota)
{
    int ok=0;

    if(mascota != NULL)
    {
        printf("ingrese datos del animal!!\n\n");

        printf("ingrese id: \n");
        scanf("%d", mascota->id );

        printf("ingrese nombre: \n");
        fflush("stdin");
        gets(mascota-> nombre);

        printf("ingrese edad: \n");
        scanf("%d", mascota-> edad);

        mascota->estado=1;

    }
}

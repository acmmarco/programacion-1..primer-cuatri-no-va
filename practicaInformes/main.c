#include <stdio.h>
#include <stdlib.h>

#define TAM 4

typedef struct
{
    int legajo;
    char nombre[20];
} eAlumno;

typedef struct
{
    int codigo;
    char descripcion[20];
} eMateria;

typedef struct
{
    int legAlumno;
    int codMateria;
} eInscripcion;

void mostrarAlumnosConMaterias(eAlumno vecAlumno[], int tamAlumnos, eInscripcion vecIncripcion[], int tamInscripcion, eMateria vecMateria[], int tamMateria);
void mostrarMateriasConCantidadDeInscriptos(eInscripcion ins[], int tamI, eMateria mat[], int tamM);
int cantidadDeInscriptos(int materia, eInscripcion ins[], int tam);
void mostrarMateriasConCantidadDeInscriptos(eInscripcion ins[], int tamI, eMateria mat[], int tamM);
void mostrarMateriasConCantidadDeInscriptos(eInscripcion ins[], int tamI, eMateria mat[], int tamM);

int main()
{
    eMateria materias[]= {{1, "programaion"}, {2,"spd"}, {3, "matematica"}, {4, "ingles"}};
    eAlumno alumnos[]= {{10, "Juan"},{20, "ana"},{30, "ella"},{40, "trozo"}};
    eInscripcion inscripciones[]= {{10,2},{10,1},{10,3},{20,2},{30,2},{30,1},{20,1}};

   // mostrarAlumnosConMaterias(alumnos,4 ,inscripciones,7 ,materias,4 );
    //mostrarMateriasConCantidadDeInscriptos(inscripciones, 7, materias,4);
    mostrarMateriasConSusAlumnos(alumnos,4 , inscripciones,7 , materias,4);

    return 0;
}

void mostrarAlumnosConMaterias(eAlumno vecAlumno[], int tamAlumnos, eInscripcion vecIncripcion[], int tamInscripcion, eMateria vecMateria[], int tamMateria)
{
    for(int i = 0; i<tamAlumnos ; i++)
    {
        printf("\n%s\n\n", vecAlumno[i].nombre);

        for(int j = 0; j<tamInscripcion ; j++)
        {
            if(vecAlumno[i].legajo == vecIncripcion[j].legAlumno)
            {
                for(int k = 0; k<tamMateria ; k++)
                {
                    if(vecIncripcion[j].codMateria== vecMateria[k].codigo)
                        printf("%s \n", vecMateria[k].descripcion);
                }
            }
        }

    }//primer for alumnos,, final
}

void mostrarMateriasConCantidadDeInscriptos(eInscripcion ins[], int tamI, eMateria mat[], int tamM)
{
    int cantidad;

    printf("\cantidad de alumnos inscriptos por materia---\n\n");

    for(int i=0; i<tamM; i++)
        {
            printf("\t%s:", mat[i].descripcion);
            cantidad=cantidadDeInscriptos(mat[i].codigo, ins, tamI);

            printf("%d\n\n", cantidad);
        }


}

int cantidadDeInscriptos(int materia, eInscripcion ins[], int tam)
{
    int cantidad = 0;

    for(int i=0; i<tam; i ++)
        {
            if(ins[i].codMateria == materia)
                {
                    cantidad++;
                }
        }
        return cantidad;
}
void mostrarMateriasConSusAlumnos(eMateria materia[], int tamMat, eInscripcion ins[], int tamIns, eAlumno alum[], int tamAlum)
{
    for(int i=0; i<tamMat; i++)
        {
            printf("%s \n", materia[i].descripcion);
        }

}

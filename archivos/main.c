#include <stdio.h>
#include <stdlib.h>
#define PATH "C:\\Users\\alumno\\Desktop\\ejemplo\\miArchivo.txt"

int main()
{
    FILE* pArchivo;
    char cadena[100]= "me fui";
    char cadena2[100]="otro texto";

    pArchivo = fopen(PATH,"w");//1direccion fisica directorio se crea o se busca archivos......w modo escritorio// fopen devuelve un puntero fine o null
    if(pArchivo!= NULL)        //modo a escribe todo seguido pero no crea directorio
    {
        fprintf(pArchivo,"1");//imprimir texto sobre la consola
        fprintf(pArchivo,cadena);
        fprintf(pArchivo, " aca con mascara: %s-- %d",cadena2,156 );//con formato
        fclose(pArchivo);//cerrar archivo.
    }
    else
    {
        printf("imposile guardar en escritorio");
    }

    pArchivo= fopen(PATH,"r");//r lectura
    if(pArchivo!= NULL)
    {
        while(!feof(pArchivo))
        {
            fgets(cadena,100,pArchivo);
            printf("\n %s", cadena);
        }
        //leer texots desde el archivo// 100 cantidad de caracteres que va a leer.. lee una linea
        fclose(pArchivo); //puts(cadena);// como print f sin formato
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2, n3, n4;

    int cant;

    FILE* f;

    f = fopen("archivo.txt", "r");

    if(f== NULL)
    {
        printf("error al abrir el archivo\n");
        exit(1);
    }

    while(! feof(f))
    {
        cant = fscanf(f,"%d,%d,%d,%d,\n", &n1, &n2, &n3, &n4);


        if(cant !=4)
        {
            if(feof(f))
            {
                break;
            }
            else
            {
                printf("problema al leer el archivo\n");
                break;
            }
        }
        printf("n1=%d n2=%d n3=%d n4=%d\n",n1,n2,n3,n4);

    }
        printf("\n\n");
        fclose(f);
    return 0;
}

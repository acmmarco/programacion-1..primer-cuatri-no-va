#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra[100];
    int contadorA=0;
    int contadorE=0;
    int contadorI=0;
    int contadorO=0;
    int contadorU=0;
    int contadorVocales=0;


    for(int contador=0;contador<1;contador++)
        {
            printf("ingrese 20 characteres \n");
            scanf("%s", letra);

          switch(letra[contadorA])
          {
            case 'a' :
                contadorA++;
                printf("el total de a es:%d\n",contadorA);
                break;
            case 'e' :
                contadorE++;
                printf("el total de a es:%d\n",contadorE);
                break;
            case 'i' :
            case 'o':
            case 'u' :
                break;
          }
            /*if(letra[a]=='a'|| letra[e]=='e' || letra[i]=='i' || letra[o]=='o' || letra[u]=='u')
            {
                contadorVocales++;

            }
             */


        }//final for







    printf("el total de e es:%d\n",contadorE);
    printf("el total de i es:%d\n",contadorI);
    printf("el total de o es:%d\n",contadorO);
    printf("el total de u es:%d\n",contadorU);
    return 0;
}

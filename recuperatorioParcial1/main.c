#include <stdio.h>
#include <stdlib.h>

#define TAM 50
#define TAMPROV 6

typedef struct
{
    int codigoProveedor;
    char descripcionProducto[50];

} eProveedor;

typedef struct
{
    int codigoProducto;
    char descripcionProduto[50];
    float importe;
    int cantidad;
    int idProveedor;
    int estado;

} eProducto;

int menu();
int obtenerEspacioLibre(eProducto lista[], int tam);
void inicializadorPersonas(eProducto lista[], int tam );
int buscarProducto(eProducto lista[], int tam, int codigo);
void mostrarProducto(eProducto prod, eProveedor proveedores[], int tam);
void mostrarProductos(eProducto lista[], int tamProduc, eProveedor proveedores[],int tamProv);
void altaProducto(eProducto lista[], int tamProduc, eProveedor proveedores[], int tamProveed);
void bajaProducto(eProducto vec[], int tam, eProveedor proveedores[], int tamProv);
void modificacionProducto(eProducto vec[], int tamProduc, eProveedor proveedores[], int tamProv);

int main()
{
    eProducto producto[TAM];
    eProveedor proveedores[]= {{1, "coto"}, {2,"morres"}, {3, "fravega"}, {4, "nicart"}, {5, "potable"}, {6, "alectro"}};
    char seguir= 's';
    while(seguir=='s')
    {
        switch(menu())
        {
        case 1:
            altaProducto(producto, TAM, proveedores, TAMPROV);
            system("pause");
            system("cls");
            break;
        case 2:
            bajaProducto(producto, TAM, proveedores, TAMPROV);
            //mostrarProductos(producto,TAM,proveedores,TAMPROV);
            system("pause");
            system("cls");
            break;
        case 3:
            modificacionProducto(producto, TAM, proveedores, TAMPROV);
            //mostrarPersonas(persona, TAM);
            system("pause");
            system("cls");
            break;
        case 4:
            mostrarProductos(producto, TAM, proveedores, TAMPROV);
            //graficosEdades(persona, TAM);
            system("pause");
            system("cls");
            break;
        case 5:
            seguir = 'n';
            system("pause");
            break;
        default:
            printf("elija opcion del 1 al 5\n");
            system("pause");
            system("cls");
        }
    }

    return 0;
}
int menu()
{
    int opcion;

    system("cls");
    printf("      ---ABM Empleados---\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Listar\n");
    printf("5- Ordenar\n");
    printf("6- Total sueldos\n");
    printf("7- Empleados que mas ganan\n");
    printf("8- Mostrar empleados x sector\n");
    printf("9- Informar cuantos empleados hay en cada sector\n");
    printf("10-Informar total de sueldos x Sector\n");
    printf("11-Salir\n");

    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
void inicializadorPersonas(eProducto lista[], int tam )
{
    for(int i = 0; i<tam ; i++ )
    {
        lista[i].estado=1;
    }

}
int obtenerEspacioLibre(eProducto lista[], int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            indice=i;
            break;
        }

    }
    return indice;
}
int buscarProducto(eProducto lista[], int tam, int codigo)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(lista[i].estado == 0 && lista[i].codigoProducto == codigo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarProductos(eProducto lista[], int tamProduc, eProveedor proveedores[],int tamProv)
{
    system("cls");
    printf("      ---Lista de productos---\n\n");
    printf("  codigo    cantidad     descripcion    importe ----  proveedores \n\n");
    for(int i=0; i< tamProduc; i++)
    {
        if(lista[i].estado ==0)
        {
            mostrarProducto(lista[i], proveedores, tamProv);
        }
    }
}

void mostrarProducto(eProducto prod, eProveedor proveedores[], int tam)// mostrar productos
{
    int indice;
    for(int i=0; i< tam; i++)
    {
        if(prod.idProveedor == proveedores[i].codigoProveedor )
        {
            indice = i;
            break;
        }
    }
    printf("  %8d-- %10s-- %3d-- %.2f ---   --- %s\n",prod.codigoProducto,prod.descripcionProduto,  prod.cantidad, prod.importe,proveedores[indice].descripcionProducto);
}

void altaProducto(eProducto lista[], int tamProduc, eProveedor proveedores[], int tamProveed)
{

    eProducto nuevoProducto;
    int indice;
    int esta;
    int codigoProduc;

    system("cls");
    printf("---Alta productos---\n\n");

    indice = obtenerEspacioLibre(lista, tamProduc);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta a empleados nuevos.\n\n");
    }
    else
    {
        printf("Ingrese codigo del producto: ");
        scanf("%d", &codigoProduc);

        esta = buscarProducto(lista, tamProduc, codigoProduc);

        if(esta != -1)
        {
            printf("\nEl legajo %d ya esta dado de alta en el sistema\n", codigoProduc);
            mostrarProducto(lista[esta], proveedores, tamProveed);
        }
        else
        {
            nuevoProducto.estado = 0;
            nuevoProducto.codigoProducto = codigoProduc;

            printf("Ingrese descripcion del producto: ");
            fflush(stdin);
            gets(nuevoProducto.descripcionProduto);

            printf("Ingrese cantidad de productos: ");
            scanf("%d", &nuevoProducto.cantidad);

            printf("Ingrese importe del producto: ");
            scanf("%f", &nuevoProducto.importe);

            nuevoProducto.idProveedor = pedirProveedor(proveedores, tamProveed);
            lista[indice] = nuevoProducto;

            printf("\nAlta exitosa!!!\n\n");

        }
    }

}

int pedirProveedor(eProveedor proveedores[], int tam)
{

    int idProv;

    printf("proveedores\n\n");

    for(int i=0; i< tam; i++)
    {
        printf("%d- %s\n", proveedores[i].codigoProveedor, proveedores[i].descripcionProducto );
    }
    printf("\nIndique proveedor: ");
    fflush(stdin);
    scanf("%d", &idProv);

    return idProv;
}
void bajaProducto(eProducto vec[], int tam, eProveedor proveedores[], int tamProv)
{
    int codigo;
    int esta;
    char confirma;

    system("cls");
    printf("---Baja producto---\n\n");

    printf("Ingrese codigo del producto: ");
    scanf("%d", &codigo);

    esta = buscarProducto(vec, tam, codigo);

    if(esta == -1)
    {
        printf("\nEl codigo del producto %d no se encuentra en el sistema\n\n", codigo);

    }
    else
    {

        mostrarProducto(vec[esta], proveedores, tamProv);

        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            vec[esta].estado = 1;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }

    }
}
void modificacionProducto(eProducto vec[], int tamProduc, eProveedor proveedores[], int tamProv)
{
    int codigo;
    int esta;
    char confirma;
    float importe;
    char descripcion[50];
    int cantidad;

    system("cls");
    printf("---Modificacion producto---\n\n");

    printf("Ingrese codigo de producto: ");
    scanf("%d", &codigo);

    esta = buscarProducto(vec, tamProduc, codigo);

    if(esta == -1)
    {
        printf("\nEl codigo %d no se encuentra en el sistema\n\n", codigo);

    }
    else
    {

        mostrarProducto(vec[esta], proveedores, tamProduc);

        //printf("\nIngrese nueva descripcion: ");
        //scanf("%s", descripcion);
        printf("\nIngrese nueva cantidad: ");
        scanf("%d", &cantidad);
        printf("\nIngrese nuevo importe: ");
        scanf("%f", &importe);




        printf("\nConfirma Modificacion?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
           // vec[esta].descripcionProduto = descripcion;
            vec[esta].importe=importe;
            vec[esta].cantidad=cantidad;
            printf("\nSe ha modificado la lista\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la modificacion\n\n");
        }

    }
}



int menu()
{
    int opcion;

    system("cls");
    printf("\n*** Menu de Opciones ***\n\n");
    printf(" 1-  Alta\n");
    printf(" 2-  Baja\n");
    printf(" 3-  Modificacion\n");
    printf(" 4-  Listar Empleados\n");
    printf(" 5-  Ordenar Empleados\n");
    printf(" 6-  Mostrar Empleados x Sector\n");
    printf(" 7-  Ordenar Empleados x Sector y Nombre\n");
    printf(" 8-  Listar empleados ganadores\n");
    printf(" 9-  Listar Comidas\n");
    printf(" 10- Alta Almuerzo\n");
    printf(" 11- Mostrar Almuerzos\n");
    printf(" 20- Salir\n\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
void cargarSectores(eSector sectores[])
{
    eSector sec[]=
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };

    for(int i=0; i < 5; i++)
    {
        sectores[i] = sec[i];
    }
}

void cargarComidas(eComida comidas[])
{
    eComida food[]=
    {
        {1, "Milanesa"},
        {2, "Pizza"},
        {3, "Ensalada"},
        {4, "Pescado"},
        {5, "Lasagna"}
    };

    for(int i=0; i < 5; i++)
    {
        comidas[i] = food[i];
    }
}

void listarComidas(eComida c[], int tam)
{
    printf("\nLista de comidas\n\n");

    for(int i=0; i < tam; i++)
    {
        printf(" %d  %10s\n",c[i].id, c[i].descripcion);
    }
    printf("\n\n");
}

void altaAlmuerzo(eAlmuerzo* a, int tama, eComida c[], int tamc, eEmpleado e[], int tame, eSector s[], int tams, int* pId)
{
    int idAlmuerzo = *pId;
    int legajo;
    int idComida;
    efecha fecha;
    eAlmuerzo nuevoAlmuerzo;
    int indice;

    indice = buscarLibreAlmuerzo(a, tama);

    if(indice == -1)
    {
        printf("No se pueden cargar mas almuerzos\n\n");
    }
    else
    {
        nuevoAlmuerzo.id = idAlmuerzo;

        mostrarEmpleados(e, tame, s, tams);

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        nuevoAlmuerzo.idEmp = legajo;

        listarComidas(c, tamc);
        printf("Ingrese comida: ");
        scanf("%d", &idComida);

        nuevoAlmuerzo.idComida = idComida;

        printf("\nIngrese dia: ");
        scanf("%d", &fecha.dia);

        printf("Ingrese mes: ");
        scanf("%d", &fecha.mes);

        printf("Ingrese anio: ");
        scanf("%d", &fecha.anio);

        nuevoAlmuerzo.fecha = fecha;

        nuevoAlmuerzo.isEmpty = 0;

        a[indice] = nuevoAlmuerzo;

        *pId = idAlmuerzo + 1;
    }
}

int buscarLibreAlmuerzo(eAlmuerzo lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void inicializarAlmuerzos(eAlmuerzo lista[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}

void mostrarAlmuerzos(eAlmuerzo a[], int tama, eComida c[], int tamc, eEmpleado e[], int tame)
{
    int flag = 0;

    system("cls");
    printf("id   fecha   Legajo   Nombre    Comida\n\n");

    for(int i=0; i < tama; i++)
    {
        if( a[i].isEmpty == 0)
        {
            mostrarAlmuerzo(a[i], c, tamc, e, tame);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay almuerzos cargados");
    }
    printf("\n\n");
}


void mostrarAlmuerzo(eAlmuerzo unAlmuerzo, eComida c[], int tamc, eEmpleado e[], int tame)
{
    char descComida[20];
    int indice;
    eEmpleado empleado;

    obtenerDescComida(c, tamc, unAlmuerzo.idComida, descComida);
    indice = buscarEmpleado(e, tame, unAlmuerzo.idEmp);

    empleado = e[indice];

    printf("%4d %02d/%02d/%d  %d %10s  %10s\n", unAlmuerzo.id, unAlmuerzo.fecha.dia, unAlmuerzo.fecha.mes, unAlmuerzo.fecha.anio, empleado.legajo, empleado.nombre, descComida);
}

void obtenerDescComida(eComida c[], int tamc, int idComida, char* cadena)
{
    for(int i=0; i < tamc; i++)
    {
        if( c[i].id == idComida)
        {
            strcpy(cadena, c[i].descripcion);
        }
    }
}


 void OrdenaPorApellido(Employees emp[],int TAM)
 {
     Employees empAux;
     int j;
     int i;

                         for(i=0;i<TAM-1;i++)
                          {
                              for(j=i+1;j<TAM;j++)
                              {
                                  if(strcmp(emp[i].lastName,emp[j].lastName)>0)/**ABCDEF....*/
                                  {
                                      empAux=emp[i];
                                      emp[i]=emp[j];
                                      emp[j]=empAux;
                                  }
                                  else
                                    {
                                            if(strcmp(emp[i].lastName,emp[j].lastName)==0)
                                            {
                                                if(emp[i].sector>emp[j].sector)
                                                {
                                                    empAux=emp[i];
                                                    emp[i]=emp[j];
                                                    emp[j]=empAux;
                                                }
                                            }
                                    }
                              }
                          }

}

 /**
 * \brief Busca el Salary promedio
 * \param emp Es el array en el cual buscar
 * \param CANT Indica la logitud del array
 * \return Si no hay Empleados activos (-1) y si los hay el salario de ese empleado
 *
 */
float getAverageSalary(Employees emp[],int CANT)
{
    int i;
    float totalSalary = 0;
    int activeEmp = 0;

    for(i=0;i < CANT; i++)
    {
        if(emp[i].isEmpty == 1)
        {
            totalSalary = totalSalary+ emp[i].salary;
            activeEmp++;
        }
    }
    if(activeEmp == 0)
        return -1;

    return (totalSalary / (float)activeEmp);
}
float getTotalSalary(Employees emp[],int CANT)
{
    int i;
    float totalSalary =0;
    for(i=0;i<CANT;i++)
    {
        if(emp[i].isEmpty==1)
        {
            totalSalary=totalSalary + emp[i].salary;
        }
    }
    if(totalSalary == 0)
    {
        return -1;
    }
    return totalSalary;
}
/** \brief Busca e informa quienes y cuantos superan el salario promedio.
 * \param emp es el Array de Employees.
 * \param TAM: longitud del Array
 * \param salaryAux recibe el salario.
 * \return -
 *
 */

void sueldoSobrePromedio(Employees emp[],int TAM,float salaryAux)
{
    int i;
   int cantActiveEmpBestpay=0;
    for(i=0;i<TAM;i++)
        {
            if(emp[i].salary>salaryAux && emp[i].isEmpty==1)
            {
                printf("\n%d - %s - %s - %.3f - %d",emp[i].id,emp[i].name,emp[i].lastName,emp[i].salary,emp[i].sector);
                cantActiveEmpBestpay++;
            }
        }
    printf("\n\nUN TOTAL DE %d SUPERAN EL SUELDO PROMEDIO",cantActiveEmpBestpay);
}







int menu()
{
    char auxopcion[50];
    int opcion;

    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Salir\n");

    if(!getsStringsSoloNumeros("ingrese una opcion del menu del 1 al 5\n",auxopcion))
    {
        printf("debe ingresar numeros de las opciones\n");

    }
    opcion= atoi(auxopcion);
    return opcion;
}

void inicializadorPersonas(EPersona vec[], int tam )
{
    for(int i = 0; i<tam ; i++ )
    {
        vec[i].estado=1;
    }

}

void mostrarPersona(EPersona persona)
{

    printf("%d      %s       %d \n", persona.dni, persona.nombre, persona.edad);

}

void mostrarPersonas(EPersona lista[], int tam)
{
    printf("-------- lista de personas ordenadas por nombre------\n\n");
    printf(" dni    nombre    edad  \n\n");
    ordenarPersonas(lista,tam);

    for(int i =0; i<tam ; i++)
    {
        if(lista[i].estado == 0)
        {
            mostrarPersona(lista[i]);
        }
    }
    printf("\n-----------------------------------------------------------\n");

}

int obtenerEspacioLibre(EPersona lista[], int tam)
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

int buscarPorDni(EPersona lista[], int tam, int dni)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==0 && lista[i].dni == dni)
        {
            indice=i;
            break;
        }

    }
    return indice;
}
void altaPersona(EPersona lista[], int tam)
{
    EPersona nuevoEmpleado;
    int indice;
    int dni;
    int esta;

    system("cls");
    printf("---- alta de personas----\n");

    indice= obtenerEspacioLibre(lista, tam);

    if(indice== -1)
    {
        printf("\n el sistema esta completo. no se puede dar de alta a mas personas.\n\n");
    }
    else
    {
        printf("ingrese dni: \n");
        scanf("%d", &dni);

        esta= buscarPorDni(lista, tam, dni);

        if(esta != -1)
        {
            printf("\nel legajo %d ya esta dado de alta en el sistema\n", dni);
            mostrarPersona(lista[esta]);

        }
        else
        {
            nuevoEmpleado.estado=0;
            nuevoEmpleado.dni=dni;


            printf("ingrese nombre\n");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            printf("ingrese edad\n");
            scanf("%d", &nuevoEmpleado.edad);

            lista[indice] = nuevoEmpleado;

            printf("\nalta exitosa !!!! \n\n");


        }
    }
}

void bajaPersona(EPersona lista[], int tam)
{
    int dni;
    int esta;
    char confirma;

    system("cls");
    printf("-----baja de persona-----\n\n");

    printf("ingrese dni\n");
    scanf("%d", &dni);

    esta = buscarPorDni(lista,tam, dni);

    if(esta== -1)
    {
        printf("\n el dni %d no se encuentra en el sistema\n\n", dni);
    }
    else
    {
        mostrarPersona(lista[esta]);

        printf("\n confirma la baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma== 's')
        {
            lista[esta].estado=1;
            printf("\n se ha realizado la baja \n\n");
        }
        else
        {
            printf("\n se ha cancelado la baja\n\n");
        }

    }
}

void ordenarPersonas(EPersona lista[], int tam)
{

    EPersona auxpersona;

    for(int i=0; i< tam-1; i++)
    {
        for(int j=i +1; j< tam; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre)>0)
            {
                auxpersona = lista[i];
                lista[i] = lista[j];
                lista[j] = auxpersona;
            }
        }
    }
}

void graficosEdades(EPersona lista[], int tam)
{
    int contador18=0;
    int contador19a35=0;
    int contador35=0;
    char item = '*';

    printf("------grafico de edades -------");

    system("cls");

    for(int i = 0; i<tam; i++ )
    {
        if(lista[i].edad <19 && lista[i].estado==0)
        {
            contador18++;
            printf("%c\n", item);
        }
        else if(lista[i].edad >18 && lista[i].edad <36 && lista[i].estado==0)
        {
            contador19a35++;
            printf("          %c\n",item);
        }
        else if(lista[i].edad>35 && lista[i].estado==0)
        {
            contador35++;
            printf("                     %c\n",item);
        }
    }

    printf("<18      19-35      >35\n");

}
int getsStringsSoloNumeros(char mensaje[],  char lugar[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esNumerico(aux))
    {
        strcpy(lugar,aux);
        return 1;
    }
    return 0;
}
int esNumerico(char cadena[])
{
    int i=0;
    while(cadena[i]!= '\0')
    {
        if(cadena[i] < '0' || cadena[i] > '9')

            return 0;
        i++;

    }
    return 1;
}

void getString(char mensaje[], char lugar[])
{
    printf(mensaje);
    scanf("%s", lugar);
}





void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i< tam; i++)
    {
        vec[i].isEmpty =1;
    }
}

void mostrarEmpleados(eEmpleado vec[], int tamEmp, eSector sectores[],int tamSec)
{
    system("cls");
    printf("      ---Lista de Empleados---\n\n");
    printf("  Legajo  Nombre   Sexo   Sueldo   Fecha de Ingreso  Sector \n\n");
    for(int i=0; i< tamEmp; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarEmpleado(vec[i], sectores, tamSec);
        }
    }
}

void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tam)
{
    int indice;
    for(int i=0; i< tam; i++)
    {
        if(emp.idSector == sectores[i].id )
        {
            indice = i;
            break;
        }
    }
    printf("  %4d%12s     %c  %10.2f    %02d/%02d/%4d     %s\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio, sectores[indice].nombre);
}

int buscarLibre(eEmpleado vec[], int tam)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaEmpleado(eEmpleado vec[], int tamEmp, eSector sectores[], int tamSec)
{

    eEmpleado nuevoEmpleado;
    int indice;
    int esta;
    int legajo;

    system("cls");
    printf("---Alta empleado---\n\n");

    indice = buscarLibre(vec, tamEmp);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta a empleados nuevos.\n\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tamEmp, legajo);

        if(esta != -1)
        {
            printf("\nEl legajo %d ya esta dado de alta en el sistema\n", legajo);
            mostrarEmpleado(vec[esta], sectores, tamSec);
        }
        else
        {
            nuevoEmpleado.isEmpty = 0;
            nuevoEmpleado.legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);

            printf("Ingrese sueldo: ");
            scanf("%f", &nuevoEmpleado.sueldo);

            printf("Ingrese fecha de ingreso d m a: ");
            scanf("%d %d %d", &nuevoEmpleado.fechaIngreso.dia, &nuevoEmpleado.fechaIngreso.mes, &nuevoEmpleado.fechaIngreso.anio);

            nuevoEmpleado.idSector = pedirSector(sectores, tamSec);
            vec[indice] = nuevoEmpleado;

            printf("\nAlta exitosa!!!\n\n");

        }
    }

}

void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int legajo;
    int esta;
    char confirma;

    system("cls");
    printf("---Baja Empleado---\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if(esta == -1)
    {
        printf("\nEl legajo %d no se encuentra en el sistema\n\n", legajo);

    }
    else
    {

        mostrarEmpleado(vec[esta], sectores, tamSec);

        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            vec[esta].isEmpty = 1;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }

    }
}

void modificacionEmpleado(eEmpleado vec[], int tamEmp, eSector sectores[], int tamSec)
{
    int legajo;
    int esta;
    char confirma;
    float sueldo;

    system("cls");
    printf("---Modificacion Empleado---\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tamEmp, legajo);

    if(esta == -1)
    {
        printf("\nEl legajo %d no se encuentra en el sistema\n\n", legajo);

    }
    else
    {

        mostrarEmpleado(vec[esta], sectores, tamEmp);

        printf("\nIngrese nuevo sueldo: ");
        scanf("%f", &sueldo);

        printf("\nConfirma Modificacion?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            vec[esta].sueldo = sueldo;
            printf("\nSe ha modificado el sueldo\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la modificacion\n\n");
        }

    }
}

void ordenarEmpleados(eEmpleado vec[], int tam)
{

    eEmpleado auxEmpleado;

    for(int i=0; i< tam-1; i++)
    {
        for(int j=i +1; j< tam; j++)
        {
            if(vec[i].sexo > vec[j].sexo)
            {
                auxEmpleado = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmpleado;
            }
            else
            {
                if(vec[i].sexo == vec[j].sexo)
                {
                    if(strcmp(vec[i].nombre, vec[j].nombre)>0)
                    {
                        auxEmpleado = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxEmpleado;
                    }

                }

            }
        }
    }
    printf("\nSistema Ordenado\n\n");
}

float sueldoMaximo(eEmpleado vec[], int tam)
{

    float maxSueldo;
    int flag = 0 ;

    for(int i=0; i< tam; i++)
    {

        if( vec[i].sueldo > maxSueldo || flag == 0)
        {
            maxSueldo = vec[i].sueldo;
            flag = 1;
        }
    }
    return maxSueldo;
}




int pedirSector(eSector sectores[], int tam)
{

    int idSector;

    printf("\nSectores\n\n");

    for(int i=0; i< tam; i++)
    {
        printf("%d- %s\n", sectores[i].id, sectores[i].nombre );
    }
    printf("\nIndique Sector: ");
    fflush(stdin);
    scanf("%d", &idSector);

    return idSector;
}


void empleadosXSector(eEmpleado gente[], int tamEmp, eSector sectores[], int tamSec)
{

    system("cls");
    printf("---Listado Empleados por Sector---\n\n");

    for(int i=0; i< tamSec; i++)
    {
        printf("-- %s --\n\n", sectores[i].nombre);

        for(int j=0; j < tamEmp; j++)
        {
            if(gente[j].idSector == sectores[i].id)
            {
                mostrarEmpleado(gente[j], sectores, tamSec);
            }
        }
        printf("\n-----------------------------------------------------------\n");
    }

    printf("\n\n");
    system("pause");

}

void CantidadEmpleadosXSector(eEmpleado gente[], int tamEmp, eSector sectores[], int tamSec)
{

    int contador;
    system("cls");
    printf("---Listado Empleados por Sector---\n\n");

    for(int i=0; i< tamSec; i++)
    {
        printf("-- %s --\n\n", sectores[i].nombre);
        contador =0;

        for(int j=0; j < tamEmp; j++)
        {
            if(gente[j].idSector == sectores[i].id)
            {
                contador++;
            }
        }
        printf("Cantidad empleados: %d\n", contador);
        printf("\n-----------------------------------------------------------\n");
    }

    printf("\n\n");
    system("pause");

}

void totalSueldosXSector(eEmpleado gente[], int tamEmp, eSector sectores[], int tamSec)
{
    int idSector;
    float acumulador = 0;
    system("cls");
    printf("---Total Sueldos por Sector---\n\n");

    idSector = pedirSector(sectores, tamSec) - 1;


    printf("\n-- %s --\n\n", sectores[idSector].nombre);

    for(int i=0; i< tamEmp; i++)
    {

        if(gente[i].idSector == sectores[idSector].id)
        {
            acumulador += gente[i].sueldo;
        }
    }
    printf("Total sueldos $ %.2f\n\n", acumulador);
    system("pause");
}

void totalSueldos(eEmpleado gente[], int tamEmp){

float total = 0;

for(int i=0; i< tamEmp; i++){
    total += gente[i].sueldo;
}

system("cls");
printf("\nEl total de sueldos es $ %.2f\n\n", total);

system("pause");
}

void empleadosMejorPagos(eEmpleado gente[], int tamEmp, eSector sectores[], int tamSec){

    float sueldoMax;
    int flag=0;

    for(int i=0; i< tamEmp; i++){

    if(gente[i].sueldo > sueldoMax || flag == 0){
        sueldoMax = gente[i].sueldo;
        flag = 1;
    }
    }

     for(int i=0; i< tamEmp; i++){

    if(gente[i].sueldo == sueldoMax){
        mostrarEmpleado(gente[i], sectores, tamEmp);
    }

    }

    system("pause");

}







#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "LinkedList.h"




int menu ()
{
    int opt;

    system("cls");
    printf("----MENU PRINCIPAL ----\n\n");
    printf("1. Alta de empleado.\n");
    printf("2. Modificar datos de empleado.\n");
    printf("3. Baja de empleado.\n");
    printf("4. Listar empleados.\n");
    printf("5. Ordenar empleados.\n");
    printf("6. Guardar los datos de los empleados en el archivo data.csv \n");
    printf("7. Crear sublistado.\n");
    printf("8. Buscar empleado.\n");
    printf("9. Vaciar lista.\n");
    printf("10. Salir.\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opt);
    return opt;

}


int EmployeeFromText(FILE* f, LinkedList* pArrayListEmployee)
{
    Employee* auxE;
    char buffer[3][30];
    char nombre[50];
    char departamento [50];
    char* legajo;
    int cant;
    int contador = 0;

    fscanf(f, "%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2]);

        while(!feof(f))
        {
            cant = fscanf(f, "%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2]);

            if( cant == 3)
            {
                legajo = buffer[0];
                strcpy(nombre, buffer[1]);
                strcpy(departamento, buffer[2]);
                auxE = employee_newParametros(legajo, nombre, departamento);
                ll_add(pArrayListEmployee, auxE);
                contador ++;
            }

        }
        //printf("Se cargaron %d empleados exitosamente!\n", contador);
        //system("pause");
        contador = 0;
        return 1;
}




Employee* employee_new()
{
    Employee* nuevo = (Employee*) malloc( sizeof(Employee));

    if(nuevo != NULL)
    {
        nuevo->legajo = 0;
        strcpy(nuevo->nombre, " ");
        strcpy(nuevo->departamento, " ");
    }
    return nuevo;
}



Employee* employee_newParametros(char* LegStr, char* nombreStr, char* DeptStr)
{
    Employee* nuevo = employee_new();

    if(nuevo != NULL)
    {
        nuevo-> legajo = atoi(LegStr);
        strcpy(nuevo->nombre, nombreStr);
        strcpy(nuevo->departamento, DeptStr);
    }
    return nuevo;
}



int addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxE = NULL;
    int legajo;

    if (pArrayListEmployee == NULL)
    {
        printf ("No es posible cargar empleados!\n");
        system("pause");
        return 0;

    }else
    {
        Employee* nuevo;
        int control;
        nuevo = employee_new();

        if (nuevo == NULL)
        {
            return 0;
        }

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxE = ll_get(pArrayListEmployee, i);

            if (auxE->legajo == legajo)
            {
                printf("El legajo ingresado ya existe!\n");
                system("pause");
                return 0;
            }
        }
        nuevo->legajo = legajo;
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nuevo->nombre);
        printf("Ingrese departamento: ");
        gets(nuevo->departamento);
        control = ll_add(pArrayListEmployee, nuevo);

        if (control == 0)
        {
            printf("Empleado ingresado con exito!\n");
            system("pause");
            return 1;

        }else
        {
            printf("Error al ingresar empleado!\n");
            system("pause");
            return 0;
        }
    }
    return 1;
}


int ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxE = NULL;

    if (ll_isEmpty(pArrayListEmployee) == 1 || pArrayListEmployee == NULL)
    {
        printf("No hay empleados para listar!\n");
        system("pause");
        return 0;
    }

    if( pArrayListEmployee != NULL && ll_len(pArrayListEmployee)>0)
    {
        printf("\n Legajo     Nombre       Departamento\n\n");

        for( int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            auxE = ll_get(pArrayListEmployee, i);
            printf(" %04d   %13s     %s  \n", auxE->legajo, auxE->nombre, auxE->departamento);
        }
    }
    system("pause");
    return 1;
}



int editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxE = NULL;
    int legajo;
    char nombre[50];
    char departamento[50];
    int control = 0;

    if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) != 1)
    {
        printf("Ingrese legajo del empleado que quiere modificar: ");
        scanf("%d", &legajo);

        for (int i = 0; i < ll_len(pArrayListEmployee); i ++)
        {
            auxE = ll_get(pArrayListEmployee, i);

            if (auxE->legajo == legajo)
            {
                control = 1;

                printf("\n Legajo     Nombre     Departamento\n\n");
                printf(" %04d   %12s     %s  \n\n", auxE->legajo, auxE->nombre, auxE->departamento);
                printf("Ingrese nuevo legajo: ");
                scanf("%d", &auxE->legajo);
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(nombre);
                strcpy(auxE->nombre, nombre);
                printf("Ingrese nuevo departamento: ");
                fflush(stdin);
                gets(departamento);
                strcpy(auxE->departamento, departamento);

                ll_remove(pArrayListEmployee, i);
                ll_push(pArrayListEmployee, i, auxE);
                printf("Empleado modificado con exito!\n");
                system("pause");
                break;
            }

        }if (control == 0)
        {
            printf("El legajo ingresado no es valido!\n");
            system("pause");
            return 0;
        }
    }else
    {
        printf ("No hay empleados para modificar!\n");
        system("pause");
        return 0;
    }
    return 1;
}



int removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxE = NULL;
    int legajo;
    int index;

    if (ll_isEmpty(pArrayListEmployee) == 1)
    {

        printf("No hay empleados para dar de baja!\n");
        system("pause");
        return 0;

    }else
    {

        ListEmployee(pArrayListEmployee);
        printf("Ingrese legajo del empleado que desea eliminar: ");
        scanf("%d", &legajo);
        int control;

        for (int i = 0 ; i < ll_len(pArrayListEmployee); i ++)
        {
            auxE = ll_get(pArrayListEmployee, i);

            if (legajo == auxE->legajo)
            {
                index = ll_indexOf(pArrayListEmployee, auxE);
                ll_remove(pArrayListEmployee, index);
                control = 0;
                break;
            }
        }

        if (control != 0)
        {
            printf("El legajo ingresado no es valido!\n");
            system("pause");
            return 0;

        }else
        {
            printf("Empleado borrado con exito!\n");
            system("pause");
            return 1;
        }
    }
}



int sortEmployee(LinkedList* pArrayListEmployee)
{
    int opt;
    int criterio;

    if (ll_isEmpty(pArrayListEmployee) == 1)
    {
        printf("No hay empleados para ordenar!\n");
        system("pause");
        return 0;
    }

    system("cls");
    printf("---- MENU ORDENAR ----\n\n");
    printf("1. Ordenar por Legajo.\n");
    printf("2. Ordenar por Nombre.\n");
    printf("Ingrese opcion: ");
    scanf ("%d", &opt);

    switch(opt)
    {
        int control;

        case 1:
            do
            {
                printf("Ingrese criterio (1. Menor a mayor/ 0. Mayor a menor): ");
                scanf ("%d", & criterio);
            }while (criterio !=0 && criterio !=1);

            control = ll_sort(pArrayListEmployee, sortByLegajo, criterio);

            if (control == 0)
            {
                printf ("Lista ordenada!\n");
                system("pause");
                return 1;
            }else
            {
                printf("Algo fallo al intentar ordenar la lista!\n");
                system("pause");
                return 0;
            }
            break;

        case 2:
            do
            {
                printf("Ingrese criterio (1. Menor a mayor/ 0. Mayor a menor): ");
                scanf ("%d", & criterio);
            }while (criterio !=0 && criterio !=1);

            control = ll_sort(pArrayListEmployee, sortByNombre, criterio);

            if (control == 0)
            {
                printf ("Lista ordenada!\n");
                system("pause");
                return 1;
            }else
            {
                printf("Algo fallo al intentar ordenar la lista!\n");
                system("pause");
                return 0;
            }
            break;

        default:
            printf("Opcion incorrecta!\n");
            system("pause");
            break;
    }
    return 1;
}


int sortByNombre(void* emp1, void* emp2)
{
    Employee* e1 = NULL;
    Employee* e2 = NULL;
    char nombre1[50];
    char nombre2[50];

    e1 = (Employee*) emp1;
    e2 = (Employee*) emp2;

    getNombre(e1, nombre1);
    getNombre(e2, nombre2);

    if(strcmp(e1->nombre , e2->nombre)<0)
    {
        return -1;
    }else if (strcmp(e1->nombre , e2->nombre)>0)
    {
        return 1;
    }else
    {
        return 0;
    }
}


int sortByLegajo(void* emp1, void* emp2)
{
    Employee* e1 = NULL;
    Employee* e2 = NULL;
    int legajo1;
    int legajo2;

    e1 = (Employee*) emp1;
    e2 = (Employee*) emp2;
    getLegajo(e1, &legajo1);
    getLegajo(e2, &legajo2);

    if(legajo1 < legajo2)
    {
        return -1;
    }else if (legajo1 > legajo2)
    {
        return 1;
    }else{
        return 0;
    }
}


int getNombre(Employee* this,char* nombre)
{
    int control = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        control = 1;
    }
    return control;
}



int getLegajo(Employee* this,int* legajo)
{
    int control = 0;

    if(this != NULL && legajo != NULL)
    {
        *legajo = this->legajo;
        control = 1;
    }
    return control;
}



int saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    Employee* auxE;
    LinkedList* archv = ll_newLinkedList();
    FILE* f;
    FILE* f2;

    if (ll_isEmpty(pArrayListEmployee) == 1)
    {
        printf("No hay empleados para guardar!\n");
        system("pause");
        return 0;
    }
    f2 = fopen(path, "r");
    EmployeeFromText(f2, archv);
    fclose(f2);

    if (ll_containsAll(archv, pArrayListEmployee) == 0 && ll_len(pArrayListEmployee) != ll_len(archv))
    {
        ll_sort(pArrayListEmployee, sortByLegajo, 1);

        if( pArrayListEmployee != NULL && path != NULL)
        {
            f = fopen(path, "w");

            if( f == NULL)
            {
                printf("No se pudo abrir el archivo!\n");
                system("pause");
                return 0;
            }

            fprintf (f, "Legajo,Nombre,Departamento\n");

            for (int i = 0; i < ll_len(pArrayListEmployee); i ++)
            {
                auxE = ll_get(pArrayListEmployee, i);
                fprintf (f, "%d,%s,%s\n", auxE->legajo, auxE->nombre, auxE->departamento);
            }
            printf("Archivo guardado con exito!\n");
            system("pause");
            fclose(f);
            return 1;
        }
    }else
    {
        printf("La lista se encuentra actualizada!\n");
        system("pause");
    }
    ll_deleteLinkedList(archv);
    return 0;
}


int clearList (LinkedList* pArrayListEmployee){

    int control;
    control = ll_clear(pArrayListEmployee);

    if (control == 0)
    {
        printf("Lista borrada con exito!\n");
        system("pause");
        return 1;
    }else
    {
        printf("Hubo un error al borrar la lista!\n");
        system("pause");
        return 0;
    }
}



int subList(LinkedList* this)
{
    int desde;
    int hasta;

    if (ll_isEmpty(this) == 1)
    {
        printf("No hay empleados para listar!\n");
        system("pause");
        return 0;
    }

    LinkedList* lista2 = ll_newLinkedList();
    ll_sort(this, sortByLegajo, 1);
    printf ("Ingrese los numeros de legajo (desde/hasta): ");
    scanf("%d/%d", &desde, &hasta);
    lista2 = ll_clone(ll_subList(this, desde-1, hasta));
    ListEmployee(lista2);
    return 1;

}


int searchEmployee (LinkedList* this){

    Employee* auxE;
    int legajo;
    int control;

    if (ll_isEmpty(this) == 1)
    {
        printf("No hay empleados para buscar!\n");
        system("pause");
        return 0;
    }

    printf("Ingrese numero de legajo: ");
    scanf("%d", &legajo);
    ll_sort(this, sortByLegajo, 1);
    auxE = ll_get(this, (legajo-1));

    if (auxE != NULL)
    {
        control = ll_contains(this, auxE);
    }

    if (control == 1)
    {
        printf("El empleado se encuentra en la lista!\n");
        printf("\n Legajo     Nombre     Departamento\n\n");
        printf(" %04d   %12s     %s  \n\n", auxE->legajo, auxE->nombre, auxE->departamento);
        system("pause");
        return 1;

    }else
    {
        printf("El empleado no se encuentra en la lista!\n");
        system("pause");
        return 1;
    }
    return 0;
}

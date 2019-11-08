#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    if (pArrayListEmployee != NULL){

        FILE* f = fopen("data.csv", "r");
        if( f == NULL)
        {
            printf("No se pudo abrir el archivo!\n");
            system("pause");
            return 0;
        }

        parser_EmployeeFromText(f , pArrayListEmployee);
        fclose(f);
    }
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

    if(pArrayListEmployee != NULL){
        FILE* f = fopen(path, "rb");
        if( f == NULL)
        {
            printf("No se pudo abrir el archivo!\n");
            system("pause");
            return 0;
        }

        parser_EmployeeFromBinary(f , pArrayListEmployee);
        fclose(f);

    }
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee = NULL;
    int id;

    if (pArrayListEmployee == NULL){
        printf ("No es posible cargar empleados!\n");
        system("pause");
        return 0;

    }else{

        Employee* nuevo;
        int control;
        nuevo = employee_new();

        if (nuevo == NULL){
            return 0;
        }

        printf("Ingrese id: ");
        scanf("%d", &id);

        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);

            if (auxEmployee->id == id){
                printf("El id ingresado ya existe!\n");
                system("pause");
                return 0;
            }
        }
            nuevo->id = id;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevo->nombre);
            printf("Ingrese horas trabajadas: ");
            scanf("%d", &nuevo->horasTrabajadas);
            printf("Ingrese sueldo: ");
            scanf("%d", &nuevo->sueldo);
            control = ll_add(pArrayListEmployee, nuevo);

            if (control == 0){
                printf("Empleado ingresado con exito!\n");
                system("pause");
                return 1;

            }else{
                printf("Error al ingresar empleado!\n");
                system("pause");
                return 0;
            }
        }
    return 1;
}



 /** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee = NULL;

    if (ll_isEmpty(pArrayListEmployee) == 1)
    {
        printf("No hay empleados para listar!\n");
        system("pause");
        return 0;
    }

    if( pArrayListEmployee != NULL && ll_len(pArrayListEmployee)>0)
    {
        printf(" Id           Nombre     Horas   Sueldo\n\n");

        for( int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            printf("%04d   %17s   %4d   %6d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
        }
    }
    system("pause");
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee = NULL;
    int id;
    char nombre[128];
    int control = 0;

    if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) != 1){

        controller_ListEmployee(pArrayListEmployee);

        printf("Ingrese id del empleado que quiere modificar: ");
        scanf("%d", &id);


        for (int i = 0; i < ll_len(pArrayListEmployee); i ++){

            auxEmployee = ll_get(pArrayListEmployee, i);

            if (auxEmployee->id == id){
                control = 1;
                printf("Ingrese nuevo id: ");
                scanf("%d", &auxEmployee->id);
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(nombre);
                strcpy(auxEmployee->nombre, nombre);
                printf("Ingrese nuevas horas trabajadas: ");
                scanf("%d", &auxEmployee->horasTrabajadas);
                printf("Ingrese nuevo sueldo: ");
                scanf("%d", &auxEmployee->sueldo);

                ll_remove(pArrayListEmployee, i);
                ll_push(pArrayListEmployee, i, auxEmployee);
                printf("Empleado modificado con exito!\n");
                system("pause");
                break;

            }

        }if (control == 0){
            printf("El id ingresado no es valido!\n");
            system("pause");
            return 0;
        }

    }else {
        printf ("No hay empleados para modificar!\n");
        system("pause");
        return 0;
    }
    return 1;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee = NULL;
    int id;
    int index;
    int control;

    if (ll_isEmpty(pArrayListEmployee) == 1){

        printf("No hay empleados para dar de baja!\n");
        system("pause");
        return 0;

    }else{

        controller_ListEmployee(pArrayListEmployee);
        printf("Ingrese id del empleado que desea eliminar: ");
        scanf("%d", &id);

        for (int i = 0 ; i < ll_len(pArrayListEmployee); i ++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);

            if (id == auxEmployee->id)
            {
                index = ll_indexOf(pArrayListEmployee, auxEmployee);
                control = ll_remove(pArrayListEmployee, index);
                break;
            }
        }

        if (control != 0)
        {
            printf("El id ingresado no es valido!\n");
            system("pause");
            return 0;

        }else {
            printf("Empleado borrado con exito!\n");
            system("pause");
            return 1;
        }
    }
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opt;
    int criterio;

    if (ll_isEmpty(pArrayListEmployee) == 1){
        printf("No hay empleados para ordenar!\n");
        system("pause");
        return 0;
    }

    system("cls");
    printf("---- MENU ORDENAR ----\n\n");
    printf("1. Ordenar por Id.\n");
    printf("2. Ordenar por Nombre.\n");
    printf("3. Ordenar por Horas trabajadas.\n");
    printf("4. Ordenar por Sueldo.\n\n");
    printf("Ingrese opcion: ");
    scanf ("%d", &opt);

    switch(opt){

        int control;

        case 1:
            do{
            printf("Ingrese criterio (1. Menor a mayor/ 0. Mayor a menor): ");
            scanf ("%d", & criterio);
            }while (criterio !=0 && criterio !=1);
            printf("Ordenando aguarde por favor...");
            control = ll_sort(pArrayListEmployee, employee_sortById, criterio);
            if (control == 0){
                printf ("\nLista ordenada!\n");
                system("pause");
                return 1;
            }else {
                printf("Algo fallo al intentar ordenar la lista!\n");
                system("pause");
                return 0;
            }
            break;

        case 2:
            do{
            printf("Ingrese criterio (1. Menor a mayor/ 0. Mayor a menor): ");
            scanf ("%d", & criterio);
            }while (criterio !=0 && criterio !=1);
            printf("Ordenando aguarde por favor...");
            control = ll_sort(pArrayListEmployee, employee_sortByNombre, criterio);
            if (control == 0){
                printf ("\nLista ordenada!\n");
                system("pause");
                return 1;
            }else {
                printf("Algo fallo al intentar ordenar la lista!\n");
                system("pause");
                return 0;
            }
            break;

        case 3:
           do{
            printf("Ingrese criterio (1. Menor a mayor/ 0. Mayor a menor): ");
            scanf ("%d", & criterio);
            }while (criterio !=0 && criterio !=1);
            printf("Ordenando aguarde por favor...");
            control = ll_sort(pArrayListEmployee, employee_sortByHoras, criterio);
            if (control == 0){
                printf ("\nLista ordenada!\n");
                system("pause");
                return 1;
            }else {
                printf("Algo fallo al intentar ordenar la lista!\n");
                system("pause");
                return 0;
            }
            break;

        case 4:
             do{
            printf("Ingrese criterio (1. Menor a mayor/ 0. Mayor a menor): ");
            scanf ("%d", & criterio);
            }while (criterio !=0 && criterio !=1);
            printf("Ordenando aguarde por favor...");
            control = ll_sort(pArrayListEmployee, employee_sortBySueldo, criterio);
            if (control == 0){
                printf ("\nLista ordenada!\n");
                system("pause");
                return 1;
            }else {
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

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;

    FILE* f;

    if (ll_isEmpty(pArrayListEmployee) == 1){
        printf("No hay empleados para guardar!\n");
        system("pause");
        return 0;
    }


    if( pArrayListEmployee != NULL && path != NULL)
    {
        f = fopen(path, "wb");

        if( f == NULL)
        {
            printf("No se pudo abrir el archivo!\n");
            system("pause");
            return 0;
        }

        fprintf (f, "Id,  Nombre,  Horas,  Sueldo\n");

        for (int i = 0; i < ll_len(pArrayListEmployee); i ++){

            auxEmployee = ll_get(pArrayListEmployee, i);

            fprintf (f, "%d, %s, %d, %d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);

        }
        printf("Archivo guardado con exito!\n");
        system("pause");
        fclose(f);
        return 1;
    }
    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int control = 0;
    int cant;
    FILE* f;


    if (ll_isEmpty(pArrayListEmployee) == 1){
        printf("No hay empleados para guardar!\n");
        system("pause");
        return 0;
    }

    if( pArrayListEmployee != NULL && path != NULL)
    {
        f = fopen(path, "wb");

        if( f == NULL)
        {
            return control;
        }

        for(int i=0; i <= ll_len(pArrayListEmployee); i++)
        {
            cant = fwrite((Employee*) ll_get(pArrayListEmployee, i), sizeof(Employee),  1, f);

            if(cant < 1 && i != ll_len(pArrayListEmployee))
            {
                printf("No se pudo guardar el archivo!\n");
                system("pause");
                return control;
            }
        }
        printf("Archivo guardado con exito!\n");
        system("pause");
        fclose(f);
        control = 1;
        return control;
    }

    return control;
}


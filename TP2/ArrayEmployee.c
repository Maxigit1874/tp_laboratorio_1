#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployee.h"



int menu()
{
    int opcion;
    fflush(stdin);
    system("cls");
    printf("---- MENU PRINCIPAL ----\n\n");
    printf("1- Altas.\n");
    printf("2- Modificar.\n");
    printf("3- Baja.\n");
    printf("4- Mostrar\n");
    printf("5- Salir\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int initEmployees (eEmployee vec[], int tam){

    int vacio = 1;
    int ok = - 1;

    for (int i = 0 ; i < tam ; i ++){
        vec[i].isEmpty = vacio;
        ok = 0;
    }

    return ok;
}

void altaEmpleado (eEmployee vec[], int tam, int id){

    char nombre[20];
    char apellido[20];
    float salario;
    int sector;
    int control;

        system("cls");
        printf ("---- ALTA EMPLEADOS ----\n\n");
        printf ("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);
        printf ("Ingrese apellido: ");
        fflush(stdin);
        gets(apellido);
        printf ("Ingrese salario: ");
        scanf ("%f", &salario);
        printf ("Ingrese sector: ");
        scanf ("%d", &sector);

        control = addEmployee(vec, tam, id, nombre, apellido, salario, sector);

        if (control == 0){

            printf ("\nAlta exitosa!\n\n");

        }else {
            printf ("\nOcurrio un error en el alta!\n\n");

        }

        system("pause");
}


int addEmployee(eEmployee vec[], int tam, int id, char name[],char lastName[],float salary,int sector){

    int control = -1;

    for (int i = 0 ; i < tam ; i ++){

        if (vec[i].isEmpty == 1){

            vec[i].id = id;
            strcpy(vec[i].name, name);
            strcpy(vec[i].lastName, lastName);
            vec[i].salary = salary;
            vec[i].sector = sector;
            vec[i].isEmpty = 0;
            control = 0;
            break;

           }

    }

    return control;
}



int printEmployees (eEmployee vec[], int tam){

    int ok = -1;
    printf ("\n Id             Nombre        Apellido          Salario       Sector   \n");

    for (int i = 0 ; i < tam ; i ++){

        if (vec[i].isEmpty == 0){

        printf ("%4d      %12s    %12s       %10.2f        %2d\n", vec[i].id, vec[i].name, vec[i].lastName, vec[i].salary, vec[i].sector);
        ok = 0;
        }

    }
     printf("\n");

     return ok;
}

int findEmployeeById (eEmployee vec[], int tam, int id){

    int index;

    for (int i = 0 ; i < tam ; i++){

        if (vec[i].isEmpty == 0 && vec[i].id == id){

            index = i;
            break;

        }else {

            index = -1;
        }

    }

    return index;

}

void modifEmployee (eEmployee vec[], int tam){

    int flag = 0;
    int id;
    int index;
    int opt;
    int controlModif = 0;

    for (int i = 0 ; i < tam ; i++){

        if (vec[i].isEmpty == 0){

            flag = 1;
        }
    }

    if (flag == 0){

        printf ("\nNo hay empleados para modificar!\n\n");

    }else {

        system("cls");
        printf ("---- MODIFICAR EMPLEADO ----\n\n");
        printf ("Ingrese id: ");
        scanf("%d", &id);
        index = findEmployeeById(vec, tam, id);


        if (index == -1){

            printf ("\nEl id esta vacio!\n\n");

         }else {

            printf ("\n1. Modificar nombre (%s).\n", vec[index].name);
            printf ("2. Modificar apellido (%s).\n", vec[index].lastName);
            printf ("3. Modificar salario (%.2f).\n", vec[index].salary);
            printf ("4. Modificar sector (%d)\n", vec[index].sector);
            printf ("5. Salir.\n");
            printf ("\nIngrese opcion: ");
            scanf ("%d", &opt);


        switch (opt){

        case 1:
            printf ("\nIngrese nombre: ");
            fflush(stdin);
            gets(vec[index].name);
            controlModif = 1;
            break;

        case 2:
            printf ("Ingrese apellido: ");
            fflush(stdin);
            gets(vec[index].lastName);
            controlModif = 1;
            break;

        case 3:
            printf ("Ingrese salario: ");
            scanf ("%f", &vec[index].salary);
            controlModif = 1;
            break;

        case 4:
            printf ("Ingrese sector: ");
            scanf("%d", &vec[index].sector);
            controlModif = 1;
            break;

        case 5:
            break;

        default:
            printf ("opcion incorrecta!");
            system("pause");
            break;
        }

        if ( controlModif == 0) {

            printf ("\nNo se realizaron cambios en el empleado.\n\n");

        } else {

            printf("\nEmpleado modificado correctamente!\n\n");
        }
    }
    }
}



void bajaEmpleado(eEmployee vec[], int tam){

    int id;
    int control = 0;
    int flag = 0;

    for (int i = 0 ; i < tam ; i ++){

        if (vec[i].isEmpty == 0){
            flag = 1;
            break;
        }
    }


    if (flag == 0){

        printf ("\nNo hay empleados para dar de baja!\n\n");
        system("pause");

        }else {
            system("cls");
            printf ("---- BAJA EMPLEADO ----\n\n");
            printf ("Ingrese id: ");
            scanf ("%d", &id);

            control = removeEmployee(vec, tam, id);

        if (control == -1){

            printf ("\nEl id no exite!\n\n");
            system ("pause");

            }else if (control == 0){

                printf ("\nBaja exitosa!\n\n");
                system("pause");

            }else {

                printf ("\nSe cancelo la baja!\n\n");
                system("pause");
            }

        }


}


int removeEmployee (eEmployee vec[], int tam, int id){

   int control;
   int index;
   char opt;


   index = findEmployeeById(vec, tam, id);

   if (index == - 1){

       control = -1;

   }else {
    printf ("\nEsta seguro que desea dar de baja el legajo %d? (s/n): ", id);
    fflush(stdin);
    scanf("%c", &opt);

    if (opt == 's'){
    vec[index].isEmpty = 1;
    control = 0;

    }else {
        control = 1;
    }


   }

    return control;

}


void informar (eEmployee vec[], int tam){

    int opt;
    int criterio;
    int flag = 0;

    for (int i = 0 ; i < tam ; i ++){

        if (vec[i].isEmpty == 0){
        flag = 1;
        }
    }

    if (flag == 0){

        printf ("\nNo hay empleados para mostrar!\n\n");
    }else {

    system ("cls");
    printf ("---- INFORMES ----\n");
    printf ("\n1. Mostrar empleados por orden alfabetico y sector.\n");
    printf ("2. Mostrar total de salarios y promedio.\n");

    printf("\nIngrese opcion: ");
    scanf("%d", &opt);

    switch (opt){

        case 1:
            system ("cls");
            printf ("---- INFORMES ----\n");
            printf ("\nSeleccione criterio: \n");
            printf ("\n1. Ordenar: A - Z.\n");
            printf ("2. Ordenar: Z - A.\n");
            printf ("\nOpcion: ");
            scanf ("%d", &criterio);
            sortEmployees(vec, tam, criterio);
            break;

        case 2:
            CalcularSalarios (vec, tam);
            break;

        default:
            printf ("Opcion incorrecta!\n");
            break;
    }
    }
}

int sortEmployees (eEmployee vec[], int tam, int order){

    eEmployee auxEmpleado;
    int control = -1;

    if (order == 1){

    for(int i= 0; i < tam-1 ; i++){

        for(int j= i+1; j <tam; j++)
        {
            if(vec[i].sector > vec[j].sector && vec[i].isEmpty == 0 && vec[j].isEmpty == 0)
            {
                auxEmpleado= vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmpleado;
                control = 0;

            }else if (vec[i].sector == vec[j].sector && strcmp(vec[i].lastName, vec[j].lastName)>0){

                auxEmpleado= vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmpleado;
                control = 0;

            }
        }

    }
    printf ("\nEmpleados ordenados A - Z: \n");
    printEmployees(vec, tam);


   }else {

    for(int i= 0; i < tam-1 ; i++){

        for(int j= i+1; j <tam; j++)
        {
            if(vec[i].sector < vec[j].sector && vec[i].isEmpty == 0 && vec[j].isEmpty == 0)
            {
                auxEmpleado= vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmpleado;
                control = 0;

            }else if (vec[i].sector == vec[j].sector && strcmp(vec[i].lastName, vec[j].lastName)<0){

                auxEmpleado= vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmpleado;
                control = 0;

            }
        }
     }

     printf ("\nEmpleados ordenados Z - A: \n");
     printEmployees(vec, tam);
   }


   return control;
}


void CalcularSalarios (eEmployee vec[], int tam){

    float tot = 0;
    float prom = 0;
    int empleProm = 0;
    int cant = 0;

    for (int i = 0 ; i < tam ; i++){

        if (vec[i].isEmpty == 0){
            cant ++;
            tot += vec[i].salary;
        }
    }
    prom = (float) tot/cant;

    for (int i = 0 ; i < tam ; i++){

        if (vec[i].salary > prom && vec[i].isEmpty == 0){
            empleProm ++;
        }
    }
    system("cls");
    printf ("---- INFORMES ----\n");
    printf("\nTotal salarios: %.2f\n", tot);
    printf ("Promedio salarios: %.2f\n", prom);

    if (empleProm == 0){

        printf("No hay empleados que superen el promedio!\n\n");

    }else{

    printf ("Empleados que superan el salario promedio: %d\n\n", empleProm);
    }
}



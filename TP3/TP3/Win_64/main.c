#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
   1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
   2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
   3. Alta de empleado
   4. Modificar datos de empleado
   5. Baja de empleado
   6. Listar empleados
   7. Ordenar empleados
   8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
   9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
  10. Salir
*****************************************************/

int menu ();

int main()
{
    char option = 'n';
    LinkedList* listaEmpleados = ll_newLinkedList();

    if (listaEmpleados == NULL){
        printf("No se pudo crear lista de empleados.\n");
        exit(EXIT_FAILURE);
        }

    do{
        switch(menu())
        {

            case 1:
                if (ll_isEmpty(listaEmpleados)== 0){

                    printf("La lista ya esta cargada!\n");

                    system("pause");
                }else{
                    controller_loadFromText("data.csv",listaEmpleados);
                }
                break;

            case 2:
                controller_loadFromBinary("data.bin", listaEmpleados);
                break;

            case 3:
                controller_addEmployee(listaEmpleados);
                break;

            case 4:
                controller_editEmployee(listaEmpleados);
                break;

            case 5:
                controller_removeEmployee(listaEmpleados);
                break;

            case 6:
                controller_ListEmployee(listaEmpleados);
                break;

            case 7:
                controller_sortEmployee(listaEmpleados);
                break;

            case 8:
                controller_saveAsText("data.csv" , listaEmpleados);
                break;

            case 9:
                controller_saveAsBinary("data.bin" , listaEmpleados);
                break;

            case 10:
                printf("Esta seguro que desea salir? (s/n): ");
                fflush(stdin);
                scanf("%c", &option);
                ll_deleteLinkedList(listaEmpleados);
                break;

            default:
                printf("Opcion incorrecta!\n");
                system("pause");
                break;





        }
    }while(option != 's');
    return 0;
}


int menu (){


    int opt;

    system("cls");
    printf("----MENU PRINCIPAL ----\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir.\n\n");
    printf("Ingrese opcion: ");

    scanf("%d", &opt);

    return opt;

}





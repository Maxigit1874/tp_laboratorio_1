#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "biblioteca.h"


int main()
{
    char opcion = 'n';

    FILE* f = fopen("data.csv", "r");

    if (f == NULL)
    {
        printf("No se pudo abrir el archivo!");
        system("pause");
    }

    LinkedList* listaEmpleados = ll_newLinkedList();

    if (listaEmpleados == NULL)
    {
        printf("No se pudo crear lista .\n");
        exit(EXIT_FAILURE);
    }

     EmployeeFromText(f, listaEmpleados);

 do{
    switch(menu())
        {
        case 1:
            addEmployee(listaEmpleados);
            break;

        case 2:
            editEmployee(listaEmpleados);
            break;

        case 3:
            removeEmployee(listaEmpleados);
            break;

        case 4:
            ListEmployee(listaEmpleados);
            break;

        case 5:
            sortEmployee(listaEmpleados);
            break;

        case 6:
            saveAsText("data.csv", listaEmpleados);
            break;

        case 7:
            subList(listaEmpleados);
            break;

        case 8:
            searchEmployee(listaEmpleados);
            break;

        case 9:
            clearList(listaEmpleados);
            break;

        case 10:
            printf("Esta seguro que desea salir? (s/n): ");
            fflush(stdin);
            scanf("%c", &opcion);
            ll_deleteLinkedList(listaEmpleados);
            break;

        default:
            printf("Opcion incorrecta!\n");
            system("pause");
            break;
        }
    }while(opcion != 's');

    return 0;
}





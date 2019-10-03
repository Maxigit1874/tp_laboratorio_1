#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployee.h"

#define TAM 1000




int main()
{


eEmployee empleados[TAM];
initEmployees(empleados, TAM);
char opt = 'n';
int id = 1000;






    do{
        switch (menu()){


        case 1:
            id ++;
            altaEmpleado(empleados, TAM, id);
            break;

        case 2:
            modifEmployee(empleados, TAM);
            system("pause");
            break;

        case 3:
            bajaEmpleado(empleados, TAM);
            break;

        case 4:
            informar(empleados, TAM);
            system("pause");
            break;

        case 5:
            printf ("Desea salir? (s/n): ");
            fflush(stdin);
            scanf("%c", &opt);
            break;

        case 6:
            printEmployees(empleados, TAM);
            system("pause");
            break;

        default:
                printf ("Opcion incorrecta!\n");
                system("pause");
                break;

        }

    }while (opt == 'n');


}


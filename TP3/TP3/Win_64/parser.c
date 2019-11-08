#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado;
    char buffer[4][30];
    char nombre[20];
    int cant;
    int contador = 0;
    char* id;
    char* horasTrabajadas;
    char* sueldo;


        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

            if( cant == 4)
            {

                id = buffer[0];
                strcpy(nombre, buffer[1]);
                horasTrabajadas = buffer[2];
                sueldo = buffer[3];

                auxEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
                ll_add(pArrayListEmployee, auxEmpleado);


            }
            contador ++;
        }
        printf("%d empleados cargados exitosamente!\n", contador);
        system("pause");
        contador = 0;
        return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int cant;
    int contador = 0;

    while( !feof(pFile))
    {
        Employee* auxEmpleado = employee_new();

        if (auxEmpleado != NULL){
            cant = fread(auxEmpleado, sizeof(Employee), 1, pFile);
            if (cant == 1){

               ll_add(pArrayListEmployee, auxEmpleado);
               contador ++;

            }
        }else return 0;
    }
    printf("%d empleados cargados exitosamente!\n", contador);
    system("pause");
    contador = 0;
    return 1;
}

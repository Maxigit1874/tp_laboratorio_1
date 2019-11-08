#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"



Employee* employee_new()
{
    Employee* nuevo = (Employee*) malloc( sizeof(Employee));

    if(nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->horasTrabajadas = 0;
        nuevo->sueldo = 0;
    }
    return nuevo;
}



Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevo = employee_new();

    if(nuevo != NULL)
    {
        if(employee_setId(nuevo, atoi(idStr)) &&
                employee_setNombre(nuevo, nombreStr)&&
                employee_setHorasTrabajadas(nuevo, atoi(horasTrabajadasStr))&&
                employee_setSueldo(nuevo, atoi(sueldoStr)));
    }else
        {
        printf("No se pudo crear el empleado!\n");
        nuevo = NULL;
        }

    return nuevo;
}



void employee_delete()
{

}



int employee_setId(Employee* this,int id)
{
    int control = 0;

    if(this != NULL && id >= 0 && id <=10000)
    {
        this->id = id;
        control = 1;
    }
    return control;
}



int employee_getId(Employee* this,int* id){

    int control = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        control = 1;
    }
    return control;
}



int employee_setNombre(Employee* this,char* nombre)
{
    int control = 0;

    if(this != NULL && nombre != NULL && strlen(nombre) <128)
    {
        strcpy(this->nombre, nombre);
        control = 1;
    }
   return control;
}



int employee_getNombre(Employee* this,char* nombre){

    int control = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        control = 1;
    }
    return control;
}



int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

    int control = 0;

    if(this != NULL && horasTrabajadas >= 0 && horasTrabajadas <= 400)
    {
        this-> horasTrabajadas = horasTrabajadas;
        control = 1;
    }
    return control;
}



int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){

    int control = 0;

    if( this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this-> horasTrabajadas;
        control= 1;
    }
    return control;

}



int employee_setSueldo(Employee* this,int sueldo){

    int control = 0;

    if( this != NULL && sueldo >0)
    {
        this-> sueldo = sueldo;
        control = 1;
    }
    return control;
}



int employee_getSueldo(Employee* this,int* sueldo){

    int control = 0;

    if( this != NULL && sueldo != NULL)
    {
        *sueldo = this-> sueldo;
        control = 1;
    }
    return control;
}



/** \brief Ordena el linkedList por Id.
 *
 * \param void* empleado1
 * \param void* empleado2
 * \return int (-1) si el id del empleado1 es menor que el id del empleado2,
 *             (1) si el id del empleado1 es mayor que el id del empleado2 o
 *             (0) si son iguales.
 *
 */

int employee_sortById(void* emp1, void* emp2){

    Employee* e1 = NULL;
    Employee* e2 = NULL;
    int id1;
    int id2;

    e1 = (Employee*) emp1;
    e2 = (Employee*) emp2;
    employee_getId(e1, &id1);
    employee_getId(e2, &id2);

    if(id1 < id2){
        return -1;
    }else if (id1 > id2) {
        return 1;
    }else{
        return 0;
    }

}



/** \brief Ordena el linkedList por nombre.
 *
 * \param void* empleado1
 * \param void* empleado2
 * \return int (<0) si el nombre del empleado1 es menor que el nombre del empleado2,
 *             (>0) si el nombre del empleado1 es mayor que el nombre del empleado2 o
 *             (0) si son iguales.
 *
 */

int employee_sortByNombre(void* emp1, void* emp2){

    Employee* e1 = NULL;
    Employee* e2 = NULL;
    char nombre1[128];
    char nombre2[128];

    e1 = (Employee*) emp1;
    e2 = (Employee*) emp2;

    employee_getNombre(e1, nombre1);
    employee_getNombre(e2, nombre2);

    if(strcmp(e1->nombre , e2->nombre)<0){
        return -1;
    }else if (strcmp(e1->nombre , e2->nombre)>0) {
        return 1;
    }else{
        return 0;
    }
}



/** \brief Ordena el linkedList por horas trabajadas.
 *
 * \param void* empleado1
 * \param void* empleado2
 * \return int (-1) si las horas del empleado1 es menor que las horas del empleado2,
 *             (1) si las horas del empleado1 es mayor que las horas del empleado2 o
 *             (0) si son iguales.
 *
 */

int employee_sortByHoras(void* emp1, void* emp2){

    Employee* e1 = NULL;
    Employee* e2 = NULL;
    int horas1;
    int horas2;

    e1 = (Employee*) emp1;
    e2 = (Employee*) emp2;
    employee_getHorasTrabajadas(e1, &horas1);
    employee_getHorasTrabajadas(e2, &horas2);

    if(horas1 < horas2){
        return -1;
    }else if (horas1 > horas2) {
        return 1;
    }else{
        return 0;
    }
}



/** \brief Ordena el linkedList por sueldo.
 *
 * \param void* empleado1
 * \param void* empleado2
 * \return int (-1) si el sueldo del empleado1 es menor que el sueldo del empleado2,
 *             (1) si el sueldo del empleado1 es mayor que el sueldo del empleado2 o
 *             (0) si son iguales.
 *
 */

int employee_sortBySueldo(void* emp1, void* emp2){

    Employee* e1 = NULL;
    Employee* e2 = NULL;
    int sueldo1;
    int sueldo2;

    e1 = (Employee*) emp1;
    e2 = (Employee*) emp2;
    employee_getSueldo(e1, &sueldo1);
    employee_getSueldo(e2, &sueldo2);

    if(sueldo1 < sueldo2){
        return -1;
    }else if (sueldo1 > sueldo2) {
        return 1;
    }else{
        return 0;
    }
}

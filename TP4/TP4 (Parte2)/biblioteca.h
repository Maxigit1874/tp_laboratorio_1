#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#include "LinkedList.h"



typedef struct
{
    int legajo;
    char nombre[50];
    char departamento [50];

}Employee;


int menu ();
Employee* employee_newParametros(char* LegStr,char* nombreStr,char* DeptStr);
int EmployeeFromText(FILE* f, LinkedList* pArrayListEmployee);
int addEmployee(LinkedList* pArrayListEmployee);
int editEmployee(LinkedList* pArrayListEmployee);
int ListEmployee(LinkedList* pArrayListEmployee);
int removeEmployee(LinkedList* pArrayListEmployee);
int sortEmployee(LinkedList* pArrayListEmployee);
int sortByLegajo(void* emp1, void* emp2);
int sortByNombre(void* emp1, void* emp2);
int getLegajo(Employee* this,int* legajo);
int getNombre(Employee* this,char* nombre);
int saveAsText(char* path , LinkedList* pArrayListEmployee);
int clearList (LinkedList* pArrayListEmployee);
int subList(LinkedList* this);
int searchEmployee (LinkedList* this);


#endif // BIBLIOTECA_H_INCLUDED

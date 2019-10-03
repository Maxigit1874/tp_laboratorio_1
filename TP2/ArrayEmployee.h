#ifndef ARRAYEMPLOYEE_H_INCLUDED
#define ARRAYEMPLOYEE_H_INCLUDED


typedef struct{

int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;



}eEmployee;

#endif // ARRAYEMPLOYEE_H_INCLUDED


int initEmployees (eEmployee vec[], int tam);

/** \brief esta funcion inicia todas las posiciones del vector de empleados poniendo en isEmpty true (1),
*    para indicar que estan vacias.
*
* \param vec[] de empleados.
* \param int tamaño vector empleados.
* \return int devuelve -1 si hubo error o 0 si se logro.
*
*/


int menu();

/** \brief Funcion menu principal.
*
*/


void altaEmpleado (eEmployee vec[], int tam, int id);

/** \brief Solicita nombre, apellido, salario y sector al usuario y lo envia a la funcion addEmployee.
*
* \param vec[] de empleados.
* \param int tamaño vector empleados.
* \param int id empleado.
*/


int addEmployee(eEmployee vec[], int tam, int id, char name[],char lastName[],float salary,int sector);

/** \brief Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
*    posición libre.
*
* \param vec[] empleados
* \param tamaño vector empleados
* \param int id
* \param char[] nombre
* \param char [] apellido
* \param float salary
* \param int sector
* \return int devuelve -1 si hubo error o 0 si pudo cargarlo.
*
*/

int printEmployees (eEmployee vec[], int tam);

/** \brief imprime el contenido del array de empleados
*
* \param vec[] de empleados
* \param int vector empleados
* \return int devuelve -1 si no pudo imprimir o 0 si imprimio.
*
*/


int findEmployeeById (eEmployee vec[], int tam, int id);

/** \brief Encuentra y devuelve el indice del empleado con el id que recibe por parametro.
*
* \param vec[] empleados.
* \param int tamaño vector empleados.
* \param int id empleado
* \return int devuelve -1 si no encontro el id o el indice.
*
*/


void modifEmployee (eEmployee vec[], int tam);

/** \brief funcion que modifica los datos que se desee del empleado
*    del id ingresado (los envia a findEmployeeById para obtener indice).
*
* \param vec [] empleados.
* \param int tamaño vector empleados.
*/


void bajaEmpleado(eEmployee vec[], int tam);

/** \brief funcion que solicita id y lo envia a funcion removeEmployee.
*
* \param vec [] empleados.
* \param int tamaño vector empleados.
*/


int removeEmployee (eEmployee vec[], int tam, int id);

/** \brief Da de baja empleado cuya id se ingresa cambiando su bandera a isEmpty = 1;
*
* \param vec [] empleados.
* \param int tamaño vector empleados.
* \param id empleado a dar de baja.
* \return int devuelve -1 si hubo un error o 0 si se dio de baja.
*
*/


void informar (eEmployee vec[], int tam);

/** \brief Funcion de submenu para los informes, envia parametros a la funcion sortEmployee
*    (para mostrar ordenados) o a la funcion CalcularSalarios (para mostrar informes salarios).
*
* \param vec [] empleados.
* \param int tamaño vector empleados.
*/


int sortEmployees (eEmployee vec[], int tam, int order);

/** \brief Ordena los empleados alfabeticamente (1 ascendente o 2 descendente) y por sector.
*
* \param vec [] empleados
* \param int tamaño vector empleados.
* \param int "order 1 = ascendente o 2 = descendente.
* \return int devuelve -1 si hubo un error o 0 si lo pudo ordenar.
*/


void CalcularSalarios (eEmployee vec[], int tam);

/** \brief Funcion que suma todos los salarios, saca el primedio, cuenta los empleados
*    que superan ese promedio y lo imprime.
*
* \param vec [] empleados.
* \param int tamaño vector empleados.
*/



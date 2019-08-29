#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int suma (int a, int b);
int resta (int a, int b);
int multiplicar (int a, int b);
int dividir (int a, int b);
int factorizar (int a);

int main()
{
  int opcion;
  int num1 = 0;
  int num2 = 0;
  int flag1 = 0;
  int flag2 = 0;
  int resultado;
  int factNum;
  int opt;
  char confirm;


do {
    system ("cls");
    printf ("Bienvenido a calculadora v1.0.\n\n");

    printf ("Ingrese su opcion: \n\n");

    if (flag1 == 0){
        printf ("1. Ingresar el primer operando. (A = X)\n");
        }else {
        printf ("1. Ingresar el primer operando. (A = %d)\n", num1);
        }

    if (flag2 == 0){
        printf ("2. Ingresar el segundo operando. (B = Y)\n");
        }else{
        printf ("2. Ingresar el segundo operando. (B = %d)\n", num2);
        }

    printf ("3. Sumar.\n");
    printf ("4. Restar.\n");
    printf ("5. Multiplicar.\n");
    printf ("6. Dividir.\n");
    printf ("7. Calcular Factorial.\n");
    printf ("8. Salir.\n");
    printf ("\nOpcion: ");

    fflush (stdin);
    scanf ("%d", &opcion);


    switch (opcion){

        case 1:

            printf ("Ingrese el primer operando: ");
            flag1 ++;
            fflush (stdin);
            scanf ("%d", &num1);
            break;

        case 2:
            printf ("Ingrese el segundo operando: ");
            flag2 ++;
            fflush (stdin);
            scanf ("%d", &num2);
            break;

        case 3:
            if (flag1 == 0 || flag2 == 0){
                  printf ("Debe ingresar los dos operando para poder sumar!\n");

            }else {
                resultado = suma (num1, num2);
                printf ("\nEl resultado de la suma es: %d\n\n", resultado);
            }

            system ("pause");
            break;

        case 4:
            resultado = resta (num1, num2);
            printf ("\nEl resultado de la resta es: %d\n\n", resultado);
            system ("pause");
            break;

        case 5:
            resultado = multiplicar (num1, num2);
            printf ("\nEl resultado de la multiplicacion es: %d\n\n", resultado);
            system ("pause");
            break;


        case 6:
            resultado = dividir (num1, num2);
            printf ("\nEl resultado de la division es: %d\n\n", resultado);
            system ("pause");
            break;


        case 7:

           printf ("Que operando quiere factorizar? \n");
           printf ("1. %d\n2. %d\nOpcion: ", num1, num2);
           scanf ("%d", &factNum);

           if (factNum == 1){
                resultado = factorizar(num1);

           }else if (factNum == 2){
                resultado = factorizar(num2);

           }else {
                printf ("Opcion incorrecta!\n");

           }
            system ("pause");
            break;



        case 8:
            printf ("Esta seguro que desea salir? (s/n): ");
            fflush(stdin);
            scanf ("%c", &confirm);


        default:
            printf ("Opcion incorrecta!\n");
            system("pause");
            break;
        }


    }while (confirm != 's');


}

int suma(int a, int b){

    int result;

    result = a + b;

    return result;

}

int resta (int a, int b){

    int result;

    result = a - b;

    return result;
}


int multiplicar (int a, int b){

    int result;

    result = a * b;

    return result;
}


int dividir (int a, int b){

    int result;

    result = a / b;

    return result;
}

int factorizar(int a){

    printf ("\nFactorizando numero %d\n", a);



}



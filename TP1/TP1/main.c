#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int suma (int a, int b);
int resta (int a, int b);
int multiplicar (int a, int b);
float dividir (float a, float b);
long long factorizar (int a);

int main()
{
  int opcion;
  int num1 = 0;
  int num2 = 0;
  int flag1 = 0;
  int flag2 = 0;
  int resultado;
  float resultDiv;
  int factNum;
  int opt;
  long long resultadoFact;
  char confirm;


do {
    system ("cls");
    printf ("|Bienvenido a calculadora v1.0.|\n--------------------------------\n\n");


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

            if (flag1 == 0 || flag2 == 0){
                  printf ("Debe ingresar los dos operando para poder restar!\n");

            }else {
            resultado = resta (num1, num2);
            printf ("\nEl resultado de la resta es: %d\n\n", resultado);
            }
            system ("pause");
            break;

        case 5:

            if (flag1 == 0 || flag2 == 0){
                  printf ("Debe ingresar los dos operando para poder multiplicar!\n");

            }else {
            resultado = multiplicar (num1, num2);
            printf ("\nEl resultado de la multiplicacion es: %d\n\n", resultado);
            }
            system ("pause");
            break;


        case 6:

            if (flag1 == 0 || flag2 == 0){
                  printf ("Debe ingresar los dos operando para poder dividir!\n");

            }else if (num1 == 0 || num2 == 0){
                  printf ("No se puede dividir por 0!\n");

            }else {
            resultDiv = dividir (num1, num2);
            printf ("\nEl resultado de la division es: %.2f\n\n", resultDiv);
            }
            system ("pause");
            break;


        case 7:

           resultadoFact = factorizar(num1);
           printf ("El resultado de %d es: %I64d\n", num1, resultadoFact);
           resultadoFact = factorizar(num2);
           printf ("El resultado de %d es: %I64d\n", num2, resultadoFact);
           system ("pause");
           break;



        case 8:
            printf ("Esta seguro que desea salir? (s/n): ");
            fflush(stdin);
            scanf ("%c", &confirm);
            break;


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


float dividir (float a, float b){

    float resultDiv;

    resultDiv = a / b;

    return resultDiv;
}


long long factorizar(int a){

    long long result = 1;

    for (int i = a; i >= 1; i-- ){

    result *= i;


    }

    return result;

}


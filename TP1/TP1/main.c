#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
  int opcion;
  int num1 = 0;
  int num2 = 0;
  char confirm;



do {
    system ("cls");
    printf ("Bienvenido a calculadora v1.0.\n");

    printf ("Ingrese su opcion: \n\n");

    printf ("1. Ingresar el primer operando. (A = %d)\n", num1);
    printf ("2. Ingresar el segundo operando. (B = %d)\n", num2);
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
            fflush (stdin);
            scanf ("%d", &num1);
            break;

        case 2:
            printf ("Ingrese el segundo operando: ");
            fflush (stdin);
            scanf ("%d", &num2);
            break;
        case 3:
            printf ("Su opcion fue la 3\n");
            system ("pause");
            break;

        case 4:
            printf ("Su opcion fue la 4\n");
            system ("pause");
            break;

        case 5:
            printf ("Su opcion fue la 5\n");
            system ("pause");
            break;

        case 8:
            printf ("Esta seguro que desea salir? (s/n): ");
            fflush(stdin);
            scanf ("%c", &confirm);
        }


    }while (confirm != 's');


}


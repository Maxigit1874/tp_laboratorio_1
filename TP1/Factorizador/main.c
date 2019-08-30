#include <stdio.h>
#include <stdlib.h>

int main()
{

  int num;
  int resultado = 1;

  printf ("Ingrese el numero...");
  scanf ("%d", &num);


  for (int a = num; a >= 1; a-- ){

        resultado = resultado * a;
        printf ("%d\n", resultado);


  }




    return 0;
}

#include <stdio.h>
#include "misFunciones.h"

int main () {
    puts("\n---> AQUÍ COMIENZA EL PROGRAMA <---\n");

    int num, num_invertido;
    do {
        puts("\nIngrese un número positivo:\n");
        scanf("%d",&num);
    } while (num == 0);
    // Llamo a la funcion y le asigno el valor que devuelve a una variable en el main:
    num_invertido = invertirNumero (num);
    printf("\nNúmero invertido: %d\n",num_invertido);

    // Llamo al procedimiento:
    digitosImpares (num);

    puts("\n---> AQUÍ TERMINA EL PROGRAMA <---\n");
    return 0;
}
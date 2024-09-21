#include <stdio.h>
#include <math.h>

int invertirNumero (int a);
void digitosImpares (int a);

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


// DESARROLLO LAS FUNCIONES //

int invertirNumero (int a) {
    int m = 0, aux = a, num = 0, resto;

    do {
        aux = aux / 10;
        m++;
    } while (aux != 0);
    
    while (a != 0) {
        resto = a % 10;
        num += resto * pow (10,m-1);
        m--;
        a = a / 10;
    }

    return num;
}

void digitosImpares (int a) {
    int cont_impares = 0, resto;

    while (a != 0) {
        resto = a % 10;

        if ( resto % 2 == 1) {
            cont_impares++;
        }

        a = a  / 10;
    }

    printf("\nCantidad de dígitos impares: %d\n",cont_impares);
}
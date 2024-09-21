#include <stdio.h>
#include <math.h>

// DEFINO LAS FUNCIONES //

int invertirNumero (int a);
void digitosImpares (int a);

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
// NUMEROS PRIMOS //
#include <stdio.h>

int main () {
    int num, totalPrimos = 0, sumaPrimos = 0, i, j, contDivisores;

    for (i = 0 ; i < 3 ; i++) {
        contDivisores = 0;
        
        printf("\nIngrese un numero:\n");
        scanf("%d",&num);

        for (j = 0 ; j < num ; j++) {
            if ( num % j == 0 ) {
                contDivisores++;
            }
        }

        if (contDivisores == 2) {
            printf("\nEl numero %d es primo.\n");
            totalPrimos++;
            sumaPrimos += num;
        }
    }
    
    printf("\nLa cantidad de numeros primos ingresados fueron %d y su suma es %d\n",totalPrimos,sumaPrimos);

    return 0;
}
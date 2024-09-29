////////////////////////////////////////////////////
/// TP_01 : EJERCICIO_01 => "CALENTANDO-MOTORES" ///
////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "misFunciones.h"

int main () {
    int tama;
    do {
        printf("\n\nIngrese el tamanio que tendra el arreglo (MAX: 15): ");
        scanf("%d",&tama);
    } while (tama > 15);

    int arreglo[tama];
    int i, num1 = 10, num2 = 350;
    int numMayor, nuevoValor;
    srand(time(NULL));

    cargarArreglo (arreglo, tama, num1, num2);
    mostrarArreglo (arreglo, tama);
    numMayor = buscarMayor (arreglo, tama);
    printf("\nEl mayor valor encontrado en el arreglo es: [%d]\n",numMayor);
    mostrarPromedio (arreglo, tama);

    for (i = 0; i < tama; i++) {
        if (arreglo[i] > 300) {
            printf("\nIngrese un nuevo valor para la posicion %d del arreglo: ",i);
            scanf("%d",&nuevoValor);
            arreglo[i] = nuevoValor;
        }
    }
    printf("\nEl nuevo arreglo con los valores ingresados queda:\n");
    mostrarArreglo (arreglo, tama);

    for (i = 0; i < tama; i++) {
        if (arreglo[i] % 2 != 0) {
            arreglo[i]++;
        }
    }
    printf("\nEl nuevo arreglo con los valores impares incrementados en 1 queda:\n");
    mostrarArreglo (arreglo, tama);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/////////////

void cargarArreglo (int arreglo[], int tama, int num1, int num2);
void mostrarArreglo (int arreglo[], int tama);
int buscarMayor (int arreglo[], int tama);
void mostrarPromedio (int arreglo[], int tama);

/////////////

void cargarArreglo (int arreglo[], int tama, int num1, int num2) {

    for (int i = 0; i < tama; i++) {
        arreglo[i] = num1 + rand() % (num2 - num1 + 1);
    }

}

void mostrarArreglo (int arreglo[], int tama) {
    
    printf("\nArreglo:\n");
    for (int i = 0; i < tama; i++) {
        printf("[%d]",arreglo[i]);
    }
    printf("\n");

}

int buscarMayor (int arreglo[], int tama) {
    int mayor = 0;

    for (int i = 0; i < tama; i++) {
        if (arreglo [i] > mayor) {
            mayor = arreglo[i];
        }
    }

    return (mayor);
}

void mostrarPromedio (int arreglo[], int tama) {
    float promedio;
    int cont = 0, suma = 0;

    for (int i = 0; i < tama; i++) {
        if (i % 2 != 0) {
            cont ++;
            suma += arreglo[i];
        }
    }
    
    promedio = suma / cont;

    printf("\nEl promedio de todos los numeros almacenados en las posiciones impares es %.0f\n",promedio);
}
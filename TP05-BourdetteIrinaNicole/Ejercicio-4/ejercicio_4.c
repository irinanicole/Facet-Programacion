//////////////////////////////////////////////////
/// TP_01 : EJERCICIO_04 => "SUMA-DE-MATRICES" ///
//////////////////////////////////////////////////

#include <stdio.h>
#include "misFunciones.h"

#define N 30

int main ()
{
    printf("\n---> INICIO DEL PROGRAMA <---\n");
    
    int matrizA[N][N], matrizB[N][N], matrizSuma[N][N];
    int tama;
    
    printf("\nIngrese la dimension de las matrices cuadradas a sumar (< a 30): ");
    scanf("%d",&tama);


    printf("\nIngrese los elementos de la matriz A:\n");
    cargarMatriz(matrizA, tama);
    printf("\nMATRIZ A:\n");
    mostrarMatriz(matrizA, tama);

    printf("\nIngrese los elementos de la matriz B:\n");
    cargarMatriz(matrizB, tama);
    printf("\nMATRIZ B:\n");
    mostrarMatriz(matrizB, tama);

    sumarMatrices(matrizA, matrizB, matrizSuma, tama);
    printf("\n\nMATRIZ SUMA:\n");
    mostrarMatriz(matrizSuma, tama);


    printf("\n---> FIN DEL PROGRAMA <---\n");
    return 0;
}
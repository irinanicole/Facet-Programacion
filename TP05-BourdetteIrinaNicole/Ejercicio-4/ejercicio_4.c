//////////////////////////////////////////////////
/// TP_01 : EJERCICIO_04 => "SUMA-DE-MATRICES" ///
//////////////////////////////////////////////////

#include <stdio.h>

#define N 30

void cargarMatriz (int matriz[N][N], int tama);
void mostrarMatriz (int matriz[N][N], int tama);
void sumarMatrices (int matriz_1[N][N], int matriz_2[N][N], int resultado[N][N], int tama);

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

// FUNCIONES //
void cargarMatriz (int matriz[N][N], int tama)
{
    int i, j;
    for (i = 0; i < tama; i++)
    {
        for (j = 0; j < tama; j++)
        {
            scanf("%d",&matriz[i][j]);
        }
    }
}
void mostrarMatriz (int matriz[N][N], int tama)
{
    int i, j;
    for (i = 0; i < tama; i++)
    {
        for (j = 0; j < tama; j++)
        {
            printf("{%d}",matriz[i][j]);
        }
        printf("\n");
    }
}
void sumarMatrices (int matriz_1[N][N], int matriz_2[N][N], int resultado[N][N], int tama)
{
    int i, j;
    for (i = 0; i < tama; i++)
    {
        for (j = 0; j < tama; j++)
        {
            resultado[i][j] = matriz_1[i][j] + matriz_2[i][j];
        }
    }
}
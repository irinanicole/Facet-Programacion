//////////////////////////////////////////////////
/// TP_01 : EJERCICIO_04 => "SUMA-DE-MATRICES" ///
//////////////////////////////////////////////////

#include <stdio.h>

#define N 30

void cargarMatriz (int matriz[N][N], int tama);
void mostrarMatriz (int matriz[N][N], int tama);
void sumarMatrices (int matriz_1[N][N], int matriz_2[N][N], int resultado[N][N], int tama);


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
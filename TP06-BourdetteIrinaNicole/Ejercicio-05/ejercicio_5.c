/* "TIRO AL BLANCO" - VERSION 1.0 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//CONSTANTES
#define COSTO_TIRO 350

// Función para cargar los puntajes de los tiros.
void cargarTiros(int *puntos, int tiros);
// Función que calcula cuánto ganó en jugador.
float calcularGanancia(int *puntos, int tiros, float *perdida);

int main()
{
    int tiros, *puntos;
    float *perdida, ganancia, saldo_final;

    printf("\nIngrese la cantidad de tiros que desea realizar: ");
    scanf("%d",&tiros);

    puntos = (int *)malloc(tiros * sizeof(int));
    
    cargarTiros(puntos, tiros);
    *perdida = tiros * COSTO_TIRO;
    ganancia = calcularGanancia(puntos, tiros, perdida);

    saldo_final = ganancia - *perdida;
    printf("\nPerdida: - $%.2f",*perdida);
    printf("\nGanancia: + $%.2f",ganancia);
    printf("\nSaldo Final: $%.2f",saldo_final);
    
    
    return 0;
}

void cargarTiros(int *puntos, int tiros)
{
    srand(time(NULL));
    printf("\n-----TIROS-----");
    printf("\n  Nro Tiro | Puntaje");
    for (int i = 0; i < tiros; i++) {
        puntos[i] = 1 + rand() % 10;
        printf("\n\t%d -> %d",i+1,puntos[i]);
    }
    printf("\n---------------\n");
}

float calcularGanancia(int *puntos, int tiros, float *perdida)
{
    float ganancia = 0, premio;
    for (int i = 0; i < tiros; i++) {
        switch(puntos[i]) {
            case 10:
                premio = 1000;
                break;
            case 9:
                premio = 850;
                break;
            case 8:
                premio = 350;
                break;
            case 7:
                premio = 300;
                break;
            default:
                premio = 0;
        }
        ganancia += premio;

        if (puntos[i] == 1 || puntos[i] == 2) {
            *perdida += 100;
        }
    }
    
    return ganancia;
}
/* "TIRO AL BLANCO" - VERSION 1.1 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//CONSTANTES
#define COSTO_TIRO 350

// Función para cargar los puntajes de los tiros.
void cargarTiros(int *puntos, int tiros);
// Función que calcula cuánto ganó en jugador.
float calcularGanancia(int *puntos, int tiros, float *perdida, float *totalPerdida, float *totalGanancia);

int main()
{
    int jugador = 0, tiros, *puntos, fin;
    float perdida, ganancia, saldo_final;
    float totalPerdida = 0, totalGanancia = 0;

    do
    {
        jugador++;
        printf("\n=> JUGADOR %d <=\n",jugador);
        printf("\nIngrese la cantidad de tiros que desea realizar: ");
        scanf("%d",&tiros);

        puntos = (int *)malloc(tiros * sizeof(int));
        cargarTiros(puntos, tiros);
        
        perdida = tiros * COSTO_TIRO;
        ganancia = calcularGanancia(puntos, tiros, &perdida, &totalPerdida, &totalGanancia);

        saldo_final = ganancia - perdida;
        printf("\nGanancia: + $%.2f",ganancia);
        printf("\nPerdida: - $%.2f",perdida);
        printf("\nSaldo Final: $%.2f",saldo_final);
        
        printf("\n\n¿Desea terminar el juego? (si-> 1 | no -> 0): ");
        scanf("%d",&fin);
        free(puntos);
        
    } while (!fin);

    printf("\nTotal Ganancias: + $%.2f",totalGanancia);
    printf("\nTotal Perdidas: - $%.2f",totalPerdida);
    printf("\nSALDO TOTAL: $%.2f",(totalGanancia-totalPerdida));

    return 0;
}

void cargarTiros(int *puntos, int tiros)
{
    srand(time(NULL));
    printf("\n-----TIROS-----");
    printf("\n   Nro | Pje");
    for (int i = 0; i < tiros; i++) {
        puntos[i] = 1 + rand() % 10;
        printf("\n     %d -> %d",i+1,puntos[i]);
    }
    printf("\n---------------\n");
}
 //cambios version1.1
float calcularGanancia(int *puntos, int tiros, float *perdida, float *totalPerdida, float *totalGanancia)
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
    
    *totalPerdida += *perdida;
    *totalGanancia += ganancia;
    return ganancia;
}
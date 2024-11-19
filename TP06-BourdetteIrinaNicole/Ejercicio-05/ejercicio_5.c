/* "TIRO AL BLANCO" - VERSION 1.0 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//CONSTANTES
#define COSTO_TIRO 350.00

// Función para cargar los puntajes de los tiros.
void cargarTiros(int *puntos, int tiros);
// Función que calcula cuánto ganó en jugador.
float calcularGanancia(int *puntos, int tiros, float *perdida);

int main()
{
    srand(time(NULL));

    int tiros, *puntos;
    float perdida, ganancia, saldo_final;

    printf("\nIngrese la cantidad de tiros que desea realizar: ");
    scanf("%d",&tiros);

    puntos = (int *)malloc(tiros * sizeof(int));
    
    cargarTiros(puntos, tiros);
    perdida = tiros * COSTO_TIRO;
    ganancia = calcularGanancia(puntos, tiros, &perdida);

    saldo_final = ganancia - perdida;
    printf("\nGanancia: + $%.2f",ganancia);
    printf("\nPerdida: - $%.2f",perdida);
    printf("\nSaldo Final: $%.2f",saldo_final);
    
    
    return 0;
}

void cargarTiros(int *puntos, int tiros)
{
    printf("\n-----TIROS-----");
    printf("\n  Nro Tiro | Puntaje");
    for (int i = 0; i < tiros; i++) {
        puntos[i] = 1 + rand() % 10;
        printf("\n\t%d -> %d",i+1,puntos[i]);
    }
    printf("\n---------------\n");
}

float calcularGanancia(int *puntos, int tiros, float *perdida)
#define VERSION 3
#if   VERSION == 1
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
                case 1:
                case 2:
                    premio = 0;
                    *perdida += 100;
                    break;
                default:
                    premio = 0;
            }
            ganancia += premio;
        }
        
        return ganancia;
    }
#elif VERSION == 2
    {
        float ganancia = 0;
        for (int i = 0; i < tiros; i++) {
            switch(puntos[i]) {
                case 10:  ganancia += 1000;  break;
                case  9:  ganancia +=  850;  break;
                case  8:  ganancia +=  350;  break;
                case  7:  ganancia +=  300;  break;
                case 1:
                case 2:
                    *perdida += 100;
                    break;
            }
        }
        
        return ganancia;
    }
#elif VERSION == 3
    {
        static float premio[ 10 ] = { 0, 0, 0, 0, 0, 0, 300, 350, 850, 1000 };
        float ganancia = 0;
        for (int i = 0; i < tiros; i++) {
            ganancia += premio[ puntos[i] - 1 ];

            switch(puntos[i]) {
                case 1:
                case 2:
                    *perdida += 100;
                    break;
            }
        }
        
        return ganancia;
    }
#endif

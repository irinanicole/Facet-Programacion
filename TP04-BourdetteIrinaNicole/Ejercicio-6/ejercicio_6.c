#include <stdio.h>
#include <stdbool.h>
#include "misFunciones.h"

int main () {
    puts("\n---> AQUÍ COMIENZA EL PROGRAMA <---\n");

    int ladoA, ladoB, ladoC;
    char angulo;
    float alpha_rad, alpha_gra;
    bool esTrianguloRectangulo = true;

    // VERIFICAR QUE NO ES TRIANGULO RECTANGULO //
    while (esTrianguloRectangulo) {
        printf("\nIngrese los 3 lados del triangulo oblicuangulo:\n");
        scanf("%d %d %d",&ladoA,&ladoB,&ladoC);
        esTrianguloRectangulo = verificarTriangR (ladoA,ladoB,ladoC);
        if (esTrianguloRectangulo) {
            puts("Triangulo rectangulo, elija otro metodo para calcular los angulos.");
        }
    }

    printf("\nSeleccione el angulo que desee conocer:");
    printf("\n'A' --> Angulo opuesto al lado a\n'B' --> Angulo opuesto al lado b\n'C' --> Angulo opuesto al lado c\n");
    scanf(" %c",&angulo);

    // CALCULAR ANGULOS EN RADIANES Y GRADOS //
    alpha_rad = calcularAngulo (ladoA,ladoB,ladoC,angulo);
    alpha_gra = convertirRadianes_Grados(alpha_rad);

    printf("\nLados:\na = %d | b = %d | c = %d",ladoA,ladoB,ladoC);
    printf("\nAngulo %c --> %.2f Radianes | %.2f Grados\n",angulo,alpha_rad,alpha_gra);

    puts("\n---> AQUÍ COMIENZA EL PROGRAMA <---\n");
    return 0;
}
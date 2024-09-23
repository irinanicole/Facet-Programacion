#include <stdio.h>
#include <math.h>
#define PI 3.14

int mostrarMenu ();
void calcularCuadrado (int l);
void calcularRectangulo (int b, int h);
void calcularCirculo (int r);
void calcularTrianguloEq (int l);

int mostrarMenu () {
    int opcion;

    printf("\nMENU: FIGURAS GEOMETRICAS\n");
    printf("\n\t1 -> Cuadrado\n\t2 -> Rectangulo\n\t3 -> Circulo\n\t4 -> Triangulo Equilatero\n");
    printf("\nEliga una figura del 1 al 4 para calcular su AREA y PERIMETRO correspondientes.\n\nElegir figura: ");
    scanf("%d",&opcion);

    return (opcion);
}

void calcularCuadrado ( int l) {
    float a, p;
    // CALCULOS //
    a = pow(l,2);
    p = 4 * l;
    // MOSTRAR RESULTADOS OBTENIDOS //
    printf("\n\tArea: %.2f\n\tPerimetro: %.2f\n",a,p);
}

void calcularRectangulo ( int b, int h) {
    float a, p;
    // CALCULOS //
    a = b * h;;
    p = 2 * (b + h);
    // MOSTRAR RESULTADOS OBTENIDOS //
    printf("\n\tArea: %.2f\n\tPerimetro: %.2f\n",a,p);
}

void calcularCirculo ( int r) {
    float a, p;
    // CALCULOS //
    a = PI * pow(r,2);
    p = 2 * PI * r;
    // MOSTRAR RESULTADOS OBTENIDOS //
    printf("\n\tArea: %.2f\n\tPerimetro: %.2f\n",a,p);
}

void calcularTrianguloEq ( int l) {
    float a, p;
    // CALCULOS //
    a = (sqrt(3)/4) * pow(l,2);
    p = 3 * l;
    // MOSTRAR RESULTADOS OBTENIDOS //
    printf("\n\tArea: %.2f\n\tPerimetro: %.2f\n",a,p);
}
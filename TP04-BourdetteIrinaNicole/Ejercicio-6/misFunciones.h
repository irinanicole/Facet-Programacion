#include <math.h>
#include <stdbool.h>

bool verificarTriangR ( int a, int b, int c);
float calcularAngulo (int a, int b, int c, char x);
float convertirRadianes_Grados (float x_radian);

bool verificarTriangR ( int a, int b, int c) {
    bool esTriangRec;
    float hipo, cat1, cat2;

    if (a >= b  &&  a >= c) {
        hipo = a;
        cat1 = b;
        cat2 = c;
    } else if (b >= a  &&  b >= c) {
        hipo = b;
        cat1 = a;
        cat2 = c;
    } else if (c >= a  &&  c >= b) {
        hipo = c;
        cat1 = a;
        cat2 = b;
    }

    if ( pow(cat1,2) + pow(cat2,2) == pow(hipo,2) ) {
        esTriangRec = true;
    } else {
        esTriangRec = false;
    }

    return (esTriangRec);
}

float calcularAngulo (int a, int b, int c, char x) {
    float resultado, y;
    switch (x) {
        case 'A':
        case 'a':
            y = (pow(a,2) - pow(b,2) - pow(c,2)) / - (2 * b * c);
            break;
        case 'B':
        case 'b':
            y = (pow(b,2) - pow(a,2) - pow(c,2)) / - (2 * a * c);
            break;
        case 'C':
        case 'c':
            y = (pow(c,2) - pow(a,2) - pow(b,2)) / - (2 * a * b);
            break;
        default:
            puts("\nHubo un error con la/s operacion/es.\n");
            y = 0;
    }
    
    resultado = acos(y);

    return (resultado);
}

float convertirRadianes_Grados (float x_radianes) {
    float x_grados;
    x_grados = x_radianes * (180 / M_PI);
    return (x_grados);
}
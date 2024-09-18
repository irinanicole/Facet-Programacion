#include <math.h>
// Defino todas las funciones que voy a crear:
int selector_operacion(int op, int a, int b);
//
int suma (int a, int b);
int resta (int a, int b);
int producto (int a, int b);
int division_entera (int a, int b);
int potencia (int a, int b);

////////// Desarrollo cada funcion //////////

int selector_operacion(int op, int a, int b) {
    int result;

    switch (op) {
        case 1:
            printf("\nUsted ha elegido la opcion SUMA.\n");
            result = suma (a, b);
            printf("\nEl resultado de la operación %d + %d es igual a %d", a, b, result,"\n");
            break;
        case 2:
            printf("\nUsted ha elegido la opcion RESTA.\n");
            result = resta (a, b);
            printf("\nEl resultado de la operación %d - %d es igual a %d", a, b, result,"\n");
            break;
        case 3:
            printf("\nUsted ha elegido la opcion PRODUCTO.\n");
            result = producto (a, b);
            printf("\nEl resultado de la operación %d x %d es igual a %d", a, b, result,"\n");
            break;
        case 4:
            printf("\nUsted ha elegido la opcion DIVISION (entera).\n");
            result = division_entera (a, b);
            if (result != 0) {
                printf("\nEl resultado entero de la operación %d / %d es igual a %d", a, b, result,"\n");
            } else {
                printf("\nNo se puede realizar una DIVISION ENTERA entre %d y %d porque el dividendo es más chico que el divisor :(\n", a, b);
            }
            break;
        case 5:
            printf("\nUsted ha elegido la opcion POTENCIA.\n");
            result = potencia (a, b);
            printf("\nEl resultado de la operación %d elevado a %d es igual a %d", a, b, result,"\n");
            break;
        default:
            printf("\nUsted ha elegido SALIR DEL PROGRAMA.\n");
    }

    return (result);
}

int suma (int a, int b) {
    int result;

    result = a + b;

    return (result);
}

int resta (int a, int b) {
    int result;

    result = a - b;

    return (result);
}

int producto (int a, int b) {
    int result, i;

    result = 0;

    for (i = 0 ; i < b ; i++) {
         result += a;
     }

    return (result);
}

int division_entera (int a, int b) {
    int result, i;
    result = 0;
    
    if (a >= b) {
        i = a;
        while ( i >= b) {
            i -= b;
            result++;
        }
    }
    
    return (result);
}

int potencia (int a, int b) {
    int result, i;
    result = 1;

    for (i = 0 ; i < b ; i++) {
       result = producto (result, a);
    }

    return (result);
}
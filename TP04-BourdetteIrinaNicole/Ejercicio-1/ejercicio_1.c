#include <stdio.h>
#include <math.h>
#include "misFunciones.h" // incluyo mi biblioteca en el archivo .c principal

// Defino todas las funciones que voy a crear:
// int selector_operacion(int op, int a, int b);

int suma (int a, int b);
int resta (int a, int b);
int producto (int a, int b);
int division_entera (int a, int b);
int potencia (int a, int b);

int main() {

    printf("\n---> AQUÍ COMIENZA EL PROGGRAMA <---\n");

    int operacion, num1, num2, resultado;

    printf("Ingrese dos numeros enteros positivos: \n");
    scanf("%d %d", &num1, &num2);

    do {
        resultado = 0;
        printf("\nEliga una operación: \n");
        printf("'1' <-- Suma\n");
        printf("'2' <-- Resta\n");
        printf("'3' <-- Producto\n");
        printf("'4' <-- División\n");
        printf("'5' <-- Potencia\n");
        printf("'0' <-- TERMINAR\n");
        scanf("%d", &operacion);

        switch (operacion) {
            case 1:
                printf("\nUsted ha elegido la opcion SUMA.\n");
                resultado = suma (num1, num2);
                printf("\nEl resultado de la suma entre %d y %d es igual a %d",num1,num2,resultado,"\n");
                break;
            case 2:
                printf("\nUsted ha elegido la opcion RESTA.\n");
                break;
            case 3:
                printf("\nUsted ha elegido la opcion PRODUCTO.\n");
                break;
            case 4:
                printf("\nUsted ha elegido la opcion DIVISION.\n");
                break;
            case 5:
                printf("\nUsted ha elegido la opcion POTENCIA.\n");
                break;
            default:
                printf("\nUsted ha elegido SALIR DEL PROGRAMA.\n");
        }

    } while (operacion != 0) ;

    printf("\n---> AQUÍ TERMINA EL PROGGRAMA <---\n");
    
    return 0;
}

// Desarrollo cada funcion

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

// int producto (int a, int b);

// int division_entera (int a, int b);

// int potencia (int a, int b);
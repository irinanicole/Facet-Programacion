#include <stdio.h>
#include "misFunciones.h" // incluyo mi biblioteca en el archivo .c principal

int main() {

    printf("\n---> AQUÍ COMIENZA EL PROGGRAMA <---\n");

    int operacion, num1, num2, resultado;

    printf("Ingrese dos numeros enteros positivos: \n");
    scanf("%d %d", &num1, &num2);

    do {

        printf("\nEliga una operación: \n");
        printf("'1' <-- Suma\n");
        printf("'2' <-- Resta\n");
        printf("'3' <-- Producto\n");
        printf("'4' <-- División\n");
        printf("'5' <-- Potencia\n");
        printf("'0' <-- TERMINAR\n");
        scanf("%d", &operacion);

        resultado = selector_operacion (operacion, num1, num2);

    } while (operacion != 0) ;

    printf("\n---> AQUÍ TERMINA EL PROGRAMA <---\n");
    
    return 0;
}
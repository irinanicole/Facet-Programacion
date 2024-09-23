#include <stdio.h>
#include "misFunciones.h"

int main () {
    puts("\n---> AQUÍ COMIENZA EL PROGRAMA <---\n");

    int figura, lado, radio, base, altura, fin = 0;

    while (fin != 1) {
        // MUESTRO MENU Y ELIJO figura PARA CALCULAR //
        figura = mostrarMenu();

        // PEDIR DATOS SEGUN FIGURA. LUEGO CALCULAR AREA Y PERIMETRO, Y MOSTRARLOS //
        switch (figura) {
            case 1:
                printf("\nFigura elegida: CUADRADO\nIngrese el valor del LADO: ");
                scanf("%d",&lado);
                calcularCuadrado(lado);
                break;
            case 2:
                printf("\nFigura elegida: RECTANGULO\nIngrese el valor de la BASE y luego de la ALTURA: ");
                scanf("%d %d",&base,&altura);
                calcularRectangulo(base,altura);
                break;
            case 3:
                printf("\nFigura elegida: CIRCULO\nIngrese el valor del RADIO: ");
                scanf("%d",&radio);
                calcularCirculo(radio);
                break;
            case 4:
                printf("\nFigura elegida: TRIANGULO EQUILATERO\nIngrese el valor del LADO: ");
                scanf("%d",&lado);
                calcularTrianguloEq(lado);
                break;
            default:
                puts("\nLa opcion elegida no es válida. Vuelva a elegir.\n");
        }
        puts("\n\n¿Desea terminar el programa? (0.NO / 1.SI): ");
        scanf("%d",&fin);
    }

    
    puts("\n---> AQUÍ TERMINA EL PROGRAMA <---\n");
    return 0;
}
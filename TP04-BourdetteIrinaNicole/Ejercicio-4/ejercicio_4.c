#include <stdio.h>
#include "misFunciones.h"


int main () {
    puts("\n---> AQUÍ COMIENZA EL PROGRAMA <---\n");

    int opcionProducto, opcionPago;
    float precioProducto, precioFinal, totalRecaudado = 0;
    int fin = 0;

    // AQUÍ VAN TODOS //
    // LOS CÁCULOS //
    // POR JORNADA //
    while (fin != 1) {
        puts("\n\t----> NUEVO CLIENTE <----\n");
        mostrarMenuCategorias();
        scanf("%d",&opcionProducto);
        mostrarMenuPagos();
        scanf("%d",&opcionPago);
        precioProducto = calcularPrecio(opcionProducto);
        precioFinal = calcularPrecioFinal(opcionPago, precioProducto);
        printf("\n--> El precio final a pagar por el cliente es: $%.2f\n", precioFinal);

        totalRecaudado += precioFinal;
        puts("\n\n¿Desea terminar el programa? (0.NO / 1.SI): ");
        scanf("%d",&fin);
    }


    printf("\nEl total recaudado en un día de ventas: $%f\n", totalRecaudado);


    puts("\n---> AQUÍ TERMINA EL PROGRAMA <---\n");
    return 0;
}
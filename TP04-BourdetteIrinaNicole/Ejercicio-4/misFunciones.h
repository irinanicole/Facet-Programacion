#include <stdio.h>

#define precioHeladera 850000
#define precioLavarropas 759000
#define precioMicroondas 520000
#define precioLaptop 1500000
#define precioTablet 755000
#define precioSmartphone 539000

#define efectivo 0.9
#define tarjeta_cuota1 1
#define tarjeta_cuota3 1.15
#define tarjeta_cuota6 1.25
// INICIALIZO LAS FUNCIONES //
float calcularPrecio ( int producto) {
    float precio;
    switch (producto) {
        case 0:
            precio = precioHeladera;
            break;
        case 1:
            precio = precioLavarropas;
            break;
        case 2:
            precio = precioMicroondas;
            break;
        case 3:
            precio = precioLaptop;
            break;
        case 4:
            precio = precioTablet;
            break;
        case 5:
            precio = precioSmartphone;
            break;
        default:
            puts("\nLa opcion elegida no es válida.\n");
            precio = 0;
    }

    return (precio);
}

float calcularPrecioFinal ( int formaPago, float precioProduc ) {
    float precio_f;
    switch (formaPago) {
        case 0:
            precio_f = precioProduc * efectivo;
            break;
        case 1:
            precio_f = precioProduc * tarjeta_cuota1;
            break;
        case 2:
            precio_f = precioProduc * tarjeta_cuota3;
            break;
        case 3:
            precio_f = precioProduc * tarjeta_cuota6;
            break;
        default:
            puts("\nLa forma de pago elegida es errónea.\n");
            precio_f = 0;
    }

    return (precio_f);
}

void mostrarMenuCategorias () {
    printf("\n\tELECTRODOMESTICOS:\n");
    printf("\n\t0 -> Heladera: $%d\n\t1 -> Lavarropas: $%d\n\t2 -> Microondas: $%d\n",precioHeladera,precioLavarropas,precioMicroondas);
    printf("\n\n\tINFORMATICA:\n");
    printf("\n\t3 -> Laptop: $%d\n\t4 -> Tablet: $%d\n\t5 -> Smartphone: $%d\n",precioLaptop,precioTablet,precioSmartphone);

    printf("\n\nElija una opcion del 0 al 5: ");
}

void mostrarMenuPagos () {
    printf("\n\tMETODOS DE PAGO:\n");
    printf("\n\t0 -> Efectivo: obtine un 10%% de descuento\n\t-> Tajetas de Crédito <-\n\t1 -> 1 Cuota: no hay ningún descuento ni recargo\n\t2 -> 3 Cuotas: hay un recargo del 15%%\n\t3 -> 6 Cuotas: hay un recargo del 25%%\n");

    printf("\nElija una opcion del 0 al 3: ");
}
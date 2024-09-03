#include <stdio.h>

#define IVA 0.21
#define descuentoA 0.20
#define descuentoB 0.10
#define descuentoAd 0.05



int main() {

    float precio, precio_final;
    char categoria;

    printf("\n-------> INICIO DEL PROGRAMA <-------\n");

    printf("\nIngrese el precio del producto que desea comprar: \n");
    scanf("%f", &precio);

    printf("\nIngrese la categoria de cliente ('A', 'B' o 'C') a la que pertenece: \n");
    fflush(stdin);
    scanf("%c", &categoria);

    // Calculo primero el precio de acuerdo al IVA:
    precio_final = precio + precio*IVA;

    printf("\nEl costo del producto con IVA es: %2.f", precio_final);

    switch (categoria) {
        case 65:
            precio_final = precio_final - precio_final*descuentoA;
            printf("\nTiene un descuento del 20/100");
            break;
        case 66: 
            precio_final = precio_final - precio_final*descuentoB;
            printf("\nTiene un descuento del 10/100");
            break;
        case 67:
        printf("\nLo sentimos, su categoría no admite descuentos :'C");    
    }
    if (precio > 10000){
        precio_final = precio_final - precio_final*descuentoAd;
        printf("\n>>>>>>> ¡Felicidades! Usted obtuvo un descuento del 10/100 por gastar más de $10.000 ;D <<<<<<<\n");
    }
    printf("\nEl precio final del producto es: %2.f", precio_final);

    printf("\n-------> FIN DEL PROGRAMA <-------\n");

    return 0;
}
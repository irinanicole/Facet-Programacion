// EJERCICIO 1 - "VOCALES ABIERTAS"
// Contar la cantidad de vocales ABIERTAS que hay en una oracion y al ultimo mostrar el conteo total de cada una con el total de vocales entre las tres.

#include <stdio.h>

int main() {

// define punto ".";
    char frase, punto;
    int cant_a, cant_e, cant_o, total_vocales;

    /// Inicializo las siguientes variables para el conteo y la marca final de la oracion:
    cant_a = 0;
    cant_e = 0;
    cant_o = 0;
    punto = 46;

    /// Comienzo la iteración Do-While para ingresar la oracion, contar las vocales y que termine cuando el usuario escriba un punto:
    
    printf("Escriba una oración:\n");
    do {
        scanf("%c",&frase);
        //// Cuento vocales
        switch (frase) {
            case 'a':
                cant_a++;
                break;
            case 'e':
                cant_e++;
                break;
            case 'o':
                cant_o++;
                break;
            default:;
        }
    } while (frase != punto);

    /// Calculo el total de todas las vocales:
    total_vocales = cant_a + cant_e + cant_o;

    /// Procedo a mostrar todo por pantalla:
    printf("\nCantidad de A: %d", cant_a);
    printf("\nCantidad de E: %d", cant_e);
    printf("\nCantidad de O: %d", cant_o);
    printf("\nTotal: %d", total_vocales);

    return 0;
}
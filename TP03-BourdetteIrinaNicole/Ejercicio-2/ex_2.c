// EJERCICIO 2 - PALABRAS MÁS, PALABRAS MENOS

#include <stdio.h>
#define MF '.'
#define espacio ' '

int main () {
    char cc;
    int letras_pLarga = 0, letras_pCorta = 0, contLetras = 0;

    printf("\nIngrese una oracion a continuacion:\n");
    do {
        scanf("%c",&cc);

        if (cc != espacio && cc != MF) {
            contLetras ++;

        } else {
            if (letras_pCorta == 0 || letras_pCorta > contLetras) {
                letras_pCorta = contLetras;
            }
            if (letras_pLarga < contLetras) {
                letras_pLarga = contLetras;
            }
            contLetras = 0;
        }
    } while (cc != MF);

    printf("\n\tPalabra mas larga: %d\n\tPalabra mas corta: %d\n",letras_pLarga,letras_pCorta);

    return 0;
}
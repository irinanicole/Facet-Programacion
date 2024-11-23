#include <stdio.h>

int main () {
    char prev, cc, MF = '.';
    int cont, p_mayor, cant_p;
    // INICIALIZO
    cant_p = 0;
    p_mayor = 0;
    // Ingreso la oración por medio de un bucle
    printf("\nIngrese una oración terminada en un punto:\n");
    do
    {
        // Inicializo el contador cada vez que comienza una palabara nueva (despues de un espacio)
        cont = 0;
        do {
            scanf("%c",&cc); // leo carácter por carácter

            if (prev==' ' && cc == 'p') {
                cont++; // el contador comienza a incrementar si el primer carácter leído es una 'p' luego de un espacio 
            }
            if (cont==1 && cc=='r') {
                cont++; // incremento el contador si el segundo carácter de la palabra es una 'r'
            }
            if (cont==2 && cc=='e') {
                cont++; // incremento el contador si el tercer carácter de la palabra es una 'e'
                cant_p++; // incremento en uno la cantidad de palabras que comienzan con 'pre'
            }

            if (cont >= 3) { // si no cumple con los requisitos anteriores el contador nunca llega 3 y no sigue contando los caracteres que ingresan
                cont++;
            }

        } while (cc != ' ' && cc != MF);
        
        if (p_mayor < (cont-2)) {
            p_mayor = cont-2;
        }
        // Actualizo 'prev' para el análisis de la siguiente palabra
        prev = cc; // prev = ' '
    } while (cc != MF);

    printf("\nCantidad de palabras que comienzan con 'pre': %d\n",cant_p);
    printf("\nCantidad de carácteres de la palabra más larga en la oración que comienza con 'pre': %d\n",p_mayor);
    
    return 0;
}
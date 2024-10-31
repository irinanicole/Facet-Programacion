#include <stdio.h>
#include <ctype.h>

int main () {
    
    char frase[100];
    char *pcadena;
    int *pcontConsonantes = 0;

    printf("\nIngrese un frase: ");
    gets(frase);
    pcadena = frase;

    while (*pcadena != '\0') {
        if (*pcadena != 'a' && *pcadena != 'A' && *pcadena != 'e' && *pcadena != 'E' && *pcadena != 'i' && *pcadena != 'I' && *pcadena != 'o' && *pcadena != 'O' && *pcadena != 'u' && *pcadena != 'U') {
            *pcadena = toupper(*pcadena);
            *pcontConsonantes++;
        }
        pcadena++;
    }

    puts(frase);

    char *punt;
    *punt = frase[0];
    punt = frase;
    printf("\n\nDireccion de la variable puntero 'punt': &punt => %p",&punt);
    printf("\nDireccion de la primera componente del arreglo 'frase': punt => %p",punt);
    printf("\nContenido de la primera componente del arreglo 'frase': *punt => %c",*punt);
    //
    printf("\n\nContenido de la cuarta celda del arreglo 'frase': frase[3] => %c",frase[3]);
    printf("\nContenido de la cuarta celda del arreglo 'frase' (punt + 3): *punt => %c",*(punt+3));
    //
    printf("\n\nDireccion de la sexta celda del arreglo 'frase' (punt += 5): *punt => %p",punt+5);
    printf("\nContenido de la sexta celda del arreglo 'frase' (punt += 5): *punt => %c",*(punt+5));


    
    
    return 0;
}
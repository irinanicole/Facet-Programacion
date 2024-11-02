#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
    punt = frase;
    // 3)
    printf("\n\nDireccion de la variable puntero 'punt': &punt => %p",&punt);
    printf("\nDireccion de la primera componente del arreglo 'frase': punt => %p",punt);
    printf("\nContenido de la primera componente del arreglo 'frase': *punt => %c",*punt);
    // 4)
    printf("\n\nContenido de la cuarta celda del arreglo 'frase': frase[3] => %c",frase[3]);
    printf("\nContenido de la cuarta celda del arreglo 'frase' (punt + 3): *punt => %c",*(punt+3));
    // 5)
    printf("\n\nDireccion de la sexta celda del arreglo 'frase' (punt + 5): *punt => %p",punt+5);
    printf("\nContenido de la sexta celda del arreglo 'frase' (punt + 5): *punt => %c",*(punt+5));
    // 6.a) Visualización de las componentes del vector frase mediante notación de punteros:
    printf("\n\nComponenentes del vector frase[] mediante notacion de punteros (punt++): ");
    while (*punt != '\0')
    {
        printf("%c",*punt);
        punt++;
    }
    // 6.a) Visualización de las componentes del vector frase mediante subíndices del punetero punt:
    printf("\n\nComponentes del vector frase[] mediante subindices de puntero (punt[i]): ");
    int longitud = strlen(frase);
    char *puntB; puntB = frase;
    for (int i = 0; i < longitud; i++)
    {
        printf("%c",puntB[i]);
    }


    return 0;
}
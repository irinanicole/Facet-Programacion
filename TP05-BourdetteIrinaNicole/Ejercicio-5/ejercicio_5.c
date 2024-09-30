///////////////////////////////////////////////////////
/// TP_01 : EJERCICIO_04 => "ADIVINANDO_LA_PALABRA" ///
///////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#define TAMA 20

void inicializarPalabraIncognita(char arre[TAMA], int tama);
int juegoAdivinar(char pAdivina[TAMA], char pOriginal[TAMA], int tama);

int main ()
{
    char palabra[TAMA], pIncognita[TAMA], salto_linea = '\n';
    int longitud, resultado;
    
    printf("\nIngrese la palabra para comenzar: ");
    gets(palabra);

    longitud = strlen(palabra);

    inicializarPalabraIncognita(pIncognita, longitud);

    // printf("\nPalabra secreta: ");
    // puts(pIncognita);

    printf("\n¡Comienza el juego de adivinar la palabra secreta!\n");
    resultado = juegoAdivinar(pIncognita, palabra, longitud);

    if (resultado)
    {
        printf("\n\n¡Felicidades has adivinado la palabra secreta!\nPalabra secreta: ");
        puts(palabra);
    }
    else
    {
        printf("\n\nTus intentos se han agotado :(\nLa palabra secreta era: ");
        puts(palabra);
        printf("\n\n¡Mejor más suerte para la próxima! :)\n");
    }


    return 0;
}

// FUNCIONES //
void inicializarPalabraIncognita(char arre[TAMA], int tama)
{
    char guion = '-';

    for (int i=0; i<tama; i++)
    {
        if (i==tama)
        {
            arre[i] = '\0';
        }
        else
        {
            arre[i] = guion;
        }
    }
}

int juegoAdivinar(char pAdivina[TAMA], char pOriginal[TAMA], int tama)
{
    int resul;
    int aciertos=0, intentos=3, vecesLetra, fin=0;
    char letra;

    while (intentos!=0 && fin!=1)
    {
        printf("\nPalabra Secreta: ");
        puts(pAdivina);
        printf("\nIntentos: %d\n",intentos);

        vecesLetra = 0;

        printf("\n\nIngresa una letra: ");
        scanf(" %c",&letra);

        for (int i=0; i<tama; i++)
        {
            if (letra == pOriginal[i])
            {
                pAdivina[i] = letra;
                vecesLetra++;
            }
        }

        if (vecesLetra > 0)
        {
            aciertos += vecesLetra;
        }
        else
        {
            printf("\n(No hay letra '%c' en la palabra)\n",letra);
            intentos--;
        }

        if (aciertos == tama)
        {
            fin = 1;
        }
    }
    
    if (intentos > 0)
    {
        resul = 1;
    }
    else
    {
        resul = 0;
    }

    return (resul);
}
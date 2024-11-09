/* VERSION 1.1 */
// INSERTAR LA SEGUNDA CADENA EN LA PRIMERA, a partir del carácter que está en la posición indicada por el número.
// Mostrar la primera cadena modificada.

//MISMO EJERCICIO 3 USANDO FUNCIONES PARA ASIGNACION DINAMICA DE PUNTEROS//
#include <stdio.h>
#include <stdlib.h>

void mezclarCadenas (char *cad1, char *cad2, int pos);

int main ()
{
    char *cad1, *cad2;
    int posicion, long1, long2;

    cad1 = (char *)malloc(sizeof(char));
    cad2 = (char *)malloc(sizeof(char));

    printf("\nEscriba la primera frase: ");
    gets(cad1);
    printf("\nEscriba la segunda frase: ");
    gets(cad2);
    printf("\nIngrese un numero para concatenar la cadena 2 a la cadena 1 en esa posicion: ");
    scanf("%d", &posicion);

    printf("\nCadena 1: ");
    puts(cad1);
    printf("Cadena 2: ");
    puts(cad2);
    printf("Numero: %d", posicion);

    mezclarCadenas(cad1, cad2, posicion);
    
    printf("\n\tCadena 1 de salida: ");
    puts(cad1);

    free(cad1);
    free(cad2);

    return 0;
}

void mezclarCadenas (char *cad1, char *cad2, int pos)
{
    int i = pos-1, j = 0;
    char aux[100];

    // Copiar caracteres de cad1 a aux desde posicion pos
    while (cad1[i] != '\0')
    {
        aux[j] = cad1[i];
        i++;
        j++;
    }
    aux[j] = '\0'; // agrega caracter nulo

    // Insertar cad2 en cad1 a partir de la posicion pos
    i = pos-1;
    j = 0;
    while (cad2[j] != '\0')
    {
        cad1[i] = cad2[j];
        i++;
        j++;
    }

    // Reiniciar el indice j para usar aux y colocar su contenido devuelta en cad1
    j = 0;
    while (aux[j] != '\0')
    {
        cad1[i] = aux[j];
        j++;
        i++;
    }
    cad1[i] = '\0'; // Asegurar el caracter nulo al final de la cadena cad1
}
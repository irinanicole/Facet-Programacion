#include <stdio.h>

void mezclarCadenas (char *cad1, char *cad2, int pos);

int main ()
{
    char cadena1[100], cadena2[100], *cadena1Aux, *cadena2Aux;
    int posicion;

    printf("\nEscriba la primera frase: ");
    gets(cadena1);
    printf("\nEscriba la segunda frase: ");
    gets(cadena2);
    printf("\nIngrese un numero para concatenar la cadena 2 a la cadena 1 en esa posicion: ");
    scanf("%d", &posicion);

    printf("\nCadena 1: ");
    puts(cadena1);
    printf("Cadena 2: ");
    puts(cadena2);
    printf("Numero: %d", posicion);

    cadena1Aux = cadena1;
    cadena2Aux = cadena2;

    mezclarCadenas(cadena1Aux, cadena2Aux, posicion);
    
    printf("\nCadena 1 de salida: ");
    puts(cadena1Aux);

    return 0;
}

void mezclarCadenas (char *cad1, char *cad2, int pos)
{
    int i = pos-1, j = 0;
    char *aux;
    while (*cad2 != '\0')
    {
        *aux = cad1[i];
        cad1[i] = cad2[j];
        aux++;
        cad1++;
        j++;
    }
    i = 0;
    j--;
    while (*cad1 != '\0')
    {
        cad1[j] = aux[i];
        j++;
        i++;
    }
    printf("hola");
    // while (*cad1 != '\0')
    // {
    //     if (i == (pos-1))
    //     {
    //         while (*cad2 != '\0')
    //         {
    //             *aux = *cad1;
    //             *cad1 = &cad2[j];
    //             aux++;
    //             cad1++;
    //             j++;
    //         }
    //     }
    //     i++;
    // }
}
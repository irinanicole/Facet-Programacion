//////////////////////////////////////////////////////
/// TP_01 : EJERCICIO_03 => "CONCATENANDO-CADENAS" ///
//////////////////////////////////////////////////////

#include <stdio.h> // main()
#include <string.h> // main() ; "misFunciones.h"

#define TAMA 30

void cargarNombreCompleto (char arreglo[]);
void cargarNombreSinEspacios (char arreglo1[], char arreglo2[], int tama);

int main ()
{
    printf("\n---> INICIO DEL PROGRAMA <---\n");
    char persona[TAMA], nombreSinEspacios[TAMA];
    int longitud;

    printf("\nIngrese APELLIDO y NOMBRES (en ese orden): ");
    cargarNombreCompleto(persona);
    printf("\nEl nombre completo ingresado fue: ");
    puts(persona);
    longitud = strlen(persona);
    cargarNombreSinEspacios(persona, nombreSinEspacios, longitud);
    printf("\nEl nombre completo SIN ESPACIOS es: ");
    puts(nombreSinEspacios);

    printf("\n---> FIN DEL PROGRAMA <---\n");
    return 0;
}


void cargarNombreCompleto (char arreglo[])
{
    int i = 0;
    char letra, salto_linea = '\n';
    do
    {
        scanf("%c",&letra);
        arreglo[i] = letra;
        i++;
    }
    while (letra != salto_linea);
}

void cargarNombreSinEspacios (char arreglo1[], char arreglo2[], int tama)
{
    int i = 0, j = 0;
    while (i < (tama - 1))
    {
        if (arreglo1[i] != ' ') // distinto de espacio
        {
            arreglo2[j] = arreglo1[i];
            j++;
        }
        i++;
    }
    arreglo2[j] = '.'; // le asigno un punto al final del arreglo.
}
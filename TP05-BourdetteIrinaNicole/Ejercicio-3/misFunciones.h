//////////////////////////////////////////////////////
/// TP_01 : EJERCICIO_03 => "CONCATENANDO-CADENAS" ///
//////////////////////////////////////////////////////

#include <string.h> // main() ; "misFunciones.h"
#define TAMA 30
//
void cargarNombreCompleto (char arreglo[TAMA]);
void cargarNombreSinEspacios (char arreglo1[TAMA], char arreglo2[TAMA], int tama);
//
void cargarNombreCompleto (char arreglo[TAMA])
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

void cargarNombreSinEspacios (char arreglo1[TAMA], char arreglo2[TAMA], int tama)
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
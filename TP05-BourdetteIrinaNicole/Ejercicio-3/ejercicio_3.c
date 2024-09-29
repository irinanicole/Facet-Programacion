//////////////////////////////////////////////////////
/// TP_01 : EJERCICIO_03 => "CONCATENANDO-CADENAS" ///
//////////////////////////////////////////////////////

#include <stdio.h> // main()
#include <string.h> // main() ; "misFunciones.h"
#include "misFunciones.h"

#define TAMA 30

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
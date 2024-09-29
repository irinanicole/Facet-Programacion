/////////////////////////////////////////////////////////
/// TP_01 : EJERCICIO_02 => "VERIFICANDO-CONTRASEÑAS" ///
/////////////////////////////////////////////////////////

#include <stdio.h> // main() ; "misFunciones.h"
#include <string.h> // main() ; "misFunciones.h"
#include <stdbool.h> // main() ; "misFunciones.h"
#include "misFunciones.h"

#define TAMA 25

int main ()
{
    printf("\n---> INICIO DEL PROGRAMA <---\n");
    
    char contra1[TAMA], contra2[TAMA];
    
    int longitud, es_valida = 0;
    bool fin = false;

    printf("\nIngrese una contraseña que contenga al menos:\n\t--> 8 caracteres\n\t--> 1 letra MAYUSCULA\n\t--> 1 letra minuscula\n\t--> 1 numero\n\t--> 1 caracter especial\n");
    // Leo la contraseña 1 entera
    printf("\nIngresar aqui: ");
    while (!es_valida)
    {
        gets(contra1);
        longitud = strlen(contra1);
        // analizo la contraseña ingresada
        es_valida = verificarContrasenia(contra1, longitud);
        mostrarValidez(contra1, longitud, es_valida);
    }

    do
    {
        printf("\nRepita la contraseña: ");
        gets(contra2);
        // guardo la segunda contraseña ingresada y verifico que coincida con la primera por medio de la funcion 'strcmp()'
        if(!strcmp(contra1,contra2))
        {
            printf("\n¡La contraseña ha sido creada exitosamente!");
            printf("\nContraseña: ");
            puts(contra1);
            fin = true;
        }
        else
        {
            printf("\nLas contraseñas no coinciden.");
        }
    }
    while (!fin);

    printf("\n---> FIN DEL PROGRAMA <---\n");
    
    return 0;
}
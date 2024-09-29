/////////////////////////////////////////////////////////
/// TP_01 : EJERCICIO_02 => "VERIFICANDO-CONTRASEÑAS" ///
/////////////////////////////////////////////////////////

#include <stdio.h> // main() ; "misFunciones.h"
#include <ctype.h> // "misFunciones.h"
#include <string.h> // main() ; "misFunciones.h"
#include <stdbool.h> // main() ; "misFunciones.h"
#define TAMA 25
//

int verificarContrasenia (char arreglo[TAMA], int tama);
void mostrarValidez (char arreglo[TAMA], int tama, int validez);

//

int verificarContrasenia(char arreglo[TAMA], int tama)
{
    int es_valida = 0;
    bool long_es_mayor = false, tiene_mayus = false, tiene_minus = false, tiene_num = false, tiene_c_especial = false;

    if (tama >= 8) {
            long_es_mayor = true;
        }

        for (int i=0; i<tama; i++)
        {
            if (isupper(arreglo[i]))
            {
                tiene_mayus = true;
            }
            if (islower(arreglo[i]))
            {
                tiene_minus = true;
            }
            if (isdigit(arreglo[i]))
            {
                tiene_num = true;
            }
            if (!isdigit(arreglo[i]) && !isalpha(arreglo[i]))
            {
                tiene_c_especial = true;
            }
        }

        if (long_es_mayor && tiene_mayus && tiene_minus && tiene_num && tiene_c_especial)
        {
            es_valida = 1;
        }

        return (es_valida);
}


void mostrarValidez (char arreglo[TAMA], int tama, int validez)
{
    bool long_es_mayor = false, tiene_mayus = false, tiene_minus = false, tiene_num = false, tiene_c_especial = false;
    
    if (validez)
    {
        printf("\nLa contraseña es válida :)\n");
    }
    else
    {
        printf("\nLa contraseña no es válida :(\n Debe contener al menos:\n");


        if (tama < 8) {
            printf("--> 8 caracteres\n");
        }

        for (int i=0; i<tama; i++)
        {
            if (isupper(arreglo[i]))
            {
                tiene_mayus = true;
            }
            if (islower(arreglo[i]))
            {
                tiene_minus = true;
            }
            if (isdigit(arreglo[i]))
            {
                tiene_num = true;
            }
            if (!isdigit(arreglo[i]) && !isalpha(arreglo[i]))
            {
                tiene_c_especial = true;
            }
        }
        if (!tiene_mayus) {
            printf ("--> 1 letra mayuscula\n");
        }
        if (!tiene_minus) {
            printf ("--> 1 letra minuscula\n");
        }
        if (!tiene_num) {
            printf ("--> 1 numero\n");
        }
        if (!tiene_c_especial) {
            printf ("--> 1 caracter especial\n");
        }

        printf("\nIngrese una nueva contraseña: ");
    }
}
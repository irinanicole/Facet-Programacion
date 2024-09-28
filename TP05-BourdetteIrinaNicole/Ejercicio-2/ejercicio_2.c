#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define TAMA 25

int verificarContrasenia (char arreglo[], int tama);
void mostrarValidez (char arreglo[], int tama, int validez);

int main () {
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

int verificarContrasenia(char arreglo[], int tama)
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

void mostrarValidez (char arreglo[], int tama, int validez)
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
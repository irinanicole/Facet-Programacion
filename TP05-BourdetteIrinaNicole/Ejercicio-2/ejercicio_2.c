#include <stdio.h>
#include "misFunciones.h"

int main () {
    puts("\n---> AQUÍ COMIENZA EL PROGRAMA <---\n");
    int tama=20;
    char contra[tama], salto_linea = '\n';
    int long_contrasenia = 0, cont_mayus = 0, cont_minus = 0, cont_num = 0, cont_c_especial = 0;


    puts("\nIngrese una contraseña que contenga al menos:\n\t--> 8 caracteres\n\t--> 1 MAYÚSCULA\n\t--> 1 minúscula\n\t--> 1 número\n\t--> 1 carácter especial\n");
    scanf("%c",&cc);
    
     while ( cc != salto_linea ) {

        long_contrasenia ++;
        cont_mayus += verifica_letra_mayuscula (cc);
        cont_minus += verifica_letra_minuscula (cc);
        cont_num += verifica_numero (cc);
        cont_c_especial += verifica_caracter_especial (cc);

        scanf("%c",&cc);
    }
    
// no puedo hacer un procedimiento pra este caso porque la terminal me informa que no puedo usar tantos argumentos en una sola funcion

    if ( (long_contrasenia >= 8) && (cont_mayus >=1) && (cont_minus >= 1) && (cont_num >= 1) && (cont_c_especial >= 1) ) {
        puts("\nLa contraseña es válida :)\n");
    } else {
        puts("\nLa contraseña no es válida :(\n Debe contener al menos:\n");
        //verifica_contrasenia (long_contraseña, cont_mayus, cont_minus, cont_num, cont_c_especial);
        
        if (long_contrasenia < 8) {
            puts("--> 8 caracteres");
        }
        if (cont_mayus == 0) {
            puts ("--> 1 mayúscula");
        }
        if (cont_minus == 0) {
            puts("--> 1 minúscula");
        }
        if (cont_num == 0) {
            puts ("--> 1 número");
        }
        if (cont_c_especial == 0) {
            puts("--> 1 carácter especial");
        }
    }


    
    puts("\n---> AQUÍ TERMINA EL PROGRAMA <---\n");
    return 0;
}
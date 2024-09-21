#include <ctype.h>

int verifica_letra_mayuscula (char caracter);
int verifica_letra_minuscula (char caracter);
int verifica_numero (char caracter);
int verifica_caracter_especial (char caracter);

/////////// FUNCIOINES ///////////

int verifica_letra_mayuscula (char caracter) {
    int result = 0;
    
    if (isupper(caracter)) {
        result = 1;
    }

    return (result);
}

int verifica_letra_minuscula (char caracter) {
    int result = 0;
    
    if (islower(caracter)) {
        result = 1;
    }

    return (result);
}

int verifica_numero (char caracter) {
    int result = 0;
    
    if (isdigit(caracter)) {
        result = 1;
    }

    return (result);
}

int verifica_caracter_especial (char caracter) {
    int result = 0;
    
    if (!isdigit(caracter) && !isalpha(caracter)) {
        result = 1;
    }

    return (result);
}
#include <ctype.h>

int verifica_letra_mayuscula (char contra[], int tama);
int verifica_letra_minuscula (char contra[], int tama);
int verifica_numero (char contra[], int tama);
int verifica_caracter_especial (char contra[], int tama);

/////////// FUNCIONES ///////////

int verifica_letra_mayuscula (char contra[], int tama) {
    int result = 0;
    
    for (int i = 0; i < tama; i++) {
        if (isupper(contra[i])) {
            result = 1;
        }
    }

    return (result);
}

int verifica_letra_minuscula (char contra[], int tama) {
    int result = 0;
    
    for (int i = 0; i < tama; i++) {
        if (islower(contra[i])) {
            result = 1;
        }
    }

    return (result);
}

int verifica_numero (char contra[], int tama) {
    int result = 0;
    
    for (int i = 0; i < tama; i++) {
        if (isdigit(contra[i])) {
            result = 1;
        }
    }

    return (result);
}

int verifica_caracter_especial (char contra[], int tama) {
    int result = 0;
    
    for (int i = 0; i < tama; i++) {
        if (!isdigit(contra[i]) && !isalpha(contra[i])) {
            result = 1;
        }
    }

    return (result);
}
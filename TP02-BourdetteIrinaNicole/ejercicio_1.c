// Autor: Daniel Mamaní y Nicole Bourdette
// Fecha: 02/09/24
// TP 1
// EJERCICIO 1:  Incrementando y Decrementando.
// // a) Declare una variable incremento de tipo entera.
// // b) Declare una variable decremento de tipo entera.
// // c) Solicite por pantalla al usuario que ingrese dos enteros y almacene los mismos en
// // incremento y decremento.
// // d) Incremente en uno la variable incremento. ¿Lo puede hacer de tres formas
// // diferentes?
// // e) Decrementa en uno la variable decremento. ¿Lo puede hacer de tres formas
// // diferentes?
// // f) Muestre por pantalla el contenido de las variables incremento y decremento.
// // g) Invierta las variables de tal forma que incremento tenga el valor de decremento y
// // decremento tenga el valor de incremento. Muestre en pantalla.

#include <stdio.h>

int main(){

int incremento, decremento, i; //declaro las variables

i=0;

printf("Ingrese 2 numeros enteros: \n"); //le pido al usuario que ingrese los valores que se operaran
scanf("%d", &incremento);
scanf("%d", &decremento);


incremento ++;
decremento --;

printf("El numero incrementado es el siguiente:%d\nEl numero decrementado es el siguiente:%d",incremento, decremento);
i= incremento;
incremento = decremento;
decremento = i;

printf("\nLos numeros invertidos son:\nIncremento: %d\nDecremento: %d\n", incremento, decremento);

    return 0;
}
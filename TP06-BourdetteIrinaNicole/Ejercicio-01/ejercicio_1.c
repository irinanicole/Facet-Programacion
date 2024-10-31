#include <stdio.h>

int main () {
    int *p, *q;
    int a,b,c;
    // a)
    printf("\nIngrese dos numeros enteros:\n");
    scanf("%d %d",&a,&b);

    printf("\nValores ingresados:\na = %d\nb = %d",a,b);

    // b) => asigno a los punteros la dirección de memoria de los datos leidos
    p = &a;
    q = &b;
    
    // Muestro lo siguiente por pantalla:
    // c)
    printf("\n\nContenido de p = %p",p);
    printf("\nContenido de q = %p",q);
    // d)
    printf("\n\nContenido apuntado por p: *p = %d",*p);
    printf("\nContenido apuntado por q: *q = %d",*q);
    // e)
    printf("\n\nDireccion de memoria de p: &p => %p",&p);
    printf("\nDireccion de memoria de q: &q => %p",&q);
    
    // f) Leer un tercer numero entero
    printf("\n\nIngresar un tercer numero: ");
    scanf("%d",&c);
    printf("\nc = %d",c);
    printf("\nDireccion de memoria de c: &c = %p",&c);
    
    // g) Asignar a 'c' el valor de 'a' con el puntero de 'a' y mostar ambas variables
    c = *p;
    printf("\n\nSegundo valor de c: c = a");
    printf("\na = %d",a);
    printf("\nc = %d",c);
    
    // h) Asignar nuevo valor de c con suma de a+b utilizando punteros y mostrar dichas variables.
    c = *p + *q;
    printf("\n\nTercer valor de c: c = a + b");
    printf("\na = %d",a);
    printf("\nb = %d",b);
    printf("\nc = %d",c);

    // i)
    *p = *p + 1;
    printf("\n\nOperacion *p = *p + 1 => *p = %d",*p);
    // j)
    p = p + 1;
    printf("\n\nOperacion p = p + 1 => p = %p",p);
    // k) => l) Sí son equivalentes
    p = &a;
    *p = *p + 1;
    printf("\n\nValor de *p: %d",*p);
    p = &a;
    *p = a + 1;
    printf("\n\nValor de *p: %d",*p);


    return 0;
}
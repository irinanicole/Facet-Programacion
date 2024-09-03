//EJERCICIO 2

#include <stdio.h>

int main(){
    float nota1, nota2, nota3, promedio;

    printf("Ingrese las 3 notas de las materias:\n");
    scanf("%f", &nota1);
    scanf("%f", &nota2);
    scanf("%f", &nota3);



    promedio = (nota1 + nota2+ nota3)/3;

    

    printf("El promedio del alumno es: %.2f", promedio);

    if (promedio>=9.0) {
        printf("\nSu calificacion es: Exelente");
    } else if (7.00<=promedio && promedio<9.00) {
        printf("\nSu calificacion es: Muy Bueno");
    } else if (5.00<=promedio && promedio<7.00) {
        printf("\nSu calificacion es: Regular");
    } else if (promedio<5.00) {
        printf("\nSu calificacion es: Reprobado");
    }

    return 0;
}

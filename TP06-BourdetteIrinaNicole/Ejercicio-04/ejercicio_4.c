/* Cargar notas aleatoriamente del 0 al 10 con 2 cigras decimales 
(dependiendo de la cantidad de alumnos que tenga el curso), calcular el promedio del curso
y la mejor nota, y presentrar los resultados por pantalla. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarNotas(float *notas, int alumnos);
float calcularPromedio(float *notas, int alumnos, float *promedio);

int main()
{
    int alumnos;

    printf("\nIngrese la cantidad total de alumnos del curso: ");
    scanf("%d",&alumnos);

    float *notas;
    notas = (float *)malloc(alumnos * sizeof(float));
    
    // Funcion para simular las notas.
    cargarNotas(notas, alumnos);
    // Función que calcula y guarda el promedio, además retorna la mejor nota.
    float *promedio, mejor_nota;
    mejor_nota = calcularPromedio(notas, alumnos, promedio);

    printf("\nPromedio del curso: %.2f",*promedio);
    printf("\nMejor nota: %.2f",mejor_nota);
    
    free(notas);
    return 0;
}

void cargarNotas(float *notas, int alumnos)
{
    srand(time(NULL));
    float num;
    for (int i=0; i<alumnos; i++) {
        num = rand() % 1001;
        notas[i] = num/100;
        printf("\nAlumno %d -> %.2f",i,notas[i]);
    }
    printf("\n");
}

float calcularPromedio(float *notas, int alumnos, float *promedio)
{
    float nota_mas_alta = 0;
    float suma_notas = 0;
    for (int i = 0; i < alumnos; i++) {
        suma_notas += notas[i];
        if (nota_mas_alta < notas[i]) {
            nota_mas_alta = notas[i];
        }
    }
    *promedio = suma_notas / alumnos;

    return nota_mas_alta;
}
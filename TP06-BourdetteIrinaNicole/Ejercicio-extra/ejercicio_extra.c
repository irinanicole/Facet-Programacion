/* Cargar notas aleatoriamente del 0 al 10 con 2 cigras decimales 
(dependiendo de la cantidad de alumnos que tenga el curso), para las 4 materias:
    [0]-> Lengua; [1]-> Matemáticas; [2]-> Naturales; [3]-> Sociales
Calcular el promedio de notas y la mejor nota para cada materia.
Presentrar los resultados por pantalla. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// void cargarNotas(float *notas, int alumnos);
// float calcularPromedio(float *notas, int alumnos, float *promedio);
void cargarMaterias(char **materias, int cant_materias);
void cargarNotas(float **notas, int alumnos, int cant_materias, char **materias);
void calcularPromedio(float **notas, int alumnos, int cant_materias, float *promedios, float *mayorNotas);
void mostrarNotas(float *promedios, float *mayorNotas, char **materias, int cant_materias);

int main()
{
    srand(time(NULL));

    int cant_materias;
    printf("\nCantidad de materias: ");
    scanf("%d",&cant_materias);
    while(fgetc(stdin) != '\n');
    char **nombre_materia = (char **)malloc(cant_materias * sizeof(char *));
    cargarMaterias(nombre_materia, cant_materias);

    float **notas = (float **)malloc(cant_materias * sizeof(float *)); //filas (4-cant_materias)
    float *promedios = (float *)malloc(cant_materias * sizeof(float));
    float *mejor_nota = (float *)malloc(cant_materias * sizeof(float));
    int alumnos;
    printf("\nCantidad Total de alumnos del curso: ");
    scanf("%d",&alumnos);
    // Funcion para simular las notas.
    cargarNotas(notas, alumnos, cant_materias, nombre_materia);

    // Función que calcula y guarda el promedio para cada materia.
    calcularPromedio(notas, alumnos, cant_materias, promedios, mejor_nota);

    mostrarNotas(promedios, mejor_nota, nombre_materia, cant_materias);

    free(mejor_nota);
    free(promedios);
    for (int i = 0; i < alumnos; i++)
    {
        free(notas[i]);
    }
    free(notas);
    free(nombre_materia);
    return 0;
}

void cargarMaterias(char **materias, int cant_materias)
{
    int i = 0;
    while (i < cant_materias) {
        materias[i] = (char *)malloc(20 * sizeof(char));
        printf("\nMateria %d: ",i+1);
        gets(materias[i]);
        i++;
    }
}

void cargarNotas(float **notas, int alumnos, int cant_materias, char **nombre_materia)
{
    float num;
    for (int i = 0; i < alumnos; i++) { // columnas (cantidad de alumnos)
        // cada alumno tendrá 1 nota por materia
        notas[i] = (float *)malloc(alumnos * sizeof(float));
        printf("\nAlumno [%d]\n",i+1);

        for (int j = 0; j < cant_materias; j++) {
            num = rand() % 1001;
            notas[i][j] = num/100;
            puts(nombre_materia[j]);
            printf("=> %.2f\n", notas[i][j]);
        }
    }
    printf("\n");
}

void calcularPromedio(float **notas, int alumnos, int cant_materias, float *promedios, float *mayorNotas)
{
    float nota_mas_alta = 0;
    float suma_notas = 0;
    for (int i = 0; i < cant_materias; i++) { /* por cada MATERIA tomo las notas de todos los alumnos */
        for (int j = 0; j < alumnos; j++)
        {
            suma_notas += notas[i][j];
            if (nota_mas_alta < notas[i][j]) {
                nota_mas_alta = notas[i][j];
            }
        }
        promedios[i] = suma_notas / alumnos;
        mayorNotas[i] = nota_mas_alta;
        suma_notas = 0; nota_mas_alta = 0;
    }
}

void mostrarNotas(float *promedios, float *mayorNotas, char **materias, int cant_materias)
{
    printf("\n--> PROMEDIOS Y MEJORES NOTAS <--\n");
    for (int i = 0; i < cant_materias; i++)
    {
        printf("\n(%d)\nMateria: ",i+1);
        puts(materias[i]);
        printf("Promedio: %.2f\nMejor nota: %.2f\n", promedios[i], mayorNotas[i]);
    }
}
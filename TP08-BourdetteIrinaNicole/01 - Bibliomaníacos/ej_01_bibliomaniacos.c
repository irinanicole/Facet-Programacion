#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

// Declaración de estructuras
typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    char nombre[MAX];
    unsigned edad;
    Fecha fechaPrestamo;
} Lector;

typedef struct {
    char titulo[MAX];
    char genero[MAX];
    unsigned cant_lectores;
    Lector *lectores;
} Libro;

// Declaración de funciones
void cargarLibro(Libro **libros, int *num_libros);
// void cargarLectores();
void mostrarDatosLibro(Libro *libros, int num_libros);
// void indicarLibroMasLeido(Libro *libros);
// void mostrarLibrosSociosMenoresDeEdad(Libro *libros);
// void mostrarLibroGeneroPolicial2023(Libro *libros);

int main ()
{
    int num_libros = 4;
    Libro *libros = (Libro *)malloc(num_libros * sizeof(Libro));
    
    // Inicialización del libro 1 [tipo: indexado]
    libros[0] = (Libro){"El señor de los anillos", "Fantasía", 3, (Lector *)malloc(3 * sizeof(Lector))};
    libros[0].lectores[0] = (Lector){"Juan Perez", 25, {12, 5, 2023}};
    libros[0].lectores[1] = (Lector){"Maria Lopez", 30, {14, 5, 2023}};
    libros[0].lectores[2] = (Lector){"Pedro Sanchez", 35, {7, 6, 2023}};

    // Inicialización del libro 2
    libros[1] = (Libro){"1984", "Distopía", 4, (Lector *)malloc(4 * sizeof(Lector))};
    libros[1].lectores[0] = (Lector){"Carlos Díaz", 21, {1, 6, 2023}};
    libros[1].lectores[1] = (Lector){"Lucía Gomez", 29, {5, 6, 2023}};
    libros[1].lectores[2] = (Lector){"Pedro Sanchez", 35, {7, 6, 2023}};
    libros[1].lectores[3] = (Lector){"Roberto Castro", 33, {20, 8, 2023}};
    
    // Inicialización del libro 3
    libros[2] = (Libro){"Cien años de soledad", "Realismo Mágico", 1, (Lector *)malloc(1 * sizeof(Lector))};
    libros[2].lectores[0] = (Lector){"Ana Martínez", 40, {10, 7, 2023}};
    
    // Inicialización del libro 4
    libros[3] = (Libro){"Don Quijote de la Mancha", "Clásico", 2, (Lector *)malloc(2 * sizeof(Lector))};
    libros[3].lectores[0] = (Lector){"Roberto Castro", 33, {20, 8, 2023}};
    libros[3].lectores[1] = (Lector){"Laura Perez", 27, {22, 8, 2023}};

    // Llamado de funcion para cargar libros
    printf("\nSe cargara un libro a continuacion:\n");
    cargarLibro(&libros, &num_libros);
    mostrarDatosLibro(libros, num_libros);


    // Llamado de funciones operacionales
    // indicarLibroMasLeido(libros);
    // mostrarLibrosSociosMenoresDeEdad(libros);
    // mostrarLibroGeneroPolicial2023(libros);

    for (int i = 0; i < libros->numLectores; i++) free(libros[i].lectores);
    free(libros);
    return 0;
}

// Desarrollo de funciones
void cargarLibro(Libro **libros, int *num_libros) {
    *num_libros++;
    *libros = (Libro *)realloc(*libros, *num_libros * sizeof(Libro));

    *libros[*num_libros-1] = (Libro){"Harry Potter y las Reliquias de La Muerte", "Fantasía", 1, (Lector *)malloc(1 * sizeof(Lector))};
    (libros)[*num_libros-1]->lectores[0] = (Lector){"Juan Perez", 25, {12, 5, 2023}};
}

void mostrarDatosLibro(Libro *libros, int num_libros) {
    for (int i=0; i < num_libros; i++) {
        printf("\n---> LIBROS <---\n");
        printf("\nTitulo: %s",libros[i].titulo);
        printf("\nGenero: %s", libros[i].genero);
        printf("\nNumero de lectores: %d",libros[i].numLectores);
        printf("\n--> Lectores del libro <--");
        for (int j = 0; j < libros[i].numLectores; j++)
        {
            printf("\nNombre del lector: %s", libros[i].lectores[j].nombre);
            printf("\nEdad: %d",libros[i].lectores[j].edad);
            printf("\nFecha Prestamo: %d-%d-%d", libros[i].lectores[j].fechaPrestamo.dia, libros[i].lectores[j].fechaPrestamo.mes, libros[i].lectores[j].fechaPrestamo.anio);
        }
        
        
    }
}
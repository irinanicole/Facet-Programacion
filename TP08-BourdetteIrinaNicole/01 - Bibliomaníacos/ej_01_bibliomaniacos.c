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
    int edad;
    Fecha fechaPrestamo;
} Lector;

typedef struct {
    char titulo[MAX];
    char genero[MAX];
    int numLectores;
    Lector *lectores;
} Libro;

// Declaración de funciones
//Libro cargarDatosLibro();
void mostrarDatosLibro(Libro *libros);
void indicarLibroMasLeido(Libro *libros);
void mostrarLibrosSociosMenoresDeEdad(Libro *libros);
void mostrarLibroGeneroPolicial2023(Libro *libros);

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
    //libros = cargarLibro();
    mostrarDatosLibro(libros);


    // Llamado de funciones operacionales
    indicarLibroMasLeido(libros);
    mostrarLibrosSociosMenoresDeEdad(libros);
    mostrarLibroGeneroPolicial2023(libros);

    free(libros[0].lectores);
    free(libros[1].lectores);
    free(libros[2].lectores);
    free(libros[3].lectores);
    free(libros);
    return 0;
}

// Desarrollo de funciones
// Libro cargarDatosLibro();
void mostrarDatosLibro(Libro *libros) {
    
    for (int i=0; i < 4; i++) {
        printf("\n---> LIBROS <---\n");
        printf("\nTitulo: ");
        puts(libros[i].titulo);
        printf("\nGenero: ");
        puts(libros[i].genero);
        printf("\nNumero de lectores: %d",libros[i].numLectores);
        printf("\n--> Lectores del libro <--");
        for (int j = 0; j < libros[i].numLectores; j++)
        {
            printf("\nNombre del lector: ");
            puts(libros[i].lectores[j].nombre);
            printf("\nEdad: %d",libros[i].lectores[j].edad);
            printf("\nFecha Prestamo: %d-%d-%d", libros[i].lectores[j].fechaPrestamo.dia, libros[i].lectores[j].fechaPrestamo.mes, libros[i].lectores[j].fechaPrestamo.anio);
        }
        
        
    }
}
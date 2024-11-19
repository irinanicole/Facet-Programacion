#include <stdio.h>
#define MAX 100

// declaro las estructuras para los tipos de datos
typedef struct {
    char nombre_empleado[MAX];
    char puesto;
} tEmpleado;

typedef struct  {
    int dia;
    int mes;
    int anio;
} tFecha;


typedef struct  {
    char nombre_proyecto[MAX];
    int duracion;
    int horas_trabajadas[12];
    tEmpleado datos_empleado;
    tFecha fecha_inicio;
} tProyecto;

// declaro las funciones
tProyecto cargarDatos();
void mostrarDatos(tProyecto dato);

// funcion main()
int main()
{
    printf("\n---> INICIO <---\n");
    tProyecto proyecto;

    proyecto = cargarDatos();

    mostrarDatos(proyecto);

    printf("\n\n---> FIN <---\n");    
    return 0;
}

// desarrollo las funciones

tProyecto cargarDatos()
{
    tProyecto datos;

    printf("\nIngrese el nombre del proyecto: ");
    gets(datos.nombre_proyecto);

    int error = 0;
    printf("\nIngrese la fecha de inicio del proyecto:\n");
    do {
        printf("\nDia (1 al 31): ");
        scanf("%d",&datos.fecha_inicio.dia);
        printf("\nMes (solo 1): ");
        scanf("%d",&datos.fecha_inicio.mes);
        printf("\nAnio (solo 2024): ");
        scanf("%d",&datos.fecha_inicio.anio);

        if ((datos.fecha_inicio.dia >= 1 && datos.fecha_inicio.dia <= 31) && datos.fecha_inicio.mes == 1 && datos.fecha_inicio.anio == 2024) {
            error = 0;
        } else {
            error = 1;
            fprintf(stderr,"\nFECHA INVALIDA");
            printf("\nEl DIA debe ser valido (del 1 al 31). El MES solo puede ser el mes 1 (Enero). El ANIO solo puede ser el actual (2024)");
            printf("\n\nIngrese nuevamente la fecha de inicio:\n");
        }

    } while (error);
    
    printf("\nIngrese la duracion estimada del proyecto (MIN: 1 mes - MAX: 12 meses): ");
    do {
        scanf("%d",&datos.duracion);
        /* ------AQUÍ------- (justo debajo del scanf() opara limpiar el buffer) */
        while (fgetc(stdin) != '\n');
        // fflush(stdin); No es recomendable su uso
        /* ------AQUÍ------- */
        if (datos.duracion < 1 || datos.duracion > 12) {
            fprintf(stderr, "\nDURACION INVALIDA");
            if (datos.duracion < 1) {
                printf("\nLa duración del proyecto debe ser como minimo de 1 mes");
            } else {
                printf("\nLa duración del proyecto no debe exceder el año (12 meses)");
            }
            printf("\n\nIngrese nuevamente la duración del proyecto (en meses): ");
        }
    } while (datos.duracion < 1 && datos.duracion > 12);

    printf("\nIngrese el nombre del empleado: ");
    gets(datos.datos_empleado.nombre_empleado);
    
    // int i = 0;
    // scanf("%c",&datos.datos_empleado.nombre_empleado[i]);
    // while (datos.datos_empleado.nombre_empleado[i] != '\n') {
    //     scanf("%c",&datos.datos_empleado.nombre_empleado[i]);
    // }

    printf("\nIndique el tipo de puesto asignado como desarrollador -> F (para Frontend) o B (para Backend): ");
    scanf("%c",&datos.datos_empleado.puesto);

    printf("\nIngrese la cantidad de tiempo trabajado por el empleado cada mes (en horas):");
    for (int i=0; i < datos.duracion; i++) {
        printf("\nMes %d: ",i+1);
        scanf("%d",&datos.horas_trabajadas[i]);
    }

    return (datos);
}

void mostrarDatos (tProyecto datos)
{
    printf("\n\n---> DATOS DEL PROYECTO <---\n");
    
    printf("\nNombre del Proyecto: ");
    puts(datos.nombre_proyecto);

    printf("\nFecha de inicio del proyecto: %d-%d-%d", datos.fecha_inicio.dia, datos.fecha_inicio.mes, datos.fecha_inicio.anio);
    
    printf("\nDuracion: %d meses", datos.duracion);

    /* ------- */
    printf("\n\n=> Datos: Empleado <=");

    printf("\nNombre: ");
    puts(datos.datos_empleado.nombre_empleado);

    printf("\nPuesto: Desarrollador ");
    if (datos.datos_empleado.puesto == 'F' || datos.datos_empleado.puesto == 'f') {
        printf("Frontend");
    } else if (datos.datos_empleado.puesto == 'B' || datos.datos_empleado.puesto == 'b') {
        printf("Backend");
    }

    printf("\nHoras trabajadas por el empleado (c/mes):");
    for (int i=0; i < datos.duracion; i++) {
        printf("\nMes %d: %d hs", i+1, datos.horas_trabajadas[i]);
    }
    /* ------- */
}
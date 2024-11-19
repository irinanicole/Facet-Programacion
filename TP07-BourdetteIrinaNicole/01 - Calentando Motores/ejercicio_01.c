#include <stdio.h>
#define MAX 100

// declaro las estructuras para los tipos de datos
struct  {
            char nombre_empleado[MAX];
            char puesto;

        } typedef tEmpleado;

struct  {
            int dia;
            int mes;
            int anio;

        } typedef tFecha;


struct  {
            char nombre_proyecto[MAX];
            int duracion;
            int horas_trabajadas[12];
            tEmpleado datos_empleado;
            tFecha fecha_inicio;

        } typedef tProyecto;

// declaro las funciones
tProyecto cargarDatos();
void mostrarDatos(tProyecto dato);

// funcion main()
int main()
{
    tProyecto proyecto;

    proyecto = cargarDatos();

    mostrarDatos(proyecto);
    
    return 0;
}

// desarrollo las funciones

tProyecto cargarDatos() {
    tProyecto datos;

    printf("\nIngrese el nombre del proyecto: ");
    gets(datos.nombre_proyecto);
    
    printf("\nIngrese la duracion estimada del proyecto (MIN: 1 mes - MAX: 12 meses): ");
    do {
        scanf("%d",&datos.duracion);
        if (datos.duracion < 1 || datos.duracion > 12) {
            printf("\nDURACION INVALIDA");
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
    printf("\nIndique el tipo de puesto asignado como desarrollador -> F (para Frontend) o B (para Backend): ");
    gets(datos.datos_empleado.puesto);

    printf("\nIngrese la cantidad de tiempo trabajado por el empleado cada mes (en horas):");
    for (int i=0; i < datos.duracion; i++) {
        printf("\nMes %d: ",i+1);
        scanf("%d",&datos.horas_trabajadas[i]);
    }
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
            printf("\nFECHA INVALIDA\nEl DIA debe ser valido (del 1 al 31). El MES solo puede ser el mes 1 (Enero). El ANIO solo puede ser el actual (2024)");
            printf("\n\nIngrese nuevamente la fecha de inicio:\n");
        }

    } while (error);

    return (datos);
}
// void mostrarDatos(tProyecto dato);
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

typedef struct {
    int dia;
    int mes;
    int anio;
} tFecha;

typedef struct {
    char apellido[MAX];
    char nombre[MAX];
    int dni;
} tCoordinador;

typedef struct {
    char destino[MAX];
    tCoordinador coordinador;
    tFecha fecha_salida;
    tFecha fecha_regreso;
    float costo;
    int hab_reservadas;
    int *lista_hab_reservadas;
} tViaje;

tViaje cargarDatos();
void mostrarDatos(tViaje viaje);
float actualizarCostoViaje(float costoViaje);
int verificarFecha(tFecha fecha);
int despues_de (tFecha a, tFecha b);
void habitaciones_por_piso (int *lista_hab_reservadas, int cant_habitaciones);

int main() {
    srand(time(NULL));
    printf("\n--- INICIO ---\n");

    tViaje viaje;

    viaje = cargarDatos();
    mostrarDatos(viaje);
    habitaciones_por_piso(viaje.lista_hab_reservadas, viaje.hab_reservadas);
    
    printf("\n¿Desea incrementar el costo del viaje? (si-> 1 | no-> 0): ");
    int actualizar;
    scanf("%d",&actualizar);
    if (actualizar) {
        viaje.costo = actualizarCostoViaje(viaje.costo);
        printf("\nEl costo del viaje fue actualizado --> Nuevo Costo: $%.2f", viaje.costo);
    }
    
    free(viaje.lista_hab_reservadas);
    printf("\n--- FIN ---\n");
    return 0;
}

#define VERSION_CARGAR_DATOS 2
tViaje cargarDatos() {
    tViaje viaje;

    printf("\n\n==> CARGAR DATOS DEL VIAJE <==\n");
    /* destino */
    printf("\nDestino: ");
    gets(viaje.destino);
    /* Coordinador */
    printf("\n--> Datos Coordinador <--\n");
    printf("Apellido: ");
    gets(viaje.coordinador.apellido);
    printf("Nombre: ");
    gets(viaje.coordinador.nombre);
    printf("DNI (sin puntos): ");
    scanf("%d",&viaje.coordinador.dni);
    /* fechas */
    int fecha_valida = 0;
    do {
        do
        {
            printf("\n*Fecha Salida*\n");
            printf("Dia: ");
            scanf("%d",&viaje.fecha_salida.dia);
            printf("Mes: ");
            scanf("%d",&viaje.fecha_salida.mes);
            printf("Anio: ");
            scanf("%d",&viaje.fecha_salida.anio);
            fecha_valida = verificarFecha(viaje.fecha_salida);
            if (!fecha_valida) {
                fprintf(stderr,"\nFecha Invalida\n");
            }
        } while (!fecha_valida);

        do {
            printf("\n*Fecha Regreso*\n");
            printf("Dia: ");
            scanf("%d",&viaje.fecha_regreso.dia);
            printf("Mes: ");
            scanf("%d",&viaje.fecha_regreso.mes);
            printf("Anio: ");
            scanf("%d",&viaje.fecha_regreso.anio);
            fecha_valida = verificarFecha(viaje.fecha_regreso);
            if (!fecha_valida) {
                fprintf(stderr,"\nFecha Invalida\n");
            }
        } while (!fecha_valida);

        if (!despues_de(viaje.fecha_salida, viaje.fecha_regreso)) {
            fprintf(stderr,"\nFecha Invalida\n");
        }

    } while (!despues_de(viaje.fecha_salida, viaje.fecha_regreso));

    #if VERSION_CARGAR_DATOS == 1
        /* costo viaje */
        printf("\nCosto del viaje: ");
        scanf("%f",&viaje.costo);

        /* habitaciones reservadas; lista */
        printf("\nCantidad de habitaciones a reservar: ");
        scanf("%d",&viaje.hab_reservadas);

        viaje.lista_hab_reservadas = (int *)malloc(viaje.hab_reservadas * sizeof(int));

        printf("\nIngresar la lista de numeros de habitaciones reservadas:");
        for (int i = 0; i < viaje.hab_reservadas; i++) {
            printf("\nHabitacion %d: ",i+1);
            scanf("%d",&viaje.lista_hab_reservadas[i]);
        }
    #elif VERSION_CARGAR_DATOS == 2
        /* costo viaje */
        viaje.costo = 25000000 + rand() % 55000001;
        printf("\nCosto del viaje: $%.2f", viaje.costo);

        /* habitaciones reservadas; lista */
        printf("\nCantidad de habitaciones a reservar: ");
        scanf("%d",&viaje.hab_reservadas);

        viaje.lista_hab_reservadas = (int *)malloc(viaje.hab_reservadas * sizeof(int));
        int num_hab;
        // printf("\nLista de numeros de habitaciones reservadas:");
        for (int i = 0; i < viaje.hab_reservadas; i++) {
            num_hab = 100 + rand() % 400;
            if (i==0) {
                viaje.lista_hab_reservadas[i] = num_hab;
            } else {
                for (int j = 0; j < i; j++)
                {
                    if (num_hab == viaje.lista_hab_reservadas[j]) {
                        i--;
                    } else {
                        viaje.lista_hab_reservadas[i] = num_hab;
                    }
                }
            }
        }
    #endif

    return viaje;
}


void mostrarDatos(tViaje viaje) {
    printf("\n\n<== VIASUALIZACION DE DATOS CARGADOS ==>\n");

    printf("\nDestino: ");
    puts(viaje.destino);
    /**/
    printf("\n--> Datos Coordinador <--");
    printf("\nApellido: ");
    puts(viaje.coordinador.apellido);
    printf("Nombre: ");
    puts(viaje.coordinador.nombre);
    printf("DNI: %d", viaje.coordinador.dni);

    printf("\nFecha Salida: %d-%d-%d", viaje.fecha_salida.dia, viaje.fecha_salida.mes, viaje.fecha_salida.anio);
    printf("\nFecha Regreso: %d-%d-%d", viaje.fecha_regreso.dia, viaje.fecha_regreso.mes, viaje.fecha_regreso.anio);

    printf("\nCosto del viaje: $%.2f", viaje.costo);

    printf("\nCantidad de habitaciones reservadas: %d", viaje.hab_reservadas);

    printf("\n--> Lista de numeros de las habitaciones reservadas <--");
    for (int i = 0; i < viaje.hab_reservadas; i++) {
        printf("\nHabitacion %d: %d", i+1, viaje.lista_hab_reservadas[i]);
    }
}


int verificarFecha(tFecha fecha)
#define VERSION 2
#if VERSION == 1
{ 
    int es_valida = 0, diasFeb;
    int dias[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (fecha.anio >= 2024 && fecha.anio <= 2026) {
        if (fecha.mes >= 1 && fecha.mes <= 12) {
            if (fecha.mes == 2) {
                diasFeb = dias[1] + (fecha.anio % 4 == 0);
                if (fecha.dia >= 1 && fecha.dia <= diasFeb) {
                    es_valida = 1;
                }
            } else {
                if (fecha.dia >= 1 && fecha.dia <= dias[fecha.mes-1]) {
                    es_valida = 1;
                }
            }
        }
    }

    return es_valida;
}
#elif VERSION == 2
{
    int dias[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    int es_valida = (fecha.anio >= 2024 && fecha.anio <= 2026)
                    && (fecha.mes >= 1 && fecha.mes <= 12)
                    && (fecha.dia >= 1 && fecha.dia <= dias[fecha.mes-1] + 
                        ((fecha.mes == 2) && (fecha.anio % 4 == 0)));
    
    return es_valida;
}
#endif

int despues_de (tFecha a, tFecha b) /* TRUE si a <= b*/
{
    int valida = ((a.anio < b.anio) 
                || ((a.anio == b.anio) 
                    && ((a.mes < b.mes) 
                        || ((a.mes == b.mes) && (a.dia <= b.dia)))));

    return valida;
}

float actualizarCostoViaje(float costoActual) {
    printf("\nIngrese el porcentaje con el que desea incrementar: ");
    float porcentaje;
    scanf("%f",&porcentaje);

    float costoViaje = costoActual * (porcentaje/100.00 + 1);
    return costoViaje;
}

void habitaciones_por_piso (int *lista_hab_reservadas, int cant_habitaciones)
{
    int piso, pisos[4] = { 0, 0, 0, 0 };
    for (int i = 0; i < cant_habitaciones; i++)
    {
        piso = lista_hab_reservadas[i] / 100; /* consigo la 1ra cifra */
        pisos[piso-1]++;
    }
    printf("\n--> Cantidad de Habitaciones por piso:");
    for (int j = 0; j < 4; j++) {
        printf("\nPiso %d: %d", j+1, pisos[j]);
    }
}
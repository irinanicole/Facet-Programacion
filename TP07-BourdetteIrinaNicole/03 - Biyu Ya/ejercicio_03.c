#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int dia;
    int mes;
    int anno;
} tFecha;

typedef struct {
    char cvu[9];
    float saldo;
    float *transacciones;
    int cant_transac;
} tCuenta;

typedef struct {
    char apellido[MAX];
    char nombre[MAX];
    int dni;
    tFecha fecNac;
    char contrasenna[MAX];
    tCuenta cuenta;
} tCliente;

int elegirUsuario (tCliente *clientes);
void cambiarContrasenna (char *contra);
void agregarFondos (float *saldo, float *transacciones, int *cant_transac);
void retirarFondos (float *saldo, float *transacciones, int *cant_transac);
void consultarSaldo (float saldo);
void mostrarInfoCuenta (char *nombre, char *apellido, char *cvu);
void mostrarHistorialTransac (float *transacciones, int cant_transac);

int main()
{
    /* INICIALIZACIÓN */
    tCliente clientes[4] = {
        {"Gonzalez", "Juan", 12345678, {15, 5, 1990}, "pass123", {"123456789", 1000.0, NULL, 0}},
        {"Lopez", "Maria", 87654321, {10, 8, 1985}, "pass456", {"987654321", 1500.0, NULL, 0}},
        {"Navarro", "Marcelo", 85651321, {19, 2, 1979}, "pass450", {"123456789", 41500.0, NULL, 0}},
        {"Medina", "Nazareno", 87654321, {21, 10, 1980}, "pass999", {"987654321", 25500.0, NULL, 0}}
    };
    for (int i = 0; i < 4; i++)
    {
        clientes[i].cuenta.transacciones = (float *)malloc(10 * sizeof(float));
    }

    printf("\n----> INICIO <----\n");

    /* MENU PRINCIPAL */
    int finOperacion = 0;
    int usuario = elegirUsuario(clientes);

    /* MENU SECUNDARIO */
    int operacion;
    do {
        if (usuario == 0) {
            finOperacion = 1;
        } else {
            /* MENU SECUNDARIO */
            printf("\n==> MENU <==\n");
            printf("\n{1}=>Cambiar contrasenna.");
            printf("\n{2}=>Agregar fondos.");
            printf("\n{3}=>Retirar fondos.");
            printf("\n{4}=>Consultar saldo.");
            printf("\n{5}=>Informacion de la cuenta.");
            printf("\n{6}=>Historial de transacciones.");
            printf("\n{x}=>Volver al menu principal.\n");
            /* leo opcion */
            printf("\n--> opcion: ");
            scanf("%d",&operacion);
            while(fgetc(stdin) != '\n');
            switch (operacion) {
                case 1: cambiarContrasenna(clientes[usuario-1].contrasenna); break;
                case 2: agregarFondos(&clientes[usuario-1].cuenta.saldo, clientes[usuario-1].cuenta.transacciones, &clientes[usuario-1].cuenta.cant_transac); break;
                case 3: retirarFondos(&clientes[usuario-1].cuenta.saldo, clientes[usuario-1].cuenta.transacciones, &clientes[usuario-1].cuenta.cant_transac); break;
                case 4: consultarSaldo(clientes[usuario-1].cuenta.saldo); break;
                case 5: mostrarInfoCuenta(clientes[usuario-1].nombre, clientes[usuario-1].apellido, clientes[usuario-1].cuenta.cvu); break;
                case 6: mostrarHistorialTransac(clientes[usuario-1].cuenta.transacciones, clientes[usuario-1].cuenta.cant_transac); break;
                default:
                    usuario = elegirUsuario(clientes);
                    break;
            }
        }
    } while (!finOperacion);


    for (int j = 0; j < 4; j++)
    {
        free(clientes[j].cuenta.transacciones);
    }
    printf("\n----> FIN <----\n");
    return 0;
}

/*===================================================*/
/* FUNCION - MENU PRINCIPAL */

int elegirUsuario (tCliente *clientes)
{
    int usu;
    printf("\n--> Eligir un usuario <--");
    for (int i = 0; i < 4; i++) {
        printf("\nUsuario %d: [%s, %s, %d]", i+1, clientes[i].apellido, clientes[i].nombre, clientes[i].dni);
    }
    printf("\n\n--[Ingrese 0: Para finalizar]--");
    printf("\n\n--> usuario: ");
    scanf("%d",&usu);

    return usu;
}

/*===================================================*/
/* PROCEDIMIENTOS */

void cambiarContrasenna (char *contra)
{
    printf("\nIngresar la nueva contrasenna: ");
    gets(contra);
}

void agregarFondos (float *saldo, float *transacciones, int *cant_transac)
{
    printf("\nIngrese el monto a agregar: ");
    float monto;
    scanf("%f",&monto);
    while(fgetc(stdin)!='\n');
    *saldo += monto;
    *cant_transac++;
    if (*cant_transac > 10) {
        transacciones = (float *)realloc(transacciones, *cant_transac * sizeof(float));
    }
    transacciones[*cant_transac-1] = monto;
}

void retirarFondos (float *saldo, float *transacciones, int *cant_transac)
{
    if (*saldo) {
        printf("\nIngrese el monto a retirar: ");
        float monto;
        scanf("%f",&monto);
        if (monto <= *saldo) {
            while(fgetc(stdin)!='\n');
            *saldo -= monto;
            *cant_transac++;
            if (*cant_transac > 10) {
                transacciones = (float *)realloc(transacciones, *cant_transac * sizeof(float));
            }
            transacciones[*cant_transac-1] = monto;
        } else {
            printf("\nNo hay suficiente saldo en la cuenta pra retirar ese monto.");
        }
    } else {
        printf("\nNo dispone de saldo para retirar.");
    }
}

void consultarSaldo (float saldo)
{
    printf("\nSaldo actual: %.2f", saldo);
}

void mostrarInfoCuenta (char *nombre, char *apellido, char *cvu)
{
    printf("\nNombre: %s %s", nombre, apellido);
    printf("\nCVU: %s", cvu);
}

void mostrarHistorialTransac (float *transacciones, int cant_transac)
{
    printf("\n==> Historial de Transacciones <==");
    for (int i = 0; i < cant_transac; i++) {
        printf("\n[%d] => %.2f", i+1, transacciones[i]);
    }
}
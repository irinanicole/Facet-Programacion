#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int dia;
    int mes;
    int anno;
} tFecha;

typedef struct {
    unsigned long cvu;
    float saldo;
    float *historial;
    unsigned cant_transac;
} tCuenta;

typedef struct {
    char apellido[MAX];
    char nombre[MAX];
    int dni;
    tFecha fecNac;
    char contrasenna[MAX];
    tCuenta cuenta;
} tCliente;

void nuevoCliente (tCliente *clientes, int cant_nueva);
int verificarFecha(tFecha fecha);
int elegirUsuario (tCliente *clientes, int cant_clientes);
void cambiarContrasenna (tCliente *c);
void agregarFondos (tCliente *c);
void retirarFondos (tCliente *c);
void consultarSaldo (tCliente *c);
void mostrarInfoCuenta (tCliente *c);
void mostrarHistorialTransac (tCliente *c);

int main()
{
    int cant_clientes = 4, crearUsuario = 0, finOperacion = 0, usuario, operacion;
    
    printf("\n----> INICIO <----\n");
    tCliente * clientes = (tCliente *)malloc(cant_clientes * sizeof(tCliente));
    /* INICIALIZACIÓN */
    clientes[0] = (tCliente){"Gonzalez", "Juan", 12345678, {15, 5, 1990}, "pass123", {123456789, 1000.0, NULL, 0}};
    clientes[1] = (tCliente){"Lopez", "Maria", 87654321, {10, 8, 1985}, "pass456", {987654321, 1500.0, NULL, 0}};
    clientes[2] = (tCliente){"Navarro", "Marcelo", 85651321, {19, 2, 1979}, "pass450", {123456789, 41500.0, NULL, 0}};
    clientes[3] = (tCliente){"Medina", "Nazareno", 87654321, {21, 10, 1980}, "pass999", {987654321, 25500.0, NULL, 0}};
    for (int i = 0; i < cant_clientes; i++) clientes[i].cuenta.historial = (float *)malloc(sizeof(float));

    /* MENU PRINCIPAL */
    usuario = elegirUsuario(clientes, cant_clientes);

    /* MENU SECUNDARIO */
    do {
        if (usuario == 0) {
            finOperacion = 1;
        } else {
            if (usuario == (cant_clientes+1)) {
                cant_clientes++;
                nuevoCliente(clientes, cant_clientes);
                printf("\n<=== BIENVENIDO ===>\n");
            }
            /* MENU SECUNDARIO */
            printf("\n==> MENU <==\n");
            printf("\n{0}=>Volver al menu principal.\n");
            printf("\n{1}=>Cambiar contrasenna.");
            printf("\n{2}=>Agregar fondos.");
            printf("\n{3}=>Retirar fondos.");
            printf("\n{4}=>Consultar saldo.");
            printf("\n{5}=>Informacion de la cuenta.");
            printf("\n{6}=>Historial de transacciones.");
            /* leo opcion */
            printf("\n--> opcion: ");
            scanf("%d",&operacion);
            while(fgetc(stdin) != '\n');
            switch (operacion) {
                case 1: cambiarContrasenna(&clientes[usuario-1]); break;
                case 2: agregarFondos(&clientes[usuario-1]); break;
                case 3: retirarFondos(&clientes[usuario-1]); break;
                case 4: consultarSaldo(&clientes[usuario-1]); break;
                case 5: mostrarInfoCuenta(&clientes[usuario-1]); break;
                case 6: mostrarHistorialTransac(&clientes[usuario-1]); break;
                default:
                    usuario = elegirUsuario(clientes, cant_clientes); break;
            }
        }
    } while (!finOperacion);

    /* --> LIBRACIÓN DE MEMORIA <-- */
    /* free(cuenta.historial); free(clientes); */
    for (int j = 0; j < cant_clientes; j++)
    {
        free(clientes[j].cuenta.historial);
        clientes[j].cuenta.historial = NULL;
        clientes[j].cuenta.cant_transac = 0;
    }
    free(clientes);
    clientes = NULL;
    cant_clientes = 0;
    printf("\n----> FIN <----\n");
    return 0;
}

/*===================================================*/
/* CREACION DE USUARIO NUEVO */
void nuevoCliente (tCliente *clientes, int cant_nueva)
{
    clientes = realloc(clientes, cant_nueva);
    int fecha_valida = 0;
    /* LLENADO DE DATOS */
    printf("\nApellido: ");
    gets(clientes[cant_nueva-1].apellido);
    
    printf("\nNombre: ");
    gets(clientes[cant_nueva-1].nombre);
    
    printf("\nDNI: ");
    scanf("%d",&clientes[cant_nueva-1].dni); /* scanf("%d",&clientes[cant_nueva-1]->dni); */
    /* fecha_nac */
    do {
        printf("\n--Fecha de Nacimiento--\n");
        printf("Dia: "); scanf("%d",&clientes[cant_nueva-1].fecNac.dia);
        printf("Mes: "); scanf("%d",&clientes[cant_nueva-1].fecNac.mes);
        printf("Anno: "); scanf("%d",&clientes[cant_nueva-1].fecNac.anno);
        while(fgetc(stdin)!='\n');
        fecha_valida = verificarFecha(clientes[cant_nueva-1].fecNac);
        if (!fecha_valida) {
            fprintf(stderr,"\nFecha Invalida\n");
        }
    } while (!fecha_valida); 

    printf("\nContrasenna: ");
    gets(clientes[cant_nueva-1].contrasenna);

    printf("\n--Datos Cuenta--\n");
    printf("CVU: "); scanf("%u",&clientes[cant_nueva-1].cuenta.cvu);
    printf("Saldo actual: "); scanf("%f",&clientes[cant_nueva-1].cuenta.saldo);
    clientes[cant_nueva-1].cuenta.historial = (float *)malloc(sizeof(float)); /* historial[] = NULL */
    clientes[cant_nueva-1].cuenta.cant_transac = 0; /* cantidad_transacciones = 0 */

    printf("\nLlenado de datos exitoso!\n");
}

int verificarFecha(tFecha fecha)
{
    int dias[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    int es_valida = (fecha.anno >= 2008 && fecha.anno <= 1950)
                    && (fecha.mes >= 1 && fecha.mes <= 12)
                    && (fecha.dia >= 1 && fecha.dia <= dias[fecha.mes-1] + 
                        ((fecha.mes == 2) && (fecha.anno % 4 == 0)));
    
    return es_valida;
}

/*===================================================*/
/* FUNCION - MENU PRINCIPAL */

int elegirUsuario (tCliente *clientes, int cant_clientes)
{
    int usu;
    printf("\n--> Eligir un usuario <--");
    for (int i = 0; i < cant_clientes; i++) {
        printf("\nUsuario %d: [%s, %s, %d]", i+1, clientes[i].apellido, clientes[i].nombre, clientes[i].dni);
    }
    printf("\n\n--[Ingrese %d: Para registrar un nuevo usuario]--",cant_clientes+1);
    printf("\n\n--[Ingrese 0: Para finalizar]--");
    printf("\n\n--> usuario: ");
    scanf("%d",&usu); while(fgetc(stdin)!='\n');

    return usu;
}

/*===================================================*/
/* PROCEDIMIENTOS */

void cambiarContrasenna (tCliente *c)
{
    printf("\nContrasenna actual: %s",c->contrasenna);
    printf("\nNueva contrasenna: ");
    gets(c->contrasenna);

    printf("\nContrasenna cambiada con exito.\nNueva contrasenna: %s\n",c->contrasenna);
}

void agregarFondos (tCliente *c)
{
    float monto;
    printf("\nIngrese el monto a agregar: ");
    scanf("%f",&monto);
    while(fgetc(stdin)!='\n');
    c->cuenta.saldo += monto;
    c->cuenta.cant_transac++;
    if (c->cuenta.cant_transac > 1) {
        c->cuenta.historial = (float *)realloc(c->cuenta.historial, c->cuenta.cant_transac * sizeof(float));
    }
    c->cuenta.historial[c->cuenta.cant_transac-1] = monto;
    printf("\nAgregado de fondos exitoso.\n");
}

void retirarFondos (tCliente *c)
{
    float monto;
    if (c->cuenta.saldo) {
        printf("\nIngrese el monto a retirar: ");
        scanf("%f",&monto);
        if (monto <= c->cuenta.saldo) {
            while(fgetc(stdin)!='\n');
            c->cuenta.saldo -= monto;
            c->cuenta.cant_transac++;
            if (c->cuenta.cant_transac > 1) {
                c->cuenta.historial = (float *)realloc(c->cuenta.historial, c->cuenta.cant_transac * sizeof(float));
            }
            c->cuenta.historial[c->cuenta.cant_transac-1] = -monto;
            printf("\nRetiro de fondos exitoso.\n");
        } else {
            printf("\nNo hay suficiente saldo en la cuenta pra retirar ese monto.\n");
        }
    } else {
        printf("\nNo dispone de saldo para retirar.");
    }
}

void consultarSaldo (tCliente *c)
{
    printf("\nDisponible: %.2f\n", c->cuenta.saldo);
}

void mostrarInfoCuenta (tCliente *c)
{
    printf("\nNombre: %s %s", c->nombre, c->apellido);
    printf("\nCVU: %u\n", c->cuenta.cvu);
}

void mostrarHistorialTransac (tCliente *c)
{
    printf("\n==> TRANSACCIONES realizadas en la cuenta <==");
    for (int i = 0; i < c->cuenta.cant_transac; i++) {
        printf("\n[%d] => %.2f", i+1, c->cuenta.historial[i]);
    }
    printf("\n");
}
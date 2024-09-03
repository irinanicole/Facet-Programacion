#include <stdio.h>


int main(){

    int cbu, dni, opcion;

    float saldo, deposito, retiro;

    printf("Ingrese el DNI, cbu y saldo:\n");
    scanf("%d %d %f", &dni, &cbu, &saldo);
    printf("Ingrese la opcion que desea realizar:\n1. Depositar dinero\n2. Retirar dinero\n3. Consultar Saldo\n4. Mostrar datos de la cuenta\n5. Salir del programa\n");
    scanf("%d", &opcion);

    switch(opcion){
        case 1: 
            printf("Ingrese el valor del dinero a depositar:\n");
            scanf("%f", &deposito);

            saldo = saldo + deposito;
            break;

         case 2:
           if(saldo>0){
              printf("Ingrese el monto que desea retirar: \n");
              scanf("%f", &retiro);

              if((saldo<retiro)){
                printf("Su cuenta no tiene saldo disponible >:)");
              }
              else{
                saldo = saldo-retiro;
                printf("La operacion se realizo con exito :/");
              }
           }
           else{
                printf("Su cuenta no tiene saldo disponible >:)");
           }
           break;

        case 3:
            printf("Saldo disponible: %f", saldo);
            break;

        case 4:
            printf("DNI:%d\nCBU:%d", dni, cbu);
            break;
        case 5:
            printf("Programa finalizado :)");
        
    }



    return 0;
}
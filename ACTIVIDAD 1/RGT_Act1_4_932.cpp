//Teresa Rivas Gomez
//Ago-22-2023 / Ago-27-2023
//A través de opciones (1.- HOMBRE 2.- MUJER ) preguntar al usuario cual es su SEXO y desplegar la leyenda “HOLA, ERES HOMBRE ”, “ HOLA, ERES MUJER”
//RGT_Act1_4_932

#include <stdio.h>
int main ()
{
    int opcion;

    printf("¿Que sexo eres?\n");
    printf("1.Hombre\n");
    printf("2.Mujer\n");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("HOLA, ERES HOMBRE\n");
    } else if (opcion == 2) {
        printf("HOLA, ERES MUJER\n");
    }

    return 0;
}
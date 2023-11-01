/*
NOMBRE: Teresa Rivas Gomez
MATRICULA: 372565
FECHA: Nov - 01 - 2023
DESCRIPCION: FUNCIONES y METODOS DE ORDENACION Y BUSQUEDA ESTRUCTURAS Y LIBRERIAS (p2)
NOMBRE DEL ARCHIVO: RGT_Act11_932.cpp
*/

#include "costco.h"

int menu_mensaje();
void menu();

int menu_mensajes_agregar();
void menu_agregar();

void imprimir_alumno(Tdatos _datos);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int menu_mensaje()
{
    int opcion;
    system ("CLS");
    printf ("ACTIVIDAD: SEMANA 12\n");
    printf("1.- AGREGAR\n");
    printf("2.- ELIMINAR REGISTRO\n");
    printf("3.- BUSCAR\n");
    printf("4.- ORDENAR\n");
    printf("5.- IMPRIMIR\n");
    printf("6.- ARCHIVO TEXTO\n");
    printf("0.- SALIR\n");
    opcion = ValidarCadena("OPCION QUE ELEGISTE(0-6):\n", 0, 6);
    return opcion;
}

void menu()
{
    int opcion;
    do {
        opcion = menu_mensaje();
        system("CLS");
        switch(opcion)
        {
            case 1:
                printf("AGREGAR\n");
                menu_agregar();
                system("PAUSE");
                break;
            case 2:
                printf("ELIMINAR REGISTRO\n");
                system("PAUSE");
                break;
            case 3:
                printf("BUSCAR\n");
                system("PAUSE");
                break;
            case 4:
                printf("ORDENAR\n");
                system("PAUSE");
                break;
            case 5:
                printf("IMPRIMIR\n");
                system("PAUSE");
                break;
            case 6:
                printf("ARCHIVO TEXTO\n");
                system("PAUSE");
                break;
            case 0:
                printf("SALISTE DEL PROGRAMA.\n");
                system("PAUSE");
                break;
        }
    } while(opcion != 0);
}

int menu_mensajes_agregar()
{
    int opcion;
    system ("CLS");
    printf ("AGREGAR:\n");
    printf("1.- MANUAL\n");
    printf("2.- AUTOMATICO\n");
    printf("3.- REGRESAR\n");
    opcion = ValidarCadena("OPCION QUE ELEGISTE(1-3):\n", 1, 3);
    return opcion;
} 

void menu_agregar()
{
    int opcion;
    Tdatos _datos;
    do {
        system("CLS");
        opcion = menu_mensajes_agregar();
        switch(opcion)
        {
            case 1:
                printf("MANUAL\n");
                generar_datos_manual(_datos);
                system("PAUSE");
                break;
            case 2:
                printf("AUTOMATICO\n");
                generar_datos_random(_datos);
                system("PAUSE");
                break;
            case 3:
                menu();
                break;
        }
    } while (opcion != 0);
}

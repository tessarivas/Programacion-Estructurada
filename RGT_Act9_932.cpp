// Teresa Rivas Gómez / Matricula: 372565
// Oct - 03 -2023
// RGT_Act9_932

// Librerias
#include <stdio.h>
#include <stdlib.h>
#include "mcdonalds.h"

// Menu para el usuario
int msges();
void menu();

// Buscar en Vector
int BuscarVector(int vector1[], int n);

// Menu
int main()
{
    menu();
    return 0;
}

// Menu para el usuario
int msges()
{
    int op;
    system ("CLS");
    printf ("\n MENU DE LA ACTIVIDAD 8 \n");
    printf("1.- LLENAR VECTOR \n");
    printf("2.- LLENAR MATRIZ \n");
    printf("3.- IMPRIMIR VECTOR \n");
    printf("4.- IMPRIMIR MATRIZ \n");
    printf("5.- ORDENAR VECTOR \n");
    printf("6.- BUSCAR VALOR EN VECTOR \n");
    printf("0.- SALIR  \n");
    op = ValidarCadena("Escribe el numero de opcion que elegiste: \n", 0, 6);
    // Retorno a opcion
    return op;
}

// Casos para el menu segun la opcion que elijan
void menu()
{
    int op;
    int n = 15;
    int vector1[15];
    int matriz[4][4];
    // Ciclo
    do{
        system("CLS");
        op=msges();
        // Casos
        switch (op)
        {
        case 1:
                LlenarVectorSinRepetir(vector1, n, 100, 200);
                printf("Vector llenado.\n");
                EsperarUsuario();
                break;
        case 2:
                LlenarMatrizSinRepetir(4, 4, matriz, 1, 16);
                printf("Matriz llenada.\n");
                EsperarUsuario();
                break;
        case 3: 
                ImprimirVector(vector1, n);
                EsperarUsuario();
                break;
        case 4:
                ImprimirMatriz(4, 4, matriz);
                EsperarUsuario();
                break;
        case 5:
                OrdenarVector(vector1, n);
                printf("Vector ordenado, vuelva a seleccionar la opcion 3.\n");
                EsperarUsuario();
                break;
        case 6:
                BuscarVector(vector1, n);
                EsperarUsuario();
                break;
        case 0:
                printf("Saliendo del programa.\n");
                break;
        }
    } while (op != 0);
}

// BUSCAR VECTOR
int BuscarVector(int vector1[], int n)
{
    // Declarar variable
    int ValorBuscar, posicion;
    // Validar el valor buscado
    ValorBuscar = ValidarCadena("Ingresa el valor que buscas (Entre 100 y 200):  ", 100, 200);
    // Realizar la búsqueda utilizando BusqSecVector
    posicion = BusqSecVector(vector1, n, ValorBuscar);
    // Condición para comprobar si se encontró o no
    if (posicion != -1)
    {
        printf("El numero ha sido encontrado, esta en la posicion: %d\n", posicion);
    }
    else
    {
        printf("El numero introducido no esta en el vector\n");
    }
    // Retorna la posicion encontrada o -1 si no se encuentra
    return posicion;
}
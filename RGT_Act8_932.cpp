// Teresa Rivas Gómez
// Sep - 26 -2023
// RGT_Act8_932

// Librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Menu para el usuario
int msges();
void menu();

// Validacion
int validar(char mensj[], int ri, int rf) ;

// Funcion para cada ejercicio
void vector_1(); // LLENAR VECTOR 1 (MANUALMENTE)
void vector_2(int vector[10]); // LLENAR VECTOR 2 ALEATORIAMENTE
void vector_3(int vector1[10], int vector2[10]); // LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2)
void imp_vector(int vector[10]); // IMPRIMIR VECTORES
void llen_matriz(int matriz[4][4]); // LLENA MATRIZ 4 X 4
void imp_matriz(int matriz[4][4]); // IMPRIMIR MATRIZ

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
    printf("1.- LLENAR VECTOR 1 (MANUALMENTE) \n");
    printf("2.- LLENAR VECTOR 2 ALEATORIAMENTE \n");
    printf("3.- LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2) \n");
    printf("4.- IMPRIMIR VECTORES \n");
    printf("5.- LLENA MATRIZ 4 X 4 \n");
    printf("6.- IMPRIMIR MATRIZ \n");
    printf("0.- SALIR  \n");
    // Matriz de caracteres para la conversion de la cadena
    char mensaje[] = "ESCOGE UNA OPCION: ";
    op = validar(mensaje, 0, 6);
    // Retorno a opcion
    return op;
}

// Casos para el menu segun la opcion que elijan
void menu()
{
    int op;
    int vector1[10];
    int vector2[10];
    int matriz[4][4];
    // Ciclo
    do{
        op=msges();
        // Casos
        switch (op)
        {
        case 1:
                vector_1(); 
                break;
        case 2:
                vector_2(vector2);
                break;
        case 3: 
                vector_3(vector1, vector2);
                break;
        case 4:
                imp_vector(vector1);
                break;
        case 5:
                llen_matriz(matriz);
                break;
        case 6:
                imp_matriz(matriz);
                break;
        case 0:
                printf("Saliste del programa.\n");
                break;
        default:
                printf("Opcion Invalida.\n");
                break;
        }
    }while (op != 0);
}

// Validacion
int validar(char mensj[], int ri, int rf) 
{
    int num;
    // Cadena que va a leer el mensaje ingresado
    char cadena[50]; 
    // Proceso y desarrollo
    do
    {
        printf("%s", mensj);
        // Borrar basura
        fflush(stdin); 
        gets(cadena);
        num = atoi(cadena);
    } while (num < ri || num > rf);
    // Retorna el valor qUe num, entre los rangos dados
    return num;
}

// Ejercicio 1
// LLENAR VECTOR 1 (MANUALMENTE)
void vector_1()
{
    printf("Hola");
}

// Ejercicio 2
// LLENAR VECTOR 2 ALEATORIAMENTE
void vector_2(int vector[10])
{
system("CLS");
    // Declarar variables
    int i;
    // Definirlos
    int m = 10, ri = 30, rf = 70; 
    // Ciclo para generar los valores aleatorios
    for (i = 0; i < m; i++)
    {
        // Sacar los valores aleatoriamente
        vector[i] = (rand() % (rf - ri + 1)) + ri;
    }
    // Ciclo para imprimir los valores
    printf("Valores generados aleatoriamente para el vector 2:\n");
    for (i = 0; i < m; i++)
    {
        // Imprimir los valores
        printf("%d\n", vector[i]);
    }
    system("PAUSE");
    getchar();
}

// Ejercicio 3
// LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2)
void vector_3(int vector1[10], int vector2[10])
{
    for (int i = 0; i < 10; i++)
    {
        // Llenar vector 1 con 2
        vector1[i] = vector2[i];
    }
}

// Ejercicio 4
// IMPRIMIR VECTORES
void imp_vector(int vector[10])
{
    printf("Valores del vector:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", vector[i]);
    }
    system("PAUSE");
    getchar();
}

// Ejercicio 5
// LLENA MATRIZ 4 X 4
void llen_matriz(int matriz[4][4])
{
    // Ciclo para los renglones
    for(int i = 0; i < 4; i++)
    {
        // Ciclo para las columnas
        for(int j = 0; j < 4; j++)
        {
            // Llena aleatoriamente
            matriz[i][j] = rand()%100;
        }
    }
}

// Ejercicio 6
// IMPRIMIR MATRIZ
void imp_matriz(int matriz[4][4])
{
    // Imprimir titulo
    printf("Matriz 4x4:\n");
    // Bucle para acomodar los numeros
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // El %3d acomoda los numeros con un ancho de 3 caracteres
            printf("%3d ", matriz[i][j]);
        }
        // Salta a la siguiente linea despues de cada fila
        printf("\n");
    }
    system("PAUSE");
    getchar();
}

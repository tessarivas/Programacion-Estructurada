// Teresa Rivas Gómez / Matricula: 372565
// Oct - 03 -2023 / Oct - 08 - 2023
// Libreria de mis funciones
// mcdonalds.h

// - LIBRERIAS - //
#include <stdio.h>
#include <stdlib.h>

/*-------------------------------------------------------*/

// - FUNCIONES - //

// PARA VALIDAR:
int ValidarCadena(char mensj[], int ri, int rf);
int DigitoEncontrado(int vector[], int longitud, int num);

// PARA ENTRADA Y SALIDA DE DATOS:
void EsperarUsuario();

// PARA VECTORES Y MATRICES:
void LlenarVectorSinRepetir(int vector1[], int n, int ri, int rf);
void LlenarMatrizSinRepetir(int m, int n, int matriz[][4], int ri, int rf);
void ImprimirVector(int vector[], int n);
void ImprimirMatriz(int n, int m, int matriz[][4]);
void OrdenarVector(int vector[], int n);
int BusqSecVector(int vector[], int n, int num);

/*-------------------------------------------------------*/

// - VALIDACION - //

// CADENA: El valor del numero entre los rangos especificados.
int ValidarCadena(char mensj[], int ri, int rf) 
{
    // Declarar variables
    int num;
    // Cadena que va a leer el mensaje ingresado
    char cadena[200]; 
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

// DIGITO: Busca un valor en especifico en el vector
int DigitoEncontrado(int vector[], int longitud, int num)
{
    // Declarar variable
    int i;
    // Ciclo para recorrer el vector
    for (i = 0; i < longitud; i++)
    {
        if (vector[i] == num)
        {
            // Retorna a la posicion en la que esta el numero en el vector
            return i;
        }
    }
    // Retorna a -1 si no esta
    return -1;
}

/*-------------------------------------------------------*/

// - DATOS - //

// ESPERA DE DATOS: para mostrar un mensaje de espera y esperar la entrada del usuario
void EsperarUsuario()
{
    printf("\nPresiona ENTER para continuar...");
    // Espera a que el usuario presione ENTER
    getchar();
}

/*-------------------------------------------------------*/

// - VECTORES Y MATRICES - //

// LLENAR VECTOR: Random sin repetir
void LlenarVectorSinRepetir(int vector1[], int n, int ri, int rf)
{
    // Declarar variables
    int num, rango;
    int i;
    // Inicializar variables
    num = 0;
    rango = (rf - ri) + 1;
    // Ciclo para llenar el vector con los valores random
    for (i = 0; i < n; i++)
    {
        // Ciclo para que no haya repeticiones
        do
        {
            num = (rand() % rango) + ri;
            // Se manda a llamar a la funcion para encontrar digitos
        } while (DigitoEncontrado(vector1, i, num) != -1);
        vector1[i] = num;
    }
}

// LLENAR MATRIZ: Random sin repetir
void LlenarMatrizSinRepetir(int m, int n, int matriz[][4], int ri, int rf)
{
    // m y n son las dimensiones de la matriz
    // Declarar variables, llenamos el vector multiplicando
    int vector[m * n];
    LlenarVectorSinRepetir(vector, m * n, ri, rf);
    // 2 ciclos anidados para asignarle los valores que tiene el vector a la matriz
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = vector[k++];
        }
    }
}


// IMPRIMIR VECTOR: Random sin repetir
void ImprimirVector(int vector[], int n)
{
    // Declarar variable
    int i;
    // n = Longitud del vector
    for (i = 0; i < n; i++)
    {
        // Vector que se imprimira
        printf("Vector [%d]: [%2d]\n", i, vector[i]);
    }
}

// IMPRIMIR MATRIZ: Random sin repetir
void ImprimirMatriz(int n, int m, int matriz[][4])
{
    // 2 ciclos anidados para poder recorrer la matriz completamente.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Imprime cada elemento con \t para darle formato
            printf("[%2d]\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// ORDENAR VECTOR
void OrdenarVector(int vector[], int n)
{
    // Declarar funciones
    int i, j;
    int temp;
    // Ciclo 1
    for(i = 0; i < n; i++)
    {
        // Ciclo 2 para comparar
        for(j = 0; j < n; j++)
        {
            // Comparacion
            if(vector[j] > vector[i])
            {
                // Usar variable temporal como espacio para la comparacion
                temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
    }
}

// BUSQUEDA SECUENCIAL
int BusqSecVector(int vector[], int n, int num)
{
    // Declarar función
    int i;
    // Ciclo para recorrer el vector
    for(i = 0; i < n; i++)
    {
        if(vector[i] == num)
        {
            return i;
        }
    }
    return -1;
}
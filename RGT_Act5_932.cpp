// Teresa Rivas Gomez 372565
// Sep - 09 - 2023 / Sep - 10 - 2023
// RGT_Act5_932

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

//Declarar Funciones
int msges();
void menu();
void ejercicio_1(void);
void ejercicio_2(void);
void ejercicio_3(void);
void ejercicio_4(void);

int main()
{
    menu();

    return 0;
}

//Menu principal que ve el usuario
int msges()
{
    int op;
    printf("\n MENU \n");
    printf("1.- EJERCICIO 1 \n");
    printf("2.- EJERCICIO 2 \n");
    printf("3.- EJERCICIO 3 \n");
    printf("4.- EJERCICIO 4 \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
// Menu para los casos
void menu()
{
    int op;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            ejercicio_1();
            break;
        case 2:
            ejercicio_2();
            break;
        case 3:
            ejercicio_3();
            break;
        case 4:
            ejercicio_4();
            break;
        }

    } while (op != 0);
}
//Funcion en C que pida al usaurio el valor de n, y desplegar todos 
// los numeros enteros positivos menores de n en orden descendente. 
void ejercicio_1()
{
    int n;
    //Mostrar valor
    printf("Ingrese un valor: \n");
    scanf("%d", &n);
    //Condicion para error
    if (n <= 0) 
    {
        printf("El numero ingresado no es positivo.\n");
    }
    printf("Numeros enteros positivos menores que %d en orden descendente:\n", n);
    while (n > 1) 
    {
        n--;
        printf("%d\n", n);
    }
}
// Función en "C" que genere 40 numeros aleatorios 
// entre el 0 y 200, desplegar los números y 
// la leyenda de cada numero si es par o impar, la cantidad 
// de los numeros pares e impares así como la suma de 
// los numeros pares o impares.
void ejercicio_2()
{
    srand(time(NULL)); 
    // Inicializar la semilla para numeros aleatorios 
    // con el tiempo actual
    int numeros[40];
    int pares = 0, impares = 0;
    int sumaPares = 0, sumaImpares = 0;
    // Generar 40 numeros aleatorios entre 0 y 200
    for (int i = 0; i < 40; i++) 
    {
        numeros[i] = rand() % 201;  // Generar numero aleatorio entre 0 y 200
    }
    // Mostrar los numeros y determinar si son pares o impares
    printf("Numeros aleatorios y su naturaleza (par o impar):\n");
    for (int i = 0; i < 40; i++) 
    {
        printf("%d ", numeros[i]);
        if (numeros[i] % 2 == 0) 
        {
            printf("(Par)\n");
            pares++;
            sumaPares += numeros[i];
        } 
        else 
        {
            printf("(Impar)\n");
            impares++;
            sumaImpares += numeros[i];
        }
    }
    printf("Cantidad de numeros pares: %d\n", pares);
    printf("Cantidad de numeros impares: %d\n", impares);
    printf("Suma de numeros pares: %d\n", sumaPares);
    printf("Suma de numeros impares: %d\n", sumaImpares);
}
//Funcion en "C" que genere N (35) cantidad de numeros (100 -200), 
// desplegar al final el numero mayor y el numero menor. 
void ejercicio_3()
{
    srand(time(NULL));  
    // Inicializar la semilla para numeros aleatorios con el tiempo actual
    int n = 35;  
    // Cantidad de numeros a generar
    int numeros[n];
    int numeroMayor, numeroMenor;
    // Generar n numeros aleatorios entre 100 y 200 y encontrar el 
    // numero mayor y menor
    for (int i = 0; i < n; i++) 
    {
        numeros[i] = rand() % 101 + 100;  
        // Generar numero aleatorio entre 100 y 200
        if (i == 0) 
        {
            numeroMayor = numeroMenor = numeros[i];  
            // Inicializar el mayor y menor con el primer 
            //numero generado
        } 
        else 
        {
            if (numeros[i] > numeroMayor) 
            {
                numeroMayor = numeros[i];  
                // Actualizar el numero mayor si es necesario
            }
            if (numeros[i] < numeroMenor) 
            {
                numeroMenor = numeros[i];  
                // Actualizar el numero menor si es necesario
            }
        }
    }
    // Mostrar los numeros generados
    printf("Numeros generados:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    // Mostrar el numero mayor y el numero menor
    printf("Numero mayor: %d\n", numeroMayor);
    printf("Numero menor: %d\n", numeroMenor);
}
//Función en "C" que despliegue la tabla de multiplicar de un numero dado 
// (número entre el 1 y 20).
void ejercicio_4()
{
    int numero;
    // Solicitar al usuario el numero para la tabla de multiplicar
    printf("Ingrese un numero entre 1 y 20 para mostrar su tabla de multiplicar: ");
    scanf("%d", &numero);
    //Condicion para el rango
    if (numero < 1 || numero > 20) 
    {
        printf("El numero debe estar en el rango de 1 a 20.\n");
    }
    printf("Tabla del %d:\n", numero);
    // Mostrar la tabla de multiplicar
    for (int i = 1; i <= 10; i++) 
    {
        printf("%d * %d = %d\n", numero, i, numero * i);
    }
}


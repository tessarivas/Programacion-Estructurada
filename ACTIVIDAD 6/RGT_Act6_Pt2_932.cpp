// Teresa Rivas Gomez 372565
// Sep - 18 - 2023
// RGT_Act6_Pt2_932

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int msges();
void menu();

// Declaracion de variables
void examen_nivelacion(void);
void tablas_multiplicar(void);
void numeros_en_rango(void);
void turistas(void);
void alumno_reprobado(void);

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
    printf ("\n M E N U \n");
    printf("1.- EXAMEN NIVELACION \n");
    printf("2.- TABLAS DE MULTIPLICAR \n");
    printf("3.- NUMEROS EN UN RANGO \n");
    printf("4.- PESO DE TURISTAS \n");
    printf("5.- ALUMNO REPROBADO \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf ("%d",&op);
    return op;
}
void menu()
{
  int op;
  do{
      op=msges();
      switch (op)
      {
        case 1:
              examen_nivelacion();
              break;
        case 2:
              tablas_multiplicar();
              break;
        case 3:
              numeros_en_rango();
              break;
        case 4:
              turistas();
              break;
        case 5:
              alumno_reprobado();
              break;
        case 0:
            printf("Gracias por usar este programa.\n");
            break;
        default:
            printf("OPCION INCORRECTA, INTENTALO DE NUEVO.\n");  
            break;
      }
    }while (op != 0);
}
// Validar argumentos dados por el usuario
int validar(char mensj[], int ri, int rf) 
{
    int num;
     // Cadena que va a leer el mensaje ingresado
    char cadena[1000]; 
    
    // Proceso y desarrollo
    do
    {
        printf("%s", mensj);
        fflush(stdin);
        gets(cadena);
        num = atoi(cadena);

    } while (num < ri || num > rf);

    // Retorna el valor qde num, entre los rangos dados
    return num;
}
// El profesor de una materia desea conocer la cantidad de sus alumnos que no tienen derecho al examen de nivelación.
// Diseñe un programa en C que lea las calificaciones obtenidas en las 5 unidades por cada uno de los 40 alumnos y 
// escriba la cantidad de ellos que no tienen derecho al examen de nivelación ( Los promedios menores de 50 no tiene 
// derecho a examen de nivelación).
void examen_nivelacion()
{
    system("CLS");

    // Declaración de variables
    int a = 4;
    int u = 5;
    int s_d = 0;

    // Bucle para los alumnos
    for (int i = 1; i <= a; i++) 
    {
        printf("\n EXAMEN DE NIVELACION \n");
        printf("Ingrese las calificaciones del alumno %d:\n", i);
        double suma = 0.0;

        // Bucle para las calificaciones
        for (int j = 1; j <= u; j++) 
        {
            double cal;
            printf("Unidad %d: ", j);

            // Validación de la calificación
            int valid = 0;
            do {
                if (valid) 
                {
                    printf("ERROR: Ingrese una calificación válida (entre 0 y 100).\n");
                }
                valid = 1;
                while (scanf("%lf", &cal) != 1) 
                {
                    printf("ERROR: Ingrese una calificación válida (entre 0 y 100).\n");
                    while (getchar() != '\n'); // Limpiar el búfer de entrada
                    printf("Unidad %d: ", j);
                }
            } while (cal < 0 || cal > 100);

            suma += cal;
        }

        // Operación para el promedio
        double prom = suma / u;

        // Condición para los reprobados
        if (prom < 50.0) 
        {
            s_d++;
        }
    }

    // Salida
    printf("Alumnos sin derecho a examen de nivelacion: %d\n", s_d);

    system("PAUSE");
}
// Realiza una función en C que imprima las tablas de multiplicar del 1 al 10.
void tablas_multiplicar()
{
    system("CLS");

    // Declaracion de variables
    int i, j;
	
    // Ciclos para generar las tablas de multiplicar
	for (i = 1; i <= 10; i++)
	{
        printf("TABLAS DE MULTIPLICAR\n");
		printf("TABLA DEL %d\n\n", i);
		for (j = 1; j <= 10; j++)
		{
			printf("%d * %d = %d\n", i, j, i * j);
		}
    }
    system("PAUSE");
}
// Realizar función en C para un programa que sirva para leer n cantidad de números dentro de un rango dado 
// por el usuario, desplegar la suma de los números y la media aritmética de los números válidos dentro del rango.
void numeros_en_rango()
{
    system("CLS");

    int n, ri, rf, num, suma = 0;
    
    // Leer datos
    printf("SUMA Y MEDIA DE NUMEROS EN UN RANGO\n");
    printf("Ingrese la cantidad de numeros a ingresar: ");
    scanf("%d", &n);
    printf("Ingrese el valor minimo del rango: ");
    scanf("%d", &ri);
    printf("Ingrese el valor maximo del rango: ");
    scanf("%d", &rf);

    // Validación de el rango inicial
    if (ri > rf) 
    {
        printf("El valor minimo del rango debe ser menor o igual al valor maximo.\n");
        return;
    }

    // Ciclos animados para los numeros
    for (int i = 1; i <= n; i++) 
    {
        num = validar("Ingresa un numero: ", ri, rf);
        suma += num;
    }

    // Calcular la suma y la media
    float media = (float)suma / n; // Convertir uno a float para obtener una división decimal que sea mas precisa

    // Impresion en pantalla
    printf("\n");
    printf("La suma es: %d\n", suma);
    printf("La media es: %.2f\n", media);
    printf("\n");

    system("PAUSE");
}
// En los cabos la embarcación finisterra que tiene fondo de cristal, solo sale a navegar con un máximo de 10 turistas
// o un máximo de 700 kilos de pasajeros. (preguntar el peso a cada turista) con un máximo de 15% de sobrepeso. 
// Desplegar el promedio de peso de los turistas y cual de los 2 condiciones se cumplió.
void turistas()
{
    system("CLS");

    // Declaracion de variables
    // p_turista = peso de turistas, p_promedio = peso promedio, s = sobrepeso en turistas
    int turistas, p_turistas = 0, p_promedio, s = 700 + (700 / 15); // Porcentaje del 15%

    for (turistas = 0; turistas < 10; turistas++)
    {
        int t;

        // Validacion y valor a la variable
        t = validar("Ingresa tu peso del turista: ", 0, 300);
        p_turistas += t; // Acumulador
        getch();

        // Condicion para el peso maximo
        if (p_turistas == s) 
        {
            printf("El peso maximo de los turistas ha llegado al limite!\n");
            break; 
        }
        // Capacidad maxima del barco
        if (turistas == 9)
        {
            printf("La capacidad maxima ha llegado al limite\n");
        }
    }
    p_promedio = p_turistas / turistas; 

    // Mostrar el promedio de peso
    printf("El promedio de peso de los turistas es: %.2d kg\n", p_promedio);

    system("PAUSE");
}
// Un alumno solo puede cursar la misma asignatura en un máximo de 3 veses, si el alumno reprueba durante sus 
// intentos deberá repetir la materia, y si en su tercera ocasión no aprueba se le dará de baja académica.
// Elabore una función donde basada en sus 3 exámenes parciales calcular el promedio y basado en su promedio 
// final, se deberá enviar mensaje al alumno de repetir materia, aprobado o baja temporal. 
void alumno_reprobado()
{
    system("CLS");

    float promedio = 0;
    // Ciclo para las veces que ha estado cursando esta materia
    for (int materia = 0; materia < 3; materia++)
    {
        printf("Ingrese la cantidad de veces que ha cursado la materia: %d\n", materia + 1);
        int acumulador = 0;
        // Ciclo para generar calificaciones
        for (int i = 0; i < 3; i++)
        {
            int calificacion; 
            // Validar que la calificacion este dentro del rango y asignarle un valor
            calificacion = validar("Ingresa tu calificacion del parcial: ", 0, 100);
            // Acumula la calificacion
            acumulador += calificacion;
        }
        // Desarrollo del primedio
        promedio = acumulador / 3; 
        printf("Tu promedio es de: %.2f\n", promedio); 
        // Condicion para saber si sera temporal
        if (materia == 2)
        {
            printf("Has alcanzado el numero maximo de intentos\n");
            printf("\n BAJA TEMPORAL\n");
            break; 
        }
        // Condicion para saber si repitira de nuevo
        if (promedio < 60)
        {
            printf("REPETIR MATERIA\n");
            getch();
        }
        else 
        {
            printf("FELICIDADES, HAS APROBADO\n");
            break; 
        }
    }
    system("PAUSE");
}
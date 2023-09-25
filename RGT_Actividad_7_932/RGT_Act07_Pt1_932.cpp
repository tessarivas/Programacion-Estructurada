// Teresa Rivas Gomez
// Sep - 19 - 2023 / Sep - 23 - 2023 / Sep - 25 - 2023
// RGT_Act07_Pt1_932

// Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Menu Principal
int msges();
void menu();

//Funcion para la pedir de datos
void datos(char nombre[]);

// Validacion
int validar(char mensj[], int ri, int rf);

// Declarar funciones
//Ejercicios de la Parte 1
void salida1(char nombre[]);
void salida2(char nombre[]);
void salida3(char nombre[]);
void salida4(char nombre[]);
void salida5(char nombre[]);
void salida6(char nombre[]);
void salida7(char nombre[]);
void salida8(char nombre[]);
void salida9(char nombre[]);
void salida10(char nombre[]);

// Funcion main
int main()
{
    menu();
    return 0;
}

// Menu que se muestra al usuario
int msges()
{ 
    int op;

    system ("CLS");
    printf("\n MENU PARA LAS DIFERENTES SALIDAS DE LA CADENA \n");
    printf("\n OPCIONES: \n");
    printf("1.- Salida 1: MAYUSCULAS\n");
    printf("2.- Salida 2: MAYUSCULAS AL REVES\n");
    printf("3.- Salida 3: UNA LETRA POR RENGLON\n");
    printf("4.- Salida 4: UNA LETRA POR RENGLON AL REVES\n");
    printf("5.- Salida 5: LA PALABRA MENOS UNA LETRA\n");
    printf("6.- Salida 6: LA PALABRA MENOS UNA LETRA AL REVES\n");
    printf("7.- Salida 7: LA PALABRA MENOS UNA LETRA DEL INICIO\n");
    printf("8.- Salida 8: LA PALABRA MENOS UNA LETRA DEL INICIO AL REVES\n");
    printf("9.- Salida 9: SOLO CONSONANTES\n");
    printf("10.- Salida 10: SOLO VOCALES\n");
    printf("0.- SALIR  \n");
    op = validar ("ESCOGE UNA OPCION: ", 0, 10);

    return op;
}

// Casos depende la seleccion del usuario
void menu()
{
     system ("CSL");
    int op;
    char nombre[50];
    do {
        op = msges();
        switch(op)
        {
            case 1:
                datos(nombre);
                salida1(nombre);
                break;
            case 2:
                datos(nombre);
                salida2(nombre);
                break;
            case 3:
                datos(nombre);
                salida3(nombre);
                break;
            case 4:
                datos(nombre);
                salida4(nombre);
                break;
            case 5:
                datos(nombre);
                salida5(nombre);
                break;
            case 6:
                datos(nombre);
                salida6(nombre);
                break;
            case 7:
                datos(nombre);
                salida7(nombre);
                break;
            case 8:
                datos(nombre);
                salida8(nombre);
                break;
            case 9:
                datos(nombre);
                salida9(nombre);
                break;
            case 10:
                datos(nombre);
                salida10(nombre);
                break;
            case 0:
                printf("Saliste del programa.\n");
                break;
            default:
                printf("Opcion Invalida.\n");
                break;
        }
    } while(op != 0);
    system("PAUSE");
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
        fflush(stdin);
        gets(cadena);
        num = atoi(cadena);
    } while (num < ri || num > rf);
    // Retorna el valor qUe num, entre los rangos dados
    return num;
}

//Pedir datos
void datos(char nombre[])
{
    system ("CLS");
    printf("Introduzca su nombre: ");
    fflush(stdin);
    gets(nombre);

    if (nombre[strlen(nombre) - 1] == '\n') 
    {
        nombre[strlen(nombre) - 1] = '\0';
    }
}

// Salidas diferentes de la cadena
// SALIDA 1
void salida1(char nombre[])
{
    system ("CLS");
    //Imprimir nombre de la salida
    printf("Salida 1: MAYUSCULAS\n");
    // Recorre todos los caracteres uno por uno
    for (int i = 0; nombre[i] != '\0'; i++)
    {
        // Comprobar si estan en minusculas
        if (nombre[i] >= 'a') 
        {
            if (nombre[i] <= 'z') 
            {
                // Si las condiciones son verdaderas se hace la conversion a mayusculas
                nombre[i] = nombre[i] - ('a' - 'A'); 
            }
        }
    // Imprime la palabra en mayusculas o igual 
        printf("%c", nombre[i]);
    }
    printf("\n");
    system("PAUSE"); 
}

// SALIDA 2
void salida2(char nombre[])
{
    system("CLS");
    //Imprimir nombre de la salida
    printf("Salida 2: MAYUSCULAS AL REVES\n");

    int length = strlen(nombre);

    for (int i = length - 1; i >= 0; i--)
    {
        if (nombre[i] >= 'a')
        {
            if (nombre[i] <= 'z')
            {
                nombre[i] = nombre[i] - ('a' - 'A');
            }
        }

        printf("%c", nombre[i]);
    }

    printf("\n");
    system("PAUSE");
}

// SALIDA 3
void salida3(char nombre[])
{
    system ("CLS");
    //Imprimir nombre de la salida
    printf("Salida 3: UNA LETRA POR RENGLON\n");

    for (int i = 0; nombre[i] != '\0'; i++)
    {
        if (nombre[i] >= 'a')
        {
            if (nombre[i] <= 'z')
            {
                nombre[i] = nombre[i] - ('a' - 'A');
            }
        }

        printf("%c\n", nombre[i]);
    }

    printf("\n");
    system("PAUSE"); 
}

// SALIDA 4
void salida4(char nombre[])
{
    system ("CLS");
    //Imprimir nombre de la salida
    printf("Salida 4: UNA LETRA POR RENGLON AL REVES\n");

    int length = strlen(nombre);

    for (int i = length - 1; i >= 0; i--)
    {
        if (nombre[i] >= 'a')
        {
            if (nombre[i] <= 'z')
            {
                nombre[i] = nombre[i] - ('a' - 'A');
            }
        }

        printf("%c\n", nombre[i]);
    }

    printf("\n");
    system("PAUSE"); 
}

// SALIDA 5
void salida5(char nombre[])
{
    system ("CLS");
    //Imprimir nombre de la salida
    printf("Salida 5: LA PALABRA MENOS UNA LETRA\n"); 
    // Declarar variables
    // Largo del nombre
    int length = strlen(nombre);
    char copia_nombre[50];
    // Copiar 
    strcpy(copia_nombre, nombre);
    // Posiciones de la cadena 
    // Elimina los caracteres desde la posicion i hasta que se acaba la cadena
    for (int i = length; i >= 0; i--) 
    {
        // Recortar la cadena copiada
        copia_nombre[i] = '\0'; 
        // Para mostrar los caracteres 
        for (int j = 0; copia_nombre[j] != '\0'; j++)
        {
            if (copia_nombre[j] >= 'a')
            {
                if (copia_nombre[j] <= 'z')
                {
                    copia_nombre[j] = copia_nombre[j] - ('a' - 'A');
                }
            }
            // Se imprime el caracter de la posicion j
            printf("%c", copia_nombre[j]);
        }
        
        printf("\n");
    }

    printf("\n");
    system("PAUSE");  
}

// SALIDA 6
void salida6(char nombre[])
{
    system ("CLS");
    printf("Salida 6: LA PALABRA MENOS UNA LETRA AL REVES\n");
    // Declarar variables
    int length = strlen(nombre);
    char copia_nombre[50];

    strcpy(copia_nombre, nombre);

    for (int i = length - 1; i > 0; i--) 
    {
        // Recortar la cadena copiada
        copia_nombre[i] = '\0'; 

        for (int j = length - 1; j >= 0; j--)
        {
            if (copia_nombre[j] >= 'a')
            {
                if (copia_nombre[j] <= 'z')
                {
                    copia_nombre[j] = copia_nombre[j] - ('a' - 'A');
                }
            }

            printf("%c", copia_nombre[j]);
        }
        
        printf("\n");
    }

    printf("\n");
    system("PAUSE");  
}

// SALIDA 7
void salida7(char nombre[])
{
    system ("CLS");
    printf("Salida 7: LA PALABRA MENOS UNA LETRA DEL INICIO\n");
    // Declarar variables
    // Largo del nombre
    char copia_nombre[50];
    // Copiar 
    strcpy(copia_nombre, nombre);
    
    for (int i = 0; copia_nombre[i] != '\0'; i++)
    {
        if (copia_nombre[i] >= 'a')
        {
            if (copia_nombre[i] <= 'z')
            {
                copia_nombre[i] = copia_nombre[i] - ('a' - 'A');
            }
        }
        printf("%c\n", copia_nombre + i + 1);
    }
    printf("\n");
    system("PAUSE"); 
}

// SALIDA 8
void salida8(char nombre[])
{
    system ("CLS");

    printf("Salida 8: LA PALABRA MENOS UNA LETRA DEL INICIO AL REVES\n");
    // Declarar variables
    int length = strlen(nombre);
    char copia_nombre[50];

    strcpy(copia_nombre, nombre);

    for (int i = 0; copia_nombre[i] != '\0'; i++) 
    {
        // Recortar la cadena copiada
        copia_nombre[i] = '\0'; 

        for (int j = length - 1; j >= 0; j--)
        {
            if (copia_nombre[j] >= 'a')
            {
                if (copia_nombre[j] <= 'z')
                {
                    copia_nombre[j] = copia_nombre[j] - ('a' - 'A');
                }
            }
            printf("%c", copia_nombre[j]);
        }
        printf("\n");
    }
    printf("\n");
    system("PAUSE"); 
}

// SALIDA 9
void salida9(char nombre[])
{
    system ("CLS");
    // Imprimir nombre de la salida
    printf("Salida 9: SOLO CONSONANTES\n");
    // Imprimir el nombre en mayúsculas
    for (int i = 0; nombre[i] != '\0'; i++) 
    {
        if (nombre[i] >= 'a') 
        {
            if(nombre[i] <= 'z')
            {
                nombre[i] = nombre[i] - ('a' - 'A');
            }
        }
    }
    // Imprimir solo las vocales
    for (int i = 0; nombre[i] != '\0'; i++) 
    {
        if ( nombre[i] != 'A')
        {
            if (nombre[i] != 'E')
            {
                if ( nombre[i] != 'I')
                {
                    if ( nombre[i] != 'O')
                    {
                        if ( nombre[i] != 'U')
                        {
                            printf ( "%c", nombre[i] );
                        }
                    }
                }
            }
        }
    }
    printf("\n");
    system("PAUSE");  
}

// SALIDA 10
void salida10(char nombre[])
{
    system ("CLS");
    //Imprimir nombre de la salida
    printf("Salida 10: SOLO VOCALES\n");
    // Imprimir el nombre en mayúsculas
    for (int i = 0; nombre[i] != '\0'; i++) 
    {
        if (nombre[i] >= 'a') 
        {
            if(nombre[i] <= 'z')
            {
                nombre[i] = nombre[i] - ('a' - 'A');
            }
        }
    }
    // Imprimir solo las vocales
    for (int i = 0; nombre[i] != '\0'; i++) 
    {
        if ( nombre[i] == 'A')
        {
            printf ( "%c", nombre[i] );
        }
        if (nombre[i] == 'E')
        {
            printf ( "%c", nombre[i] );
        }
        if ( nombre[i] == 'I')
        {
            printf ( "%c", nombre[i] );
        }
        if ( nombre[i] == 'O')
        {
            printf ( "%c", nombre[i] );
        }
        if ( nombre[i] == 'U')
        {
            printf ( "%c", nombre[i] );
        }
    }
    printf("\n");
    system("PAUSE");  
}

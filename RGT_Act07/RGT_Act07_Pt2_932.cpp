// Teresa Rivas Gomez
// Sep - 19 - 2023 / Sep - 24 - 2023 / Sep - 25 - 2023
// RGT_Act07_Pt2_932

// Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Menu Principal
int msges();
void menu();

// Validacion:
// Declaracion de la función es_numero
int es_numero(char caracter);
// Declaracion de la función es_espacio
int es_espacio(char caracter);
// Función de validacion
int validarCadena(const char *cadena);

//Funcion para la pedir de datos
void datos(char cadena[]);

// Ejercicios de la Parte 2
void ej1_pt2(char cadena[]);
void ej2_pt2(char cadena[]);
void ej3_pt2(char cadena[]);
void ej4_pt2(char cadena[]);
void ej5_pt2(char cadena[]);
void ej6_pt2(char cadena[]);
void ej7_pt2(char cadena[]);
void ej8_pt2(char cadena[]);
void ej9_pt2(char cadena[]);

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
    printf ("\n MENU DE LA ACTIVIDAD 7 \n");
    printf ("\n PARTE 2 \n");
    printf("1.- Mayusculas \n");
    printf("2.- Minusculas \n");
    printf("3.- Capital \n");
    printf("4.- Cantidad \n");
    printf("5.- Inversa \n");
    printf("6.- Nueva Cadena \n");
    printf("7.- Alfabeto \n");
    printf("8.- TODO \n");
    printf("9.- PALINDROMO \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf ("%d",&op);

    return op;
}

// Casos depende la seleccion del usuario
void menu()
{
  int op;
  char cadena[50];
  do{
      op=msges();
      switch (op)
      {
        case 1:
              datos(cadena);
              ej1_pt2(cadena);
              break;
        case 2:
              datos(cadena);
              ej2_pt2(cadena);
              break;
        case 3:
              datos(cadena);
              ej3_pt2(cadena);
              break;
        case 4:
              datos(cadena);
              ej4_pt2(cadena);
              break;
        case 5:
              datos(cadena);
              ej5_pt2(cadena);
              break;
        case 6:
              datos(cadena);
              ej6_pt2(cadena);
              break;
        case 7:
              datos(cadena);
              ej7_pt2(cadena);
              break;
        case 8:
              datos(cadena);
              ej8_pt2(cadena);
              break;      
        case 9:
              datos(cadena);
              ej9_pt2(cadena);
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
int validarCadena(const char *cadena) 
{
    int contieneNumero = 0;
    int contieneDobleEspacio = 0;

    for (int i = 0; cadena[i] != '\0'; i++) 
    {
        if (es_numero(cadena[i])) 
        {
            contieneNumero = 1;
        } 
        if (es_espacio(cadena[i])) 
        {
            if (cadena[i + 1] == ' ') 
            {
                contieneDobleEspacio = 1;
            }
        }
    }

    if (contieneNumero || contieneDobleEspacio) 
    {
        // La cadena no cumple con los requisitos
        return 0;
    } 
    else 
    {
        // La cadena cumple con los requisitos
        return 1; 
    }
}

int es_numero(char caracter) 
{
    return (caracter >= '0' && caracter <= '9');
}

int es_espacio(char caracter) 
{
    return (caracter == ' ');
}

//Pedir datos
void datos(char cadena[])
{
    system ("CLS");
    printf( "Introduzca una palabra: " );
    fflush(stdin);
    gets(cadena);

    // Validar la cadena después de que el usuario la ingrese
    if (!validarCadena(cadena)) 
    {
        printf("La cadena no cumple con los requisitos.\n");
        printf("No uses dobles espacios y no ingreses numeros.\n");
        // Borra la cadena si no es valida
        cadena[0] = '\0'; 
        system("PAUSE");
    }
}

// PARTE 2
// Ejercicio 1 Parte 2
// Función que reciba como parámetro una cadena y la convierta a MAYUSCULAS
void ej1_pt2(char cadena[])
{
    // // Verifica la cadena
    if (cadena[0] != '\0')
    {
        system ("CLS");
        // Titulo
        printf("CONVERTIR A MAYUSCULAS\n");
        // Recorre todos los caracteres uno por uno
        for (int i = 0; cadena[i] != '\0'; i++)
        {
            // Comprobar si estan en minusculas
            if (cadena[i] >= 'a') 
            {
                if (cadena[i] <= 'z') 
                {
                    // Si las condiciones son verdaderas se hace la conversion a mayusculas
                    cadena[i] = cadena[i] - ('a' - 'A'); 
                }
            }
        // Imprime la palabra en mayusculas o igual 
            printf("%c", cadena[i]);
        }
        printf("\n");
        system("PAUSE");
    }
}

// Ejercicio 2 Parte 2
// Función Que reciba como parámetro una cadena y la convierta a MINUSCULAS
void ej2_pt2(char cadena[])
{
    if (cadena[0] != '\0')
    {
        system ("CLS");
        // Titulo
        printf("CONVERTIR A MINUSCULAS\n");
        // Recorre todos los caracteres uno por uno
        for (int i = 0; cadena[i] != '\0'; i++)
        {
            // Comprobar si estan en mayusculas
            if (cadena[i] >= 'A') 
            {
                if (cadena[i] <= 'Z') 
                {
                    // Si las condiciones son verdaderas se hace la conversion a minusculas
                    cadena[i] = cadena[i] - ('A' - 'a'); 
                }
            }
        // Imprime la palabra en mayusculas o igual 
            printf("%c", cadena[i]);
        }
        printf("\n");
        system("PAUSE");
    }
}

// Ejercicio 3 Parte 2
// Función que reciba como parámetro una cadena y la convierta a CAPITAL
void ej3_pt2(char cadena[])
{
    if (cadena[0] != '\0')
    {
        system ("CLS");
        // Titulo
        printf("CONVERTIR A CAPITAL\n");
        // Bandera para indicar que estamos en la primera letra
        int primera_letra = 1;
        // Recorre todos los caracteres uno por uno
        for (int i = 0; cadena[i] != '\0'; i++)
        {
            // Comprobar si estan en minusculas
            if (cadena[i] >= 'a') 
            {
                if (cadena[i] <= 'z') 
                {
                    // Si es la primera letra
                    if (primera_letra)
                    {
                        // Convierte en mayUscula
                        cadena[i] = cadena[i] - ('a' - 'A');
                        // Ya no estamos en la primera letra
                        primera_letra = 0;
                    }
                }
            }
            // Imprime la palabra en mayusculas o igual 
            printf("%c", cadena[i]);
        }
        printf("\n");
        system("PAUSE");
    }
}


// Ejercicio 4 Parte 2
void ej4_pt2(char cadena[])
{
    system ("CLS");
    printf("hola");
    system("PAUSE");
}

// Ejercicio 5 Parte 2
void ej5_pt2(char cadena[])
{
    system ("CLS");
    printf("hola");
    system("PAUSE");
}

// Ejercicio 6 Parte 2
void ej6_pt2(char cadena[])
{
    system ("CLS");
    printf("hola");
    system("PAUSE");
}

// Ejercicio 7 Parte 2
void ej7_pt2(char cadena[])
{
    system ("CLS");
    printf("hola");
    system("PAUSE");
}

// Ejercicio 8 Parte 2
void ej8_pt2(char cadena[])
{
    system ("CLS");
    printf("hola");
    system("PAUSE");
}

// Ejercicio 9 Parte 2
void ej9_pt2(char cadena[])
{
    system ("CLS");
    printf("hola");
    system("PAUSE");
}

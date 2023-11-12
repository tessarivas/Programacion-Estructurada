// Teresa Rivas Gomez
// Sep - 19 - 2023 / Sep - 24 - 2023 / Sep - 25 - 2023
// RGT_Act07_Pt2_932

// Librerias
#include <stdio.h>
#include <stdlib.h>

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
// Validar la cadena
void validar(char cadena[]);

//Funcion para la pedir de datos
void datos(char cadena[]);

// Ejercicios de la Parte 2
void ej1_pt2(char cadena[]);
void ej2_pt2(char cadena[]);
void ej3_pt2(char cadena[]);
int ej4_pt2(char cadena[]);
int ej5_pt2(char cadena[]);
void ej6_pt2(char cadena[]);
int ej7_pt2(char cadena[]);
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
    printf("6.- Sin espacios \n");
    printf("7.- Alfabeto \n");
    printf("8.- Todo \n");
    printf("9.- Palindromo \n");
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
int validarCadena(const char cadena[]) 
{
    // Declarar variables e inicializarlas en 0
    int contieneNumero = 0;
    int contieneDobleEspacio = 0;
    int contieneMinuscula = 0;
    // Recorre cada caracter hasta encontrar el nulo
    for (int i = 0; cadena[i] != '\0'; i++) 
    {
        char caracter = cadena[i];
        // Si encuentra que tiene un numero se establece en 1 para indicarlo
        if (caracter >= '0') 
        {
            if(caracter <= '9')
            {
                contieneNumero = 1;
            }
        } 
        if (caracter == ' ') 
        {
            if (cadena[i + 1] == ' ') 
            {
                contieneDobleEspacio = 1;
            }
        }
        if (caracter >= 'a')
        {
            if(caracter <= 'z')
            {
                contieneMinuscula = 1;
            }
        }
    }
    // Verifica si alguna de las dos se establecio en 1
    if (contieneNumero || contieneDobleEspacio || contieneMinuscula) 
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
    if (caracter >= '0') 
    {
        if (caracter <= '9') 
        {
            return 1; // Es numero
        }
    }
    return 0; // No es numero
}

int es_espacio(char caracter) 
{
    return (caracter == ' ');
}

int es_minuscula(char caracter) 
{
    if (caracter >= 'a') 
    {
        if (caracter <= 'z') 
        {
            return 1; // Es minuscula
        }
    }
    return 0; // No es minuscula
}

//Pedir datos
void datos(char cadena[])
{
    system ("CLS");
    printf( "Introduzca una palabra: " );
    fflush(stdin);
    gets(cadena);
}

// Validar la cadena
void validar(char cadena[])
{
    // Validar la cadena después de que el usuario la ingrese
    if (!validarCadena(cadena)) 
    {
        printf("La cadena NO cumple con los requisitos.\n");
        printf("No uses dobles espacios, minusculas y no ingreses numeros.\n");
        // Borra la cadena si no es valida
        cadena[0] = '\0'; 
    }
    else
    {
        printf("La cadena SI cumple con los requisitos.\n");
    }
}

// PARTE 2
// Ejercicio 1 Parte 2
// Función que reciba como parámetro una cadena y la convierta a MAYUSCULAS
void ej1_pt2(char cadena[])
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
    getchar();
}

// Ejercicio 2 Parte 2
// Función Que reciba como parámetro una cadena y la convierta a MINUSCULAS
void ej2_pt2(char cadena[])
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
    getchar();
}

// Ejercicio 3 Parte 2
// Función que reciba como parámetro una cadena y la convierta a CAPITAL
void ej3_pt2(char cadena[])
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
        else
        {
            if(cadena[i] == ' ')
            {
                primera_letra = 1;
            }
        }
        // Imprime la palabra en mayusculas o igual 
        printf("%c", cadena[i]);
    }

    printf("\n");
    getchar();
}

// Ejercicio 4 Parte 2
// Función que reciba como parámetro una cadena y retorne la cantidad de 
// caracteres que tiene la cadena.
int ej4_pt2(char cadena[])
{
    system ("CLS");
    // Titulo
    printf("CANTIDAD DE CARACTERES\n");
    // Declarar variable para la longitud/largo
    int length = 0;
    // Calcular
    while (cadena[length] != '\0')
    {
        // Incremento
        length++;
    }
    // Imprimir tamaño de la cadena
    printf("Su tamaño es de: %d\n", length);
    getchar();
    return 0;
}

// Ejercicio 5 Parte 2
// Función que reciba como parámetro una cadena y retorne una cadena con sus 
// caracteres acomodados de forma inversa (al reves)
int ej5_pt2(char cadena[])
{
    system ("CLS");
    // Titulo
    printf("CADENA INVERSA\n");
    // Declarar variable para la longitud/largo
    int length = 0;
    // Calcular
    while (cadena[length] != '\0')
    {
        // Incrementa longitud
        length++;
    }
    // Recorre todos los caracteres uno por uno
    for (int i = length - 1; i >= 0; i--)
    {
        // Imprime la cadena al reves
        printf("%c", cadena[i]);
    }
    printf("\n");
    getchar();
    return 0;
}

// Ejercicio 6 Parte 2
// Función que reciba como parámetro una cadena y genere una nueva cadena 
// basada en la origina pero sin espacios.
void ej6_pt2(char cadena[])
{
    system ("CLS");
    // Titulo
    printf("SIN ESPACIOS\n");
    // Declarar una nueva cadena para almacenar el resultado sin espacios
    char nuevaCadena[50];
    // Inicializar la longitud de la nueva cadena
    int nuevaLongitud = 0;
    // Recorre la cadena original
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] != ' ')
        {
            // Copia los caracteres que no sean espacios a la nueva cadena
            nuevaCadena[nuevaLongitud] = cadena[i];
            nuevaLongitud++;
        }
    }
    // Agrega el caracter nulo al final de la nueva cadena para finalizarla
    nuevaCadena[nuevaLongitud] = '\0';
    // Imprime la nueva cadena sin espacios
    printf("%s\n", nuevaCadena);
    getchar();
}

// Ejercicio 7 Parte 2
// Función que sirva para leer una cadena y solo permita caracteres alfabéticos
// (A...Z) y el espacio, donde una cadena no puede comenzar o terminar con espacio, 
// no debe tener dos espacios seguidos. retornar la cadena ya sea como parámetro o variable.
int ej7_pt2(char cadena[])
{
    system("CLS");
    // Declarar variables booleanas para seguir el estado de la cadena
    bool tieneEspaciosAlPrincipio = false;
    bool terminaConEspacios = false;
    bool tieneNumeros = false;
    int i = 0;
    while (cadena[i] != '\0') 
    {
        // Para los espacios
        if (cadena[i] == ' ') 
        {
            if (i == 0) 
            {
                tieneEspaciosAlPrincipio = true; // Tiene espacios al principio
            }
            if (cadena[i + 1] == '\0') 
            {
                terminaConEspacios = true; // Termina con espacios
            }
        }
        // Para los numeros
        if (cadena[i] >= '0' && cadena[i] <= '9')
        {
            tieneNumeros = true; // Tiene numeros
        }
        i++;
    }
    // Comprobar los indicadores para determinar si la cadena es válida
    if (tieneEspaciosAlPrincipio) 
    {
        printf("No es valida (Tiene espacios al principio)\n");
    } 
    if (terminaConEspacios)
    {
        printf("No es valida (Termina con espacios)\n");
    }
    if (tieneNumeros)
    {
        printf("No es valida (Tiene numeros)\n");
    }
    if (!tieneEspaciosAlPrincipio && !terminaConEspacios && !tieneNumeros)
    {
        printf("Es valida\n");
    }
    else
    {
        printf("No es valida\n");
    }
    getchar();
    return 0;
}

// Ejercicio 8 Parte 2
// Función que reciba como parámetro una cadena, y utilizando las funciones anteriores, 
// imprima en MAYUSCULAS, MINUSCULAS , CAPITAL, SIN ESPACIOS, ALREVES la cadena original.
void ej8_pt2(char cadena[])
{
    system ("CLS");
    // Titulo
    printf("TODO EN 1\n");
    // Mandar a llamar a las funciones
    ej1_pt2(cadena); // Convertir a MAYUSCULAS
    ej2_pt2(cadena); // Convertir a MINUSCULAS
    ej3_pt2(cadena); // Convertir a CAPITAL
    ej5_pt2(cadena); // Imprimir AL REVES
    ej6_pt2(cadena); // Imprimir SIN ESPACIOS
    getchar();
}

// Ejercicio 9 Parte 2
// Función que reciba como parámetro una cadena, y desplegar la leyenda si la cadena es
// un palíndromo SI o NO
void ej9_pt2(char cadena[])
{
    system ("CLS");
    // Titulo
    printf("PALINDROMO\n");
    // Llamar a mi funcion de validacon
    validarCadena(cadena);
    validar(cadena);
    getchar();
}

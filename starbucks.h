/*
NOMBRE: Teresa Rivas Gómez
MATRICULA: 372565
FECHA: Oct - 10 - 2023
NOMBRE DEL ARCHIVO: starbucks.h
¿QUE HACE?: Libreria personalizada
*/

// - LIBRERIAS - //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*-------------------------------------------------------*/

// - FUNCIONES - //

// PARA VALIDAR:
int ValidarCadena(char mensj[], int ri, int rf);
int ValidarCadenaTexto(const char cadena[]);

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

// CADENA DE TEXTO
int ValidarCadenaTexto(const char cadena[]) 
{
    int longitud = strlen(cadena);
    // CADENA VACIA
    if (longitud == 0) 
    {
        return 0;
    }
    // ESPACIO AL INICIO O FIN
    if (cadena[0] == ' ' || cadena[longitud - 1] == ' ') 
    {
        return 0; 
    }
    // SOLO MAYUSCULAS Y ESPACIOS
    for (int i = 0; cadena[i] != '\0'; i++) 
    {
        if (cadena[i] == ' ') 
        {
            // DOBLES ESPACIOS
            if(cadena[i + 1] == ' ')
            {
                return 0;
            }
        }
        else
        {
            // CARACTERES NO VALIDOS
            if(cadena[i] < 'A' || cadena[i] > 'Z')
            {
                return 0;
            }
        }
    }
    // TODO AL 100
    return 1;
}

int Mayusculas(char cadena[]) 
{
    int i = 0;
    while ( cadena[i] != '\0' ) 
    {
        if ( cadena[i] >= 'a' )
        {
            if ( cadena [i] <= 'z' )
            {
                cadena[i] = cadena[i] - ( 'a' - 'A');
            }
        }
        i++;
    }
    return 0;
}
/*
NOMBRE: Teresa Rivas Gomez
MATRICULA: 372565
FECHA: Oct - 19 - 2023
DESCRIPCION: Libreria para la CURP
NOMBRE DEL ARCHIVO: harry_potter.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int ValidarCadena(char mensj[], int ri, int rf);
int ValidarGenero(const char genero[2]);
int ValidarRango(int num, int ri, int rf);
int ValidarNombre(char cadena[]);
int Mayusculas(char cadena[]);
int validar_fecha(int anio, int mes, int dia);
int counter(char array[]);

int ValidarCadena(char mensj[], int ri, int rf) 
{
    int num;
    char cadena[200]; 
    do
    {
        printf("%s", mensj);
        fflush(stdin); 
        gets(cadena);
        num = atoi(cadena);
    } while (num < ri || num > rf);
    return num;
}

int ValidarGenero(const char genero[2])
{
    return (strcmp(genero, "H") == 0 || strcmp(genero, "M") == 0);
}

int ValidarRango(int num, int ri, int rf) 
{
    return (num >= ri && num <= rf);
}

int ValidarNombre(char cadena[])
{
    int i = 0;
    // ESPACIO AL INICIO
    if (cadena[0] == ' ')
    {
        return -1;
    }
    // CARACTERES
    if (cadena[0] == '\0')
    {
        return -1;
    }
    // ACENTOS Y Ñ
    for (i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] == -92 || cadena[i] == -91 || cadena[i] == '/' || cadena[i] == '-')
        {
            cadena[i] = 'X';
        }
        if (cadena[i] == -102 || cadena[i] == -127)
        {
            cadena[i] = 'U';
        }
        if (cadena[i] == -75 || cadena[i] == -96)
        {
            cadena[i] = 'A';
        }
        if (cadena[i] == -126 || cadena[i] == -112)
        {
            cadena[i] = 'E';
        }
        if (cadena[i] == -42 || cadena[i] == -95)
        {
            cadena[i] = 'i';
        }
        if (cadena[i] == -32 || cadena[i] == -94)
        {
            cadena[i] = 'O';
        }
    }
    Mayusculas(cadena);

    i = 0;
    while (cadena[i] != '\0')
    {
        if ((cadena[i] >= 'A' && cadena[i] <= 'Z'))
        {
            // MAYUSCULAS
        }
        else
        {
            // MINUSCULAS
            if ((cadena[i] >= 'a' && cadena[i] <= 'z'))
            {
                return -1;
            }
            else
            {
                // DOBLE ESPACIO
                if (cadena[i] == ' ')
                {
                    if (cadena[i + 1] == ' ')
                    {
                        return -1; 
                    }
                }
                else
                {
                    cadena[i] = 'X';
                }
            }
        }
        i++;
    }
    // TERMINA CON ESPACIO
    if (cadena[i - 1] == ' ')
    {
        return -1; 
    }
    // SI SE CUMPLE, RETORNO A 1
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

int validar_fecha(int anio, int mes, int dia) 
{
    if (mes == 2 && dia == 29) 
    {
        if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) 
        {
            return 1;
        } 
        else 
        {
            return 0;
        }
    }

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) 
    {
        return 0;
    }

    if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia > 31) 
    {
        return 0;
    }

    return 1;
}

int counter(char cadena[])
{
    int largo;
    largo = 0;
    while (cadena[largo] != '\0')
    {
        largo++;
    }
    return largo;
}
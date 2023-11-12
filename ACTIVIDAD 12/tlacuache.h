/*
NOMBRE: Teresa Rivas Gomez
MATRICULA: 372565
FECHA: Nov - 07 - 2023
DESCRIPCION: LIBRERIA CON FUNCIONES Y VALIDACIONES
NOMBRE DEL ARCHIVO: tlacuache.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MESES 12

/* DEFINIR FUNCIONES PARA ESTRUCTURAS */

int rango(int ri, int rf);
int matricula_random();
int bisiesto_random(int anio);
int es_bisiesto(int anio);
void ciclo(char cadena[]);

/* DEFINIR FUNCIONES PARA VALIDACION */

int ValidarCadena(char mensj[], int ri, int rf);
int ValidarCadenaTexto(const char cadena[]);
int ValidarGenero(const char genero[2]);
int ValidarRango(int num, int ri, int rf);
int ValidarNombre(char cadena[]);
int Mayusculas(char cadena[]);
int ValidarFecha(int anio, int mes, int dia);
int contador(char array[]);

/* DEFINIR FUNCIONES PARA CADENAS */

void meses_delanio(char meses[][30]);
void nombre_femenino1(char cadena[]);
void nombre_femenino2(char cadena[]);
void nombre_masculino1(char cadena[]);
void nombre_masculino2(char cadena[]);
void apellidos(char cadena[]);
void segundo_nombre_masculino(char cadena[]);
void segundo_nombre_femenino(char cadena[]);

/* DEFINIR FUNCIONES PARA CURP*/

char consonante_apellido(char cadena[]);
char consonante_nombre(char cadena[]);
char vocal(char cadena[]);
void saltar_nombre(char cadena[]);
void saltar_mini_nombre(char cadena[]);
int ValidarTabu(char cadena[], char tabu[][5], int numero_tabu);

/* PARA FUNCIONES */

int rango(int ri, int rf) 
{
    return ri + rand() % (rf - ri + 1);
}

int matricula_random() 
{
    int ri = 300000;
    int rf = 399999;
    return ri + rand() % (rf - ri + 1);
}

int bisiesto_random(int anio)
{
    return((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0));
}

int es_bisiesto(int anio)
{
    if (anio % 4 == 0)
    {
        if (anio % 100 == 0)
        {
            if (anio % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

void ciclo(char cadena[])
{
    do
    {
        fflush(stdin);
        gets(cadena);
        Mayusculas(cadena);
        printf("%s", cadena);
        printf("\n");
    } while (ValidarNombre(cadena) != 1);
}

/* VALIDACIONES */

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

int ValidarFecha(int anio, int mes, int dia) 
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

int contador(char cadena[])
{
    int largo;
    largo = 0;
    while (cadena[largo] != '\0')
    {
        largo++;
    }
    return largo;
}

/* FUNCIONES PARA ESTRUCTURAS */

void meses_delanio(char meses[][30])
{
    strcpy(meses[0], "Enero");
    strcpy(meses[1], "Febrero");
    strcpy(meses[2], "Marzo");
    strcpy(meses[3], "Abril");
    strcpy(meses[4], "Mayo");
    strcpy(meses[5], "Junio");
    strcpy(meses[6], "Julio");
    strcpy(meses[7], "Agosto");
    strcpy(meses[8], "Septiembre");
    strcpy(meses[9], "Octubre");
    strcpy(meses[10], "Noviembre");
    strcpy(meses[11], "Diciembre");
}

void nombre_femenino1(char cadena[])
{
    char PriNomFem[10][10] = {"ANA", "MARIA", "DANNA", "ELBA", "IRMA", "SONIA", "LUZ", "DULCE", "EVA", "CARMEN"};
    strcpy(cadena, PriNomFem[rand()%10]);
}

void nombre_femenino2(char cadena[])
{
    char SegNomFem[10][15] = {"VICTORIA", "FERNANDA", "CRISTINA", "CAROLINA", "ALEJANDRA", "ISABELA", "DANIELA", "MARTINA", "SOFIA", "MARIANA"};
    strcpy(cadena, SegNomFem[rand()%10]);
}

void nombre_masculino1(char cadena[])
{
    char PriNomMas[10][10] = {"LUIS", "HECTOR", "SAUL", "SAID", "IVAN", "JESUS", "ALDO", "PABLO", "KEVIN", "OMAR"};
    strcpy(cadena, PriNomMas[rand()%10]);
}

void nombre_masculino2(char cadena[])
{
    char SegNomMas[10][10] = {"FERNANDO", "ALEJANDRO", "RAFAEL", "ANTONIO", "FRANCISCO", "ALFREDO", "JAZIEL", "MANUEL", "MIGUEL", "JAVIER"};
    strcpy(cadena, SegNomMas[rand()%10]);
}

void apellidos(char cadena[])
{
    char Apellido1[20][10] = {"LOPEZ", "GOMEZ", "DIAZ", "OROZCO", "AGUILAR", "CAMPOS", "JIMENEZ", "VAZQUEZ", "LOMA", "PEREZ", "ANDRADE", "PALACIOS", "GONZALEZ", "HERNANDEZ", "RODRIGUEZ", "MARTINEZ", "CHAVEZ", "CRUZ", "SANCHEZ", "QUIJADA"};
    strcpy(cadena, Apellido1[rand()%20]);
}

void segundo_nombre_masculino(char cadena[])
{
    char cadena2[20];
    int i;
    int j = 0;
    int cuenta;

    cuenta = contador(cadena);
    nombre_masculino2(cadena2);
    cadena[cuenta] = ' ';

    for (i = 0; cadena2[j] != '\0'; i++)
    {
        if (i != 0)
        {
            cadena[i + cuenta] = cadena2[j];
            j++;
        }
    }

    cadena[cuenta + i] = '\0';
}

void segundo_nombre_femenino(char cadena[])
{
    char cadena2[20];
    int i;
    int j = 0;
    int cuenta;

    cuenta = contador(cadena);
    nombre_femenino2(cadena2);
    cadena[cuenta] = ' ';

    for (i = 0; cadena2[j] != '\0'; i++)
    {
        if (i != 0)
        {
            cadena[i + cuenta] = cadena2[j];
            j++;
        }
    }
    
    cadena[cuenta + i] = '\0';
}

/* PARA GENERAR LA CURP */

char consonante_apellido(char cadena[])
{
    int i;
    char primera_consonante = 'X'; 
    int letra_ignorada = 0;

    for (i = 1; cadena[i] != '\0'; i++)
    {
        char palabra_temporal = cadena[i];

        if (!letra_ignorada)
        {
            if(palabra_temporal != 'A')
            {
                if(palabra_temporal != 'E')
                {
                    if(palabra_temporal != 'I')
                    {
                        if(palabra_temporal != 'O')
                        {
                            if(palabra_temporal != 'U')
                            {
                                letra_ignorada = 1;
                            }
                        }
                    }
                }
            } 
        }
        if (letra_ignorada)
        {
            return palabra_temporal;
        }
    }

    return primera_consonante;
}

char consonante_nombre(char cadena[])
{
    int i = 1;
    char primera_consonante = 'X'; 

    while (cadena[i] != '\0')
    {
        char palabra_temporal = cadena[i];

        if(palabra_temporal != 'A')
        {
            if(palabra_temporal != 'E')
            {
                if(palabra_temporal != 'I')
                {
                    if(palabra_temporal != 'O')
                    {
                        if(palabra_temporal != 'U')
                        {
                            if (primera_consonante == 'X')
                            {
                                primera_consonante = palabra_temporal;
                            }
                        }
                    }
                }
            }
        } 
        i++;
    }

    return primera_consonante;
}

char vocal(char cadena[])
{
    int i = 1; 

    while (cadena[i] != '\0')
    {
        char caracter = cadena[i];

        if (strchr("X", caracter))
        {
            return caracter;
        }
        if (strchr("AEIOUaeiou", caracter))
        {
            return caracter;
        }
        i++;
    }

    return '\0';
}

void saltar_nombre(char cadena[])
{
    int i;
    char nombres_a_omitir[][7] = {"MARIA ", "MAX ", "MA ", "MX ", "M ", "JOSE ", "JX ", "J "};

    for (i = 0; nombres_a_omitir[i][0] != '\0'; i++)
    {
        int encontrado = 0;

        while (cadena[encontrado] != '\0')
        {
            int j;
            int coincidencia = 1;
            int longitud = strlen(nombres_a_omitir[i]);

            for (j = 0; nombres_a_omitir[i][j] != '\0' && coincidencia; j++)
            {
                if (cadena[encontrado + j] != nombres_a_omitir[i][j])
                {
                    coincidencia = 0;
                }
            }
            if (coincidencia)
            {
                for (j = encontrado; cadena[j] != '\0'; j++)
                {
                    cadena[j] = cadena[j + longitud];
                }
            }
            else
            {
                encontrado++;
            }
        }
    }
}

void saltar_mini_nombre(char cadena[])
{
    int i;
    char nombres_mini[][5] = {"DAS ", "DEL ", "DE ", "DER ", "DIE ", "LOS ", "LAS ", "LES ", "MAC ",
    "VAN ", "VON ", "DA ", "DI ", "DD ", "EL ", "LA ", "LE ", "MC ", "Y "};

    for (i = 0; nombres_mini[i][0] != '\0'; i++)
    {
        int encontrado = 0;

        while (cadena[encontrado] != '\0')
        {
            int j;
            int coincidencia = 1;
            int longitud = strlen(nombres_mini[i]);

            for (j = 0; nombres_mini[i][j] != '\0' && coincidencia; j++)
            {
                if (cadena[encontrado + j] != nombres_mini[i][j])
                {
                    coincidencia = 0;
                }
            }
            if (coincidencia)
            {
                for (j = encontrado; cadena[j] != '\0'; j++)
                {
                    cadena[j] = cadena[j + longitud];
                }
            }
            else
            {
                encontrado++;
            }
        }
    }
}

int ValidarTabu(char cadena[], int numero_tabu)
{
    char tabu[81][5] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO",
                        "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO",
                        "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA",
                        "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO",
                        "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR",
                        "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE",
                        "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO",
                        "RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI",
                        "WUEY"};
    char subcadena[5];

    strncpy(subcadena, cadena, 4);
    subcadena[4] = '\0';

    for (int i = 0; i < numero_tabu; i++)
    {
        if (strcmp(subcadena, tabu[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

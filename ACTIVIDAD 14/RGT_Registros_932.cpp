#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* DECLARAR LLAVE */
typedef int Tllave;

/* ESTRUCTURAS */
typedef struct _datos {
    int status;
    Tllave matricula;
    char nombre[30];
    char apellido1[50];
    char apellido2[50];
    char sexo[15];
    char puesto[30];
    char estado[30];
    int edad;
    Tllave telefono;
} Tdatos;

int main(int args, char *arg[])
{
    FILE *archivo;

    int posicion = 0;
    Tdatos registro;
    char nombre_archivo[30];

    strcpy(nombre_archivo, arg[1]);
    archivo = fopen(nombre_archivo, "rb");

    if(archivo)
    {
        while (fread(&registro, sizeof(Tdatos), 1, archivo))
        {
            posicion++;
        }
        fclose(archivo);
        return posicion;
    }
    else
    {
        return -1;
    }

    return 0;
}

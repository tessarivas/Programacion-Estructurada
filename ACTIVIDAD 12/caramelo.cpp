/* Este programa cuenta el numero de registros en un archivo de texto con un formato especifico. 
Toma el nombre del archivo como argumento de linea de comandos, construye el nombre completo agregando 
".txt", abre el archivo y cuenta los registros siguiendo un formato especifico. Retorna el numero de 
registros leidos o -1 en caso de error.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

int main(int args, char *arg[]) 
{
    FILE *archivo;
    int posicion = 0;
    char nombre_archivo[MAX];
    int numero;
    int matricula;
    char nombre[20], apellido1[20], apellido2[20];
    int edad;
    char genero[10];

    strcpy(nombre_archivo, arg[1]);
    strcat(nombre_archivo, ".txt");

    archivo = fopen(nombre_archivo, "r");

    if (archivo) 
    {
        char linea[1000];

        while (fgets(linea, sizeof(linea), archivo) != NULL) 
        {
            if (sscanf(linea, "%d.- %d %s %s %s %d %s", &numero, &matricula, nombre, apellido1, apellido2, &edad, genero) == 7) 
            {
                posicion++;
            }
        }

        fclose(archivo);
        return posicion;
    } 
    else 
    {
        printf("Error: No se pudo abrir el archivo %s\n", nombre_archivo);
        return -1;
    }

    return 0;
}

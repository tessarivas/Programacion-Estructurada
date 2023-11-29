/*
NOMBRE: Teresa Rivas Gomez
MATRICULA: 372565
FECHA: Nov - 21 - 2023
DESCRIPCION: LIBRERIA PARA ACTIVIDAD 14
NOMBRE DEL ARCHIVO: tulipan.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lavanda.h"

/*  DECLARAR LLAVE */
typedef int Tllave;

/* ESTRUCTURAS */
typedef struct _indice {
    Tllave matricula;
    int indice;
} Tindice;

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

/* FUNCIONES UTILIZADAS EN ESTA LIBRERIA */

int binaria(Tindice indice[], int izq, int der, Tllave matricula);
int fusion(Tindice indice[], int l, int m, int r);
int particion(Tindice indice[], int ri, int rf);
void intercambio(Tindice indice[], int i, int j);

/* GENERAR EMPLEADO RANDOM */
Tdatos generar_datos_random(Tdatos _datos)
{
    // STATUS
    _datos.status = 1;
    // MATRICULA
    _datos.matricula = rango(300000, 399999);
    // PUESTO
    puesto_empleado(_datos.puesto);
    // SEXO
    int sex = rango(1,2);
    // NOMBRE
    if(sex == 1)
    {
        // NOMBRE DE HOMBRE
        strcpy(_datos.sexo, "HOMBRE");
        nombre_masculino1(_datos.nombre);
    }
    else
    {
        // NOMBRE DE MUJER
        strcpy(_datos.sexo, "MUJER");
        nombre_femenino1(_datos.nombre);
    }
    // APELLIDOS
    apellidos(_datos.apellido1);
    apellidos(_datos.apellido2);
    // ESTADO
    estados(_datos.estado);
    // TELEFONO CELULAR
    char telefono[15];
    telefono_random(telefono);
    _datos.telefono = strtol(telefono, NULL, 10);
    // EDAD
    _datos.edad = rango(18, 65);
    // IMPRIMIR
    printf("MATRICULA: %d\n", _datos.matricula);
    printf("NOMBRE: %s\n", _datos.nombre);
    printf("PRIMER APELLIDO: %s\n", _datos.apellido1);
    printf("SEGUNDO APELLIDO: %s\n", _datos.apellido2);
    printf("SEXO: %s\n", _datos.sexo);
    printf("PUESTO: %s\n", _datos.puesto);
    printf("ESTADO: %s\n", _datos.estado);
    printf("EDAD: %d\n", _datos.edad);
    printf("TELEFONO: %d\n", _datos.telefono);
    printf("\n");
    // RETORNO
    return _datos;
}

void imprimir(Tdatos _datos)
{
    printf("MATRICULA: %d\n", _datos.matricula);
    printf("NOMBRE: %s\n", _datos.nombre);
    printf("PRIMER APELLIDO: %s\n", _datos.apellido1);
    printf("SEGUNDO APELLIDO: %s\n", _datos.apellido2);
    printf("SEXO: %s\n", _datos.sexo);
    printf("PUESTO: %s\n", _datos.puesto);
    printf("ESTADO: %s\n", _datos.estado);
    printf("EDAD: %d\n", _datos.edad);
    printf("TELEFONO: %d\n", _datos.telefono);
    printf("\n");
}

/* RELACIONADAS A LA ESTRUCTURA */
int secuencial(Tindice indice[], int v, int key) 
{
    int i;

    for (i = 0; i < v; i++)
    {
        if (indice[i].matricula == key)
        {
            return i;
        }
    }

    return -1; 
}


int binaria(Tindice indice[], int izq, int der, Tllave matricula)
{
    while (izq <= der)
    {
        int medio = izq + (der - izq) / 2;

        if (indice[medio].matricula == matricula)
        {
            return medio;
        }

        if (indice[medio].matricula < matricula)
        {
            izq = medio + 1;
        }

        if (indice[medio].matricula > matricula)
        {
            der = medio - 1;
        }
    }

    return -1;
}

int fusion(Tindice indice[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Tindice *L = (Tindice *)malloc(n1 * sizeof(Tindice));
    Tindice *R = (Tindice *)malloc(n2 * sizeof(Tindice));

    if (L == NULL || R == NULL)
    {
        fprintf(stderr, "NO SE PUDO ASIGNAR MEMORIA.\n");

        free(L);
        free(R);

        return 0;
    }

    for (i = 0; i < n1; i++)
        L[i] = indice[l + i];
    for (j = 0; j < n2; j++)
        R[j] = indice[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].matricula <= R[j].matricula)
        {
            indice[k] = L[i];
            i++;
        }
        else
        {
            indice[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        indice[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        indice[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);

    return 1;
}

int particion(Tindice indice[], int ri, int rf)
{
    Tindice para;

    para.matricula = indice[rf].matricula;

    int i, j;
    i = ri - 1;

    for (j = ri; j <= rf - 1; j++)
    {
        if (indice[j].matricula <= para.matricula)
        {
            i++;
            intercambio(indice, i, j);
        }
    }

    intercambio(indice, i + 1, rf);

    return i + 1;
}

void intercambio(Tindice indice[], int i, int j)
{
    Tindice temporal = indice[i];
    indice[i] = indice[j];
    indice[j] = temporal;
}

/* RELACIONADO A ARCHIVOS */
void crear_archivo(char nombre_archivo_texto[], char nombre_archivo_binario[])
{
    Tdatos registro;
    Tindice indice;
    int contador = 0;

    FILE *texto = fopen(nombre_archivo_texto, "rb");

    if (texto == NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO DE TEXTO.\n");
        return;
    }

    FILE *binario = fopen(nombre_archivo_binario, "wb");
    if (binario == NULL)
    {
        fclose(texto);
        printf("NO SE PUDO CREAR EL ARCHIVO BINARIO.\n");
        return;
    }

    while (fread(&registro, sizeof(Tdatos), 1, texto))
    {
        indice.matricula = registro.matricula;
        indice.indice = contador;
        fwrite(&indice, sizeof(Tindice), 1, binario);
        contador++;
    }

    fclose(binario);
    fclose(texto);
}

int indice_registro(Tindice indice[], int i)
{
    FILE *binario;
    Tdatos datos;

    binario = fopen("registro.dat", "rb");

    if (binario)
    {
        while (fread(&datos, sizeof(Tdatos), 1, binario) == 1)
        {
            indice[i].matricula = datos.matricula;
            indice[i].indice = i;
            (i)++;
        }
        fclose(binario);
    }
    return i;
}

/*
NOMBRE: Teresa Rivas Gomez
MATRICULA: 372565
FECHA: Nov - 14 - 2023
DESCRIPCION: LIBRERIA PARA ACTIVIDAD 13
NOMBRE DEL ARCHIVO: birote.h
*/

#define MAX_TELEFONO 12
#define TAM_BLOQUE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bolillo.h"

/*  DECLARAR LLAVE */
typedef int Tllave;

/* ESTRUCTURA PRINCIPAL*/
typedef struct _datos{
    int status;
    Tllave matricula;
    char puesto[20];
    char apellido1[20];
    char apellido2[20];
    char nombre[20];
    char telefono[MAX_TELEFONO + 1];
    int edad;
    int sex;
    char sexo[10];
} Tdatos;

/* DEFINIR FUNCIONES PARA ESTRUCTURAS */
int busqueda_secuencial(Tdatos almacen[], int j, int matricula);
int busqueda_binaria(Tdatos almacen[], int izquierda, int derecha, int matricula);
int particion(Tdatos almacen[], int ri, int rf);
void intercambio(Tdatos almacen[], int i, int j);

/* DEFINIR FUNCION PARA EMPLEADO RANDOM */
Tdatos generar_datos_random(void);

/* DEFINIR FUNCIONES PARA ARCHIVOS BINARIOS */
int respaldo_binario( char cadena[]);

/* FUNCIONES CON Y PARA ESTRUCTURAS*/
int busqueda_secuencial(Tdatos almacen[], int j, int matricula)
{
    int i;

    for (i = 0; i < j; i++)
    {
        if (almacen[i].matricula == matricula)
        {
            return i; 
        }
    }

    return -1; 
}

int busqueda_binaria(Tdatos almacen[], int izquierda, int derecha, int matricula)
{
    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (almacen[medio].matricula == matricula)
        {
            return medio;
        }

        if (almacen[medio].matricula < matricula)
        {
            izquierda = medio + 1;
        }

        if (almacen[medio].matricula > matricula)
        {
            derecha = medio - 1;
        }
    }

    return -1;
}

int particion(Tdatos almacen[], int ri, int rf)
{
    Tdatos para;

    para.matricula = almacen[rf].matricula;

    int i, j;
    i = ri - 1;

    for (j = ri; j <= rf - 1; j++)
    {
        if (almacen[j].matricula <= para.matricula)
        {
            i++;
            intercambio(almacen, i, j);
        }
    }

    intercambio(almacen, i + 1, rf);

    return i + 1;
}

void intercambio(Tdatos almacen[], int i, int j)
{
    Tdatos temp = almacen[i];
    almacen[i] = almacen[j];
    almacen[j] = temp;
}

/* EMPLEADO RANDOM */
Tdatos generar_datos_random(Tdatos _datos)
{
    // STATUS
    _datos.status = 1;
    // MATRICULA
    _datos.matricula = rango(2000, 7000);
    // PUESTO
    puesto_empleado(_datos.puesto);
    // SEXO
    _datos.sex = rango(1,2);
    // NOMBRE
    if(_datos.sex == 1)
    {
        // NOMBRE DE HOMBRE
        strcpy(_datos.sexo, "H");
        nombre_masculino1(_datos.nombre);
    }
    else
    {
        // NOMBRE DE MUJER
        strcpy(_datos.sexo, "M");
        nombre_femenino1(_datos.nombre);
    }
    // APELLIDOS
    apellidos(_datos.apellido1);
    apellidos(_datos.apellido2);
    // TELEFONO CELULAR
    char* telefono = telefono_random();
    strcpy(_datos.telefono, telefono);
    // EDAD
    _datos.edad = rango(18, 65);
    // IMPRIMIR
    printf("MATRICULA: %d\n", _datos.matricula);
    printf("PUESTO: %s\n", _datos.puesto);
    printf("NOMBRE: %s\n", _datos.nombre);
    printf("PRIMER APELLIDO: %s\n", _datos.apellido1);
    printf("SEGUNDO APELLIDO: %s\n", _datos.apellido2);
    printf("TELEFONO: %s\n", _datos.telefono);
    printf("EDAD: %d\n", _datos.edad);
    printf("SEXO: %s\n", _datos.sexo);
    printf("\n");
    // RETORNO
    return _datos;
}

/* RESPALDO BINARIO */
/* Crea un respaldo de un archivo binario. Abre el archivo original y de respaldo, utiliza un buffer para copiar datos en bloques. */
int respaldo_binario( char cadena[])
{
    char direccion_original[1000];
    strcpy(direccion_original, "C:\\Users\\52616\\OneDrive\\Documentos\\U A B C\\3er Semestre\\Programacion Estructurada\\Actividad 13\\output\\");
    strcat(direccion_original, cadena);
    strcat(direccion_original, ".dll");

    char direccion_respaldo[1000];
    strcpy(direccion_respaldo, "C:\\Users\\52616\\OneDrive\\Documentos\\U A B C\\3er Semestre\\Programacion Estructurada\\Actividad 13\\output\\");
    strcat(direccion_respaldo, cadena);
    strcat(direccion_respaldo, ".tmp");

    FILE *origen = fopen(direccion_original, "rb");
    if (origen == NULL)
    {
        printf("ERROR AL ABRIR EL ARCHIVO ORIGINAL");
        fclose(origen);
        return -1;
    }

    FILE *respaldo = fopen(direccion_respaldo, "wb");
    if (respaldo == NULL)
    {
        printf("ERROR AL ABRIR EL ARCHIVO DE RESPALDO");
        fclose(origen); 
        return -1;
    }

    char buffer[TAM_BLOQUE];
    size_t bytes_leidos;

    while ((bytes_leidos = fread(buffer, 1, TAM_BLOQUE, origen)) > 0) 
    {
        fwrite(buffer, 1, bytes_leidos, respaldo);
    }

    printf("ARCHIVO DE RESPALDO CREADO CORRECTAMENTE\n");

    fclose(origen);
    fclose(respaldo);

    return 0;
}

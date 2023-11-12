/*
NOMBRE: Teresa Rivas Gomez
MATRICULA: 372565
FECHA: Nov - 01 - 2023
DESCRIPCION: LIBRERIA PARA ACTIVIDAD 12
NOMBRE DEL ARCHIVO: tamales.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tlacuache.h"

/* NOMBRE COMPLETO */
typedef struct _nombre{
    char nombres[50];
    char nombre1[20];
    char nombre2[20];
    char apellido1[20];
    char apellido2[20];
} Tnombre;

/* ESTRUCTURA PRINCIPAL*/
typedef struct _datos{
    int status;
    int matricula;
    Tnombre _nombre;
    int edad;
    int sex;
    char sexo[2];
} Tdatos;

/* DEFINIR FUNCIONES PARA ESTRUCTURAS */
int busqueda_secuencial(Tdatos almacen[], int j, int matricula);
int busqueda_binaria(Tdatos almacen[], int izquierda, int derecha, int matricula);
int particion(Tdatos almacen[], int ri, int rf);
void intercambio(Tdatos almacen[], int i, int j);

Tdatos generar_datos_random(void);
Tdatos generar_datos_manual(Tdatos _datos);

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

/* ESTRUCTURAS */
Tdatos generar_datos_random(Tdatos _datos)
{
    int segundo_nombre = rango(1,2);
    // STATUS
    _datos.status = 1;
    // MATRICULA
    _datos.matricula = matricula_random();
    // SEXO
    _datos.sex = rango(1,2);
    // NOMBRE
    if(_datos.sex == 1)
    {
        strcpy(_datos.sexo, "H");
        nombre_masculino1(_datos._nombre.nombres);
        if(segundo_nombre == 1)
        {
            segundo_nombre_masculino(_datos._nombre.nombres);
        }
    }
    else
    {
        strcpy(_datos.sexo, "M");
        nombre_femenino1(_datos._nombre.nombres);
        if(segundo_nombre == 1)
        {
            segundo_nombre_femenino(_datos._nombre.nombres);
        }
    }
    apellidos(_datos._nombre.apellido1);
    apellidos(_datos._nombre.apellido2);
    // EDAD
    _datos.edad = rango(17, 99);

    printf("MATRICULA: %d\n", _datos.matricula);
    printf("NOMBRES: %s\n", _datos._nombre.nombres);
    printf("PRIMER APELLIDO: %s\n", _datos._nombre.apellido1);
    printf("SEGUNDO APELLIDO: %s\n", _datos._nombre.apellido2);
    printf("EDAD: %d\n", _datos.edad);
    printf("SEXO: %s\n", _datos.sexo);
    printf("\n");

    return _datos;
}

Tdatos generar_datos_manual(Tdatos _datos)
{
    //STATUS
    _datos.status = 1;

    // MATRICULA
    _datos.matricula = ValidarCadena("Ingresa la matricula (entre 300000 y 399999): ", 300000, 399999);

    // NOMBRES
    int nombre_completo;

    char nombre_uno[20];
    char nombre_dos[20];

    _datos._nombre.nombre1[0] = '\0';
    _datos._nombre.nombre2[0] = '\0';

    nombre_completo = ValidarCadena("INGRESA EL NUMERO DE NOMBRES QUE TIENES (1|2):", 1, 2);
    printf("INGRESA TU PRIMER NOMBRE: \n");

    ciclo(nombre_uno);
    strcpy(_datos._nombre.nombre1, nombre_uno);
    saltar_nombre(_datos._nombre.nombre1);
    strcpy(_datos._nombre.nombres, nombre_uno);

    if (nombre_completo == 2)
    {
        printf("INGRESA TU SEGUNDO NOMBRE: \n");
        ciclo(nombre_dos);
        strcat(_datos._nombre.nombres, " ");
        strcat(_datos._nombre.nombres, nombre_dos);
        saltar_nombre(_datos._nombre.nombres);
        saltar_mini_nombre(_datos._nombre.nombres);

        strcpy(_datos._nombre.nombre2, nombre_dos);
    }

    //APELLIDOS
    int apellido_completo;

    char apellido_uno[20];
    char apellido_dos[20];

    apellido_completo = ValidarCadena("INGRESA EL NUMERO DE APELLIDOS QUE TIENES (1|2|0): ", 0, 2);

    if (apellido_completo == 1)
    {
        printf("INGRESA TU PRIMER APELLIDO: \n");
        ciclo(apellido_uno);
        saltar_mini_nombre(apellido_uno);
        saltar_mini_nombre(apellido_uno);
        strcpy(_datos._nombre.apellido1, apellido_uno);

        _datos._nombre.apellido2[0] = '\0';
    }
    else
    {
        if (apellido_completo == 2)
        {
            printf("INGRESA TU PRIMER APELLIDO: \n");
            ciclo(apellido_uno);
            saltar_mini_nombre(apellido_uno);
            printf("INGRESA TU SEGUNDO APELLIDO: \n");
            ciclo(apellido_dos);
            saltar_mini_nombre(apellido_dos);
            strcpy(_datos._nombre.apellido1, apellido_uno);
            strcpy(_datos._nombre.apellido2, apellido_dos);

            saltar_mini_nombre(_datos._nombre.apellido1);
            saltar_mini_nombre(_datos._nombre.apellido2);
        }
        else
        {
            if (apellido_completo == 3)
            {
                _datos._nombre.apellido1[0] = '\0';
                _datos._nombre.apellido2[0] = '\0';
            }
        }
    }
    // EDAD
    int edad;
    edad = ValidarCadena("INGRESA TU EDAD: ", 17, 99);

    _datos.edad = edad;

    // GENERO
    int genero;
    genero = ValidarCadena("INGRESA TU SEXO:\n[1]HOMBRE\n[2]MUJER\n", 1, 2);

    _datos.sex = genero;

    if (genero == 1)
    {
        strcpy(_datos.sexo, "H");
    }
    else
    {
        strcpy(_datos.sexo, "M");
    }

    // IMPRIMIR
    printf("STATUS: %d\n", _datos.status);
    printf("MATRICULA: %d\n", _datos.matricula);
    printf("NOMBRE 1: %s\n", _datos._nombre.nombre1);
    printf("NOMBRE 2: %s\n", _datos._nombre.nombre2);
    printf("APELLIDO PATERNO: %s\n", _datos._nombre.apellido1);
    printf("APELLIDO MATERNO: %s\n", _datos._nombre.apellido2);
    printf("EDAD: %d\n", _datos.edad);
    printf("SEXO: %s\n", _datos.sexo);
    printf("\n");

    return _datos;
}
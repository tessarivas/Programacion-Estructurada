/*
NOMBRE: Teresa Rivas Gomez
MATRICULA: 372565
FECHA: Nov - 01 - 2023
DESCRIPCION: LIBRERIA PARA ACTIVIDAD 11
NOMBRE DEL ARCHIVO: costco.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "champurrado.h"

/* DEFINIR ESTRUCTURAS */

typedef struct _nombre{
    char nombres[50];
    char nombre1[20];
    char nombre2[20];
    char apellido1[20];
    char apellido2[20];
} Tnombre;

typedef struct _fecha{
    int anio;
    int mes;
    int dia;
    char anio1[5];
    char mes1[3];
    char dia1[3];
} Tfecha;

typedef struct _datos{
    int status;
    int matricula;
    Tnombre _nombre;
    int edad;
    Tfecha _fecha;
    int sex;
    char sexo[2];
    char estado[33];
    char estado_abreviado[33];
    char curp[19];
} Tdatos;

/* DEFINIR FUNCIONES PARA ESTRUCTURAS */

Tfecha bisiesto(void);
int busqueda_secuencial(Tdatos almacen[], int j, int matricula);
int busqueda_binaria(Tdatos almacen[], int izquierda, int derecha, int matricula);
int particion(Tdatos almacen[], int ri, int rf);
void intercambio(Tdatos almacen[], int i, int j);

Tfecha generar_fecha_random(void);
Tdatos generar_datos_random(void);
Tdatos generar_datos_manual(Tdatos _datos);
void generar_datos_curp(Tdatos _datos);
void generar_datos_curp_texto(Tdatos _datos, FILE *archivo);

/* FUNCIONES CON Y PARA ESTRUCTURAS*/

Tfecha bisiesto()
{
    Tfecha temp_fecha;

    int dias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dias_bisiestos[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    temp_fecha.anio = ValidarCadena("INGRESA TU ANIO DE NACIMIENTO: ", 1900, 2023);
    temp_fecha.mes = ValidarCadena("INGRESA TU MES DE NACIMIENTO: ", 1, 12);

    if (es_bisiesto(temp_fecha.anio))
    {
        temp_fecha.dia = ValidarCadena("INGRESA TU DIA DE NACIMIENTO: ", 1, dias_bisiestos[temp_fecha.mes]);
    }
    else
    {
        temp_fecha.dia = ValidarCadena("INGRESA TU DIA DE NACIMIENTO: ", 1, dias[temp_fecha.mes]);
    }

    return temp_fecha;
}

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

Tfecha generar_fecha_random(void)
{
    Tfecha _fecha;
    int ultimo_dia = 31;

    _fecha.anio = rango(1923, 2023);

    if(_fecha.anio == 2023)
    {
       _fecha.mes = rango(1, 10);
    }
    else
    {
        _fecha.mes = rango(1, 12);
    }

    if (_fecha.mes == 2)
    {
        ultimo_dia = (bisiesto_random(_fecha.anio) ? 29 : 28);
    }
    else
    {
        if (_fecha.mes == 4 || _fecha.mes == 6 || _fecha.mes == 9 || _fecha.mes == 11)
        {
            ultimo_dia = 30;
        }
    }

    _fecha.dia = rango(1, ultimo_dia);

    return _fecha;
}

Tdatos generar_datos_random(Tdatos _datos)
{
    int segundo_nombre = rango(1,2);
    char abreviado_estado[3];
    char estado[50];
    int estadito;
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
    // FECHA
    _datos._fecha = generar_fecha_random();
    // EDAD
    if(_datos._fecha.anio == 2023)
    {
        _datos.edad = -1;
    }
    else
    {
        _datos.edad = 2023 - _datos._fecha.anio;
    }
    // ESTADO
    estadito = rand() %33;
    estados(abreviado_estado, estadito, estado);
    strcpy(_datos.estado, estado);
    strcpy(_datos.estado_abreviado, abreviado_estado);

    printf("MATRICULA: %d\n", _datos.matricula);
    printf("NOMBRES: %s\n", _datos._nombre.nombres);
    printf("PRIMER APELLIDO: %s\n", _datos._nombre.apellido1);
    printf("SEGUNDO APELLIDO: %s\n", _datos._nombre.apellido2);
    printf("DIA: %d\n", _datos._fecha.dia);
    printf("MES: %d\n", _datos._fecha.mes);
    printf("ANIO: %d\n", _datos._fecha.anio);
    printf("EDAD: %d\n", _datos.edad);
    printf("SEXO: %s\n", _datos.sexo);
    printf("ESTADO: %s\n", _datos.estado);
    printf("CURP: ");
    generar_datos_curp(_datos);
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

    // FECHA DE NACIMIENTO
    _datos._fecha = bisiesto();

    // ESTADOS
    int up;
    char input[20];
    char estado[20];
    char estado_abreviado[3];
    char estados[ESTADOS][30];
    char estados_abreviados[ESTADOS][3];
    estados_republica(estados);
    estados_republica_abreviados(estados_abreviados);

    printf("ESTADOS EN MEXICO: \n");
    for (int i = 0; i < ESTADOS; i++) 
    {
        printf("%d. %s\n", i + 1, estados[i]);
    }
    do {
        printf("INGRESA EL NUMERO DE ESTADO DONDE FUISTE REGISTRADO: ");
        fflush(stdin); 
        gets(input);  
        up = atoi(input);
        if (up < 1 || up > ESTADOS) 
        {
            printf("ESTADO NO VALIDO. DEBE DE ESTAR ENTRE EL 1 Y %d.\n", ESTADOS);
        }
    } while (up < 1 || up > ESTADOS);

    strcpy(estado, estados[up - 1]);
    strcpy(estado_abreviado, estados_abreviados[up - 1]);

    printf("SELECCIONASTE EL ESTADO: %s\n", estado);
    strcpy(_datos.estado, estado);
    strcpy(_datos.estado_abreviado, estado_abreviado);

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
    printf("MATRICULA: %d\n", _datos.matricula);
    printf("NOMBRE 1: %s\n", _datos._nombre.nombre1);
    printf("NOMBRE 2: %s\n", _datos._nombre.nombre2);
    printf("APELLIDO PATERNO: %s\n", _datos._nombre.apellido1);
    printf("APELLIDO MATERNO: %s\n", _datos._nombre.apellido2);
    printf("FECHA DE NACIMIENTO: %02d-%02d-%04d\n", _datos._fecha.dia, _datos._fecha.mes, _datos._fecha.anio);
    if (_datos._fecha.anio == 2023)
    {
        printf("EDAD: MESES DE EDAD\n");
    }
    else
    {
        _datos.edad = 2023 - _datos._fecha.anio;
    }
    printf("EDAD: %d\n", _datos.edad);
    printf("SEXO: %s\n", _datos.sexo);
    printf("ESTADO DE REGISTRO: %s\n", _datos.estado);
    printf("CURP: ");
    generar_datos_curp(_datos);
    printf("\n");

    return _datos;
}

void generar_datos_curp(Tdatos _datos)
{
    char anio[8];
    char mes[3];
    char dia[3];

    char cero = '0'; 

    if (_datos._fecha.anio > 1983)
    {
        if (_datos._fecha.anio <= 1999)
        {
            cero = '0';
        }
    }

    if (_datos._fecha.anio > 1999)
    {
        cero = 'A';
    }

    if (_datos._fecha.anio > 2010)
    {
        cero = 'B';
    }

    char cero1[2];
    cero1[0] = cero;
    cero1[1] = '\0';

    sprintf(anio, "%d", _datos._fecha.anio);
    sprintf(mes, "%d", _datos._fecha.mes);
    sprintf(dia, "%d", _datos._fecha.dia);

    char curp[20];

    if (strlen(_datos._nombre.apellido1) == 0)
    {
        curp[0] = 'X';
        curp[1] = 'X';
    }
    else
    {
        curp[0] = _datos._nombre.apellido1[0];
        curp[1] = vocal(_datos._nombre.apellido1);
    }

    if (strlen(_datos._nombre.apellido2) == 0)
    {
        curp[2] = 'X';
    }
    else
    {
        curp[2] = _datos._nombre.apellido2[0];
    }

    curp[3] = _datos._nombre.nombres[0];
    curp[4] = anio[2];
    curp[5] = anio[3];

    if (_datos._fecha.mes < 10)
    {
        curp[6] = '0'; 
        curp[7] = mes[0];
    }
    else
    {
        curp[6] = mes[0];
        curp[7] = mes[1];
    }
    if (_datos._fecha.dia < 10)
    {
        curp[8] = '0'; 
        curp[9] = dia[0];
    }
    else
    {
        curp[8] = dia[0];
        curp[9] = dia[1];
    }
 
    char sexo[2];

    sprintf(sexo, "%s", _datos.sexo);

    if (_datos.sex == 1)
    {
        _datos.sexo[0] = 'H';
    }
    else
    {
        _datos.sexo[0] = 'M';
    }

    curp[10] = _datos.sexo[0];
    curp[11] = _datos.estado_abreviado[0];
    curp[12] = _datos.estado_abreviado[1];

    if (!consonante_apellido(_datos._nombre.apellido1) || strlen(_datos._nombre.apellido1) == 0)
    {
        curp[13] = 'X';
    }
    else
    {
        curp[13] = consonante_apellido(_datos._nombre.apellido1);
    }

    if (!consonante_apellido(_datos._nombre.apellido2) || strlen(_datos._nombre.apellido2) == 0)
    {
        curp[14] = 'X';
    }
    else
    {
        curp[14] = consonante_apellido(_datos._nombre.apellido2);
    }
 
    if (!consonante_nombre(_datos._nombre.nombres))
    {
        curp[15] = 'X';
    }
    else
    {
        curp[15] = consonante_nombre(_datos._nombre.nombres);
    }

    curp[16] = cero1[0];
    curp[17] = rango(0, 9) + '0';
    curp[18] = '\0';

    if (ValidarTabu(curp, 81))
    {
        curp[1] = 'X';
    }

    strcpy(_datos.curp, curp);
    printf("%s\n", _datos.curp);
}

void generar_datos_curp_texto(Tdatos _datos, FILE *archivo)
{
    char anio[8];
    char mes[3];
    char dia[3];

    char cero = '0'; 

    if (_datos._fecha.anio > 1983)
    {
        if (_datos._fecha.anio <= 1999)
        {
            cero = '0';
        }
    }

    if (_datos._fecha.anio > 1999)
    {
        cero = 'A';
    }

    if (_datos._fecha.anio > 2010)
    {
        cero = 'B';
    }

    char cero1[2];
    cero1[0] = cero;
    cero1[1] = '\0';

    sprintf(anio, "%d", _datos._fecha.anio);
    sprintf(mes, "%d", _datos._fecha.mes);
    sprintf(dia, "%d", _datos._fecha.dia);

    char curp[20];

    if (strlen(_datos._nombre.apellido1) == 0)
    {
        curp[0] = 'X';
        curp[1] = 'X';
    }
    else
    {
        curp[0] = _datos._nombre.apellido1[0];
        curp[1] = vocal(_datos._nombre.apellido1);
    }

    if (strlen(_datos._nombre.apellido2) == 0)
    {
        curp[2] = 'X';
    }
    else
    {
        curp[2] = _datos._nombre.apellido2[0];
    }

    curp[3] = _datos._nombre.nombres[0];
    curp[4] = anio[2];
    curp[5] = anio[3];

    if (_datos._fecha.mes < 10)
    {
        curp[6] = '0'; 
        curp[7] = mes[0];
    }
    else
    {
        curp[6] = mes[0];
        curp[7] = mes[1];
    }
    if (_datos._fecha.dia < 10)
    {
        curp[8] = '0'; 
        curp[9] = dia[0];
    }
    else
    {
        curp[8] = dia[0];
        curp[9] = dia[1];
    }
 
    char sexo[2];

    sprintf(sexo, "%s", _datos.sexo);

    if (_datos.sex == 1)
    {
        _datos.sexo[0] = 'H';
    }
    else
    {
        _datos.sexo[0] = 'M';
    }

    curp[10] = _datos.sexo[0];
    curp[11] = _datos.estado_abreviado[0];
    curp[12] = _datos.estado_abreviado[1];

    if (!consonante_apellido(_datos._nombre.apellido1) || strlen(_datos._nombre.apellido1) == 0)
    {
        curp[13] = 'X';
    }
    else
    {
        curp[13] = consonante_apellido(_datos._nombre.apellido1);
    }

    if (!consonante_apellido(_datos._nombre.apellido2) || strlen(_datos._nombre.apellido2) == 0)
    {
        curp[14] = 'X';
    }
    else
    {
        curp[14] = consonante_apellido(_datos._nombre.apellido2);
    }
 
    if (!consonante_nombre(_datos._nombre.nombres))
    {
        curp[15] = 'X';
    }
    else
    {
        curp[15] = consonante_nombre(_datos._nombre.nombres);
    }

    curp[16] = cero1[0];
    curp[17] = rango(0, 9) + '0';
    curp[18] = '\0';

    if (ValidarTabu(curp, 81))
    {
        curp[1] = 'X';
    }

    strcpy(_datos.curp, curp);
    fprintf(archivo, "%s\n", curp);
}

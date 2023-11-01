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

#define MESES 12
#define ESTADOS 33

typedef struct _nombre{
    char nombres[50];
    char apellido1[50];
    char apellido2[50];
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
} Tdatos;

Tnombre generar_nombre_random(char nombre[]);
Tfecha generar_fecha_random(void);
Tdatos generar_datos_random(void);

int rango(int ri, int rf);
int matricula_random();
int bisiesto_random(int anio);
int ValidarCadena(char mensj[], int ri, int rf);
int ValidarCadenaTexto(const char cadena[]);
int ValidarGenero(const char genero[2]);
int ValidarRango(int num, int ri, int rf);
int ValidarNombre(char cadena[]);
int Mayusculas(char cadena[]);
int validar_fecha(int anio, int mes, int dia);
int contador(char array[]);

void meses_delanio(char meses[][30]);
void nombre_femenino1(char cadena[]);
void nombre_femenino2(char cadena[]);
void nombre_masculino1(char cadena[]);
void nombre_masculino2(char cadena[]);
void apellidos(char cadena[]);
void segundo_nombre_masculino(char cadena[]);
void segundo_nombre_femenino(char cadena[]);
void estados(char estado_abreviado[], int opcion, char estado[]);
void estados_republica(char estados[][30]);
void estados_republica_abreviados(char estados_abreviados[][3]);

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

    printf("Matricula: %d\n", _datos.matricula);
    printf("Nombres: %s\n", _datos._nombre.nombres);
    printf("Primer apellido: %s\n", _datos._nombre.apellido1);
    printf("Segundo apellido: %s\n", _datos._nombre.apellido2);
    printf("Dia: %d\n", _datos._fecha.dia);
    printf("Mes: %d\n", _datos._fecha.mes);
    printf("Anio: %d\n", _datos._fecha.anio);
    printf("Edad: %d\n", _datos.edad);
    printf("Sexo: %s\n", _datos.sexo);
    printf("Estado: %s\n", _datos.estado);

    return _datos;
}

Tdatos generar_datos_manual(Tdatos _datos)
{
    int op;
    char PriNom[100];
    char SegNom[100];
    char PriApe[100];
    char SegApe[100];

    int ap;
    char anio[5];
    char mes[3];
    char dia[3];

    int up;
    int seleccion;
    char input[20];
    char meses[MESES][30];
    meses_delanio(meses);

    char estado[20];
    char estado_abreviado[3];
    char estados[ESTADOS][30];
    char estados_abreviados[ESTADOS][3];
    estados_republica(estados);
    estados_republica_abreviados(estados_abreviados);

    char genero[2];

    // MATRICULA
    _datos.matricula = ValidarCadena("Ingresa la matricula (entre 300000 y 399999): ", 300000, 399999);
    // NOMBRES
    do {
        printf("Ingresa tu primer nombre: \n");
        fflush(stdin);
        gets(PriNom);
        Mayusculas(PriNom);
        op = ValidarCadenaTexto(PriNom);
        if (op != 1) 
        {
            printf("Nombre no valido.\n");
        }
    } while (op != 1);
    strcpy(_datos._nombre.nombres, PriNom);
    op = ValidarCadena("Tienes un segundo nombre? (SI = 0, NO = 1): \n", 0, 1);
    if (op == 0) 
    {
        printf("Ingresa tu segundo nombre: \n");
        fflush(stdin);
        gets(SegNom);
        Mayusculas(SegNom);
        op = ValidarCadenaTexto(SegNom);
        if (op != 1) 
        {
            printf("Nombre no valido.\n");
        }
        strcat(_datos._nombre.nombres, " "); 
        strcat(_datos._nombre.nombres, SegNom);
    }
    // APELLIDOS
    do {
        printf("Ingresa tu primer apellido: \n");
        fflush(stdin);
        gets(PriApe);
        Mayusculas(PriApe);
        op = ValidarCadenaTexto(PriApe);
        if (op != 1) 
        {
            printf("Apellido no valido.\n");
        }
    } while (op != 1);
    op = ValidarCadena("Tienes un segundo apellido? (SI = 0, NO = 1): \n", 0, 1);
    if (op == 0) 
    {
        printf("Ingresa tu segundo apellido: \n");
        fflush(stdin);
        gets(SegApe);
        Mayusculas(SegApe);
        op = ValidarCadenaTexto(SegApe);
        if (op != 1) 
        {
            printf("Apellido no valido.\n");
        }
        strcat(_datos._nombre.apellido1, " ");
        strcat(_datos._nombre.apellido1, PriApe);
        strcat(_datos._nombre.apellido2, " ");
        strcat(_datos._nombre.apellido2, SegApe);
    }
    // FECHA NACIMIENTO
    do {
        // AÑO DE NACIMIENTO
        do {
        ap = ValidarCadena("Ingresa tu anioo de nacimiento (4 digitos): \n", 1893, 2023);
        if (ap < 1893) 
        {
            printf("El año debe ser mayor o igual a 1893.\n");
        } 
        else
        {
            if (ap > 2023)
            {
                printf("El año debe ser menor o igual a 2023.\n");
            }
        }
        } while (ap < 1893 || ap > 2023);
        sprintf(_datos._fecha.anio1, "%d", ap);
        // MES DE NACIMIENTO
        printf("Meses del anio:\n");
        for (int i = 0; i < MESES; i++) 
        {
            printf("%d. %s\n", i + 1, meses[i]);
        }
        do {
            printf("Ingresa tu mes de nacimiento (numero): ");
            fflush(stdin);
            gets(input);
            seleccion = atoi(input);
            up = ValidarRango(seleccion, 1, MESES);
            if (up != 1) 
            {
                printf("Mes no valido. Debe estar entre 1 y %d.\n", MESES);
            }
        } while (up != 1);
        mes[0] = seleccion;
        strcpy(_datos._fecha.mes1, mes);
        // DIA DE NACIMIENTO
        do {
            printf("Ingresa tu dia de nacimiento (1-31): \n");
            fflush(stdin);
            gets(input);
            dia[0] = atoi(input);
            up = ValidarRango(dia[0], 1, 31);
            if (up != 1) 
            {
                printf("Dia no valido. Debe estar entre 1 y 31.\n");
            }
        } while (up != 1);
        strcpy(_datos._fecha.dia1, dia);
        up = validar_fecha(anio[0], mes[0], dia[0]);
        if (up != 1) {
            printf("Fecha de nacimiento no valida. Por favor, ingresela nuevamente.\n");
        }
    } while (up != 1);
    // ESTADO DONDE FUE REGISTRADO
    printf("Estados en la Republica Mexicana:\n");
    for (int i = 0; i < ESTADOS; i++) 
    {
        printf("%d. %s\n", i + 1, estados[i]);
    }
    do {
        printf("Ingresa el numero del estado donde fuiste registrado: ");
        fflush(stdin); 
        gets(input);  
        up = atoi(input);
        if (up < 1 || up > ESTADOS) 
        {
            printf("Estado no valido. Debe estar entre 1 y %d.\n", ESTADOS);
        }
    } while (up < 1 || up > ESTADOS);
    strcpy(estado, estados[up - 1]);
    strcpy(estado_abreviado, estados_abreviados[up - 1]);
    printf("Seleccionaste el estado: %s\n", estado);
    strcpy(_datos.estado, estado);
    strcpy(_datos.estado_abreviado, estado_abreviado);
    // SEXO
    do {
        printf("Ingresa tu genero (H para hombre, M para mujer): ");
        fflush(stdin);
        gets(genero);
        Mayusculas(genero); 
        up = ValidarGenero(genero);
        if (up != 1) 
        {
            printf("Genero no valido. Debe ser 'H' o 'M'.\n");
        }
    } while (up != 1);
    strcpy(_datos.sexo, genero);

    return _datos;
}

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
    char PriNomFem[10][10] = {"ANA", "MARIA", "MIA", "ELBA", "IRMA", "SONIA", "LUZ", "DULCE", "EVA", "CARMEN"};
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

void estados(char estado_abreviado[], int opcion, char estado[])
{
    char estado_chiquito[33][3] = {
        "AS", "BC", "BS", "CC", "CL", "CM", "CS", "CH", "DF", "DG", "GT", "GR",
        "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP",
        "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS", "NE"};

    char estado_grande[33][25] = {
        "AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE",
        "CHIAPAS", "CHIHUAHUA", "COAHUILA", "COLIMA", "CIUDAD DE MEXICO",
        "DURANGO", "GUANAJUATO", "GUERRERO", "HIDALGO",
        "JALISCO", "MEXICO", "MICHOACAN", "MORELOS", "NAYARIT",
        "NUEVO LEON", "OAXACA", "PUEBLA", "QUERETARO",
        "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA", "SONORA",
        "TABASCO", "TAMAULIPAS", "TLAXCALA", "VERACRUZ",
        "YUCATAN", "ZACATECAS", "EXTRANJERO"};

    strcpy(estado_abreviado, estado_chiquito[opcion]);
    strcpy(estado, estado_grande[opcion]);
}

void estados_republica(char estados[][30])
{
    strcpy(estados[0], "Aguascalientes");
    strcpy(estados[1], "Baja California");
    strcpy(estados[2], "Baja California Sur");
    strcpy(estados[3], "Campeche");
    strcpy(estados[4], "Chiapas");
    strcpy(estados[5], "Chihuahua");
    strcpy(estados[6], "Coahuila");
    strcpy(estados[7], "Colima");
    strcpy(estados[8], "Ciudad de Mexico");
    strcpy(estados[9], "Durango");
    strcpy(estados[10], "Guanajuato");
    strcpy(estados[11], "Guerrero");
    strcpy(estados[12], "Hidalgo");
    strcpy(estados[13], "Jalisco");
    strcpy(estados[14], "Mexico");
    strcpy(estados[15], "Michoacan");
    strcpy(estados[16], "Morelos");
    strcpy(estados[17], "Nayarit");
    strcpy(estados[18], "Nuevo Leon");
    strcpy(estados[19], "Oaxaca");
    strcpy(estados[20], "Puebla");
    strcpy(estados[21], "Queretaro");
    strcpy(estados[22], "Quintana Roo");
    strcpy(estados[23], "San Luis Potosi");
    strcpy(estados[24], "Sinaloa");
    strcpy(estados[25], "Sonora");
    strcpy(estados[26], "Tabasco");
    strcpy(estados[27], "Tamaulipas");
    strcpy(estados[28], "Tlaxcala");
    strcpy(estados[29], "Veracruz");
    strcpy(estados[30], "Yucatan");
    strcpy(estados[31], "Zacatecas");
    strcpy(estados[32], "Nacido en el Extranjero");
}

void estados_republica_abreviados(char estados_abreviados[][3])
{
    strcpy(estados_abreviados[0], "AG");
    strcpy(estados_abreviados[1], "BC");
    strcpy(estados_abreviados[2], "BS");
    strcpy(estados_abreviados[3], "CM");
    strcpy(estados_abreviados[4], "CS");
    strcpy(estados_abreviados[5], "CH");
    strcpy(estados_abreviados[6], "CO");
    strcpy(estados_abreviados[7], "CL");
    strcpy(estados_abreviados[8], "CMX");
    strcpy(estados_abreviados[9], "DG");
    strcpy(estados_abreviados[10], "GT");
    strcpy(estados_abreviados[11], "GR");
    strcpy(estados_abreviados[12], "HG");
    strcpy(estados_abreviados[13], "JC");
    strcpy(estados_abreviados[14], "MC");
    strcpy(estados_abreviados[15], "MN");
    strcpy(estados_abreviados[16], "MS");
    strcpy(estados_abreviados[17], "NT");
    strcpy(estados_abreviados[18], "NL");
    strcpy(estados_abreviados[19], "OC");
    strcpy(estados_abreviados[20], "PL");
    strcpy(estados_abreviados[21], "QT");
    strcpy(estados_abreviados[22], "QR");
    strcpy(estados_abreviados[23], "SP");
    strcpy(estados_abreviados[24], "SL");
    strcpy(estados_abreviados[25], "SR");
    strcpy(estados_abreviados[26], "TC");
    strcpy(estados_abreviados[27], "TS");
    strcpy(estados_abreviados[28], "TL");
    strcpy(estados_abreviados[29], "VZ");
    strcpy(estados_abreviados[30], "YN");
    strcpy(estados_abreviados[31], "ZS");
    strcpy(estados_abreviados[32], "NE");
}

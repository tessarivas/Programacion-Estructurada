/*
NOMBRE: Teresa Rivas Gomez
MATRICULA: 372565
FECHA: Oct - 19 - 2023
DESCRIPCION: CURP
NOMBRE DEL ARCHIVO: RGT_Act9.75_932
*/

#include "harry_potter.h"

#define MESES 12
#define ESTADOS 33

void imprimir_curp(char curp[]);

void pedir_apelidos(char pri_ape[20], char seg_ape[20]);
void pedir_nombres(char primero[20], char segundo[20], char tercero[20]);
char buscar_primera_vocal(const char nombre[20]);
char buscar_primera_vocal_interna(const char palabra[20]);
char buscar_primera_consonante_interna(const char palabra[20]);
void eliminar_palabras_compuestas(char cadena[]);

void pedir_fecha_nacimiento(int anio[4], int mes[2], int dia[2]);
void meses_delanio(char meses[][30]);

void pedir_genero(char genero[2]);

void pedir_estado(char estado[20], char estado_abreviado[3]);
void estados_republica(char estados[][30]);
void estados_republica_abreviados(char estados_abreviados[][3]);

void reemplazar_palabras_tabu(char curp[]);

int main()
{
    int op;
    char curp[20];
    srand(time(NULL));
    system("CLS");

    printf("ACTIVIDAD 9 3/4\n");
    do {
    printf("Generador de CURP: \n");
    imprimir_curp(curp);
    reemplazar_palabras_tabu(curp);
    printf("CURP generada: %s\n", curp);
    op = ValidarCadena("\nDeseas buscar otra curp(SI = 1, NO = 2): \n", 1, 2);
    } while (op != 2);

    return 0;
}

void imprimir_curp(char curp[19])
{
    char pri_ape[20], seg_ape[20];
    pedir_apelidos(pri_ape, seg_ape);

    char pri_nom[20], seg_nom[20], ter_nom[20];
    pedir_nombres(pri_nom, seg_nom, ter_nom);

    int anio[4], mes[2], dia[2];
    pedir_fecha_nacimiento(anio, mes, dia);

    char estado[30], estado_abreviado[3];
    pedir_estado(estado, estado_abreviado);

    char genero[2];
    pedir_genero(genero);

    eliminar_palabras_compuestas(pri_ape);
    eliminar_palabras_compuestas(seg_ape);
    eliminar_palabras_compuestas(pri_nom);
    eliminar_palabras_compuestas(seg_nom);
    eliminar_palabras_compuestas(ter_nom);

    char primer_consonante_ape = buscar_primera_consonante_interna(pri_ape);
    char primer_consonante_seg_ape = buscar_primera_consonante_interna(seg_ape);
    char primer_consonante_pri_nom = buscar_primera_consonante_interna(pri_nom);

    char clave_primera_letra;
    char vocal_despues_primera_vocal = buscar_primera_vocal_interna(pri_ape);

    char caracter_despues_consonantes = '0';
    int numero_aleatorio = rand() % 10;

    // PRIMER APELLIDO
    if (counter(pri_ape) == 0) 
    {
        curp[0] = 'X';
        curp[1] = 'X';
    } 
    else
    {
        curp[0] = pri_ape[0];
        curp[1] = vocal_despues_primera_vocal;
    }
    // SEGUNDO APELLIDO
    if (counter(seg_ape) == 0)
    {
        curp[2] = 'X';
    } 
    else 
    {
        curp[2] = seg_ape[0];
    }

    // NOMBRE/S
    if (strlen(pri_nom) > 0) 
    {
        clave_primera_letra = (strcasecmp(pri_nom, "MARIA") == 0 || strcasecmp(pri_nom, "MA.") == 0 || 
                              strcasecmp(pri_nom, "MA") == 0 || strcasecmp(pri_nom, "JOSE") == 0 || 
                              strcasecmp(pri_nom, "J") == 0 || strcasecmp(pri_nom, "J.") == 0) ? seg_nom[0] : pri_nom[0];
        curp[3] = clave_primera_letra;
    } 
    else 
    {
        curp[3] = 'X';
    }

    // ANIO
    if (anio[0] >= 1893) 
    {
        curp[4] = '0' + (anio[0] % 100) / 10;
        curp[5] = '0' + (anio[0] % 100) % 10;
    } 

    // MES
    if (mes[0] >= 10) 
    {
        curp[6] = '0' + mes[0] / 10; 
        curp[7] = '0' + mes[0] % 10; 
    } 
    else 
    {
        curp[6] = '0'; 
        curp[7] = '0' + mes[0]; 
    }

    // DIA
    if (dia[0] >= 10) 
    {
        curp[8] = '0' + dia[0] / 10; 
        curp[9] = '0' + dia[0] % 10; 
    } 
    else 
    {
        curp[8] = '0'; 
        curp[9] = '0' + dia[0];
    }

    // GENERO
    curp[10] = genero[0];

    // ESTADO
    curp[11] = estado_abreviado[0];
    curp[12] = estado_abreviado[1];

    // CONSONANTES INTERNAS
    if (primer_consonante_seg_ape == '\0' || counter(pri_ape) == 0)
    {
        curp[13] = 'X';
    } 
    else 
    {
        curp[13] = primer_consonante_ape;
    }

    if (primer_consonante_seg_ape == '\0' || counter(seg_ape) == 0)
    {
        curp[14] = 'X';
    } 
    else 
    {
        curp[14] = primer_consonante_seg_ape;
    }

    if (primer_consonante_pri_nom != '\0') 
    {
        if (strcasecmp(pri_nom, "MARIA") == 0 || strcasecmp(pri_nom, "MA.") == 0 || 
            strcasecmp(pri_nom, "MA") == 0 || strcasecmp(pri_nom, "JOSE") == 0 || 
            strcasecmp(pri_nom, "J") == 0 || strcasecmp(pri_nom, "J.") == 0) 
        {
            clave_primera_letra = buscar_primera_consonante_interna(seg_nom);
        }
        else
        {
            clave_primera_letra = buscar_primera_consonante_interna(pri_nom);
        }
        curp[15] = clave_primera_letra;
    } 
    else 
    {
       curp[15] = 'X';
    }

    // CARACTER 17
    if (anio[0] > 1983)
    {
        if (anio[0] <= 1999)
        {
            caracter_despues_consonantes = '0';
        }
    }

    if (anio[0] > 1999)
    {
        caracter_despues_consonantes = 'A';
    }

    if (anio[0] > 2010)
    {
        caracter_despues_consonantes = 'B';
    }
    curp[16] = caracter_despues_consonantes;

    // CARACTER 18
    curp[17] = '0' + numero_aleatorio;

    // CIERRE
    curp[18] = '\0';
}

void pedir_apelidos(char pri_ape[20], char seg_ape[20])
{
    int op;
    int up;
    // PRIMER APELLIDO
    do {
        up = ValidarCadena("Tienes un primer apellido? (SI = 1, NO = 2): \n", 1, 2);
        if (up == 1) 
        {
            printf("Ingresa tu primer apellido: \n");
            fflush(stdin);
            gets(pri_ape);
            Mayusculas(pri_ape);
            op = ValidarNombre(pri_ape);
            if (op != 1) 
            {
                printf("Apellido no valido.\n");
            }
            printf("Primer apellido: %s\n", pri_ape);
        }
        else
        {
            pri_ape[0] = '\0';
        }
    } while (op != 1);
    // SEGUNDO APELLIDO
    do {
        up = ValidarCadena("Tienes un segundo apellido? (SI = 1, NO = 2): \n", 1, 2);
        if (up == 1) 
        {
            printf("Ingresa tu segundo apellido: \n");
            fflush(stdin);
            gets(seg_ape);
            Mayusculas(seg_ape);
            op = ValidarNombre(seg_ape);
            if (op != 1) 
            {
                printf("Apellido no valido.\n");
            }
            printf("Segundo apellido: %s\n", seg_ape);
        }
        else
        {
            seg_ape[0] = '\0';
        }
    } while (op != 1);
}

void pedir_nombres(char pri_nom[20], char seg_nom[20], char ter_nom[20])
{
    int op;
    int up;
    // PRIMER NOMBRE
    do {
        printf("Ingresa tu primer nombre: \n");
        fflush(stdin);
        gets(pri_nom);
        Mayusculas(pri_nom);
        op = ValidarNombre(pri_nom);
        if (op != 1) 
        {
            printf("Nombre no valido.\n");
        }
    } while (op != 1);
    printf("Nombre: %s\n", pri_nom);
    // SEGUNDO NOMBRE
    do {
        up = ValidarCadena("Tienes un segundo nombre? (SI = 1, NO = 2): \n", 1, 2);
        if (up == 1) 
        {
            printf("Ingresa tu segundo nombre: \n");
            fflush(stdin);
            gets(seg_nom);
            Mayusculas(seg_nom);
            op = ValidarNombre(seg_nom);
            if (op != 1) 
            {
                printf("Nombre no valido.\n");
            }
            printf("Segundo nombre: %s\n", seg_nom);
            // TERCER NOMBRE
            up = ValidarCadena("Tienes un tercer nombre? (SI = 1, NO = 2): \n", 1, 2);
            if (up == 1) 
            {
                printf("Ingresa tu tercer nombre: \n");
                fflush(stdin);
                gets(ter_nom);
                Mayusculas(ter_nom);
                op = ValidarNombre(ter_nom);
                if (op != 1) 
                {
                    printf("Nombre no valido.\n");
                }
                printf("Tercer nombre: %s\n", ter_nom);
            }
        }
    } while (op != 1);
}

char buscar_primera_vocal(const char palabra[20])
{
    for (int i = 0; palabra[i] != '\0'; i++) 
    {
        char c = palabra[i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
            {
            return palabra[i];
        }
    }
    return '\0';
}

char buscar_primera_vocal_interna(const char palabra[20])
{
    for (int i = 1; palabra[i] != '\0'; i++) 
    {
        char c = palabra[i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
            {
            return palabra[i];
        }
    }
    return 'X';
}

char buscar_primera_consonante_interna(const char palabra[20])
{
    char palabra_modificada[20];
    strcpy(palabra_modificada, palabra);
    eliminar_palabras_compuestas(palabra_modificada);
    int i = 1;
    while(palabra[i] != '\0')
    {
        char c = palabra[i];
        if (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U' && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') 
        {
            return c;
        }
        i++;
    }
    return '\0';
}

void eliminar_palabras_compuestas(char cadena[]) 
{
    char partes[][6] = {"DAS ", "DEL ", "DE ", "DER ", "DIE ", "LOS ", "LAS ", "LES ", "MAC ", "VAN ", "VON ",
                        "DA ", "DI ", "DD ", "EL ", "LA ", "LE ", "MC ", "Y "};
    for (int i = 0; partes[i][0] != '\0'; i++) 
    {
        int encontrado = 0;
        int coincidencia = 0; 
        
        while (cadena[encontrado] != '\0') 
        {
            int longitud_partes = strlen(partes[i]);
            coincidencia = 1;     
            for (int j = 0; j < longitud_partes; j++) 
            {
                if (cadena[encontrado + j] != partes[i][j]) 
                {
                    coincidencia = 0;
                }
            }
            if (coincidencia) 
            {
                int longitud_resto = strlen(cadena + encontrado + longitud_partes);
                for (int j = 0; j <= longitud_resto; j++) 
                {
                    cadena[encontrado + j] = cadena[encontrado + longitud_partes + j];
                }
            } 
            else 
            {
                encontrado++;
            }
        }
    }
}

void pedir_fecha_nacimiento(int anio[4], int mes[2], int dia[2])
{
    int up;
    int seleccion;
    char input[20];
    char meses[MESES][30];
    meses_delanio(meses);

    do {
        // AÑO DE NACIMIENTO
        do {
            printf("Ingresa tu anio de nacimiento (4 digitos): \n");
            fflush(stdin);
            gets(input);
            anio[0] = atoi(input);
            up = ValidarRango(anio[0], 1893, 2023);
            if (up != 1) 
            {
                printf("Anio no valido. Debe estar entre 1893 y 2023.\n");
            }
        } while (up != 1);

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

        up = validar_fecha(anio[0], mes[0], dia[0]);

        if (up != 1) {
            printf("Fecha de nacimiento no valida. Por favor, ingresela nuevamente.\n");
        }
    } while (up != 1);
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

void pedir_genero(char genero[2])
{
    int up;
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
}

void pedir_estado(char estado[20], char estado_abreviado[3])
{
    int up;
    char input[20];
    char estados[ESTADOS][30];
    char estados_abreviados[ESTADOS][3];
    estados_republica(estados);
    estados_republica_abreviados(estados_abreviados);
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

void reemplazar_palabras_tabu(char curp[]) 
{
    const char palabras_tabu[81][5] = {
        "BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO",
        "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO",
        "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA",
        "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO",
        "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR",
        "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE",
        "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO",
        "RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI",
        "WUEY"
    };

    for (size_t i = 0; i < sizeof(palabras_tabu) / sizeof(palabras_tabu[0]); i++) 
    {
        const char *palabra_tabu = palabras_tabu[i];
        const char *pos_tabu = strstr(curp, palabra_tabu);

        while (pos_tabu != NULL) 
        {
            if (pos_tabu[1] != '\0') 
            {
                curp[pos_tabu - curp + 1] = 'X';
            }

            pos_tabu = strstr(pos_tabu + 1, palabra_tabu);
        }
    }
}

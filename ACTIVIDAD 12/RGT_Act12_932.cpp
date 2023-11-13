/*
NOMBRE: Teresa Rivas Gomez
MATRICULA: 372565
FECHA: Nov - 07 - 2023
DESCRIPCION: ARCHIVOS TEXTO
NOMBRE DEL ARCHIVO: RGT_Act12_932.cpp
*/

#include "tamales.h"

#define REGISTROS 1500

int menu_mensaje();
int menu();

int imprimir_registro(Tdatos almacen[], int i);
void eliminar_registro(Tdatos almacen[], int i);
int busqueda(Tdatos almacen[], int i);
int busqueda2(Tdatos almacen[], int i);
int seleccion_temporal( Tdatos almacen[], int tamaño);
int seleccion(Tdatos almacen[], int ri, int rf);
int cargar_archivo(Tdatos almacen[], int i, char nombre_archivo[]);
void copiar_registro_texto(Tdatos almacen[], int i, char nombre_direccion[]);
void copiar_eliminados_texto(Tdatos almacen[], int i, char nombre_direccion[]);
void contador_registros();

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int menu_mensaje()
{
    int opcion;
    system ("CLS");
    printf ("ACTIVIDAD: SEMANA 14\n");
    printf("1.- CARGAR ARCHIVO\n");
    printf("2.- AGREGAR\n");
    printf("3.- ELIMINAR\n");
    printf("4.- BUSCAR\n");
    printf("5.- ORDENAR\n");
    printf("6.- MOSTRAR TODO\n");
    printf("7.- GENERAR ARCHIVO\n");
    printf("8.- CANTIDAD DE REGISTROS EN ARCHIVO\n");
    printf("9.- MOSTRAR ELIMINADOS\n");
    printf("0.- SALIR\n");
    opcion = ValidarCadena("OPCION QUE ELEGISTE(0-9):\n", 0, 9);
    return opcion;
}

int menu()
{
    int i = 0;
    int orden;
    int opcion;
    char nombre[15];
    Tdatos almacen[REGISTROS];
    Tdatos _datos;
    do {
        opcion = menu_mensaje();
        system("CLS");
        switch(opcion)
        {
            case 1:
                printf("CARGAR ARCHIVO\n");
                i = cargar_archivo(almacen, i, "C:\\Users\\52616\\OneDrive\\Documentos\\U A B C\\3er Semestre\\Programacion Estructurada\\Actividad 12\\output\\datos.txt");
                system("PAUSE");
                break;
            case 2:
                printf("AGREGAR\n");
                printf("SE AÑADIO CORRECTAMENTE\n");
                if (i + 10 <= REGISTROS)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        if (i < REGISTROS)
                        {
                            _datos = generar_datos_random(_datos);
                            while (busqueda_secuencial(almacen, i, _datos.matricula) != -1)
                            {
                                _datos.matricula = (rand() % 399999) + 300000;
                            }
                            almacen[i] = _datos;
                            i++;
                        }
                    }
                    printf("SE HAN AGREGADO LOS REGISTROS CORRECTAMENTE \n");
                }
                else
                {
                    printf("YA HAZ LLENADO TODOS LOS REGISTROS\n");
                }

                orden = 0;
                system("PAUSE");
                break;
            case 3:
                printf("ELIMINAR\n");
                eliminar_registro(almacen, i);
                system("PAUSE");
                break;
            case 4:
                printf("BUSCAR\n");
                if (orden == 0)
                {
                    busqueda(almacen, i);
                    system("PAUSE");
                }
                else
                {
                    busqueda2(almacen, i);
                    system("PAUSE");
                }
                break;
            case 5:
                printf("ORDENAR\n");
                if (orden == 0)
                {
                    if (i <= 500)
                    {
                        
                        orden = seleccion_temporal(almacen, i);
                        printf("SE ORDENO EL REGISTRO DE ALUMNOS POR MATRICULA.\n");
                        system("PAUSE");
                    }
                    else
                    {
                        if (i > 500)
                        {
                            orden = seleccion(almacen, 0, i);
                            printf("SE ORDENO EL REGISTRO DE ALUMNOS POR MATRICULA.\n");
                            system("PAUSE");
                        }
                    }
                }
                else
                {
                    printf("YA HA SIDO PREVIAMENTE ORDENADO.\n");
                    system("PAUSE");
                }
                break;
            case 6:
                printf("MOSTRAR TODO\n");
                imprimir_registro(almacen, i);
                system("PAUSE");
                break;
            case 7:
                printf("GENERAR ARCHIVO\n");
                printf("INGRESA EL NOMBRE DE TU NUEVO ARCHIVO: \n");
                fflush(stdin);
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0'; 
                copiar_registro_texto(almacen, i, nombre);
                system("PAUSE");
                break;
            case 8:
                printf("CANTIDAD DE REGISTROS EN ARCHIVO\n\n");
                contador_registros();
                system("PAUSE");
                break;
            case 9:
                printf("MOSTRAR ELIMINADOS\n");
                printf("GENERAR ARCHIVO\n");
                printf("INGRESA EL NOMBRE DE TU NUEVO ARCHIVO: \n");
                fflush(stdin);
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0'; 
                copiar_eliminados_texto(almacen, i, nombre);
                system("PAUSE");
                break;
            case 0:
                printf("SALISTE DEL PROGRAMA.\n");
                break;
        }
    } while(opcion != 0);
    return 0;
}

/* Muestra en la terminal los registros de alumnos que tienen status 1.
Se pueden ver 40 registros a la vez, y para ver mas solo hay que darle al "ENTER".*/
int imprimir_registro(Tdatos almacen[], int i) 
{
    int j;
    int status_uno = 0;

    system("CLS");
    printf("REGISTRO DE ALUMNOS\n");
    printf("+---------+--------+-----------+------------------+------------------+---------------------+----------+----------+\n");
    printf("| NO. REG | STATUS | MATRICULA | APELLIDO PATERNO | APELLIDO MATERNO |      NOMBRE(S)      |   EDAD   |   SEXO   |\n");
    printf("+---------+--------+-----------+------------------+------------------+---------------------+----------+----------+\n");

    for (j = 0, status_uno = 0; j < i; j++) 
    {
        if (almacen[j].status == 1) 
        {
            printf("| %-6d  | %-5d  | %-9d | %-16s | %-16s | %-19s | %-6d   | ", 
                j + 1,
                almacen[j].status,
                almacen[j].matricula,
                almacen[j]._nombre.apellido1,
                almacen[j]._nombre.apellido2,
                almacen[j]._nombre.nombres,
                almacen[j].edad
            );
            if (strcmp(almacen[j].sexo, "H") == 0 || strcmp(almacen[j].sexo, "MASCULINO") == 0)
            {
                printf("HOMBRE");
            }
            else if (strcmp(almacen[j].sexo, "M") == 0 || strcmp(almacen[j].sexo, "FEMENINO") == 0)
            {
                printf("MUJER");
            }
            printf("\n");
            status_uno++;
        }

        if ((status_uno) % 40 == 0) 
        {
            if(status_uno < i)
            {
            printf("+---------+--------+-----------+------------------+------------------+---------------------+----------+----------+\n");
            printf("PRESIONA (ENTER) PARA VER MAS...\n");
            getchar();
            system("CLS");
            printf("REGISTROS %d - %d\n\n", status_uno + 1, (status_uno + 40) > i ? i : (status_uno + 40));
            printf("+---------+--------+-----------+------------------+------------------+---------------------+----------+----------+\n");
            printf("| NO. REG | STATUS | MATRICULA | APELLIDO PATERNO | APELLIDO MATERNO |      NOMBRE(S)      |   EDAD   |   SEXO   |\n");
            printf("+---------+--------+-----------+------------------+------------------+---------------------+----------+----------+\n");
            }
        }
    }
    return 0;
}

/* Ingresas la matricula de un alumno para eliminar. Luego busca la matricula en el 
arreglo de registros. Si la encuentra y el status 1, muestra la info del alumno y solicita 
confirmacion SI o NO para eliminar. Despues actualiza el status en 0 si se confirma.*/
void eliminar_registro(Tdatos almacen[], int i)
{
    int borrar;
    int decision;
    int encontrar;
    borrar = ValidarCadena("INGRESA LA MATRICULA DEL ALUMNO A ELIMINAR: \n", 300000, 399999);
    encontrar = busqueda_secuencial(almacen, i, borrar);

    if(encontrar != -1) 
    {
        printf("MATRICULA ENCONTRADA\n");
        if (almacen[encontrar].status == 1)
        {
            Tdatos copia = almacen[encontrar];

            printf("MATRICULA: %d\n", copia.matricula);
            printf("NOMBRES: %s\n", copia._nombre.nombres);
            printf("APELLIDOS: %s %s\n", copia._nombre.apellido1, copia._nombre.apellido2);
            printf("EDAD: %d\n", copia.edad);

            decision = ValidarCadena("ESTAS SEGURO QUE DESEAS ELIMINAR ESTE REGISTRO?\n[1] SI\n[2] NO\n", 1, 2);

            if (decision == 1)
            {
                almacen[encontrar].status = 0;
                printf("LA MATRICULA %i HA SIDO ELIMINADA PREVIAMENTE.\n", borrar);
            }
            else
            {
                almacen[encontrar].status = 1;
                printf("MATRICULA NO ELIMINADA.\n");
            }
        }
        else
        {
            printf("LA MATRICULA %i YA HA SIDO ELIMINADA ANTERIORMENTE\n", borrar);
        }
    }
    else
    {
        printf("MATRICULA NO ENCONTRADA\n");
    }
}

int busqueda(Tdatos almacen[], int i)
{
    printf("BUSQUEDA SECUENCIAL\n");

    int matricula = ValidarCadena("MATRICULA QUE DESEAS BUSCAR: \n", 300000, 399999);
    int posicion = busqueda_secuencial(almacen, i, matricula);

    if (posicion == -1)
    {
        printf("NO SE ENCONTRO LA MATRICULA\n");
    }
    else
    {
        printf("LA MATRICULA %d ESTA EN EL REGISTRO: %d\n", matricula, posicion + 1);
        printf("MATRICULA: %d\n", almacen[posicion].matricula);
        printf("NOMBRES: %s\n", almacen[posicion]._nombre.nombres);
        printf("APELLIDOS: %s %s\n", almacen[posicion]._nombre.apellido1, almacen[posicion]._nombre.apellido2);
        printf("EDAD: %d\n", almacen[posicion].edad);
        if (almacen[posicion].sex == 1)
        {
            printf("SEXO: HOMBRE\n");
        }
        else
        {
            printf("SEXO: MUJER\n");
        }
    }

    return -1;
}

int busqueda2(Tdatos almacen[], int i)
{
    printf("BUSQUEDA BINARIA\n");
    int matricula = ValidarCadena("MATRICULA QUE DESEAS BUSCAR: \n", 300000, 399999);
    int posicion = busqueda_binaria(almacen, 0, i - 1, matricula);

    if(posicion == -1)
    {
        printf("NO SE ENCONTRO LA MATRICULA\n");
    }
    else
    {
        printf("LA MATRICULA %d ESTA EN EL REGISTRO: %d\n ", matricula, posicion + 1);
        printf("MATRICULA: %d\n", almacen[posicion].matricula);
        printf("NOMBRES: %s\n", almacen[posicion]._nombre.nombres);
        printf("APELLIDOS: %s %s\n", almacen[posicion]._nombre.apellido1, almacen[posicion]._nombre.apellido2);
        printf("EDAD: %d\n", almacen[posicion].edad);
        if (almacen[posicion].sex == 1)
        {
            printf("SEXO: HOMBRE\n");
        }
        else
        {
            printf("SEXO: MUJER\n");
        }
    }

    return -1;
}

int seleccion_temporal( Tdatos almacen[], int tamaño)
{
    Tdatos temp;
    int j;
    int k;

    for (j = 0; j < tamaño - 1; j++)
    {
        for ( k = j + 1; k < tamaño; k++)
        {
            if (almacen[k].matricula < almacen[j].matricula)
            {
                temp = almacen[j];
                almacen[j] = almacen[k];
                almacen[k] = temp;
            }
        }
    }

    return 1;
}

int seleccion(Tdatos almacen[], int ri, int rf)
{
    if (ri < rf)
    {
        int parti = particion(almacen, ri, rf);

        seleccion(almacen, ri, parti - 1);
        seleccion(almacen, parti + 1, rf);
    }
    return -1;
}

/* Aqui abrimos un archivo con el nombre que se ingreso y verificamos si existe. Luego si el archivo
esta vacio o si tiene un encabezado. Si hay un encabezado, lo omite. Despues lee cada linea en el archivo, 
interpreta los datos y los guarda en el arreglo de registros. */
int cargar_archivo(Tdatos almacen[], int i, char nombre_archivo[])
{
    FILE *archivo;
    int trash;

    archivo = fopen(nombre_archivo, "r");

    if (archivo == NULL)
    {
        printf("EL ARCHIVO NO EXISTE\n");
        return i;
    }

    // VERIFICAR SI TIENE ENCABEZADO.
    char pr_linea[100];
    if (fgets(pr_linea, sizeof(pr_linea), archivo) == NULL)
    {
        printf("EL ARCHIVO ESTA VACIO\n");
        fclose(archivo);
        return i;
    }

    // VERIFICO SI TIENE ENCABEZADO CON EL FORMATO QUE YA TENGO.
    int encabezado = sscanf(pr_linea, "%d.- %d %s %s %s %d %s", &trash, &almacen[i].matricula, almacen[i]._nombre.nombres, almacen[i]._nombre.apellido1, almacen[i]._nombre.apellido2, &almacen[i].edad, almacen[i].sexo) != 7;

    if (encabezado)
    {
        if (fgets(pr_linea, sizeof(pr_linea), archivo) == NULL)
        {
            printf("NO HAY MAS DATOS EN EL ARCHIVO\n");
            fclose(archivo);
            return i;
        }
    }

    do
    {
        if (sscanf(pr_linea, "%d.- %d %s %s %s %d %s", &trash, &almacen[i].matricula, almacen[i]._nombre.nombres, almacen[i]._nombre.apellido1, almacen[i]._nombre.apellido2, &almacen[i].edad, almacen[i].sexo) == 7)
        {
            almacen[i].status = 1;
            printf("Leer datos: %d %s %s %s %d %s\n", almacen[i].matricula, almacen[i]._nombre.nombres, almacen[i]._nombre.apellido1, almacen[i]._nombre.apellido2, almacen[i].edad, almacen[i].sexo);
            i++;
        }
    } while (fgets(pr_linea, sizeof(pr_linea), archivo) != NULL);

    printf("LOS DATOS HAN SIDO AGREGADOS A LOS REGISTROS\n");
    fclose(archivo);

    return i;
}

/*  Crea un nuevo archivo de texto, con el nombre que pusimos y con ".txt". Luego escribe en ese archivo un 
formato de tabla con los datos almacenados en el arreglo. Solo incluye registros con status 1 y muestra la 
info con el encabezado.*/
void copiar_registro_texto(Tdatos almacen[], int i, char nombre_direccion[])
{
    char direccion[1000];
    strcpy(direccion, "C:\\Users\\52616\\OneDrive\\Documentos\\U A B C\\3er Semestre\\Programacion Estructurada\\Actividad 12\\");
    strcat(direccion, nombre_direccion);
    strcat(direccion, ".txt");

    FILE *archivo = fopen(direccion, "w");

    if (archivo == NULL) 
    {
        printf("ERROR AL ABRIR EL ARCHIVO.\n");
        return;
    }

    fprintf(archivo, "+---------+-----------+------------------+------------------+------------------+----------+--------+\n");
    fprintf(archivo, "| NO. REG | MATRICULA | APELLIDO PATERNO | APELLIDO MATERNO |      NOMBRE      |   EDAD   |  SEXO  |\n");
    fprintf(archivo, "+---------+-----------+------------------+------------------+------------------+----------+--------+\n");

    for (int j = 0; j < i; j++) 
    {
        if (almacen[j].status == 1)
        {
            fprintf(archivo, "%2d.-        %-10d  %-17s  %-17s  %-20s  %-6d  ", 
            j + 1,
            almacen[j].matricula,
            almacen[j]._nombre.apellido1,
            almacen[j]._nombre.apellido2,
            almacen[j]._nombre.nombres,
            almacen[j].edad
            );
            if (strcmp(almacen[j].sexo, "H") == 0 || strcmp(almacen[j].sexo, "MASCULINO") == 0)
            {
                fprintf(archivo,"HOMBRE");
            }
            else 
            {
                if (strcmp(almacen[j].sexo, "M") == 0 || strcmp(almacen[j].sexo, "FEMENINO") == 0)
                {
                    fprintf(archivo,"MUJER");
                }
            }
            fprintf(archivo, "\n");
        }
    }
    fclose(archivo);
} 

/*  Crea un nuevo archivo de texto, con el nombre que pusimos y con ".txt". Luego escribe en ese archivo un 
formato de tabla con los datos almacenados en el arreglo. Solo incluye registros con status 0 (eliminados) y 
muestra la info con el encabezado.*/
void copiar_eliminados_texto(Tdatos almacen[], int i, char nombre_direccion[])
{
    char direccion[1000];
    strcpy(direccion, "C:\\Users\\52616\\OneDrive\\Documentos\\U A B C\\3er Semestre\\Programacion Estructurada\\Actividad 12\\");
    strcat(direccion, nombre_direccion);
    strcat(direccion, ".txt");

    FILE *archivo = fopen(direccion, "w");

    if (archivo == NULL) 
    {
        printf("ERROR AL ABRIR EL ARCHIVO.\n");
        return;
    }

    fprintf(archivo, "+---------+-----------+------------------+------------------+------------------+----------+--------+\n");
    fprintf(archivo, "| NO. REG | MATRICULA | APELLIDO PATERNO | APELLIDO MATERNO |      NOMBRE      |   EDAD   |  SEXO  |\n");
    fprintf(archivo, "+---------+-----------+------------------+------------------+------------------+----------+--------+\n");

    for (int j = 0; j < i; j++) 
    {
        if (almacen[j].status == 0) 
        {
            fprintf(archivo, "%2d.-        %-10d  %-17s  %-17s  %-20s  %-6d  ", 
            j + 1,
            almacen[j].matricula,
            almacen[j]._nombre.apellido1,
            almacen[j]._nombre.apellido2,
            almacen[j]._nombre.nombres,
            almacen[j].edad
            );
            if (strcmp(almacen[j].sexo, "H") == 0 || strcmp(almacen[j].sexo, "MASCULINO") == 0)
            {
                fprintf(archivo,"HOMBRE");
            }
            else 
            {
                if (strcmp(almacen[j].sexo, "M") == 0 || strcmp(almacen[j].sexo, "FEMENINO") == 0)
                {
                    fprintf(archivo,"MUJER");
                }
            }
            fprintf(archivo, "\n");
        }
    }
    fclose(archivo);
} 

/*  Ingresa el nombre del archivo. Luego utiliza la funcion "sprintf" para hacer un comando con el formato 
"churrumais.exe %s", donde (%s) es el nombre del archivo. Despues ejecuta el comando mediante "system" para 
obtener el contador de registros en el archivo y muestra esta info en la salida estandar.*/
void contador_registros()
{
    int contador;
    char nombre_archivo[50];
    char cmd[50];
    do
    {
        preguntar("INGRESE NOMBRE DEL ARCHIVO: ",nombre_archivo);
    } while (ValidarNombre(nombre_archivo) == -1);

    sprintf(cmd,"churrumais.exe %s", nombre_archivo);
    contador = system(cmd);
    
    if (contador != -1)
    {
        printf("ACTUALMENTE EL ARCHIVO %s CONTIENE %d REGISTROS.\n", nombre_archivo, contador);
    }
    else
    {
        printf("NO SE ENCONTRO EL ARCHIVO\n");
    }
}

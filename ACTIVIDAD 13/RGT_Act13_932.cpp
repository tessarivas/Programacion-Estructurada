/*
NOMBRE: Teresa Rivas Gomez
MATRICULA: 372565
FECHA: Nov - 14 - 2023 / Nov - 19 - 2023
DESCRIPCION: ARCHIVOS BINARIOS
NOMBRE DEL ARCHIVO: RGT_Act13_932.cpp
*/

#include "birote.h"

#define REGISTROS 5000

int menu_mensaje();
int menu();

Tdatos modificar_registros(Tdatos almacen[], int i);
void eliminar_registro(Tdatos almacen[], int i);
int busqueda(Tdatos almacen[], int i);
int busqueda2(Tdatos almacen[], int i);
int seleccion_temporal( Tdatos almacen[], int tamaño);
int seleccion(Tdatos almacen[], int ri, int rf);
int imprimir_registro(Tdatos almacen[], int i);
void copiar_registro_texto(Tdatos almacen[], int i, char nombre_direccion[]);
void ver_registro(char cadena[]);
int crear_binario(Tdatos almacen[], int i, char cadena[]);
int cargar_binario(Tdatos almacen[], int i, int max, char cadena[]);
int imprimir_eliminados(Tdatos almacen[], int i) ;

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int menu_mensaje()
{
    int opcion;
    system("CLS");
    printf("ACTIVIDAD: SEMANA 15\n");
    printf("-------------------------\n");
    printf("ARCHIVO DE TEXTO\n");
    printf("1.- AGREGAR\n");
    printf("2.- EDITAR\n");
    printf("3.- ELIMINAR\n");
    printf("4.- BUSCAR\n");
    printf("5.- ORDENAR\n");
    printf("6.- IMPRIMIR\n");
    printf("7.- GENERAR\n");
    printf("8.- VER\n");
    printf("-------------------------\n");
    printf("ARCHIVO BINARIO\n");
    printf("9.- CREAR\n");
    printf("10.- CARGAR\n");
    printf("-------------------------\n");
    printf("11.- ELIMINADOS\n");
    printf("-------------------------\n");
    printf("0.- SALIR\n");
    opcion = ValidarCadena("OPCION QUE ELEGISTE(0-10):\n", 0, 11);
    return opcion;
}

int menu()
{
    int i = 0;
    int orden;
    int opcion;
    int editar;
    int decision;
    int encontrar;
    int resultado;
    char nombre[15];
    Tdatos almacen[REGISTROS];
    Tdatos _datos;
    do {
        opcion = menu_mensaje();
        system("CLS");
        switch(opcion)
        {
            case 1:
                printf("AGREGAR\n");
                if(i + 100 <= REGISTROS)
                {
                    for (int j = 0; j < 100; j++)
                        {
                            if (i < REGISTROS)
                            {
                                _datos = generar_datos_random(_datos);
                                while (busqueda_secuencial(almacen, i, _datos.matricula) != -1)
                                {
                                    _datos.matricula = (rand() % 7000) + 2000;
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
            case 2:
                printf("EDITAR\n");
                editar = ValidarCadena("INGRESA LA MATRICULA DEL ALUMNO A EDITAR: \n", 2000, 7000);
                encontrar = busqueda_secuencial(almacen, i, editar);

                if(encontrar != -1) 
                {
                    printf("MATRICULA ENCONTRADA\n");
                    if (almacen[encontrar].status == 1)
                    {
                        Tdatos copia = almacen[encontrar];

                        printf("MATRICULA: %d\n", copia.matricula);
                        printf("PUESTO DE TRABAJO: %s\n", copia.puesto);
                        printf("NOMBRES: %s\n", copia.nombre);
                        printf("APELLIDOS: %s %s\n", copia.apellido1, copia.apellido2);
                        printf("EDAD: %d\n", copia.edad);

                        decision = ValidarCadena("ESTAS SEGURO QUE DESEAS EDITAR ESTE REGISTRO?\n[1] SI\n[2] NO\n", 1, 2);

                        if (decision == 1)
                        {
                            almacen[encontrar] = modificar_registros(almacen, encontrar);
                            printf("LA MATRICULA %i HA SIDO EDITADA.\n", editar);
                        }
                        break;
                    }
                }
                orden = 0;
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
                printf("IMPRIMIR\n");
                imprimir_registro(almacen, i);
                system("PAUSE");
                break;
            case 7:
                printf("GENERAR\n");
                printf("INGRESA EL NOMBRE DE TU NUEVO ARCHIVO: \n");
                fflush(stdin);
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0'; 
                copiar_registro_texto(almacen, i, nombre);
                system("PAUSE");
                break;
            case 8:
                printf("VER\n");
                printf("INGRESA EL NOMBRE DE TU NUEVO ARCHIVO: \n");
                fflush(stdin);
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0';
                ver_registro(nombre);
                system("PAUSE");
                break;
            case 9:
                printf("CREAR\n");
                printf("INGRESA EL NOMBRE DE TU NUEVO ARCHIVO: \n");
                fflush(stdin);
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0';
                resultado = crear_binario(almacen, i, nombre);
                if (resultado != 0)
                {
                    printf("NO SE PUDO CREAR EL ARCHIVO.\n");
                    return -1;
                }
                else
                {
                    printf("ARCHIVO CREADO CORRECTAMENTE.\n");
                    return 0;
                }
                respaldo_binario(nombre);
                system("PAUSE");
                break;
            case 10:
                printf("CARGAR\n");
                printf("INGRESA EL NOMBRE DE TU NUEVO ARCHIVO: \n");
                fflush(stdin);
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0';
                strcat(nombre, ".dll");
                i = cargar_binario(almacen, i, REGISTROS, nombre);
                system("PAUSE");
                break;
            case 11:
                printf("ELIMINADOS\n");
                imprimir_eliminados(almacen, i);
                system("PAUSE");
                break;
            case 0:
                printf("SALISTE DEL PROGRAMA.\n");
                break;
        }
    } while(opcion != 0);
}

/* EDITAR */
Tdatos modificar_registros(Tdatos almacen[], int i)
{
    int dato;
    dato = ValidarCadena("QUE DATO DESEAS EDITAR?\n[1]NOMBRE\n[2]PRIMER APELLIDO\n[3]SEGUNDO APELLIDO\n[4]EDAD\n[5]PUESTO\n", 1, 5);

    switch (dato)
    {
        case 1:
            printf("INGRESA EL NUEVO NOMBRE: \n");
            ciclo(almacen[i].nombre);
            break;
        case 2:
            printf("INGRESA EL NUEVO PRIMER APELLIDO: \n");
            ciclo(almacen[i].apellido1);
            break;
        case 3:
            printf("INGRESA EL NUEVO SEGUNDO APELLIDO: \n");
            ciclo(almacen[i].apellido2);
            break;
        case 4:
            printf("INGRESA LA NUEVA EDAD: \n");
            almacen[i].edad = ValidarCadena("INGRESA LA NUEVA EDAD: \n", 18, 100);
            break;
        case 5:
            printf("INGRESA EL NUEVO PUESTO: \n");
            ciclo(almacen[i].puesto);
            break;
    }

    return almacen[i];
}

/* ELIMINAR */
void eliminar_registro(Tdatos almacen[], int i)
{
    int borrar;
    int decision;
    int encontrar;
    borrar = ValidarCadena("INGRESA LA MATRICULA DEL ALUMNO A ELIMINAR: \n", 2000, 7000);
    encontrar = busqueda_secuencial(almacen, i, borrar);

    if(encontrar != -1) 
    {
        printf("MATRICULA ENCONTRADA\n");
        if (almacen[encontrar].status == 1)
        {
            Tdatos copia = almacen[encontrar];

            printf("MATRICULA: %d\n", copia.matricula);
            printf("PUESTO DE TRABAJO: %s\n", copia.puesto);
            printf("NOMBRES: %s\n", copia.nombre);
            printf("APELLIDOS: %s %s\n", copia.apellido1, copia.apellido2);
            printf("EDAD: %d\n", copia.edad);

            decision = ValidarCadena("ESTAS SEGURO QUE DESEAS ELIMINAR ESTE REGISTRO?\n[1] SI\n[2] NO\n", 1, 2);

            if (decision == 1)
            {
                almacen[encontrar].status = 0;
                printf("LA MATRICULA %i HA SIDO ELIMINADA.\n", borrar);
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

/* BUSQUEDA SECUENCIAL */
int busqueda(Tdatos almacen[], int i)
{
    printf("BUSQUEDA SECUENCIAL\n");

    int matricula = ValidarCadena("MATRICULA QUE DESEAS BUSCAR: \n", 2000, 7000);
    int posicion = busqueda_secuencial(almacen, i, matricula);

    if (posicion == -1)
    {
        printf("NO SE ENCONTRO LA MATRICULA\n");
    }
    else
    {
        printf("LA MATRICULA %d ESTA EN EL REGISTRO: %d\n", matricula, posicion + 1);
        printf("MATRICULA: %d\n", almacen[posicion].matricula);
        printf("PUESTO DE TRABAJO: %s\n", almacen[posicion].puesto);
        printf("NOMBRE: %s\n", almacen[posicion].nombre);
        printf("APELLIDOS: %s %s\n", almacen[posicion].apellido1, almacen[posicion].apellido2);
        printf("TELEFONO: (646)%s\n", almacen[posicion].telefono);
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

/* BUSQUEDA BINARIA */
int busqueda2(Tdatos almacen[], int i)
{
    printf("BUSQUEDA BINARIA\n");
    int matricula = ValidarCadena("MATRICULA QUE DESEAS BUSCAR: \n", 2000, 7000);
    int posicion = busqueda_binaria(almacen, 0, i - 1, matricula);

    if(posicion == -1)
    {
        printf("NO SE ENCONTRO LA MATRICULA\n");
    }
    else
    {
        printf("LA MATRICULA %d ESTA EN EL REGISTRO: %d\n", matricula, posicion + 1);
        printf("MATRICULA: %d\n", almacen[posicion].matricula);
        printf("PUESTO DE TRABAJO: %s\n", almacen[posicion].puesto);
        printf("NOMBRE: %s\n", almacen[posicion].nombre);
        printf("APELLIDOS: %s %s\n", almacen[posicion].apellido1, almacen[posicion].apellido2);
        printf("TELEFONO: (646)%s\n", almacen[posicion].telefono);
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

/* ORDENAR */
int seleccion_temporal(Tdatos almacen[], int tamaño)
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

/* IMPRIMIR */
int imprimir_registro(Tdatos almacen[], int i) 
{
    int j;
    int status_uno = 0;

    system("CLS");
    printf("REGISTRO DE ALUMNOS\n");
    printf("+---------+--------+-----------+------------+------------------+------------------+---------------------+------------------+----------+----------+\n");
    printf("| NO. REG | STATUS | MATRICULA |   PUESTO   | APELLIDO PATERNO | APELLIDO MATERNO |      NOMBRE(S)      |     TELEFONO     |   EDAD   |   SEXO   |\n");
    printf("+---------+--------+-----------+------------+------------------+------------------+---------------------+------------------+----------+----------+\n");

    for (j = 0, status_uno = 0; j < i; j++) 
    {
        if (almacen[j].status == 1) 
        {
            printf("| %-6d  | %-5d  | %-9d | %-10s | %-16s | %-16s | %-19s | %-16s | %-6d   | ", 
                j + 1,
                almacen[j].status,
                almacen[j].matricula,
                almacen[j].puesto,
                almacen[j].apellido1,
                almacen[j].apellido2,
                almacen[j].nombre,
                almacen[j].telefono,
                almacen[j].edad
            );
            if (strcmp(almacen[j].sexo, "H") == 0 || strcmp(almacen[j].sexo, "MASCULINO") == 0)
            {
                printf("HOMBRE   |");
            }
            else if (strcmp(almacen[j].sexo, "M") == 0 || strcmp(almacen[j].sexo, "FEMENINO") == 0)
            {
                printf("MUJER    |");
            }
            printf("\n");
            status_uno++;
        }

        if ((status_uno) % 40 == 0) 
        {
            if(status_uno < i)
            {
            printf("+---------+--------+-----------+------------+------------------+------------------+---------------------+------------------+----------+----------+\n");
            printf("PRESIONA (ENTER) PARA VER MAS...\n");
            getchar();
            system("CLS");
            printf("REGISTROS %d - %d\n\n", status_uno + 1, (status_uno + 40) > i ? i : (status_uno + 40));
            printf("+---------+--------+-----------+------------+------------------+------------------+---------------------+------------------+----------+----------+\n");
            printf("| NO. REG | STATUS | MATRICULA |   PUESTO   | APELLIDO PATERNO | APELLIDO MATERNO |      NOMBRE(S)      |     TELEFONO     |   EDAD   |   SEXO   |\n");
            printf("+---------+--------+-----------+------------+------------------+------------------+---------------------+------------------+----------+----------+\n");
            }
        }
    }
    return 0;
}

/* GENERAR */
void copiar_registro_texto(Tdatos almacen[], int i, char nombre_direccion[])
{
    char direccion[1000];
    strcpy(direccion, "C:\\Users\\52616\\OneDrive\\Documentos\\U A B C\\3er Semestre\\Programacion Estructurada\\Actividad 13\\");
    strcat(direccion, nombre_direccion);
    strcat(direccion, ".txt");

    FILE *archivo = fopen(direccion, "w");

    if (archivo == NULL) 
    {
        printf("ERROR AL ABRIR EL ARCHIVO.\n");
        return;
    }

    fprintf(archivo,"+---------+--------+-----------+------------+------------------+------------------+---------------------+------------------+----------+----------+\n");
    fprintf(archivo,"| NO. REG | STATUS | MATRICULA |   PUESTO   | APELLIDO PATERNO | APELLIDO MATERNO |      NOMBRE(S)      |     TELEFONO     |   EDAD   |   SEXO   |\n");
    fprintf(archivo,"+---------+--------+-----------+------------+------------------+------------------+---------------------+------------------+----------+----------+\n");

    for (int j = 0; j < i; j++) 
    {
        if (almacen[j].status == 1)
        {
            fprintf(archivo, "%3d.-      %-8d  %-10d  %-10s   %-17s  %-17s  %-20s  %-17s  %-6d     ", 
            j + 1,
            almacen[j].status,
            almacen[j].matricula,
            almacen[j].puesto,
            almacen[j].apellido1,
            almacen[j].apellido2,
            almacen[j].nombre,
            almacen[j].telefono,
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

/* VER */
void ver_registro(char cadena[])
{
    char nombre_direccion[1000];
    char caracter; 

    strcpy(nombre_direccion, "C:\\Users\\52616\\OneDrive\\Documentos\\U A B C\\3er Semestre\\Programacion Estructurada\\Actividad 13\\output\\");
    strcat(nombre_direccion, cadena);
    strcat(nombre_direccion, ".txt");
    printf("%s\n", nombre_direccion);

    FILE *archivo = fopen(nombre_direccion, "r");

    if (archivo == NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO\n");
        return;
    }

    do {
        caracter = fgetc(archivo);
        printf("%c", caracter);
    } while (!feof(archivo));

    fclose(archivo);
}

/* CREAR */
/* Crea un archivo binario y escribe en el los datos almacenados en un array de estructuras (almacen). Como
parametros tenemos el array almacen para los datos almacenados, i para la cantidad y una cadena para escribir
el nombre del archivo binario que se va a crear. Se abre con el modo de escritura binaria que es "wb". */
int crear_binario(Tdatos almacen[], int i, char cadena[])
{
    int j;
    Tdatos _datos;

    char nombre_direccion[1000];
    strcpy(nombre_direccion, "C:\\Users\\52616\\OneDrive\\Documentos\\U A B C\\3er Semestre\\Programacion Estructurada\\Actividad 13\\output\\");
    strcat(nombre_direccion, cadena);
    strcat(nombre_direccion, ".dll");

    FILE *archivo_binario;

    archivo_binario = fopen(nombre_direccion, "wb");

    for (j = 0; j < i; j++)
    {
        _datos = almacen[j];
        fwrite(&_datos, sizeof(Tdatos), 1, archivo_binario);
    }

    fclose(archivo_binario);
    return 0;
}

/* CARGAR */
/* Carga datos desde un archivo binario y los almacena en un array de estructuras (almacen). Tiene los mismos parametros
que la funcion anterior pero aqui añadi un entero "max" para la cantidad maxima que tiene el array y se abre el archivo
binario en modo de lectura "lb", para despues almacenarlos en el array (almacen). */
int cargar_binario(Tdatos almacen[], int i, int max, char cadena[])
{
    Tdatos _datos;
    FILE *binario;
    binario = fopen(cadena, "rb");

    if (binario)
    {

        while (fread(&_datos, sizeof(Tdatos), 1, binario))
        {
            if (i < max)
            {
                almacen[i] = _datos;
                i++;
            }
        }

        fclose(binario);
        printf("ARCHIVO ABIERTO CORRECTAMENTE\n");
        return i;
    }
    else
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO\n");
        return -1;
    }
}

/* ELIMINADOS */
int imprimir_eliminados(Tdatos almacen[], int i) 
{
    int j;
    int eliminados = 0;

    system("CLS");
    printf("+---------+--------+-----------+------------+------------------+------------------+---------------------+------------------+----------+----------+\n");
    printf("| NO. REG | STATUS | MATRICULA |   PUESTO   | APELLIDO PATERNO | APELLIDO MATERNO |      NOMBRE(S)      |     TELEFONO     |   EDAD   |   SEXO   |\n");
    printf("+---------+--------+-----------+------------+------------------+------------------+---------------------+------------------+----------+----------+\n");

    for (j = 0, eliminados = 0; j < i; j++) 
    {
        if (almacen[j].status == 0) 
        {
            printf("| %-6d  | %-5d  | %-9d | %-10s | %-16s | %-16s | %-19s | %-16s | %-6d   | ", 
                j + 1,
                almacen[j].status,
                almacen[j].matricula,
                almacen[j].puesto,
                almacen[j].apellido1,
                almacen[j].apellido2,
                almacen[j].nombre,
                almacen[j].telefono,
                almacen[j].edad
            );
            if (strcmp(almacen[j].sexo, "H") == 0 || strcmp(almacen[j].sexo, "MASCULINO") == 0)
            {
                printf("HOMBRE   |");
            }
            else if (strcmp(almacen[j].sexo, "M") == 0 || strcmp(almacen[j].sexo, "FEMENINO") == 0)
            {
                printf("MUJER    |");
            }
            printf("\n");
            eliminados++;
        }
    }
    return 0;
}

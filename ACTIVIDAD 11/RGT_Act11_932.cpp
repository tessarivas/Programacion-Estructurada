/*
NOMBRE: Teresa Rivas Gomez
MATRICULA: 372565
FECHA: Nov - 01 - 2023
DESCRIPCION: FUNCIONES y METODOS DE ORDENACION Y BUSQUEDA ESTRUCTURAS Y LIBRERIAS (p2)
NOMBRE DEL ARCHIVO: RGT_Act11_932.cpp
*/

#include "costco.h"

#define REGISTROS 2000

int menu_mensaje();
int menu();

int imprimir_registro(Tdatos almacen[], int i);
void eliminar_registro(Tdatos almacen[], int i);
int busqueda(Tdatos almacen[], int i);
int busqueda2(Tdatos almacen[], int i);
int seleccion_temporal( Tdatos almacen[], int tamaño);
int seleccion(Tdatos almacen[], int ri, int rf);
void copiar_registro_texto(Tdatos almacen[], int i);

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
    printf ("ACTIVIDAD: SEMANA 12\n");
    printf("1.- AGREGAR\n");
    printf("2.- ELIMINAR REGISTRO\n");
    printf("3.- BUSCAR\n");
    printf("4.- ORDENAR\n");
    printf("5.- IMPRIMIR\n");
    printf("6.- ARCHIVO TEXTO\n");
    printf("0.- SALIR\n");
    opcion = ValidarCadena("OPCION QUE ELEGISTE(0-6):\n", 0, 6);
    return opcion;
}

int menu()
{
    int i = 0;
    int orden;
    int opcion;
    int subopcion;
    Tdatos almacen[REGISTROS];
    Tdatos _datos;
    do {
        opcion = menu_mensaje();
        system("CLS");
        switch(opcion)
        {
            case 1:
                printf("AGREGAR\n");
                do {
                    system("CLS");
                    printf("AGREGAR:\n");
                    printf("1.- MANUAL\n");
                    printf("2.- AUTOMATICO\n");
                    printf("3.- REGRESAR\n");
                    subopcion = ValidarCadena("OPCION QUE ELEGISTE(1-3):\n", 1, 3);
                    switch (subopcion) 
                    {
                        case 1:
                            if(i >= REGISTROS)
                            {
                                printf("YA HAZ LLENADO TODOS LOS REGISTROS\n");
                            }
                            else
                            {
                                if (i + 1 < REGISTROS)
                                {
                                    _datos = generar_datos_manual(_datos);

                                    while(busqueda_secuencial(almacen, i, _datos.matricula) != -1)
                                    {
                                        _datos.matricula = (rand() % 399999) + 300000;
                                    }

                                    almacen[i] = _datos;
                                    i++;
                                }
                            }
                            printf("SE AÑADIO CORRECTAMENTE\n");

                            orden = 0;
                            system("PAUSE");
                            break;
                        case 2:
                            printf("AUTOMATICO\n");
                            int j;
                            for (j = 0; j < 100; j++)
                            {
                                if (i < REGISTROS)
                                {
                                    _datos = generar_datos_random(_datos);

                                    while(busqueda_secuencial(almacen, i, _datos.matricula) != -1)
                                    {
                                        _datos.matricula = (rand() % 399999) + 300000;
                                    }

                                    almacen[i] = _datos;
                                    i++;
                                }
                            }
                            printf("LOS REGISTROS HAN SIDO AGREGADOS CORRECTAMENTE\n");

                            orden = 0;
                            system("PAUSE");
                            break;
                        case 3:
                            break;
                    }
                } while (subopcion != 3);
                break;
            case 2:
                printf("ELIMINAR REGISTRO\n");
                eliminar_registro(almacen, i);
                system("PAUSE");
                break;
            case 3:
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
            case 4:
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
            case 5:
                printf("IMPRIMIR\n");
                imprimir_registro(almacen, i);
                system("PAUSE");
                break;
            case 6:
                printf("ARCHIVO TEXTO\n");
                copiar_registro_texto(almacen, i);
                system("PAUSE");
                break;
            case 0:
                printf("SALISTE DEL PROGRAMA.\n");
                break;
        }
    } while(opcion != 0);
}

int imprimir_registro(Tdatos almacen[], int i) 
{
    int j;
    int status_uno = 0;

    system("CLS");
    printf("REGISTRO DE ALUMNOS\n");
    printf("+---------+-----------+------------------+------------------+---------------------+------------+----------+----------+----------------------+\n");
    printf("| NO. REG | MATRICULA | APELLIDO PATERNO | APELLIDO MATERNO |      NOMBRE(S)      | NACIMIENTO |   EDAD   |   SEXO   |         CURP         |\n");
    printf("+---------+-----------+------------------+------------------+---------------------+------------+----------+----------+----------------------+\n");

    for (j = 0, status_uno = 0; j < i; j++) 
    {
        if (almacen[j].status == 1) 
        {
            printf("| %-6d  | %-9d | %-16s | %-16s | %-19s | %02d/%02d/%04d | ", 
                j + 1,
                almacen[j].matricula,
                almacen[j]._nombre.apellido1,
                almacen[j]._nombre.apellido2,
                almacen[j]._nombre.nombres,
                almacen[j]._fecha.dia,
                almacen[j]._fecha.mes,
                almacen[j]._fecha.anio
            );

            if (almacen[j].edad == -1) 
            {
                printf(" MESES  | ");
            } 
            else 
            {
                if (almacen[j].edad < 10) 
                {
                    printf("   0%d    | ", almacen[j].edad);
                } else {
                    printf("   %d    | ", almacen[j].edad);
                }
            }

            if (almacen[j].sex == 1)
            {
                printf(" HOMBRE  | ");
            }
            else
            {
                if (almacen[j].sex == 2)
                {
                    printf(" MUJER   | ");
                }
            }
            generar_datos_curp(almacen[j]);

            status_uno++;
        }

        if ((status_uno) % 40 == 0) 
        {
            if(status_uno < i)
            {
            printf("+---------+-----------+------------------+------------------+---------------------+------------+----------+----------+----------------------+\n");
            printf("PRESIONA (ENTER) PARA VER MAS...\n");
            getchar();
            system("CLS");
            printf("REGISTROS %d - %d\n\n", status_uno + 1, (status_uno + 40) > i ? i : (status_uno + 40));
            printf("+---------+-----------+------------------+------------------+---------------------+------------+----------+----------+----------------------+\n");
            printf("| NO. REG | MATRICULA | APELLIDO PATERNO | APELLIDO MATERNO |      NOMBRE(S)      | NACIMIENTO |   EDAD   |   SEXO   |         CURP         |\n");
            printf("+---------+-----------+------------------+------------------+---------------------+------------+----------+----------+----------------------+\n");
            }
        }
    }
    return 0;
}

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
            printf("FECHA DE NACIMIENTO: %02d/%02d/%04d\n", copia._fecha.dia, copia._fecha.mes, copia._fecha.anio);
            printf("EDAD: %d\n", copia.edad);
            printf("ESTADO DE REGISTRO: %s\n", copia.estado);
            generar_datos_curp(copia);

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
            printf("LA MATRICULA %i YA HA SIDO REMOVIDA\n", borrar);
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
        printf("FECHA DE NACIMIENTO: %02d/%02d/%04d\n", almacen[posicion]._fecha.dia, almacen[posicion]._fecha.mes, almacen[posicion]._fecha.anio);
        printf("EDAD: %d\n", almacen[posicion].edad);
        if (almacen[posicion].sex == 1)
        {
            printf("SEXO: HOMBRE\n");
        }
        else
        {
            printf("SEXO: MUJER\n");
        }
        printf("ESTADO DE REGISTRO: %s\n", almacen[posicion].estado);
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
        printf("FECHA DE NACIMIENTO: %02d/%02d/%04d\n", almacen[posicion]._fecha.dia, almacen[posicion]._fecha.mes, almacen[posicion]._fecha.anio);
        printf("EDAD: %d\n", almacen[posicion].edad);
        if (almacen[posicion].sex == 1)
        {
            printf("SEXO: HOMBRE\n");
        }
        else
        {
            printf("SEXO: MUJER\n");
        }
        printf("ESTADO DE REGISTRO: %s\n", almacen[posicion].estado);
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

void copiar_registro_texto(Tdatos almacen[], int i) 
{
    FILE *archivo;
    archivo = fopen("C:\\Users\\52616\\OneDrive\\Documentos\\U A B C\\3er Semestre\\Programacion Estructurada\\Actividad 11\\registros.txt", "w");

    if (archivo == NULL) 
    {
        printf("ERROR AL ABRIR EL ARCHIVO.\n");
        return;
    }

    fprintf(archivo, "REGISTRO DE ALUMNOS\n");
    fprintf(archivo, "+---------+-----------+------------------+------------------+---------------------+------------+----------+----------+----------------------+\n");
    fprintf(archivo, "| NO. REG | MATRICULA | APELLIDO PATERNO | APELLIDO MATERNO |      NOMBRE(S)      | NACIMIENTO |   EDAD   |   SEXO   |         CURP         |\n");
    fprintf(archivo, "+---------+-----------+------------------+------------------+---------------------+------------+----------+----------+----------------------+\n");

    for (int j = 0; j < i; j++) 
    {
        if (almacen[j].status == 1) 
        {
            fprintf(archivo, "| %-6d  | %-9d | %-16s | %-16s | %-19s | %02d/%02d/%04d | ", 
                j + 1,
                almacen[j].matricula,
                almacen[j]._nombre.apellido1,
                almacen[j]._nombre.apellido2,
                almacen[j]._nombre.nombres,
                almacen[j]._fecha.dia,
                almacen[j]._fecha.mes,
                almacen[j]._fecha.anio
            );

            if (almacen[j].edad == -1) 
            {
                fprintf(archivo, " MESES  | ");
            } 
            else 
            {
                if(almacen[j].edad < 10) 
                {
                    fprintf(archivo, "   0%d    | ", almacen[j].edad);
                } 
                else 
                {
                    fprintf(archivo, "   %d    | ", almacen[j].edad);
                }
            }

            if (almacen[j].sex == 1)
            {
                fprintf(archivo, " HOMBRE  | ");
            }
            else
            {
                if (almacen[j].sex == 2)
                {
                    fprintf(archivo, " MUJER   | ");
                }
            }
            generar_datos_curp_texto(almacen[j], archivo);
        }
    }
    fclose(archivo);
    printf("Los registros se han copiado al archivo 'registros.txt'.\n");
}

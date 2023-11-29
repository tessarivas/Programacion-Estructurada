/*
NOMBRE: Teresa Rivas Gomez
MATRICULA: 372565
FECHA: Nov - 21 - 2023 / Nov - 28 - 2023
DESCRIPCION: ARCHIVOS BINARIOS
NOMBRE DEL ARCHIVO: RGT_Act13_932.cpp
*/

#include "tulipan.h"

int menu_mensaje();
int menu();

/* FUNCIONES EMPLEADAS */
int contar_registros();
int indice_agregar(Tindice indice[], int i, int REGISTROS);
void eliminar_registro(Tindice indice[], int i, int matricula, int orden);
void buscar(Tindice indice[], int i);
int buscar_binaria(Tindice indice[], int i);
void ordenacion1(Tindice indice[], int l, int r);
int ordenacion2(Tindice indice[], int tamano);
int ordenacion3(Tindice indice[], int ri, int rf);
void imprimir_registros(Tindice indice[], int i, int ord);
void generar_archivo_texto(char nombre[], Tindice indice[], int i, int orden);
void empaquetar();

/* MENU PRINCIPAL */
int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

/* FUNCION QUE EMITE LOS MENSAJES DEL MENU AL USUARIO PARA QUE PROCEDA A ELEGIR LA ACCION QUE DESEA REALIZAR.*/
int menu_mensaje()
{
    int opcion;
    system("CLS");
    printf("         ACTIVIDAD 15: SEMANA 16       \n");
    printf("---------------------------------------\n");
    printf("1.- AGREGAR\n");
    printf("2.- ELIMINAR\n");
    printf("3.- BUSCAR\n");
    printf("4.- ORDENAR\n");
    printf("5.- IMPRIMIR REGISTROS ARCHIVO ORIGINAL\n");
    printf("6.- IMPRIMIR REGISTROS ARCHIVO ORDENADO\n");
    printf("7.- GENERAR ARCHIVO DE TEXTO\n");
    printf("8.- EMPAQUETAR\n");
    printf("---------------------------------------\n");
    printf("0.- SALIR\n");
    opcion = ValidarCadena("OPCION QUE ELEGISTE(0-8):\n", 0, 8);
    return opcion;
}

/* CASOS DEPENDIENDO LA OPCION SELECCIONADA EN EL MENU, SE APLICA UN SWITCH PARA EL CAMBIO DE CASOS SEGUN SEA. */
int menu()
{
    int REGISTROS = 0;
    REGISTROS = contar_registros();
    int i = 0;
    REGISTROS += REGISTROS * 0.25;
    Tindice indice[REGISTROS];
    i = indice_registro(indice, i);
    int orden = 0;
    int op;
    int opcion;
    int borrar;
    char nombre[50];
    
    // CONTAR REGISTROS
    system("CLS");
    crear_archivo("datos.dat", "indices.dat");
    printf("CANTIDAD DE REGISTROS: %d\n", REGISTROS);
    system("PAUSE");

    do {
        opcion = menu_mensaje();
        system("CLS");
        switch(opcion)
        {
            case 1:
                printf("AGREGAR\n");
                i = indice_agregar(indice, i, REGISTROS);
                orden = 0;
                system("PAUSE");
                break;
            case 2:
                printf("ELIMINAR\n");
                borrar = ValidarCadena("INGRESA LA CLAVE DEL EMPLEADO QUE DESEAS REMOVER: \n", 300000, 399999);
                eliminar_registro(indice, i, borrar, orden);
                break;
            case 3:
                printf("BUSCAR\n");
                if (orden == 0)
                {
                    buscar(indice, i);
                }
                else
                {
                    buscar_binaria(indice, i);
                    system("PAUSE");
                }
                break;
            case 4:
                printf("ORDENAR\n");
                if (orden == 0)
                {
                    if (i < 100)
                    {
                        ordenacion1(indice, 0, i - 1);
                    }
                    if (i > 100)
                    {
                        if (i < 1500)
                        {
                            ordenacion2(indice, i);
                        }
                    }
                    if (i > 1500)
                    {
                        if (i < 10000)
                        {
                            ordenacion3(indice, 0, i - 1);
                        }
                    }
                    printf("SE HA ORDENADO CORRECTAMENTE.\n");
                    orden = 1;
                    system("PAUSE");
                    break;
                }
            case 5:
                printf("IMPRIMIR REGISTROS ARCHIVO ORIGINAL\n");
                imprimir_registros(indice, i, 0);
                system("PAUSE");
                break;
            case 6:
                printf("IMPRIMIR REGISTROS ARCHIVO ORDENADO\n");
                imprimir_registros(indice, i, 1);
                system("PAUSE");
                break;
            case 7:
                printf("GENERAR ARCHIVO DE TEXTO\n");
                printf("INGRESA EL NOMBRE DEL ARCHIVO DE TEXTO:\n");
                fflush(stdin);
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0';
                printf("DE QUE MANERA DESEAS CREAR EL ARCHIVO?\n[1]ORDENADO\n[2]NORMAL\n");
                op = ValidarCadena("INGRESA UNA OPCION(1|2):\n", 1, 2);
                generar_archivo_texto(nombre, indice, i, op);
                break;
            case 8:
                printf("EMPAQUETAR\n");
                empaquetar();
                break; 
            case 0:
                printf("SALISTE DEL PROGRAMA.\n");
                break;
        }
    } while(opcion != 0);
}

/* FUNCION PARA CANTIDAD DE REGISTROS */
int contar_registros()
{
    int contador;
    char cmd[50];

    sprintf(cmd,"REGISTROS.exe %s", "datos.dat");
    contador = system(cmd);
    
    if (contador != -1)
    {
        printf("ACTUALMENTE EL ARCHIVO CONTIENE %d REGISTROS.\n", contador);
    }
    else
    {
        printf("NO SE ENCONTRO EL ARCHIVO\n");
    }

    return contador;
}

/* AGREGAR */
int indice_agregar(Tindice indice[], int i, int REGISTROS)
{
    Tdatos datos;

    if (i < REGISTROS)
    {
        datos = generar_datos_random(datos);

        while (secuencial(indice, i, datos.matricula) != -1)
        {
            datos.matricula = (rand() % 399999) + 300000;
        }

        FILE *binario;

        binario = fopen("datos.dat", "ab+");
        if (binario == NULL)
        {
            printf("ERROR AL ABRIR EL ARCHIVO.\n");
            return i;
        }

        fwrite(&datos, sizeof(Tdatos), 1, binario);
        fclose(binario);

        FILE *indice_archivo;
        indice_archivo = fopen("indices.dat", "ab");

        if (indice_archivo == NULL)
        {
            printf("ERROR AL ABRIR EL ARCHIVO DE INDICES.\n");
            return i;
        }

        Tindice indice_registro;
        indice_registro.matricula = datos.matricula;

        fwrite(&indice_registro, sizeof(Tindice), 1, indice_archivo);
        fclose(indice_archivo);

        indice[i].matricula = datos.matricula;
        indice[i].indice = i;
        i++;
        printf("SE HA AGREGADO EL REGISTRO CORRECTAMENTE.\n");
    }
    else
    {
        printf("YA HAS LLENADO TODOS LOS REGISTROS.\n");
    }

    return i;
}

/* ELIMINAR */
void eliminar_registro(Tindice indice[], int i, int matricula, int orden)
{
    Tdatos datos;
    int buscar;
    int decidir;
    
    FILE *binario;

    if (orden == 0)
    {
        buscar = secuencial(indice, i, matricula);
    }
    else
    {
        buscar = binaria(indice, 0, i, matricula);
    }

    if (buscar != -1)
    {
        binario = fopen("datos.dat", "rb+");
        if (binario == NULL)
        {
            printf("ERROR AL ABRIR EL ARCHIVO.\n");
            return;
        }

        fseek(binario, indice[buscar].indice * sizeof(Tdatos), SEEK_SET);
        fread(&datos, sizeof(Tdatos), 1, binario);

        if (datos.status == 0)
        {
            printf("EL REGISTRO YA HA SIDO ELIMINADO.\n");
        }
        else
        {
            imprimir(datos);
            decidir = ValidarCadena("DESEAS ELIMINAR EL REGISTRO?\n[1]SI\n[2]NO\n", 1, 2);
            if (decidir == 1)
            {
                datos.status = 0;
                fseek(binario, -sizeof(Tdatos), SEEK_CUR); 
                fwrite(&datos, sizeof(Tdatos), 1, binario);
                printf("SE HA ELIMINADO EL REGISTRO CORRECTAMENTE.\n");
                system("PAUSE");
            }
            else
            {
                printf("LA MATRICULA NO HA SIDO ELIMINADA.\n");
                system("PAUSE");
            }
        }
        fclose(binario);
    }
    else
    {
        printf("NO SE ENCONTRO EL REGISTRO\n");
        system("PAUSE");
    }
}

/* BUSCAR */
void buscar(Tindice indice[], int i)
{
    printf("BUSQUEDA LINEAL/SECUENCIAL:\n");
    int matricula = ValidarCadena("MATRICULA QUE DESEAS BUSCAR: \n", 300000, 399999);
    int posicion = secuencial(indice, i, matricula);

    if (posicion == -1)
    {
        printf("NO SE ENCONTRO EL NUMERO.\n");
        system("PAUSE");
    }
    else
    {
        FILE *binario = fopen("datos.dat", "rb");

        if (binario == NULL)
        {
            printf("ERROR AL ABRIR EL ARCHIVO.\n");
            system("PAUSE");
            return;
        }

        fseek(binario, indice[posicion].indice * sizeof(Tdatos), SEEK_SET);

        Tdatos datos;
        fread(&datos, sizeof(Tdatos), 1, binario);

        fclose(binario);

        if (datos.status == 0)
        {
            printf("EL REGISTRO YA HA SIDO ELIMINADO.\n");
        }
        
        imprimir(datos);
        system("PAUSE");
    }
}

int buscar_binaria(Tindice indice[], int i)
{
    printf("BUSQUEDA BINARIA:\n");
    int matricula = ValidarCadena("MATRICULA QUE DESEAS BUSCAR: \n", 300000, 399999);
    int posicion = binaria(indice, 0, i - 1, matricula);

    if (posicion == -1)
    {
        printf("NO SE ENCONTRO EL NUMERO.\n");
    }
    else
    {
        FILE *binario = fopen("datos.dat", "rb");

        if (binario == NULL)
        {
            printf("ERROR AL ABRIR EL ARCHIVO.\n");
            return -1;
        }

        fseek(binario, indice[posicion].indice * sizeof(Tdatos), SEEK_SET);

        Tdatos datos;
        fread(&datos, sizeof(Tdatos), 1, binario);
        fclose(binario);

        imprimir(datos);
    }

    return -1;
}

/* ORDENAR */
void ordenacion1(Tindice indice[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        ordenacion1(indice, l, m);
        ordenacion1(indice, m + 1, r);

        fusion(indice, l, m, r);
    }
}

int ordenacion2(Tindice indice[], int tamano)
{
    Tindice temporal;
    int j;
    int k;
    for (j = 0; j < tamano - 1; j++)
    {
        for ( k = j + 1; k < tamano; k++)
        {
            if (indice[k].matricula < indice[j].matricula)
            {
                temporal = indice[j];
                indice[j] = indice[k];
                indice[k] = temporal;
            }
        }
    }
    return 1;
}

int ordenacion3(Tindice indice[], int ri, int rf)
{
    if (ri < rf)
    {
        int pi = particion(indice, ri, rf);

        ordenacion3(indice, ri, pi - 1);
        ordenacion3(indice, pi + 1, rf);
    }
    return -1;
}

/* IMPRIMIR */
void imprimir_registros(Tindice indice[], int i, int orden)
{
    FILE *archivo;
    Tdatos registro;

    if (orden == 0)
    {
        int j = 0;
        archivo = fopen("datos.dat", "rb");
        if (archivo)
        {
            while (fread(&registro, sizeof(Tdatos), 1, archivo))
            {
                if (registro.status == 1)
                {
                    printf("%-9d  %-11d  %-15s  %-20s  %-17s  %-7d  %-13s  %-18s  %-13s  %d\n", j++, registro.matricula, registro.nombre, registro.apellido1, registro.apellido2, registro.edad, registro.sexo, registro.puesto, registro.estado, registro.telefono);
                }
            }
            fclose(archivo);
        }
    }
    else
    {
        int k = 1; 
        ordenacion3(indice, 0, i - 1);
        archivo = fopen("datos.dat", "rb");
        if (archivo)
        {
            for (int m = 0; m < i; m++)
            {
                fseek(archivo, indice[m].indice * sizeof(Tdatos), SEEK_SET);
                fread(&registro, sizeof(Tdatos), 1, archivo);
                printf("%-9d  %-11d  %-15s  %-20s  %-17s  %-7d  %-13s  %-18s  %-13s  %d\n", k++, registro.matricula, registro.nombre, registro.apellido1, registro.apellido2, registro.edad, registro.sexo, registro.puesto, registro.estado, registro.telefono);
            }
            fclose(archivo);
        }
    }
}

/* ARCHIVO TEXTO */
void generar_archivo_texto(char nombre[], Tindice indice[], int i, int orden)
{
    FILE *binario;
    FILE *texto;
    Tdatos datos;

    binario = fopen("datos.dat", "rb");
    texto = fopen(nombre, "w");

    if (binario == NULL || texto == NULL)
    {
        printf("ERROR AL ABRIR EL ARCHIVO.\n");
        return;
    }

    int j;

    if (orden == 1)
    {
        ordenacion3(indice, 0, i - 1);
        for (j = 0; j < i; j++)
        {
            fseek(binario, indice[j].indice * sizeof(Tdatos), SEEK_SET);
            fread(&datos, sizeof(Tdatos), 1, binario);
            if (datos.status == 1)
            {
                fprintf(texto, "%d %s %s %s %s %s %s %d %d\n", datos.matricula, datos.nombre, datos.apellido1, datos.apellido2, datos.sexo, datos.puesto, datos.estado, datos.edad, datos.telefono);
            }
        }
    }
    else
    {
        while (fread(&datos, sizeof(Tdatos), 1, binario) == 1)
        {
            if (datos.status == 1)
            {
                fprintf(texto, "%d %s %s %s %s %s %s %d %d\n", datos.matricula, datos.nombre, datos.apellido1, datos.apellido2, datos.sexo, datos.puesto, datos.estado, datos.edad, datos.telefono);
            }
        }
    }

    fclose(binario);
    fclose(texto);

    printf("SE HA CREADO EL ARCHIVO: %s ,CORRECTAMENTE.\n", nombre);
}

/* EMPAQUETAR */
void empaquetar()
{
    FILE *documento = fopen("datos.dat", "rb");
    FILE *archivo = fopen("datos.bak", "wb");

    Tdatos datos;

    if(documento)
    {
        while (fread(&datos, sizeof(Tdatos), 1, documento))
        {
            if (datos.status == 1)
            {
                fwrite(&datos, sizeof(Tdatos), 1, archivo);
            }
        }
    }

    fclose(documento);
    fclose(archivo);
}

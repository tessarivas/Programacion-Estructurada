// Teresa Rivas Gómez 372565
// Sep - 05 - 2023
// RGT_Act3_932

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

//Funciones
int msges();
void menu();
void promedio(void);
void chinchampu1(void);
void chinchampu2(void);
void num_mayor(void);
void num_medio(void);
void num_menor(void);
void zodiaco(void);

int main()
{
    menu();
    zodiaco();

    return 0;
}

int msges()

{
    int op;
    printf("\n MENU \n");
    printf("1.- PROMEDIO \n");
    printf("2.- CHINCHAMPU \n");
    printf("3.- CHINCHAMPU 2.0 \n");
    printf("4.- NUMERO MAYOR \n");
    printf("5.- NUMERO MEDIO \n");
    printf("6.- NUMERO MENOR \n");
    printf("7.- SIGNO ZODIACAL \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
// Menu Principal
void menu()
{
    int op;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            promedio();
            break;
        case 2:
            chinchampu1();
            break;
        case 3:
            chinchampu2();
            break;
        case 4:
            num_mayor();
            break;
        case 5:
            num_medio();
            break;
        case 6:
            num_menor();
            break;
        case 7:
            zodiaco();
            break;
        }

    } while (op != 0);
}
// 1.- Programa en C que lea 3 calificaciones calcule el promedio del alumno y desplegar:
// Si prom < 30 Repetir. Si prom >=30 y prom <60 extraordinario. Si prom >=60 y prom <70 suficiente. Si prom >=70 y prom <80 Regular
// Si prom >=80 y prom <90 bien. Si prom >=90 y prom <98 muy bien. Si prom >=98 y prom <=100 excelente. Si prom >100 Error en promedio
void promedio(void)
{
        system("CLS");
        int cal1, cal2, cal3;
        float prom;

        printf("Ingrese la primera calificacion: \n");
        scanf("%d", &cal1);
        printf("Ingrese la segunda calificacion: \n");
        scanf("%d", &cal2);
        printf("Ingrese la tercera calificacion: \n");
        scanf("%d", &cal3);

        prom = (cal1 + cal2 + cal3) / 3.0;
        
        if (prom < 80)
    {
        if (prom < 60)
        {
            if (prom < 30)
            {
                printf("Repetir");
            }
            else
            {
                printf("Extraordinario");
            }
        }
        else
        {
            printf("Suficiente");
        }
    }
    else
    {
        if (prom < 98)
        {
            if (prom < 90)
            {
                printf("Bien");
            }
            else
            {
                printf("Muy Bien");
            }
        }
        else
        {
            printf("Excelente");
        }
    }
}
// 2.- Programa en C que sirva para el juego del CHINCHAMPU 
// (Piedra, Papel, Tijera) para 1 jugador y la computadora, 
// (usar condición anidada) 
void chinchampu1(void)
{
    int jugador, computadora;
    srand(time(NULL)); // Inicializar la semilla aleatoria

    printf("Bienvenido al juego del Chinchampu\n");
    printf("1. Piedra\n");
    printf("2. Papel\n");
    printf("3. Tijera\n");

    // El jugador elige su opción
    printf("Elije tu jugada (1-3): ");
    scanf("%d", &jugador);

    // Generar la elección aleatoria de la computadora (1-3)
    computadora = rand() % 3 + 1;

    // Mostrar las elecciones del jugador y la computadora
    printf("Jugador eligio: ");
    switch (jugador) {
        case 1:
            printf("Piedra\n");
            break;
        case 2:
            printf("Papel\n");
            break;
        case 3:
            printf("Tijera\n");
            break;
        default:
            printf("Selección no valida\n");
            break;
    }

    printf("Computadora eligio: ");
    switch (computadora) {
        case 1:
            printf("Piedra\n");
            break;
        case 2:
            printf("Papel\n");
            break;
        case 3:
            printf("Tijera\n");
            break;
    }

    // Determinar el resultado del juego utilizando condicionales anidados
    if (jugador == computadora) 
    {
        printf("Empate!\n");
    } 
    else 
    {
        if ((jugador == 1 && computadora == 3) || (jugador == 2 && computadora == 1) || (jugador == 3 && computadora == 2)) 
        {
        printf("Ganaste!\n");
        }
        else 
        {
        printf("La computadora gana!\n");
        }
    }
}
// 3.- Programa en C que sirva para el juego del CHINCHAMPU (Piedra, Papel,
//  Tijera) para 1 jugador y la computadora, (usar selección múltiple) 
void chinchampu2(void)
{
    int jugador, computadora;
    srand(time(NULL)); // Inicializar la semilla aleatoria

    printf("Bienvenido al juego del Chinchampu\n");
    printf("1. Piedra\n");
    printf("2. Papel\n");
    printf("3. Tijera\n");

    // El jugador elige su opción
    printf("Elije tu jugada (1-3): ");
    scanf("%d", &jugador);

    // Generar la elección aleatoria de la computadora (1-3)
    computadora = rand() % 3 + 1;

    // Mostrar las elecciones del jugador y la computadora
    printf("Jugador eligio: ");
    switch (jugador) {
        case 1:
            printf("Piedra\n");
            break;
        case 2:
            printf("Papel\n");
            break;
        case 3:
            printf("Tijera\n");
            break;
        default:
            printf("Seleccion no valida\n");
            break;
    }

    printf("Computadora eligio: ");
    switch (computadora) {
        case 1:
            printf("Piedra\n");
            break;
        case 2:
            printf("Papel\n");
            break;
        case 3:
            printf("Tijera\n");
            break;
    }

    // Determinar el resultado del juego utilizando selección múltiple
    switch (jugador) {
        case 1:
            if (computadora == 1) 
            {
                printf("Empate!\n");
            } 
            else
            {
                if (computadora == 2) 
                {
                printf("La computadora gana!\n");
                } 
                else 
                {
                    printf("Ganaste!\n");
                }
            }
            break;
        case 2:
            if (computadora == 1) 
            {
                printf("Ganaste!\n");
            } 
            else 
            {
                if (computadora == 2) 
                {
                printf("Empate!\n");
                } 
                else 
                {
                    printf("La computadora gana!\n");
                }
            }
            break;
        case 3:
            if (computadora == 1) 
            {
                printf("La computadora gana!\n");
            } 
            else 
            {
                if (computadora == 2) 
                {
                    printf("Ganaste!\n");
                } 
                else 
                {
                    printf("Empate!\n");
                }
            }
            break;
    }   
}
// 4.- Programa en C que lea 3 números y desplegar cuál número es el mayor 
// (usar AND o OR)
void num_mayor(void)
{
    int num1, num2, num3;

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    printf("Ingrese el tercer numero: ");
    scanf("%d", &num3);

    if (num1 > num2 && num1 > num3) 
    {
        printf("%d es el numero mayor.\n", num1);
    } 
    else 
    {
        if (num2 > num1 && num2 > num3) 
        {
            printf("%d es el numero mayor.\n", num2);
        } 
        else 
        {
            if (num3 > num1 && num3 > num2) 
            {
                printf("%d es el numero mayor.\n", num3);
            } 
        
            else 
            {
                printf("No hay un numero mayor, los numeros son iguales.\n");
            }
        }
    }
}
// 5.- Programa en C que lea 3 números y desplegar el número del medio 
// (usar AND o OR)
void num_medio(void)
{
    int num1, num2, num3;

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    printf("Ingrese el tercer numero: ");
    scanf("%d", &num3);

    if ((num1 > num2 && num1 < num3) || (num1 > num3 && num1 < num2)) 
    {
        printf("%d es el numero del medio.\n", num1);
    } 
    else
    { 
        if ((num2 > num1 && num2 < num3) || (num2 > num3 && num2 < num1)) 
        {
            printf("%d es el numero del medio.\n", num2);
        }
        else 
        {
            if ((num3 > num1 && num3 < num2) || (num3 > num2 && num3 < num1)) 
            {
                printf("%d es el numero del medio.\n", num3);
            } 
            else 
            {
                printf("No hay un numero del medio, los numeros son iguales.\n");
            }
        }
    } 
}
// 6.- Programa en C que lea 3 números y despegarlos en forma ascendente 
// (usar AND o OR)
void num_menor(void)
{
    int num1, num2, num3;

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    printf("Ingrese el tercer numero: ");
    scanf("%d", &num3);

    if (num1 < num2 && num1 < num3) 
    {
        printf("%d es el numero menor.\n", num1);
    } 
    else 
    {
        if (num2 < num1 && num2 < num3) 
        {
            printf("%d es el numero menor.\n", num2);
        } 
        else
        { 
            if (num3 < num1 && num3 < num2) 
            {
                printf("%d es el numero menor.\n", num3);
            } 
            else 
            {
                printf("No hay un numero menor, los numeros son iguales.\n");
            }
        }
    }
}
// 7.- Función en C que pida el mes y día de nacimiento de una persona 
// y el programa le despliega el signo del zodiaco que le corresponde y su correspondiente horoscopo del Dia.
void zodiaco(void)
{
    int mes, dia;

    printf("Ingrese el mes de nacimiento (1-12): ");
    scanf("%d", &mes);

    printf("Ingrese el dia de nacimiento (1-31): ");
    scanf("%d", &dia);

    if ((mes == 3 && dia >= 21) || (mes == 4 && dia <= 19)) 
    {
        printf("Tu signo del zodiaco es Aries.\n");
        printf("Horoscopo del dia: Hoy te sientes fuerte, mas fortalecido fisica y mentalmente. \n");
    } 
    else 
    {
        if ((mes == 4 && dia >= 20) || (mes == 5 && dia <= 20)) 
        {
            printf("Tu signo del zodiaco es Tauro.\n");
            printf("Horoscopo del dia: Domingo para darle atencion a tu hogar. \n");
        } 
        else
        { 
            if ((mes == 5 && dia >= 21) || (mes == 6 && dia <= 20)) 
            {
                printf("Tu signo del zodiaco es Geminis.\n");
                printf("Horoscopo del dia: Parece que los duendes magicos o algun angel travieso te hace maldades.\n");
            } 
            else 
            {
                if ((mes == 6 && dia >= 21) || (mes == 7 && dia <= 22)) 
                {
                    printf("Tu signo del zodiaco es Cancer.\n");
                    printf("Horoscopo del dia: Se acaba para ti el estres de los pasados días y comienzas una semana llena de buenos acontecimientos. \n");
                } 
                else 
                {
                    if ((mes == 7 && dia >= 23) || (mes == 8 && dia <= 22)) 
                    {
                        printf("Tu signo del zodiaco es Leo.\n");
                        printf("Horoscopo del dia: La luna te visita en este dia haciendo florecer los más bellos sentimientos y atributos que posees. \n");
                    } 
                    else 
                    {
                        if ((mes == 8 && dia >= 23) || (mes == 9 && dia <= 22)) 
                        {
                            printf("Tu signo del zodiaco es Virgo.\n");
                            printf("Horoscopo del dia: Concentrate en disfrutar, en vivir el hoy y el ahora.\n");
                        }
                        else 
                        {
                            if ((mes == 9 && dia >= 23) || (mes == 10 && dia <= 22)) 
                            {
                                printf("Tu signo del zodiaco es Libra.\n");
                                printf("Horoscopo del dia: Pronto cierras una etapa en tu vida dejando atrás la inseguridad, la nostalgia y la ansiedad que sientes por no tener control de lo que te repara el futuro. \n");
                            } 
                            else 
                            {
                                if ((mes == 10 && dia >= 23) || (mes == 11 && dia <= 21)) 
                                {
                                    printf("Tu signo del zodiaco es Escorpio.\n");
                                    printf("Horoscopo del dia: Una amistad de energia femenina, te anima, te contagia con su positivismo y alegría. \n");
                                } 
                                else 
                                {
                                    if((mes == 11 && dia >= 22) || (mes == 12 && dia <= 21)) 
                                    {
                                        printf("Tu signo del zodiaco es Sagitario.\n");
                                        printf("Horoscopo del dia: La Luna y el Sol te inclinan a sentirte fuerte y poderoso. \n");
                                    }
                                    else 
                                    {
                                        if((mes == 12 && dia >= 22) || (mes == 1 && dia <= 19))
                                        {
                                            printf("Tu signo del zodiaco es Capricornio.\n");
                                            printf("Horoscopo del dia: Renace en ti un deseo de libertad, de sentirte en paz y en armonía contigo y con los que te rodean.\n");
                                        } 
                                        else 
                                        {
                                            if((mes == 1 && dia >= 20) || (mes == 2 && dia <= 18))
                                            {
                                                printf("Tu signo del zodiaco es Acuario.\n");
                                                printf("Horoscopo del dia: Domingo relajado y disfrutas de lo que te gusta hacer.\n");
                                            } 
                                            else 
                                            {
                                                if((mes == 2 && dia >= 19) || (mes == 3 && dia <= 20))
                                                {
                                                    printf("Tu signo del zodiaco es Piscis.\n");
                                                    printf("Horoscopo del dia: La Luna y el Sol contrarrestan la energia retrograda de otros planetas. \n");
                                                } 
                                                else
                                                {
                                                    printf("Fecha de nacimiento no valida.\n");
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
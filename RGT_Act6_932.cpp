// Teresa Rivas Gomez 372565
// Sep - 12 - 2023 / Sep - 18 - 2023
// RGT_Act6_932

#include <stdio.h>
#include <stdlib.h>

int msges();
void menu();

void Fibonacci (void);

void FibonacciF (void); // For
void FibonacciW (void); // While
void FibonacciD (void); // Do-While

void Factorial (void);

void FactorialF(void); // For
void FactorialW (void); // While
void FactorialD (void); // Do-While

void Digitos (void);

void DigitosF(void); // For
void DigitosW (void); // While
void DigitosD (void); // Do-While

int main()
{
    menu();
    return 0;
}

int msges()
{ 
    int op;
    system ("CLS");
    printf ("\n M E N U \n");
    printf("1.- FIBONACCI \n");
    printf("2.- FACTORIAL \n");
    printf("3.- DIGITOS \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf ("%d",&op);
    return op;
}

void menu()
{
  int op;
  do{
      op=msges();
      switch (op)
      {
        case 1:
              Fibonacci();
              break;
        case 2:
              Factorial();
              break;
        case 3:
              Digitos();
              break;
      }
    }while (op != 0);
}

void Fibonacci (void)
{
    int op;

    system ("CLS");
    printf("FIBONACCI\n"); 
    printf("\n M E N U \n");
    printf("1-FOR \n");
    printf("2-WHILE \n");
    printf("3-DO-WHILE \n");
    printf("4-Salir \n");
    printf("SELECCIONA UNA OPCION NUMERICA\n");
    scanf("%d", &op);

    switch (op)
    {
        case 1:
            FibonacciF();
            break;
        case 2:
            FibonacciW();
            break;
        case 3:
            FibonacciD();
            break;
        case 4:
            printf("Gracias por usar el programa Fibonacci.\n");
            break;
        default:
            printf("OPCION INCORRECTA, INTENTALO DE NUEVO.\n");  
            break;
    }
    printf("\n");
    system ("PAUSE");
}

void Factorial (void)
{
    int op;

    system ("CLS");
    printf("FACTORIAL\n"); 
    printf("\n M E N U \n");
    printf("1-FOR \n");
    printf("2-WHILE \n");
    printf("3-DO-WHILE \n");
    printf("4-Salir \n");
    printf("SELECCIONA UNA OPCION NUMERICA\n");
    scanf("%d", &op);

    switch (op)
    {
        case 1:
            FactorialF();
            break;
        case 2:
            FactorialW();
            break;
        case 3:
            FactorialD();
            break;
        case 4:
            printf("Gracias por usar el programa Factorial.\n");
            break;
        default:
            printf("OPCION INCORRECTA, INTENTALO DE NUEVO.\n");  
            break;
    }
    printf("\n");
    system ("PAUSE");
}

void Digitos (void)
{
    int op;

    system ("CLS");
    printf("CANTIDAD DE DIGITOS\n"); 
    printf("\n M E N U \n");
    printf("1-FOR \n");
    printf("2-WHILE \n");
    printf("3-DO-WHILE \n");
    printf("4-Salir \n");
    printf("SELECCIONA UNA OPCION NUMERICA\n");
    scanf("%d", &op);

    switch (op)
    {
        case 1:
            DigitosF();
            break;
        case 2:
            DigitosW();
            break;
        case 3:
            DigitosD();
            break;
        case 4:
            printf("Gracias por usar el programa Cantidad de Digitos.\n");
            break;
        default:
            printf("OPCION INCORRECTA, INTENTALO DE NUEVO.\n");  
            break;
    }
    printf("\n");
    system ("PAUSE");
}
void FibonacciF()
{
    system ("CLS");

    int a, s, r, v, contador;

    printf("FIBONACCI CON FOR\n");

    r = 0;
    a = -1;
    s = 1;

    printf("Ingrese cuantas veces desea que se ejecute Fibonacci: ");
    scanf("%d", &v);

    for(contador = 0; contador < v; contador = contador + 1)
    {
        r = a + s;
        printf("%d, ",r);
        a = s;
        s = r;
    }

    system ("PAUSE");
}
void FibonacciW()
{
    system ("CLS");

    int a, s, r, v, contador;

    printf("FIBONACCI CON WHILE\n");

    r = 0;
    a = -1;
    s = 1;

    printf("Ingrese cuantas veces desea que se ejecute Fibonacci: ");
    scanf("%d", &v);

    contador = 0;
    while (contador < v)
    {
        r = a + s;
        printf("%d, ",r);
        a = s;
        s = r;
        contador = contador + 1;
    }
    system ("PAUSE");
}
void FibonacciD()
{
    system ("CLS");

    int a, s, r, v, contador;

    printf("FIBONACCI CON DO-WHILE\n");

    r = 0;
    a = -1;
    s = 1;

    printf("Ingrese cuantas veces desea que se ejecute Fibonacci: ");
    scanf("%d", &v);

    contador = 0;
    do{
        r = a + s;
        printf("%d, ",r);
        a = s;
        s = r;
        contador=contador+1;
    }while(contador < v);

    system ("PAUSE");
}
void FactorialF()
{
    system ("CLS");

    int a, b, factorial = 1;

    printf("FACTORIAL CON FOR\n");
    printf("Ingrese un numero: \n");
    scanf("%d", &a);

    for(b = a; b > 1; b--)
    {
        factorial = factorial * b;
    }

    printf("El factorial de %d = %d\n", a, factorial);

    system ("PAUSE");
}
void FactorialW()
{
    system ("CLS");

    int a, b, factorial = 1;

    printf("FACTORIAL CON WHILE\n");
    printf("Ingrese un numero: \n");
    scanf("%d", &a);

    b = a;
    while(b > 1)
    {
        factorial = factorial * b;
        b--;
    }

    printf("El factorial de %d = %d\n", a, factorial);

    system ("PAUSE");
}
void FactorialD()
{
    system ("CLS");

    int a, b, factorial = 1;

    printf("FACTORIAL CON DO-WHILE\n");
    printf("Ingrese un numero: \n");
    scanf("%d", &a);

    b = a;
    do {
        factorial = factorial * b;
        b--;
    } while (b > 1);

    printf("El factorial de %d = %d\n", a, factorial);

    system ("PAUSE");
}
void DigitosF()
{
    system ("CLS");

    int num;
    int dig = 0, x= 1;

    printf("CANTIDAD DE DIGITOS CON FOR\n");
    printf("Ingrese un numero: \n");
    scanf("%d", &num);

    for(dig = 0; num >= x; dig++)
    {
        x = x * 10; 
    }

    printf("La cantidad de digitos que tiene %d es = %d\n", num, dig);

    system ("PAUSE");
}
void DigitosW()
{
    system ("CLS");

    int num;
    int dig = 0, x= 1;

    printf("CANTIDAD DE DIGITOS CON WHILE\n");
    printf("Ingrese un numero: \n");
    scanf("%d", &num);

    dig = 0;
    while(num >= x)
    {
        x = x * 10;
        dig ++;
    }

    printf("La cantidad de digitos que tiene %d es = %d\n", num, dig);

    system ("PAUSE");
}
void DigitosD()
{
    system ("CLS");

    int num;
    int dig = 0, x= 1;

    printf("CANTIDAD DE DIGITOS CON DO-WHILE\n");
    printf("Ingrese un numero: \n");
    scanf("%d", &num);

    dig = 0;
    do {
        x = x * 10;
        dig ++;
    } while(num >= 0);

    printf("La cantidad de digitos que tiene %d es = %d\n", num, dig);

    system ("PAUSE");
}
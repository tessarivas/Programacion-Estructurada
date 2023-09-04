// Teresa Rivas Gómez
// Ago - 29 - 2023
// Programa en C que lea 6 números, desplegar el valor del número mayor
// RGT_Act4_3_932

#include <stdio.h>

int main ()
{
    int n1, n2, n3, n4, n5, n6;

    printf("Ingresa el primer numero: \n");
    scanf("%d", &n1);
    printf("Ingresa el segundo numero: \n");
    scanf("%d", &n2);
    printf("Ingresa el tercer numero: \n");
    scanf("%d", &n3);
    printf("Ingresa el cuarto numero: \n");
    scanf("%d", &n4);
    printf("Ingresa el quinto numero: \n");
    scanf("%d", &n5);
    printf("Ingresa el sexto numero: \n");
    scanf("%d", &n6);
    
    if (n1 > n2 && n1 > n3 && n1 > n4 && n1 > n5 && n1 > n6)
    {
        printf("El mayor es el primer numero ingresado: %d", n1);
    }
    else
    {
        if (n2 > n3 && n2 > n1 && n2 > n4 && n2 > n5 && n2 > n6)
        {
            printf("El mayor es el segundo numero ingresado: %d", n2);
        }
        else
        {
            if (n3 > n1 && n3 > n2 && n3 > n4 && n3 > n5 && n3 > n6)
            {
                printf("El mayor es el tercer numero ingresado: %d", n3);
            }
            else
            {
                if (n4 > n1 && n4 > n2 && n4 > n3 && n4 > n5 && n4 > n6)
                {
                    printf("El mayor es el cuarto numero ingresado: %d", n4);
                }
                else
                {
                    if (n5 > n1 && n5 > n2 && n5 > n3 && n5 > n6 && n5 > n6)
                    {
                        printf("El mayor es el quinto numero ingresado: %d", n5);
                    }
                    else
                    {
                        printf("El mayor es el sexto numero ingresado: %d", n6);
                    }
                }
            }
        }
    }

    return 0;
}
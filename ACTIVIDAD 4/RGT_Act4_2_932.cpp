// Teresa Rivas Gómez
// Ago - 29 - 2023
// Un menú para realizar conversiones de unidades de medida, 
// donde el usuario selecciona una opción y realizará la opción según sea su selección del menú.
// 1.- cm a pulgadas, 2.- cm a pies, 3.- Km a millas, 4.- Pulgadas a cm, 5.- pies a cm y 6.- millas a Km
// RGT_Act4_2_932

#include <stdio.h>

int main ()
{
    int opcion;
    float cifra;
    float c1, c2, c3, c4, c5, c6;

    printf("¡Bienvenido a la calculadora de conversiones!\n");
    printf("1. cm a pulgadas\n");
    printf("2. cm a pies\n");
    printf("3. km a millas\n");
    printf("4. pulgadas a cm\n");
    printf("5. pies a cm\n");
    printf("6. millas a km\n");
    printf("Seleccione una opcion entre (1/2/3/4/5/6)\n");
    scanf("%d", &opcion);

    printf("Introduce la cifra que quieres convertir: \n");
    scanf("%f", &cifra);

    if (opcion == 1)
    {
        c1 = cifra * 0.393701;
        printf("El resultado de tu cifra en cm a pulgadas es: %.4f\n", c1);
    }
    else
    {
        if (opcion == 2)
        {
            c2 = cifra / 30.48;
            printf("El resultado de tu cifra en cm a pies es: %.4f\n", c2);
        }
        else
        {
            if (opcion == 3)
            {
                c3 = cifra * 0.621371;
                printf("El resultado de tu cifra en km a millas es: %.4f\n", c3);
            }
            else
            {
                if (opcion == 4)
                {
                    c4 = cifra * 2.54;
                    printf("El resultado de tu cifra en pulgadas a cm es: %.4f\n", c4);
                }
                else
                {
                    if (opcion == 5)
                    {
                        c5 = cifra * 30.48;
                        printf("El resultado de tu cifra en pies a cm es: %.4f\n", c5);
                    }
                    else
                    {
                        if (opcion == 6)
                        {
                            c6 = cifra * 1.60934;
                            printf("El resultado de tu cifra en millas a km es: %.4f\n", c6);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
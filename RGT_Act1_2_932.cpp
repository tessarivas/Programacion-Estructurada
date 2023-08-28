//Teresa Rivas Gomez
//Ago-22-2023
//Lee un número entero, y desplega si el número es “PAR” o “IMPAR”
//RGT_Act1_2_932

#include <stdio.h>
int main ()
{
    int num;

    printf("Ingrese un numero: \n");
    scanf("%d", &num);

    if (num % 2 == 0){
        printf("%d es un numero PAR\n", num);
    } else {
        printf("%d es un numero IMPAR\n", num);
    }

    return 0;
}
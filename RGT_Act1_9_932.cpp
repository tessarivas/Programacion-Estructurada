//Teresa Rivas Gomez
//Ago-27-2023
//Lee 3 números y desplegar de forma ascendente
//RGT_Act1_9_932

#include <stdio.h>

int main ()
{
    int n1,n2,n3;

    printf("Ingrese el primer numero: \n");
    scanf("%d", &n1);
    printf("Ingrese el segundo numero: \n");
    scanf("%d", &n2);
    printf("Ingrese el tercer numero: \n");
    scanf("%d", &n3);

   if (n1 > n2) {
        float temp = n1;
        n1 = n2;
        n2 = temp;
    }
    if (n2 > n3) {
        float temp = n2;
        n2 = n3;
        n3 = temp;
    }
    if (n1 > n2) {
        float temp = n1;
        n1 = n2;
        n2 = temp;
    }

    printf("Los numeros en orden ascendente son: %.2d, %.2d, %.2d\n", n1, n2, n3);


    return 0;
}
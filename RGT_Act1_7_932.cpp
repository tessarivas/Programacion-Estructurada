//Teresa Rivas Gomez
//Ago-27-2023
//Lee 3 números y desplegar cuál número es el menor y su valor
//RGT_Act1_7_932

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

    if (n1 < n2 && n3 > n1){
        printf("El numero menor es el primero: %d", n1);
    } else if (n2 < n3 && n1 > n2){
        printf("El numero menor es el segundo: %d", n2);
    } else {
        printf("El numero menor es el tercero: %d", n3);
    }

    return 0;
}
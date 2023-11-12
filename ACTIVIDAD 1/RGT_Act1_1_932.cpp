//Teresa Rivas Gomez
//Ago-22-2023
//Lee 4 calificaciones de un alumno, calcula y desplega el promedio acompañado de la leyenda APROBADO o REPROBADO
//RGT_Act1_1_932

#include <stdio.h>
int main ()
{
    int cal1, cal2, cal3, cal4;
    float promedio;

    printf("Ingrese la calificacion numero 1: \n");
    scanf("%d", &cal1);
    printf("Ingrese la calificacion numero 2: \n");
    scanf("%d", &cal2);
    printf("Ingrese la calificacion numero 3: \n");
    scanf("%d", &cal3);
    printf("Ingrese la calificacion numero 4: \n");
    scanf("%d", &cal4);

    promedio = (cal1 + cal2 + cal3 +cal4) / 4;
    
    printf("El promedio es de: %.2f\n", promedio);

    if (promedio >= 60){
        printf("APROBADO");    
    } else if (promedio < 60) {
        printf("REPROBADO");
    }

    return 0;
}

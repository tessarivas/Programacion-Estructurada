//Teresa Rivas Gomez
//Ago-27-2023
//Programa que sirva para calcular el salario semanal de un trabajador donde se obtiene como dato de entrada las ​ horas semanales​ trabajadas, el ​ salario por hora​ .El programa deberá calcular el ​ salario normal​ , ​ salario extra​ y ​ salario total​ , considerando
//lo siguiente: ● Jornada Normal de 40 horas. ● El salario normal se considera las horas trabajadas menores o igual a la jornada normal ● Salario extra se considera las horas trabajadas mayores a la jornada normal y se pagan dobles las primeras 9 y triples a partir de la décima hora extra 
//Nota:​ Desplegar todos los datos (Salario x hora, Horas Trabajadas, Salario normal, Salario extra y Salario Total)
//RGT_Act1_10_932

#include <stdio.h>
 int main()
 {
    float salario_hora, horas_trabajadas, salario_extra, salario_normal, salario_total, salario_extra_triple;

    printf("Ingrese el salario por hora: \n");
    scanf("%f", &salario_hora);
    printf("Ingrese las horas trabajadas: \n");
    scanf("%f", &horas_trabajadas);

    if(horas_trabajadas <= 40){
        salario_normal = horas_trabajadas * salario_hora;
        salario_total = salario_normal;
    } else if (horas_trabajadas > 40 && horas_trabajadas <= 49){
        salario_normal = 40 * salario_hora;
        salario_extra = (horas_trabajadas - 40) * (salario_hora * 2);
        salario_total = salario_normal + salario_extra;
    } else if (horas_trabajadas > 49){
        salario_normal = 40 * salario_hora;
        salario_extra_triple = (horas_trabajadas - 49);
        salario_extra = (horas_trabajadas - 40 - salario_extra_triple) * (salario_hora * 2) + (salario_extra_triple * (salario_hora * 3));
        salario_total = salario_normal + salario_extra;
    } else {
        printf("Error en el calculo\n");
    }

    printf("Salario por hora: $%.2f\n",salario_hora);
    printf("Horas trabajadas: %.0f\n",horas_trabajadas);
    printf("Salario normal de: $%.2f\n",salario_normal);
    printf("Salario extra de: $%.2f\n",salario_extra);
    printf("Salario total de: $%.2f\n",salario_total);

    return 0;
 }
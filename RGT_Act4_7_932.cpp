// Teresa Rivas Gómez
// Sep - 03 - 2023
// En la materia programación estructurada se aplican 5 exámenes, calcular el promedio final de la materia donde la calificación 
// menor de los exámenes se anula y el promedio se calcula en base a 4 exámenes. Desplegar el promedio final.
// RGT_Act4_7_932

#include <stdio.h>

int main ()
{
    int e1, e2, e3, e4, e5;
    float promedio;

    printf("Calificacion del primer examen: \n");
    scanf("%d", &e1);
    printf("Calificacion del segundo examen: \n");
    scanf("%d", &e2);
    printf("Calificacion del tercero examen: \n");
    scanf("%d", &e3);
    printf("Calificacion del cuarto examen: \n");
    scanf("%d", &e4);
    printf("Calificacion del quinto examen: \n");
    scanf("%d", &e5);

    if (e1 < e2 && e1 < e3 && e1 < e4 && e1 < e5)
    {
        promedio = (e2 + e3 + e4 + e5) / 4;
    }
    else
    {
        if (e2 < e1 && e2 < e3 && e2 < e4 && e2 < e5)
        {
            promedio = (e1 + e3 + e4 + e5) / 4;
        }
        else
        {
            if (e3 < e1 && e3 < e2 && e3 < e4 && e3 < e5)
            {
                promedio = (e1 + e2 + e4 + e5) / 4;
            }
            else
            {
                if (e4 < e1 && e4 < e2 && e4 < e3 && e4 < e5)
                {
                    promedio = (e1 + e2 + e3 + e5) / 4;
                }
                else
                {
                    promedio = (e1 + e2 + e3 + e4) / 4;
                }
            }
        }
    }

    printf("El promedio final es: %.0f\n", promedio);

    return 0;
}
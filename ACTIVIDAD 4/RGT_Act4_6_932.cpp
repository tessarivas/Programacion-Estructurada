// Teresa Rivas Gómez
// Sep - 02 - 2023
// Programa en C que sirva para calcular el Total a pagar por consumo de agua, donde el dato de entrada son los M3 de agua consumidos, Tomar en cuenta que se cobra escalonada de la Siguiente manera:
// Rango1: 0 al 4 M3 $50 x facturación sin importar cuánto consumió en este rango
// Rango2: 5 a 15 M3 $8.00 x M3
// Rango3: 16 a 50 M3 $10.00 x M3
// Rango4: 51 M3 en adelante $11.00 x M3
// Nota: Desplegar SubTotal, Iva(16%), y Total a pagar.
// RGT_Act4_6_932

#include <stdio.h>

int main() {
    float m3_consumidos;
    float subtotal, iva, total;

    printf("Ingrese la cantidad de M3 de agua consumidos: ");
    scanf("%f", &m3_consumidos);

    if (m3_consumidos <= 4) 
    {
        subtotal = 50.0;
    } 
    else 
    {
        if (m3_consumidos <= 15) 
        {
            subtotal = 50.0 + (m3_consumidos - 4) * 8.0;
        } 
        else 
        {
            if (m3_consumidos <= 50) 
            {
                subtotal = 50.0 + 11.0 * 11.0 + (m3_consumidos - 15) * 10.0;
            }
            else 
            {
                subtotal = 50.0 + 11.0 * 11.0 + 35.0 * 10.0 + (m3_consumidos - 50) * 11.0;
            }
        }
    }

    iva = 0.16 * subtotal;
    total = subtotal + iva;

    printf("Subtotal: $%.2f\n", subtotal);
    printf("IVA (16%%): $%.2f\n", iva);
    printf("Total a pagar: $%.2f\n", total);

    return 0;
}

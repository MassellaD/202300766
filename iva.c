#include <stdio.h>

int main() {
    float precioTotal, siniva, iva;
    const float porcentajeIVA = 0.12;

   
    printf("Ingrese el precio en quetzales: ");
    scanf("%f", &precioTotal);


    iva = precioTotal * porcentajeIVA;
    siniva = precioTotal - iva;


    printf("Precio sin IVA: %.2f\n", siniva);
    printf("IVA: %.2f\n", iva);

    FILE *archivoSalida = fopen("salida.txt", "w");
    if (archivoSalida == NULL) {
        printf("Error al abrir el archivo de salida.\n");
        return 1;
    }

    fprintf(archivoSalida, "Precio sin IVA: %.2f\n", siniva);
    fprintf(archivoSalida, "IVA: %.2f\n", iva);

    fclose(archivoSalida);

    return 0;
}

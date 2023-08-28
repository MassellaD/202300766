#include <stdio.h>
#include <stdlib.h>

int main() {
    int suma, lanzamiento = 1;
    char continuar = 's';
    FILE *archivoSalida;

    archivoSalida = fopen("salida.txt", "w");

    if (archivoSalida == NULL) {
        printf("No se pudo abrir el archivo de salida.\n");
        return 1;
    }

    while (continuar == 's' || continuar == 'S') {
        int dado1 = 1 + rand() % 6;
        int dado2 = 1 + rand() % 6;
        suma = dado1 + dado2;

        printf("Lanzamiento %d: Dado 1: %d, Dado 2: %d, Suma: %d\n", lanzamiento, dado1, dado2, suma);

        fprintf(archivoSalida, "Lanzamiento %d: Dado 1: %d, Dado 2: %d, Suma: %d\n", lanzamiento, dado1, dado2, suma);

        if (suma == 8) {
            printf("Ganaste!!!\n");
            break;
        } else if (suma == 7) {
            printf("Perdiste :( \n");
            break;
        } else {
            printf("¿Quieres continuar lanzando? (s/n): ");
            scanf(" %c", &continuar);
            lanzamiento++;
        }
    }

    fclose(archivoSalida);

    return 0;
}

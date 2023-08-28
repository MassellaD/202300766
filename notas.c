#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


float calcularMediana(int arreglo[], int n) {
    if (n % 2 == 0) {
        return (arreglo[n / 2 - 1] + arreglo[n / 2]) / 2.0;
    } else {
        return arreglo[n / 2];
    }
}

int main() {
    int n;
    printf("Ingrese el numero de calificaciones: ");
    scanf("%d", &n);

    int calificaciones[n];
    printf("Ingrese las calificaciones:\n");
    for (int i = 0; i < n; i++) {
        printf("Calificacion %d: ", i + 1);
        scanf("%d", &calificaciones[i]);
    }


    qsort(calificaciones, n, sizeof(int), comparar);


    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += calificaciones[i];
    }
    float media = suma / n;


    float mediana = calcularMediana(calificaciones, n);


    int frecuenciaMax = 0;
    int moda = calificaciones[0];
    int frecuenciaActual = 1;
    for (int i = 1; i < n; i++) {
        if (calificaciones[i] == calificaciones[i - 1]) {
            frecuenciaActual++;
        } else {
            frecuenciaActual = 1;
        }

        if (frecuenciaActual > frecuenciaMax) {
            frecuenciaMax = frecuenciaActual;
            moda = calificaciones[i];
        }
    }


    int rango = calificaciones[n - 1] - calificaciones[0];


    float sumaDiferenciasCuadrado = 0;
    for (int i = 0; i < n; i++) {
        sumaDiferenciasCuadrado += pow(calificaciones[i] - media, 2);
    }
    float varianza = sumaDiferenciasCuadrado / n;
    float desviacionEstandar = sqrt(varianza);

    // Imprimir los resultados
    printf("Resultados:\n");
    printf("Media: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);
    printf("Rango: %d\n", rango);
    printf("Desviacion Estandar: %.2f\n", desviacionEstandar);
    printf("Varianza: %.2f\n", varianza);

    return 0;
}

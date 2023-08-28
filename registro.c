#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_estudiantes 100
#define max_materias 10
#define max_longitud_nombre 50

typedef struct {
    char nombre[max_longitud_nombre];
    float notas[max_materias];
} Estudiante;

void guardar_en_archivo(Estudiante estudiantes[], int contador) {
    FILE *archivo = fopen("salida.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for (int i = 0; i < contador; i++) {
        fprintf(archivo, "Nombre: %s\n", estudiantes[i].nombre);
        for (int j = 0; j < max_materias; j++) {
            fprintf(archivo, "Materia %d: %.2f\n", j + 1, estudiantes[i].notas[j]);
        }
        fprintf(archivo, "\n");
    }

    fclose(archivo);
    printf("Registros guardados en el archivo 'salida.txt'.\n");
}

void mostrar_historial(Estudiante estudiantes[], int contador) {
    if (contador == 0) {
        printf("No hay registros para mostrar.\n");
        return;
    }

    for (int i = 0; i < contador; i++) {
        printf("Nombre: %s\n", estudiantes[i].nombre);
        for (int j = 0; j < max_materias; j++) {
            printf("Materia %d: %.2f\n", j + 1, estudiantes[i].notas[j]);
        }
        printf("\n");
    }
}

void borrar_historial(Estudiante estudiantes[], int *contador) {
    *contador = 0;
    printf("Historial de notas borrado.\n");
}

int main() {
    Estudiante estudiantes[max_estudiantes];
    int contador_estudiantes = 0;
    int opcion;

    do {
        printf("Menu:\n");
        printf("1. Registrar nuevo estudiante y sus notas.\n");
        printf("2. Ver el historial de notas.\n");
        printf("3. Borrar historial de notas.\n");
        printf("4. Salir.\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (contador_estudiantes < max_estudiantes) {
                    Estudiante nuevo_estudiante;
                    printf("Ingrese el nombre del estudiante sin espacios: ");
                    scanf("%s", nuevo_estudiante.nombre);

                    printf("Ingrese las notas para cada materia:\n");
                    for (int i = 0; i < max_materias; i++) {
                        printf("Materia %d: ", i + 1);
                        scanf("%f", &nuevo_estudiante.notas[i]);
                    }

                    estudiantes[contador_estudiantes] = nuevo_estudiante;
                    contador_estudiantes++;
                    printf("Estudiante registrado exitosamente.\n");
                } else {
                    printf("Se ha alcanzado el limite maximo de estudiantes.\n");
                }
                break;
            case 2:
                mostrar_historial(estudiantes, contador_estudiantes);
                break;
            case 3:
                borrar_historial(estudiantes, &contador_estudiantes);
                break;
            case 4:
                guardar_en_archivo(estudiantes, contador_estudiantes);
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
        }
    } while (opcion != 4);

    return 0;
}

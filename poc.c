#include <stdio.h>


int Primo(int num) {
    if (num <= 1) {
        return 0; 
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    
    int resultado = Primo(numero);
    
    FILE *archivo = fopen("salida.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }
    
    if (resultado) {
        fprintf(archivo, "%d es un numero primo.\n", numero);
        printf("%d es un numero primo.\n", numero);
    } else {
        fprintf(archivo, "%d es un numero compuesto.\n", numero);
        printf("%d es un numero compuesto.\n", numero);
    }
    
    fclose(archivo);
    return 0;
}

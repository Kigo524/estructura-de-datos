//Ejercicio 4: Arreglo y punteros

#include <stdio.h>

int main() {
    int arreglo[] = {10, 20, 30, 40};
    int *p = arreglo;
    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);

    for (int i = 0; i < tamaño; i++) {
        printf("%d, ", *(p + i));
    }

    return 0;
}


//PISTA: Usa un for con *(p + i).
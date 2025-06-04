#include <stdio.h>

int main() {
    int a = 5;
    int *ptr;

    // 1. Apunta el puntero 'ptr' a la variable 'a'
    ptr = &a;

    // 2. Imprime la dirección de 'a' y el valor de 'ptr'
    printf("La direccion de a es: %p\n", &a);

    // 3. Imprime el valor de 'a' usando el puntero
    printf("El valor al que apunta ptr es: %d\n", *ptr);

    return 0;
}

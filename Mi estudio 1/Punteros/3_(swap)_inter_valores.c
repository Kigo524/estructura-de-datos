//Ejercicio 3: Intercambiar valores con punteros (swap)

#include <stdio.h>

void intercambiar(int *x, int *y) {
    // Implementa el intercambio usando un temporal
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 3, b = 8;

    // Llama a la función intercambiar con &a y &b
    intercambiar(&a,&b);

    // Imprime los valores después del intercambio
    printf("El valor de a es: %d\n", a);
    printf("El valor de b es: %d\n", b);
}

/*PISTA
Dentro de la funcion:
int temp = *x;
*x = *y;
*y = temp; */
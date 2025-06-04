//Ejercicio 2: Modificar una variable a través de un puntero
#include <stdio.h>

int main() {
    int numero = 7;
    int *p = &numero;

    // 1. Usa el puntero para cambiar el valor de 'numero' a 20
    *p = 20;

    // 2. Imprime el nuevo valor de 'numero'
    printf("El valor de numero es: %d\n", numero);
    printf("El valor al que apunta p es: %d\n", *p);

}

//Usa *p = 20; para cambiar el valor.
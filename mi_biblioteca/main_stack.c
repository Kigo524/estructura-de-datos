#include <stdio.h>
#include "stack.h"

int main() {
    Stack pila;
    init(&pila);

    push(&pila, 10);
    push(&pila, 20);
    push(&pila, 30);
    print(&pila);

    printf("Tope: %d\n", peek(&pila));
    printf("Eliminado: %d\n", pop(&pila));
    print(&pila);

    return 0;
}
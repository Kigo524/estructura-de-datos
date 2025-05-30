#include <stdio.h>
#define MAX 5  // Tamaño máximo de la pila

int pila[MAX]; // Arreglo que representa la pila
int tope = -1; // Índice del tope de la pila (-1 indica que está vacía)

// Función para agregar un elemento (push)
void push(int valor) {
    if (tope == MAX - 1) {
        printf("La pila está llena.\n");
    } else {
        tope++;
        pila[tope] = valor;
        printf("Elemento %d agregado a la pila.\n", valor);
    }
}

// Función para sacar un elemento (pop)
void pop() {
    if (tope == -1) {
        printf("La pila está vacía.\n");
    } else {
        printf("Elemento %d eliminado de la pila.\n", pila[tope]);
        tope--;
    }
}

// Función para ver el elemento superior
void verTope() {
    if (tope == -1) {
        printf("La pila está vacía.\n");
    } else {
        printf("Elemento en el tope: %d\n", pila[tope]);
    }
}

// Función principal
int main() {
    push(10);
    push(20);
    verTope();  // Debería mostrar 20
    pop();      // Elimina 20
    verTope();  // Ahora debería mostrar 10
    return 0;
}
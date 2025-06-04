#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Verifica si la pila está llena
int isFull() {//se usara internamente en otra funcion
    return top == MAX - 1;//si es verdadero devuelve 1
}

// Verifica si la pila está vacía
int isEmpty() {
    return top == -1;
}

// Agrega un elemento a la pila
void push(int valor) {
    if (isFull()) {//si isFull devuelve 1 o verdadero...
        printf("Pila llena. No se puede agregar %d\n", valor);
    } else {
        top++;
        stack[top] = valor;
        printf("Se ha hecho push de: %d\n", valor);
    }
}

// Quita el elemento de la cima
void pop() {
    if (isEmpty()) {//si isEmptry devuelve 1 o verdadero...
        printf("Pila vacía. No se puede hacer pop\n");
    } else {
        printf("Se ha hecho pop de: %d\n", stack[top]);
        top--;
    }
}

// Devuelve el elemento de la cima sin quitarlo
int peek() {
    if (isEmpty()) {//si isEmpty devuelve 1(vacio)...
        printf("Pila vacía. No hay cima\n");
        return -1;
    }
    return stack[top];
}

// Muestra el contenido interno de la pila
void printStack() {
    printf("\n--- Estado actual de la pila ---\n");
    if (isEmpty()) {//si esta vacia...
        printf("[Vacía]\n");
    } else {
        for (int i = top; i >= 0; i--) {
            if (i == top) {
                printf("[%d] <- cima\n", stack[i]);
            } else {
                printf("[%d]\n", stack[i]);
            }
        }
    }
    printf("-------------------------------\n\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);  // Este debería mostrar que la pila está llena

    printStack();

    pop();
    pop();

    printStack();

    printf("Elemento en la cima: %d\n", peek());

    return 0;
}

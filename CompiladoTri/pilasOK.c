#include <stdio.h>

#define MAX 5

typedef struct {
    int stack[MAX];
    int top;
} Pila;

// Inicializa la pila
void initPila(Pila* p) {
    p->top = -1;
}

// Verifica si la pila está llena
int isFull(Pila* p) {
    return p->top == MAX - 1;
}

// Verifica si la pila está vacía
int isEmpty(Pila* p) {
    return p->top == -1;
}

// Agrega un elemento a la pila
void push(Pila* p, int valor) {
    if (isFull(p)) {
        printf("Pila llena. No se puede agregar %d\n", valor);
    } else {
        p->top++;
        p->stack[p->top] = valor;
        printf("Se ha hecho push de: %d\n", valor);
    }
}

// Quita el elemento de la cima
void pop(Pila* p) {
    if (isEmpty(p)) {
        printf("Pila vacía. No se puede hacer pop\n");
    } else {
        printf("Se ha hecho pop de: %d\n", p->stack[p->top]);
        p->top--;
    }
}

// Devuelve el elemento de la cima sin quitarlo
int peek(Pila* p) {
    if (isEmpty(p)) {
        printf("Pila vacía. No hay cima\n");
        return -1;
    }
    return p->stack[p->top];
}

// Muestra el contenido interno de la pila
void printStack(Pila* p) {
    printf("\n--- Estado actual de la pila ---\n");
    if (isEmpty(p)) {
        printf("[Vacía]\n");
    } else {
        int i = p->top;
        while (i >= 0) {
            if (i == p->top) {
                printf("[%d] <- cima\n", p->stack[i]);
            } else {
                printf("[%d]\n", p->stack[i]);
            }
            i--;
        }
    }
    printf("-------------------------------\n\n");
}

int main() {
    Pila miPila;
    initPila(&miPila);

    push(&miPila, 10);
    push(&miPila, 20);
    push(&miPila, 30);
    push(&miPila, 40);
    push(&miPila, 50);
    push(&miPila, 60);  // Este debería mostrar que la pila está llena

    printStack(&miPila);

    pop(&miPila);
    pop(&miPila);

    printStack(&miPila);

    printf("Elemento en la cima: %d\n", peek(&miPila));

    return 0;
}
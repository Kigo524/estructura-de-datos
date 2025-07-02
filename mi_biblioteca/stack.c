#include <stdio.h>
#include "stack.h"

void init(Stack *pila) {
    pila->top = -1;
}

int isEmpty(Stack *pila) {
    return pila->top == -1;
}

int isFull(Stack *pila) {
    return pila->top == MAX - 1;
}

void push(Stack *pila, int valor) {
    if (!isFull(pila)) {
        pila->top++;
        pila->datos[pila->top] = valor;
    } else {
        printf("La pila está llena\n");
    }
}

int pop(Stack *pila) {
    if (!isEmpty(pila)) {
        int val = pila->datos[pila->top];
        pila->top--;
        return val;
    } else {
        printf("La pila está vacía\n");
        return -1;
    }
}

int peek(Stack *pila) {
    if (!isEmpty(pila)) {
        return pila->datos[pila->top];
    } else {
        return -1;
    }
}

void print(Stack *pila) {
    if (isEmpty(pila)) {
        printf("La pila está vacía\n");
    } else {
        printf("Pila: ");
        for (int i = pila->top; i >= 0; i--) {
            printf("%d ", pila->datos[i]);
        }
        printf("\n");
    }
}
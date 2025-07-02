#ifndef STACK_H
#define STACK_H

#define MAX 5

// Estructura para la pila
typedef struct {
    int datos[MAX];
    int top;
} Stack;

// Prototipos de funciones
void init(Stack *pila);
int isEmpty(Stack *pila);
int isFull(Stack *pila);
void push(Stack *pila, int valor);
int pop(Stack *pila);
int peek(Stack *pila);
void print(Stack *pila);

#endif
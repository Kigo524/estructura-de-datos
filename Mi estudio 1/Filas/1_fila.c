#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0;
int rear = -1;

// Verifica si la fila está vacía
int isEmpty() {
    return front > rear;
}

// Verifica si la fila está llena
int isFull() {
    return rear == MAX - 1;
}

// Inserta un elemento al final
void enqueue(int valor) {
    if (isFull()) {
        printf("Fila llena. No se puede agregar %d\n", valor);
    } else {
        rear++;
        queue[rear] = valor;
        printf("Enqueued: %d\n", valor);
    }
}

// Elimina el primer elemento
void dequeue() {
    if (isEmpty()) {
        printf("Fila vacía. No se puede eliminar\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front++;
    }
}

// Muestra el elemento del frente
int peek() {
    if (isEmpty()) {
        printf("Fila vacía. No hay elemento al frente\n");
        return -1;
    }
    return queue[front];
}

// Imprime la fila
void printQueue() {
    printf("\n--- Estado actual de la fila ---\n");
    if (isEmpty()) {
        printf("[Vacía]\n");
    } else {
        for (int i = front; i <= rear; i++) {
            if (i == front)
                printf("[%d] <- frente\n", queue[i]);
            else
                printf("[%d]\n", queue[i]);
        }
    }
    printf("-------------------------------\n\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); // Fila llena

    printQueue();

    dequeue();
    dequeue();

    printQueue();

    printf("Elemento al frente: %d\n", peek());

    return 0;
}

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Verifica si la fila está vacía
int isEmpty() {
    return front == -1;
}

// Verifica si la fila está llena (posición siguiente de rear es front)
int isFull() {
    return (rear + 1) % MAX == front;
}

// Agrega un elemento
void enqueue(int valor) {
    if (isFull()) {
        printf("Fila llena. No se puede agregar %d\n", valor);
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
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
        if (front == rear) {
            // Solo había un elemento
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

// Muestra el elemento al frente
int peek() {
    if (isEmpty()) {
        printf("Fila vacía.\n");
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
        int i = front;
        while (1) {
            if (i == front) printf("[%d] <- frente\n", queue[i]);
            else printf("[%d]\n", queue[i]);

            if (i == rear) break;
            i = (i + 1) % MAX;
        }
    }
    printf("-------------------------------\n\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue(); // Elimina 10
    dequeue(); // Elimina 20
    enqueue(50);
    enqueue(60); // Ocupa el espacio del principio
    enqueue(70); // Fila llena (ya no hay espacio)

    printQueue();

    printf("Elemento al frente: %d\n", peek());

    return 0;
}

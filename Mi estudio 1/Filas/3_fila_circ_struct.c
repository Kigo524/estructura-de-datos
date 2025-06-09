#include <stdio.h>

#define MAX 5  // Capacidad máxima de la fila (número de elementos)

// Definimos una estructura llamada Queue para representar una fila circular
typedef struct {
    int datos[MAX];  // Arreglo que almacena los elementos de la fila
    int front;       // Índice del primer elemento (frente de la fila)
    int rear;        // Índice del último elemento (final de la fila)
} Queue;

// Inicializa una fila vacía: front y rear a -1
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Verifica si la fila está vacía
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Verifica si la fila está llena usando aritmética circular
int isFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// Agrega un elemento a la fila
void enqueue(Queue *q, int valor) {
    if (isFull(q)) {
        printf("Fila llena. No se puede agregar %d\n", valor);
    } else {
        if (isEmpty(q)) {
            // Si la fila estaba vacía, inicializamos front en 0
            q->front = 0;
        }
        // Avanzamos rear en forma circular
        q->rear = (q->rear + 1) % MAX;
        q->datos[q->rear] = valor;
        printf("Enqueued: %d\n", valor);
    }
}

// Elimina un elemento del frente de la fila
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Fila vacía. No se puede eliminar\n");
    } else {
        printf("Dequeued: %d\n", q->datos[q->front]);

        // Si solo había un elemento, se reinicia la fila
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            // Avanzamos front en forma circular
            q->front = (q->front + 1) % MAX;
        }
    }
}

// Devuelve el valor al frente sin eliminarlo
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Fila vacía. No hay elemento al frente\n");
        return -1;  // Retorna un valor inválido para indicar que está vacía
    }
    return q->datos[q->front];
}

// Imprime todos los elementos de la fila desde front hasta rear
void printQueue(Queue *q) {
    printf("\n--- Estado actual de la fila ---\n");
    if (isEmpty(q)) {
        printf("[Vacía]\n");
    } else {
        int i = q->front;
        while (1) {
            if (i == q->front)
                printf("[%d] <- frente\n", q->datos[i]);
            else
                printf("[%d]\n", q->datos[i]);

            if (i == q->rear) break; // Terminamos al llegar al último elemento
            i = (i + 1) % MAX;       // Avanzamos circularmente
        }
    }
    printf("-------------------------------\n\n");
}

// Función principal para probar la fila
int main() {
    Queue q;             // Creamos una fila
    initQueue(&q);       // La inicializamos

    enqueue(&q, 10);     // Agregamos 10
    enqueue(&q, 20);     // Agregamos 20
    enqueue(&q, 30);     // Agregamos 30
    enqueue(&q, 40);     // Agregamos 40

    dequeue(&q);         // Quitamos el 10
    dequeue(&q);         // Quitamos el 20

    enqueue(&q, 50);     // Agregamos 50 (reutilizando espacio)
    enqueue(&q, 60);     // Agregamos 60 (ciclo circular)

    enqueue(&q, 70);     // Ya está llena, no se puede agregar

    printQueue(&q);      // Mostramos la fila actual

    printf("Elemento al frente: %d\n", peek(&q));  // Mostramos el frente

    return 0;
}

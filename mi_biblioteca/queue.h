#ifndef QUEUE_H
#define QUEUE_H

#define MAX 5

typedef struct {
    int datos[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, int valor);
int dequeue(Queue *q);
int peek(Queue *q);
void printQueue(Queue *q);

#endif
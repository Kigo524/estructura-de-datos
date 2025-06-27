/*Simular una cola de tickets es una excelente forma de aplicar lo que aprendiste con filas. 
Vamos a hacer un ejercicio práctico basado en el mundo real: atención al cliente.

Objetivo del ejercicio
*** Simular una cola donde cada cliente saca un número (ticket) y espera ser atendido.

Tendremos operaciones como:
Un cliente llega → se agrega su número a la fila (enqueue)
Un cliente es atendido → se elimina el número del frente (dequeue)
Mostrar la cola actual
Ver el ticket del siguiente cliente (peek)

Consideraciones
Cada ticket será un número consecutivo (1, 2, 3, ...).
La fila tendrá un tamaño limitado (MAX clientes esperando).
*/

#include<stdio.h>

#define MAX 15 //cant de clientes

typedef struct{
    int datos[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q){
    q -> front = -1;
    q -> rear = -1;
}

void isEmpty(Queue *q){
    return q->front == -1;
}

void isFull(Queue *q){
    return (q->rear +1) % MAX == q->front;
}

//agregar dato
void enqueue(Queue *q, int valor){
    if(isFull(q)){
        
    }
}
#include <stdio.h>
#include "queue.h"

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printQueue(&q);

    printf("Front value: %d\n", peek(&q));

    printf("Dequeued: %d\n", dequeue(&q));
    printQueue(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);  // This should print "Queue is full"
    printQueue(&q);

    return 0;
}
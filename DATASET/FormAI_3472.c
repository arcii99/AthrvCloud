//FormAI DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int front, rear;
    int items[MAX_QUEUE_SIZE];
} CQueue;

void enqueue(CQueue *q, int data) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) {
        printf("Queue is full!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->items[q->rear] = data;
}

int dequeue(CQueue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->items[q->front];
}

int main() {
    CQueue queue;
    queue.front = 0;
    queue.rear = 0;
    
    enqueue(&queue, 5);
    enqueue(&queue, 10);
    enqueue(&queue, 15);
    enqueue(&queue, 20);
    enqueue(&queue, 25); // Should print "Queue is full!"
    
    printf("Dequeued item: %d\n", dequeue(&queue));
    printf("Dequeued item: %d\n", dequeue(&queue));
    
    enqueue(&queue, 30);
    enqueue(&queue, 35);
    
    printf("Dequeued item: %d\n", dequeue(&queue));
    printf("Dequeued item: %d\n", dequeue(&queue));
    printf("Dequeued item: %d\n", dequeue(&queue));
    printf("Dequeued item: %d\n", dequeue(&queue));
    printf("Dequeued item: %d\n", dequeue(&queue)); // Should print "Queue is empty!"
    
    return 0;
}
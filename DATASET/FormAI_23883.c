//FormAI DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct Queue {
    int array[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isFull(Queue *q) {
    return (q->rear == MAX_QUEUE_SIZE - 1);
}

int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(Queue *q, int element) {
    if (isFull(q)) {
        printf("The queue is full.");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->array[q->rear] = element;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty.");
        return -1;
    }
    int element = q->array[q->front];
    q->front++;
    return element;
}

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("Elements in the queue are: %d, %d, %d\n", dequeue(&q), dequeue(&q), dequeue(&q));
    enqueue(&q, 4);
    printf("Elements in the queue are: %d\n", dequeue(&q));
    enqueue(&q, 5);
    printf("Elements in the queue are: %d\n", dequeue(&q));
    return 0;
}
//FormAI DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isFull(Queue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue overflow!\n");
        exit(EXIT_FAILURE);
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow!\n");
        exit(EXIT_FAILURE);
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main() {
    Queue q;
    initQueue(&q);

    printf("Enqueuing 1, 2, 3...\n");
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("Dequeuing %d, %d, %d...\n", dequeue(&q), dequeue(&q), dequeue(&q));

    printf("Enqueuing 4, 5, 6, 7, 8, 9, 10, 11, 12, 13...\n");
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);
    enqueue(&q, 10);
    enqueue(&q, 11);
    enqueue(&q, 12);
    enqueue(&q, 13);

    printf("Dequeuing %d, %d, %d, %d, %d, %d, %d, %d, %d, %d...\n",
            dequeue(&q), dequeue(&q), dequeue(&q), dequeue(&q),
            dequeue(&q), dequeue(&q), dequeue(&q), dequeue(&q),
            dequeue(&q), dequeue(&q));

    return 0;
}
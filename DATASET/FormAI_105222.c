//FormAI DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int front, rear;
    int elements[MAX_QUEUE_SIZE];
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int is_empty(Queue *q) {
    return q->front == -1 && q->rear == -1;
}

int is_full(Queue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(Queue *q, int x) {
    if (is_full(q)) {
        printf("Error: Queue is full\n");
        return;
    } else if (is_empty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    }
    q->elements[q->rear] = x;
}

int dequeue(Queue *q) {
    int x;
    if (is_empty(q)) {
        printf("Error: Queue is empty\n");
        return -1;
    } else if (q->front == q->rear) {
        x = q->elements[q->front];
        q->front = -1;
        q->rear = -1;
    } else {
        x = q->elements[q->front];
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    return x;
}

int main() {
    Queue q;
    initialize(&q);

    // Enqueue some numbers
    printf("Enqueuing 5 numbers...\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    // Dequeue and print the numbers
    printf("Dequeuing 3 numbers...\n");
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));

    // Enqueue some more numbers
    printf("Enqueuing 2 numbers...\n");
    enqueue(&q, 60);
    enqueue(&q, 70);

    // Dequeue and print the rest of the numbers
    printf("Dequeuing the rest of the numbers...\n");
    while (!is_empty(&q)) {
        printf("%d\n", dequeue(&q));
    }

    return 0;
}
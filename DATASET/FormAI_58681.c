//FormAI DATASET v1.0 Category: Queue Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int front, rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return (q->rear == MAX_QUEUE_SIZE - 1);
}

int isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

void enqueue(Queue *q, int val) {
    if (isFull(q)) {
        printf("\nError: Queue is full.\n");
        return;
    } else if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = val;
    printf("\nEnqueued %d\n", val);
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("\nError: Queue is empty.\n");
        return;
    } else if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("\nError: Queue is empty.\n");
        return;
    }
    printf("\nQueue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initialize(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);
    enqueue(&q, 10);
    enqueue(&q, 11);

    printQueue(&q);

    dequeue(&q);
    dequeue(&q);

    printQueue(&q);

    enqueue(&q, 11);
    enqueue(&q, 12);

    printQueue(&q);

    return 0;
}
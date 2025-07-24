//FormAI DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    }
    return 0;
}

int isEmpty(Queue *q) {
    if (q->front == -1 && q->rear == -1) {
        return 1;
    }
    return 0;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("\nQueue is full!");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = value;
    printf("\nInserted element : %d", value);
}

int dequeue(Queue *q) {
    int element;
    if (isEmpty(q)) {
        printf("\nQueue is empty !");
        return (-1);
    } else if (q->front == q->rear) {
        element = q->items[q->front];
        q->front = -1;
        q->rear = -1;
    } else {
        element = q->items[q->front];
        q->front++;
    }
    printf("\nDeleted element : %d", element);
    return (element);
}

void printQueue(Queue *q) {
    int i = q->front;
    if (isEmpty(q)) {
        printf("\nQueue is empty !");
    } else {
        printf("\nQueue elements are : \n");
        for (i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
    }
}

int main() {
    Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    enqueue(&myQueue, 40);
    enqueue(&myQueue, 50);
    enqueue(&myQueue, 60);

    printQueue(&myQueue);

    dequeue(&myQueue);
    dequeue(&myQueue);
    dequeue(&myQueue);
    dequeue(&myQueue);
    dequeue(&myQueue);
    dequeue(&myQueue);

    printQueue(&myQueue);

    return 0;
}
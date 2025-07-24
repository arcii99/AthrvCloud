//FormAI DATASET v1.0 Category: Queue Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct queue {
    int front, rear;
    int arr[MAX_QUEUE_SIZE];
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueFull(Queue *q) {
    return q->rear == MAX_QUEUE_SIZE - 1;
}

int isQueueEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int data) {
    if (isQueueFull(q)) {
        printf("The queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = data;
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("The queue is empty!\n");
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else {
        q->front++;
    }
    return data;
}

void display(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("The queue is empty!\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);
    // Output: 10 20 30 40 50

    dequeue(&q);
    dequeue(&q);
    display(&q);
    // Output: 30 40 50

    enqueue(&q, 60);
    display(&q);
    // Output: 30 40 50 60

    return 0;
}
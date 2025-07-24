//FormAI DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_MAX_SIZE 100

typedef struct {
    int items[QUEUE_MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isQueueEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

bool isQueueFull(Queue *q) {
    return ((q->rear + 1) % QUEUE_MAX_SIZE == q->front);
}

void enqueue(Queue *q, int val) {
    if (isQueueFull(q)) {
        printf("Queue overflow!\n");
    } else if (isQueueEmpty(q)) {
        q->front = q->rear = 0;
        q->items[q->rear] = val;
    } else {
        q->rear = (q->rear + 1) % QUEUE_MAX_SIZE;
        q->items[q->rear] = val;
    }
}

int dequeue(Queue *q) {
    int item = 0;
    if (isQueueEmpty(q)) {
        printf("Queue underflow!\n");
    } else if (q->front == q->rear) {
        item = q->items[q->front];
        q->front = q->rear = -1;
    } else {
        item = q->items[q->front];
        q->front = (q->front + 1) % QUEUE_MAX_SIZE;
    }
    return item;
}

void printQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i = (i + 1) % QUEUE_MAX_SIZE) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    printQueue(&q);
    dequeue(&q);
    dequeue(&q);
    printQueue(&q);
    enqueue(&q, 5);
    enqueue(&q, 6);
    printQueue(&q);
    return 0;
}
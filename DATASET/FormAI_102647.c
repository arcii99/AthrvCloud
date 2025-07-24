//FormAI DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front, rear, count;
} Queue;

void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

void enqueue(Queue *q, int x) {
    if(q->count == MAX_QUEUE_SIZE) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = x;
    q->count++;
}

int dequeue(Queue *q) {
    if(q->count == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int x = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->count--;
    return x;
}

int main() {
    Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d ", dequeue(&q));
    return 0;
}
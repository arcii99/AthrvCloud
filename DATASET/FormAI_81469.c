//FormAI DATASET v1.0 Category: Queue Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int front;
    int rear;
    int count;
    int data[MAX_QUEUE_SIZE];
} Queue;

void init_queue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int is_full(Queue *q) {
    return q->count == MAX_QUEUE_SIZE;
}

int is_empty(Queue *q) {
    return q->count == 0;
}

void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        printf("Queue is full, unable to enqueue value %d\n", value);
        return;
    }

    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = value;
    q->count++;
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty, unable to dequeue\n");
        return -1;
    }

    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->count--;

    return value;
}

int main() {
    Queue q;
    init_queue(&q);

    printf("Queue size is %d\n", MAX_QUEUE_SIZE);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Dequeuing value: %d\n", dequeue(&q));
    printf("Dequeuing value: %d\n", dequeue(&q));

    enqueue(&q, 60);
    enqueue(&q, 70);

    printf("Dequeuing value: %d\n", dequeue(&q));
    printf("Dequeuing value: %d\n", dequeue(&q));
    printf("Dequeuing value: %d\n", dequeue(&q));
    printf("Dequeuing value: %d\n", dequeue(&q));
    printf("Dequeuing value: %d\n", dequeue(&q));

    return 0;
}
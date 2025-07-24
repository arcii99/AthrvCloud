//FormAI DATASET v1.0 Category: Queue ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int front;
    int rear;
    int arr[MAX_QUEUE_SIZE];
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1) || (q->front > q->rear);
}

int isQueueFull(Queue *q) {
    return q->rear == MAX_QUEUE_SIZE - 1;
}

void enqueue(Queue *q, int data) {
    if (isQueueFull(q)) {
        printf("Error: Queue is full\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = data;
    printf("%d enqueued successfully\n", data);
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int data = q->arr[q->front];
    q->front++;
    printf("%d dequeued successfully\n", data);
    return data;
}

int main() {
    Queue q;
    initQueue(&q);
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); // Error: Queue is full
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q); // Error: Queue is empty
    
    return 0;
}
//FormAI DATASET v1.0 Category: Queue ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct queue {
    int front, rear;
    int arr[MAX_QUEUE_SIZE];
} Queue;

void init_queue(Queue* q) {
    q->front = q->rear = -1;
}

int is_empty(Queue* q) {
    return q->front == -1;
}

int is_full(Queue* q) {
    return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

void enqueue(Queue* q, int val) {
    if (is_full(q)) {
        printf("Queue is full, cannot insert.\n");
        return;
    }
    if (is_empty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    }
    q->arr[q->rear] = val;
}

int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty, cannot delete.\n");
        return -1;
    }
    int deleted = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    return deleted;
}

int main() {
    Queue q;
    init_queue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    enqueue(&q, 40);
    enqueue(&q, 50);
    while (!is_empty(&q)) {
        printf("Dequeued: %d\n", dequeue(&q));
    }
    return 0;
}
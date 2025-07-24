//FormAI DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int front, rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

int is_full(Queue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int is_empty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        printf("[ERROR] Queue is full!\n");
        return;
    }
    q->items[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("[ERROR] Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return item;
}

int main() {
    Queue q;
    q.front = 0;
    q.rear = 0;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);

    int item = dequeue(&q);
    printf("Dequeued item = %d\n", item);

    item = dequeue(&q);
    printf("Dequeued item = %d\n", item);

    enqueue(&q, 70);

    while (!is_empty(&q)) {
        item = dequeue(&q);
        printf("Dequeued item = %d\n", item);
    }

    return 0;
}
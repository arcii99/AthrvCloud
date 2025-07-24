//FormAI DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX 50

typedef struct {
    int front;
    int rear;
    int size;
    int items[QUEUE_MAX];
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
    q->size = 0;
}

int isFull(Queue *q) {
    return q->size == QUEUE_MAX;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue overflow!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else if (q->rear == QUEUE_MAX - 1) {
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = value;
    q->size++;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow!\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else if (q->front == QUEUE_MAX - 1) {
        q->front = 0;
    } else {
        q->front++;
    }
    q->size--;
    return value;
}

int main() {
    Queue q;
    initQueue(&q);

    // Testing enqueue and dequeue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Dequeued %d from the queue\n", dequeue(&q));
    printf("Dequeued %d from the queue\n", dequeue(&q));

    enqueue(&q, 60);
    enqueue(&q, 70);
    enqueue(&q, 80);
    enqueue(&q, 90);

    printf("Queue front: %d\n", q.items[q.front]);
    printf("Queue rear: %d\n", q.items[q.rear]);

    printf("Dequeued %d from the queue\n", dequeue(&q));
    printf("Dequeued %d from the queue\n", dequeue(&q));
    printf("Dequeued %d from the queue\n", dequeue(&q));
    printf("Dequeued %d from the queue\n", dequeue(&q));
    printf("Dequeued %d from the queue\n", dequeue(&q));

    // Testing underflow
    printf("Dequeued %d from the queue\n", dequeue(&q));

    return 0;
}
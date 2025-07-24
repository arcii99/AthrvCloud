//FormAI DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

typedef struct queue {
    int items[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void enqueue(Queue *q, int value) {
    if(q->rear == QUEUE_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if(q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued %d to position %d\n", value, q->rear);
}

int dequeue(Queue *q) {
    if(q->front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if(q->front > q->rear) {
        q->front = q->rear = -1;
    }
    printf("Dequeued %d from position %d\n", item, q->front);
    return item;
}

void display(Queue *q) {
    if(q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue:\n");
    for(int i=q->front; i<=q->rear; i++) {
        printf("%d\n", q->items[i]);
    }
}

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 7);
    enqueue(&q, 8);

    display(&q);

    return 0;
}
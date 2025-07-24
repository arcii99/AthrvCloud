//FormAI DATASET v1.0 Category: Queue ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 5 

typedef struct queue {
    int items[MAXQUEUE];
    int front;
    int rear;
} Queue;

void initQueue (Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull (Queue* q) {
    return (q->rear == MAXQUEUE - 1);
}

int isEmpty (Queue* q) {
    return (q->rear == -1 || q->front > q->rear);
}

void enqueue (Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted %d into the queue\n", value);
    }
}

int dequeue (Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
    }
    return item;
}

void printQueue (Queue* q) {
    int i = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: \n");
        for (i = q->front; i < q->rear + 1; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);

    printQueue(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    printf("After three dequeues: \n");

    printQueue(&q);

    return 0;
}
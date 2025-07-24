//FormAI DATASET v1.0 Category: Queue Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_CAPACITY 5

struct Queue {
    int items[QUEUE_CAPACITY];
    int front;
    int rear;
};

void initQueue(struct Queue* Q) {
    Q->front = -1;
    Q->rear = -1;
}

int isQueueEmpty(struct Queue* Q) {
    if (Q->front == -1 && Q->rear == -1) {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue* Q, int item) {
    if ((Q->rear + 1) % QUEUE_CAPACITY == Q->front) {
        printf("Uh oh! Looks like the queue is full\n");
        return;
    } else if (isQueueEmpty(Q)) {
        Q->front = 0;
        Q->rear = 0;
        Q->items[Q->rear] = item;
    } else {
        Q->rear = (Q->rear + 1) % QUEUE_CAPACITY;
        Q->items[Q->rear] = item;
    }
}

int dequeue(struct Queue* Q) {
    int item;
    if (isQueueEmpty(Q)) {
        printf("Uh oh! Looks like the queue is empty\n");
        return -1;
    } else if (Q->front == Q->rear) {
        item = Q->items[Q->front];
        Q->front = -1;
        Q->rear = -1;
    } else {
        item = Q->items[Q->front];
        Q->front = (Q->front + 1) % QUEUE_CAPACITY;
    }
    return item;
}

int main() {
    struct Queue Q;
    initQueue(&Q);

    printf("Welcome to the Queue Puzzle!\n");

    printf("Adding 1 to the queue\n");
    enqueue(&Q, 1);

    printf("Adding 2 to the queue\n");
    enqueue(&Q, 2);

    printf("Adding 3 to the queue\n");
    enqueue(&Q, 3);

    printf("Adding 4 to the queue\n");
    enqueue(&Q, 4);

    printf("Adding 5 to the queue\n");
    enqueue(&Q, 5);

    printf("Adding 6 to the queue\n");
    enqueue(&Q, 6);

    printf("Removing an item from the queue: %d\n", dequeue(&Q));

    printf("Adding 7 to the queue\n");
    enqueue(&Q, 7);

    printf("Removing an item from the queue: %d\n", dequeue(&Q));

    printf("Removing an item from the queue: %d\n", dequeue(&Q));

    printf("Removing an item from the queue: %d\n", dequeue(&Q));

    printf("Removing an item from the queue: %d\n", dequeue(&Q));

    printf("Removing an item from the queue: %d\n", dequeue(&Q));

    return 0;
}
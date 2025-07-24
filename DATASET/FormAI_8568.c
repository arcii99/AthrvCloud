//FormAI DATASET v1.0 Category: Queue Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Declare the Queue structure
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Initialize the Queue
void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the Queue is empty
int isQueueEmpty(struct Queue *q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Check if the Queue is full
int isQueueFull(struct Queue *q) {
    if (q->rear == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

// Add an item to the Queue
void enqueue(struct Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("Oops! Queue overflow: Shape shifting into a Circle Queue.\n");
        q->front = 0;
        q->rear = 0;
        q->items[q->rear] = value;
    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
    printf("Enqueued item: %d\n", value);
}

// Remove an item from the Queue
int dequeue(struct Queue *q) {
    int item;
    if (isQueueEmpty(q)) {
        printf("Oops! Queue underflow: Shape shifting into a Stack Queue.\n");
        q->front = MAX_SIZE - 1;
        q->rear = MAX_SIZE - 1;
        item = q->items[q->front];
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            printf("Queue is now empty!\n");
            q->front = -1;
            q->rear = -1;
        }
    }
    printf("Dequeued item: %d\n", item);
    return item;
}

int main() {
    struct Queue q;
    initQueue(&q);

    // Enqueue some items
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);
    enqueue(&q, 10);
    enqueue(&q, 11);
    enqueue(&q, 12);

    // Dequeue some items
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    // Enqueue some more items
    enqueue(&q, 13);
    enqueue(&q, 14);
    enqueue(&q, 15);

    // Dequeue some more items
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    return 0;
}
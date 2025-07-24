//FormAI DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

// Define the queue struct
typedef struct Queue {
    int items[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    if (q->rear == -1) {
        return 1;
    }
    return 0;
}

// Check if the queue is full
int isFull(Queue *q) {
    if (q->rear == QUEUE_SIZE - 1) {
        return 1;
    }
    return 0;
}

// Add an item to the queue
void enqueue(Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = item;
        printf("Enqueued item: %d\n", item);
    }
}

// Remove an item from the queue
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Dequeued item: %d\n", q->items[q->front]);
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
}

// Print the queue
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue:\n");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Testing the queue implementation
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printQueue(&q);

    dequeue(&q);

    printQueue(&q);

    return 0;
}
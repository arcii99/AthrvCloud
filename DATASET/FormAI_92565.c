//FormAI DATASET v1.0 Category: Queue ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Maximum size of the Queue

// Structure of the Queue
struct Queue {
    int array[MAX_SIZE];
    int front;
    int rear;
};

// Initialize the Queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the Queue is empty
int isQueueEmpty(struct Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

// Check if the Queue is full
int isQueueFull(struct Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// Add an element to the Queue
void enqueue(struct Queue* q, int num) {
    if (isQueueFull(q)) {
        printf("Queue is full\n");
        return;
    }

    if (isQueueEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }

    q->array[q->rear] = num;
}

// Remove an element from the Queue
int dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    int num = q->array[q->front];

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }

    return num;
}

// Print the elements in the Queue
void printQueue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", q->array[i]);
    }
    printf("%d\n", q->array[i]);
}

int main() {
    struct Queue myQueue;
    initQueue(&myQueue);

    printf("Queue is empty = %d\n", isQueueEmpty(&myQueue));
    printf("Queue is full = %d\n", isQueueFull(&myQueue));

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    enqueue(&myQueue, 40);
    enqueue(&myQueue, 50);

    printQueue(&myQueue);
    printf("Queue is empty = %d\n", isQueueEmpty(&myQueue));
    printf("Queue is full = %d\n", isQueueFull(&myQueue));

    int num = dequeue(&myQueue);
    printf("Removed %d from the Queue\n", num);

    printQueue(&myQueue);
}
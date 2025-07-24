//FormAI DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

// Queue struct
typedef struct Queue {
    int arr[QUEUE_SIZE];
    int front, rear;
} queue;

// Initialize queue with empty values
void initQueue(queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is full
int isFull(queue* q) {
    if ((q->front == 0 && q->rear == QUEUE_SIZE - 1) || q->front == q->rear + 1) {
        return 1;
    }
    return 0;
}

// Check if queue is empty
int isEmpty(queue* q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

// Insert element into queue
void enqueue(queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->arr[q->rear] = value;
}

// Remove element from queue
int dequeue(queue* q) {
    int value;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % QUEUE_SIZE;
    }
    return value;
}

int main() {
    queue q;
    initQueue(&q);

    // Insert elements into queue
    for (int i = 1; i <= 5; i++) {
        enqueue(&q, i * 10);
    }

    // Remove elements from queue
    int removedItem = dequeue(&q);
    printf("Removed item: %d\n", removedItem);

    // Insert more elements into queue
    for (int i = 6; i <= 12; i++) {
        enqueue(&q, i * 10);
    }

    // Remove all elements from queue
    while (!isEmpty(&q)) {
        removedItem = dequeue(&q);
        printf("Removed item: %d\n", removedItem);
    }

    return 0;
}
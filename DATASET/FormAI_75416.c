//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10 // Maximum queue size

// Queue struct
typedef struct {
    int front, rear;
    int elements[MAX_QUEUE_SIZE];
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isQueueEmpty(Queue* q) {
    return (q->front == -1);
}

// Check if the queue is full
int isQueueFull(Queue* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// Add element to the queue
void enqueue(Queue* q, int element) {
    if (isQueueFull(q)) {
        printf("Queue overflow\n");
        exit(EXIT_FAILURE);
    }
    if (isQueueEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    }
    q->elements[q->rear] = element;
}

// Remove element from the queue
int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue underflow\n");
        exit(EXIT_FAILURE);
    }
    int element = q->elements[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    return element;
}

int main() {
    Queue q;
    initQueue(&q);

    // Add elements to the queue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    // Remove elements from the queue
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));

    return 0;
}
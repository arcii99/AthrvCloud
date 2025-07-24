//FormAI DATASET v1.0 Category: Queue Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100 // Maximum number of queue elements

// Queue struct
typedef struct {
    int front;  // Queue front
    int rear;   // Queue rear
    int items[MAX_QUEUE_SIZE];  // Array containing items in the queue
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue *q) {
    if (q->front == -1 && q->rear == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to check if the queue is full
int isQueueFull(Queue *q) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to add an item to the queue
void enqueue(Queue *q, int x) {
    if (isQueueFull(q)) {
        printf("Error: Queue is full\n");
    }
    else if (isQueueEmpty(q)) {
        q->front = 0;
        q->rear = 0;
        q->items[q->rear] = x;
    }
    else {
        q->rear++;
        q->items[q->rear] = x;
    }
}

// Function to remove an item from the queue
int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    else if (q->front == q->rear) {
        int x = q->items[q->front];
        q->front = -1;
        q->rear = -1;
        return x;
    }
    else {
        int x = q->items[q->front];
        q->front++;
        return x;
    }
}

int main() {
    Queue q;     // Create the queue
    initializeQueue(&q);    // Initialize the queue
    
    // Enqueue some items
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    
    // Dequeue and print the items
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    
    return 0;
}
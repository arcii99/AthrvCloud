//FormAI DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

// Create a structure to represent the queue
typedef struct {
    int front;
    int rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

// Function declarations
void initQueue(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
void printQueue(Queue *q);

int main() {
    // Initialize the queue
    Queue q;
    initQueue(&q);
    
    // Enqueue some values
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    printf("Queue after enqueue operations:\n");
    printQueue(&q);
    
    // Dequeue a value
    int removedValue = dequeue(&q);
    printf("Removed value: %d\n", removedValue);
    printf("Queue after dequeue operation:\n");
    printQueue(&q);
    
    // Enqueue more values
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);
    enqueue(&q, 10);
    printf("Queue after more enqueue operations:\n");
    printQueue(&q);
    
    // Try to enqueue one more value
    printf("Attempting to enqueue one more value:\n");
    enqueue(&q, 11);
    
    return 0;
}

// Initialize the queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Check if the queue is full
int isFull(Queue *q) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    if (q->rear < q->front) {
        return 1;
    }
    else {
        return 0;
    }
}

// Add an item to the queue
void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", data);
        return;
    }
    else {
        q->rear++;
        q->items[q->rear] = data;
    }
}

// Remove an item from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    else {
        int removedValue = q->items[q->front];
        q->front++;
        return removedValue;
    }
}

// Print the contents of the queue
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue:\n");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}
//FormAI DATASET v1.0 Category: Queue Implementation ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 100 // maximum size of the queue

typedef struct {
    int front; // index of the first element in the queue
    int rear; // index of the last element in the queue
    int count; // total number of elements in the queue
    int data[MAX_QUEUE_SIZE]; // array to hold the elements
} Queue;

/**
 * Initializes the queue.
 */
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

/**
 * Adds an element to the end of the queue.
 */
void enqueue(Queue *q, int value) {
    if (q->count == MAX_QUEUE_SIZE) {
        printf("Queue overflow!\n");
        exit(EXIT_FAILURE);
    }
    
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = value;
    q->count++;
}

/**
 * Removes an element from the front of the queue.
 */
int dequeue(Queue *q) {
    if (q->count == 0) {
        printf("Queue underflow!\n");
        exit(EXIT_FAILURE);
    }
    
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->count--;
    
    return value;
}

/**
 * Returns the value at the front of the queue without removing it.
 */
int peek(Queue *q) {
    if (q->count == 0) {
        printf("Queue underflow!\n");
        exit(EXIT_FAILURE);
    }
    
    return q->data[q->front];
}

int main() {
    Queue q;
    initQueue(&q);

    // Adding elements to the queue
    enqueue(&q, 5);
    enqueue(&q, 7);
    enqueue(&q, 10);
    enqueue(&q, 15);

    // Printing the queue using dequeue operation
    while (q.count > 0) {
        printf("%d ", dequeue(&q));
    }

    return 0;
}
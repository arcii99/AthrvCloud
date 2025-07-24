//FormAI DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_QUEUE_SIZE 10

// Define the queue element structure
typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int count; // Stores the count of elements in the queue
} Queue;

// Function to initialize the queue
void init_queue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Function to check if the queue is empty
int is_empty(Queue *q) {
    return (q->count == 0);
}

// Function to check if the queue is full
int is_full(Queue *q) {
    return (q->count == MAX_QUEUE_SIZE);
}

// Recursive function to enqueue an element in the queue
void enqueue(Queue *q, int element) {
    // Base case : If the queue is full, return
    if (is_full(q)) {
        return;
    }
    
    // Recursive case : 
    // 1. Increment the rear index and store the element
    // 2. Increment the count of elements in the queue
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = element;
    q->count++;

    // Check if the queue is not empty
    if (!is_empty(q)) {
        // Dequeue the previously enqueued element
        int temp = q->data[q->front];
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        q->count--;
       
        // Recursive call to enqueue the dequeued element at the end of the queue
        enqueue(q, temp);
    }
}

// Main function
int main() {
    Queue q;
    init_queue(&q);

    // Enqueue elements in the queue recursively
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);
    enqueue(&q, 10); // The queue is full at this point and no more elements can be enqueued

    // Dequeue and print the elements in the queue
    printf("Elements in the queue : ");
    while (!is_empty(&q)) {
        int element = q.data[q.front];
        printf("%d ", element);
        q.front = (q.front + 1) % MAX_QUEUE_SIZE;
        q.count--;
    }

    return 0;
}
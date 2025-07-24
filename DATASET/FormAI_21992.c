//FormAI DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100 // Maximum queue size

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front; // Index of front element in the queue
    int rear; // Index of rear element in the queue
} Queue;

// Initialize the queue
void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int is_empty(Queue *q) {
    return q->front == -1 && q->rear == -1;
}

// Check if the queue is full
int is_full(Queue *q) {
    return q->rear == MAX_QUEUE_SIZE - 1;
}

// Enqueue an element into the queue
void enqueue(Queue *q, int x) {
    // Check if the queue is full
    if (is_full(q)) {
        printf("Queue Overflow!\n");
        return;
    }

    // If the queue is empty, set the front and rear to 0
    // Else, increment the rear index and enqueue the new element
    if (is_empty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }

    q->data[q->rear] = x; // Add the new element to the queue
}

// Dequeue an element from the queue
int dequeue(Queue *q) {
    // Check if the queue is empty
    if (is_empty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }

    int dequeued_element = q->data[q->front]; // Save the front element
    if (q->front == q->rear) { // If only one element in the queue
        q->front = -1;
        q->rear = -1;
    } else { // Else, increment the front index
        q->front++;
    }

    return dequeued_element;
}

// Print the elements in the queue
void print(Queue *q) {
    // Check if the queue is empty
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    print(&q);

    dequeue(&q);
    dequeue(&q);
    print(&q);

    enqueue(&q, 50);
    enqueue(&q, 60);
    print(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    print(&q);

    dequeue(&q);
    print(&q);

    return 0;
}
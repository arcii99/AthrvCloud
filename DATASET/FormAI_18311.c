//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_QUEUE_SIZE 100

// Define the structure of a bag
typedef struct {
    int id;
    int weight;
} Bag;

// Define the structure of the queue
typedef struct {
    Bag data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Initialize the queue
void init_queue(Queue *q) {
    q->front = q->rear = 0;
}

// Check if the queue is full
int is_full(Queue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

// Check if the queue is empty
int is_empty(Queue *q) {
    return q->front == q->rear;
}

// Add a bag to the queue
void enqueue(Queue *q, Bag bag) {
    if (is_full(q)) {
        printf("Error: queue is full\n");
        exit(1);
    }
    q->data[q->rear] = bag;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

// Remove a bag from the queue
Bag dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Error: queue is empty\n");
        exit(1);
    }
    Bag bag = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return bag;
}

int main() {
    // Initialize the queue
    Queue q;
    init_queue(&q);

    // Simulate bags coming in from the check-in counter
    Bag bag1 = {1, 20};
    Bag bag2 = {2, 30};
    Bag bag3 = {3, 40};
    enqueue(&q, bag1);
    enqueue(&q, bag2);
    enqueue(&q, bag3);

    // Simulate bags being moved through the conveyor belt
    while (!is_empty(&q)) {
        Bag bag = dequeue(&q);
        printf("Bag %d with weight %d is being moved\n", bag.id, bag.weight);
    }

    return 0;
}
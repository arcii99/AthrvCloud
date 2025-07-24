//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Alan Touring
// Alan Turing Style C Queue Implementation

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Define Queue struct
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function prototypes
void enqueue(struct Queue* q, int item);
int dequeue(struct Queue* q);
void display(struct Queue* q);

int main() {
    // Declare and initialize Queue
    struct Queue q;
    q.front = -1;
    q.rear = -1;

    // Test Queue functions
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    display(&q);

    dequeue(&q);
    display(&q);

    enqueue(&q, 4);
    display(&q);

    return 0;
}

// Adds item to the rear of the Queue
void enqueue(struct Queue* q, int item) {
    // Check if Queue is full
    if (q->rear == MAX_SIZE - 1) {
        printf("Error: Queue is full\n");
        return;
    }

    // Increment rear and add item to Queue
    if (q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = item;
    printf("Enqueued %d\n", item);
}

// Removes item from the front of the Queue
int dequeue(struct Queue* q) {
    // Check if Queue is empty
    if (q->front == -1) {
        printf("Error: Queue is empty\n");
        return -1;
    }

    // Get front item and increment front
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    printf("Dequeued %d\n", item);
    return item;
}

// Displays all items in the Queue
void display(struct Queue* q) {
    // Check if Queue is empty
    if (q->front == -1) {
        printf("Error: Queue is empty\n");
        return;
    }

    // Traverse Queue and print items
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}
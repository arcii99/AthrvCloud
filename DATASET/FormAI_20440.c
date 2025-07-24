//FormAI DATASET v1.0 Category: Queue ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

// Define the queue structure
typedef struct {
    int front;
    int rear;
    int items[MAX_SIZE];
} Queue;

// Initialize a queue
void initialize(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Add an item to the queue
void enqueue(Queue *q, int data) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Error: Queue is full.\n");
        exit(1);
    } else {
        q->rear++;
        q->items[q->rear] = data;
    }
}

// Remove an item from the queue
int dequeue(Queue *q) {
    if (q->front > q->rear) {
        printf("Error: Queue is empty.\n");
        exit(1);
    } else {
        int data = q->items[q->front];
        q->front++;
        return data;
    }
}

// Print the queue
void print(Queue *q) {
    if (q->front > q->rear) {
        printf("Error: Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initialize(&q);

    // Add some items to the queue
    enqueue(&q, 1);
    enqueue(&q, 3);
    enqueue(&q, 5);

    // Remove an item from the queue
    int data = dequeue(&q);
    printf("Removed from queue: %d\n", data);

    // Print the queue
    print(&q);

    return 0;
}
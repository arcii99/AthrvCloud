//FormAI DATASET v1.0 Category: Queue ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Defining the maximum size of our Queue
#define MAX_SIZE 5

// Defining our Queue structure
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function prototypes
void enqueue(struct Queue *q, int value);
int dequeue(struct Queue *q);
void display(struct Queue *q);

int main() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;

    // Enqueueing some values into our Queue
    printf("Enqueueing values 10, 20, 30, 40, and 50...\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    // Displaying our Queue
    printf("Our Queue is currently: ");
    display(&q);

    // Dequeueing some values from our Queue
    printf("\nDequeueing two values from our Queue...\n");
    dequeue(&q);
    dequeue(&q);

    // Displaying our Queue again
    printf("Our Queue is now: ");
    display(&q);

    // Enqueueing another value into our Queue
    printf("\nEnqueueing value 60...\n");
    enqueue(&q, 60);

    // Displaying our Queue once more
    printf("Our Queue is now: ");
    display(&q);

    return 0;
}

// Enqueue function to insert values into the Queue
void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full! Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Enqueued %d successfully!\n", value);
    }
}

// Dequeue function to remove values from the Queue
int dequeue(struct Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    } else {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        printf("Dequeued %d successfully!\n", item);
        return item;
    }
}

// Display function to print the values of our Queue
void display(struct Queue *q) {
    if (q->rear == -1) {
        printf("Queue is empty!\n");
    } else {
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}
//FormAI DATASET v1.0 Category: Queue Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5    // Maximum size of the queue
#define TRUE 1
#define FALSE 0

// Initialize the queue
struct Queue {
   int items[MAXSIZE];
   int front;
   int rear;
   int size;
};
typedef struct Queue queue;

void initialize(queue *q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

// Check if the queue is empty
int isEmpty(queue *q) {
    return q->front == -1 && q->rear == -1;
}

// Check if the queue is full
int isFull(queue *q) {
    return q->rear == MAXSIZE - 1;
}

// Add an element to the queue
void enqueue(queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    else if (isEmpty(q)) {
        q->front = q->rear = 0;
    }
    else {
        q->rear++;
    }
    q->items[q->rear] = value;
    q->size++;
}

// Remove an element from the queue
int dequeue(queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return FALSE;
    }
    else if (q->front == q->rear) {
        item = q->items[q->front];
        q->front = q->rear = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
    }
    q->size--;
    return item;
}

// Display the elements of the queue
void display(queue *q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue elements: \n");
        for (i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    queue myqueue;
    initialize(&myqueue);

    // Add elements
    enqueue(&myqueue, 1);
    enqueue(&myqueue, 2);
    enqueue(&myqueue, 3);
    enqueue(&myqueue, 4);
    enqueue(&myqueue, 5);

    // Try adding more elements
    enqueue(&myqueue, 6);

    // Display elements
    display(&myqueue);

    // Remove some elements
    printf("Removed element: %d\n", dequeue(&myqueue));
    printf("Removed element: %d\n", dequeue(&myqueue));

    // Display elements
    display(&myqueue);

    // Add more elements
    enqueue(&myqueue, 6);
    enqueue(&myqueue, 7);

    // Display elements
    display(&myqueue);

    return 0;
}
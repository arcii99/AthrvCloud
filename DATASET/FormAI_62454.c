//FormAI DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

typedef struct {
    int front, rear;
    int items[QUEUE_SIZE];
} Queue;

// Function to check if the queue is full
int isFull(Queue* q) {
    return (q->rear == QUEUE_SIZE - 1 && q->front == 0) || (q->rear + 1 == q->front);
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to add an item to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % QUEUE_SIZE;
        q->items[q->rear] = value;
        printf("Inserted %d into queue\n", value);
    }
}

// Function to remove an item from the queue
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        item = -1;
    } else {
        item = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % QUEUE_SIZE;
        }
    }
    return item;
}

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;

    // Adding 5 elements to the queue
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    // Removing 3 elements from the queue
    printf("Removed %d from queue\n", dequeue(&q));
    printf("Removed %d from queue\n", dequeue(&q));
    printf("Removed %d from queue\n", dequeue(&q));

    // Adding 2 elements to the queue
    enqueue(&q, 6);
    enqueue(&q, 7);

    // Removing all elements from the queue
    while (!isEmpty(&q)) {
        printf("Removed %d from queue\n", dequeue(&q));
    }

    // Trying to remove an element from empty queue
    dequeue(&q);

    return 0;
}
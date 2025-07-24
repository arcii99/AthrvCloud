//FormAI DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int front, rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

//Initialize the Queue
void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(Queue *q) {
    return ((q->front == q->rear + 1) || (q->front == 0 && q->rear == MAX_QUEUE_SIZE - 1));
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1);
}

// Add an item to the queue
void enqueue(Queue *q, int element) {
    if (isFull(q)) {
        printf("Queue is full!");
    }
    else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->items[q->rear] = element;
        printf("\nInserted element: %d", element);
    }
}

// Remove an item from the queue
int dequeue(Queue *q) {
    int element;
    if (isEmpty(q)) {
        printf("Queue is empty!");
        return (-1);
    }
    else {
        element = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } 
        else {
            q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        }
        return (element);
    }
}

int main() {
    Queue q;
    initialize(&q);

    // Enqueue a few elements
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    // Dequeue a few elements
    printf("\nDeleted element: %d", dequeue(&q));
    printf("\nDeleted element: %d", dequeue(&q));
    printf("\nDeleted element: %d", dequeue(&q));

    // Enqueue a few more elements
    enqueue(&q, 60);
    enqueue(&q, 70);
    enqueue(&q, 80);
    enqueue(&q, 90);

    // Dequeue all the remaining elements
    while (!isEmpty(&q)) {
        printf("\nDeleted element: %d", dequeue(&q));
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10 // Maximum allowed size for the queue

// Defining the queue structure
typedef struct {
    int front, rear;
    int arr[MAX_SIZE];
} Queue;

// Function to initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue *q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isQueueFull(Queue *q) {
    return q->rear == MAX_SIZE-1;
}

// Function to add items to the queue
void enqueue(Queue *q, int item) {
    if(isQueueFull(q)) {
        printf("Queue full. Cannot enqueue %d\n", item);
        return;
    }
    if(isQueueEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->arr[q->rear] = item;
    printf("%d enqueued to the queue.\n", item);
}

// Function to remove an item from the queue
int dequeue(Queue *q) {
    if(isQueueEmpty(q)) {
        printf("Queue empty. Cannot dequeue an item.\n");
        return -1;
    }
    int item = q->arr[q->front];
    if(q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    printf("%d dequeued from the queue.\n", item);
    return item;
}

// Function to display the queue
void displayQueue(Queue *q) {
    if(isQueueEmpty(q)) {
        printf("Queue empty. Nothing to display.\n");
        return;
    }
    printf("Queue: ");
    for(int i=q->front; i<=q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    // Testing the queue implementation
    printf("Adding 5 items to the queue:\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    displayQueue(&q);

    printf("Removing 2 items from the queue:\n");
    dequeue(&q);
    dequeue(&q);
    displayQueue(&q);

    printf("Adding 2 items to the queue:\n");
    enqueue(&q, 60);
    enqueue(&q, 70);
    displayQueue(&q);

    printf("Removing 3 items from the queue:\n");
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    displayQueue(&q);

    return 0;
}
//FormAI DATASET v1.0 Category: Queue Implementation ; Style: authentic
#include <stdio.h>
#define MAX_QUEUE_SIZE 20

// Struct representing a queue
struct queue {
    int arr[MAX_QUEUE_SIZE];
    int front, rear;
};

// Function to initialize a queue
void initializeQueue(struct queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isQueueEmpty(struct queue *q) {
    return (q->front == -1 && q->rear == -1);
}

// Function to check if the queue is full
int isQueueFull(struct queue *q) {
    return (q->rear == MAX_QUEUE_SIZE - 1);
}

// Function to add an element to the queue
void enqueue(struct queue *q, int x) {
    if (isQueueFull(q)) {
        printf("Queue is full, cannot add element.\n");
        return;
    }
    else if (isQueueEmpty(q)) {
        q->front = q->rear = 0;
    }
    else {
        q->rear++;
    }
    q->arr[q->rear] = x;
}

// Function to remove an element from the queue
int dequeue(struct queue *q) {
    int x;
    if (isQueueEmpty(q)) {
        printf("Queue is empty, cannot remove element.\n");
        return -1;
    }
    else if (q->front == q->rear) {
        x = q->arr[q->front];
        q->front = q->rear = -1;
    }
    else {
        x = q->arr[q->front];
        q->front++;
    }
    return x;
}

// Function to display the queue
void display(struct queue *q) {
    int i;
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("After enqueuing 10, 20, 30: ");
    display(&q);

    dequeue(&q);
    printf("After dequeuing: ");
    display(&q);

    enqueue(&q, 40);
    printf("After enqueuing 40: ");
    display(&q);

    return 0;
}
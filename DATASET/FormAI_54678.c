//FormAI DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 100

// Structure of the queue
typedef struct {
    int queue[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// Initialize the queue
void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    if (q->front == -1 && q->rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Check if the queue is full
int isFull(Queue *q) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Add an element to the queue
void enqueue(Queue *q, int x) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    } else if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->queue[q->rear] = x;
}

// Remove an element from the queue
int dequeue(Queue *q) {
    int x = 0;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else if (q->front == q->rear) {
        x = q->queue[q->front];
        q->front = q->rear = -1;
    } else {
        x = q->queue[q->front];
        q->front++;
    }
    return x;
}

// Display the contents of the Queue
void displayQueue(Queue q) {
    int i;
    if (isEmpty(&q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Front -> ");
        for (i = q.front; i <= q.rear; i++) {
            printf("%d -> ", q.queue[i]);
        }
        printf("Rear\n");
    }
}

int main() {
    Queue q;
    init(&q);
    
    // Add elements to the queue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    // Display the contents of the queue
    displayQueue(q);

    // Remove elements from the queue and display them
    printf("%d dequeued from the queue\n", dequeue(&q));
    printf("%d dequeued from the queue\n", dequeue(&q));

    // Display the contents of the queue again
    displayQueue(q);

    return 0;
}
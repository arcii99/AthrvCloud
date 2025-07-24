//FormAI DATASET v1.0 Category: Queue Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 50

// Create a queue struct
struct Queue {
    int front, rear, size;
    int data[MAX_QUEUE_SIZE];
};

// Initialize the queue
void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

// Check if queue is empty
int isEmpty(struct Queue *q) {
    return q->size == 0;
}

// Check if queue is full
int isFull(struct Queue *q) {
    return q->size == MAX_QUEUE_SIZE;
}

// Add an element to the queue
void enqueue(struct Queue *q, int value) {
    if(isFull(q)) {
        printf("Queue is full!\n");
        return;
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->data[q->rear] = value;
        q->size++;

        if(q->front == -1) {
            q->front = q->rear;
        }
    }
}

// Remove an element from the queue
int dequeue(struct Queue *q) {
    int value;

    if(isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        value = q->data[q->front];
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        q->size--;

        if(q->size == 0) {
            q->front = -1;
            q->rear = -1;
        }
    }

    return value;
}

// Print the queue
void printQueue(struct Queue *q) {
    int i;

    if(isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Front [ ");
    for(i = q->front; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", q->data[i]);
    }
    printf("%d ", q->data[i]);
    printf("] Rear\n");
}

int main() {
    struct Queue q;

    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    printQueue(&q);

    dequeue(&q);
    dequeue(&q);
    printQueue(&q);

    enqueue(&q, 60);
    enqueue(&q, 70);
    printQueue(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    printQueue(&q);

    dequeue(&q);
    printQueue(&q);

    dequeue(&q);
    return 0;
}
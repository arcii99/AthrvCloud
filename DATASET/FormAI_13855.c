//FormAI DATASET v1.0 Category: Queue Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_CAPACITY 10 // maximum capacity of the queue

typedef struct {
    int data[QUEUE_CAPACITY]; // array to store the queue data
    int front; // index of the front of the queue
    int rear; // index of the rear of the queue
    int size; // number of elements currently in the queue
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isFull(Queue *q) {
    return q->size == QUEUE_CAPACITY ? 1 : 0;
}

int isEmpty(Queue *q) {
    return q->size == 0 ? 1 : 0;
}

void enqueue(Queue *q, int value) {
    if (!isFull(q)) { // if queue is not full
        q->rear = (q->rear + 1) % QUEUE_CAPACITY;
        q->data[q->rear] = value;
        q->size++;
    }
}

int dequeue(Queue *q) {
    if (!isEmpty(q)) { // if queue is not empty
        int value = q->data[q->front];
        q->front = (q->front + 1) % QUEUE_CAPACITY;
        q->size--;
        return value;
    }
    return -1; // return -1 to indicate error (queue is empty)
}

int main() {
    Queue q;
    initQueue(&q);
    printf("Queue initialized. Current size is %d.\n", q.size);
    enqueue(&q, 10);
    printf("Element %d enqueued. Current size is %d.\n", q.data[q.rear], q.size);
    enqueue(&q, 20);
    printf("Element %d enqueued. Current size is %d.\n", q.data[q.rear], q.size);
    enqueue(&q, 30);
    printf("Element %d enqueued. Current size is %d.\n", q.data[q.rear], q.size);
    printf("Dequeueing element %d...\n", q.data[q.front]);
    dequeue(&q);
    printf("Element dequeued. Current size is %d.\n", q.size);
    printf("Dequeueing element %d...\n", q.data[q.front]);
    dequeue(&q);
    printf("Element dequeued. Current size is %d.\n", q.size);
    printf("Dequeueing element %d...\n", q.data[q.front]);
    dequeue(&q);
    printf("Element dequeued. Current size is %d.\n", q.size);
    printf("Trying to dequeue again...\n");
    dequeue(&q);
    printf("Element dequeued. Current size is %d.\n", q.size);
    return 0;
}
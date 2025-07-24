//FormAI DATASET v1.0 Category: Queue Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    if ((q->rear + 1) % MAX_SIZE == q->front) {
        return 1;
    }
    return 0;
}

int isEmpty(Queue *q) {
    if (q->front == -1 && q->rear == -1) {
        return 1;
    }
    return 0;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Cannot insert, queue is full!\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }

    q->data[q->rear] = value;
    printf("Inserted %d into the queue.\n", value);
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty, nothing to delete.\n");
        return;
    }

    int deletedValue = q->data[q->front];
    printf("Deleted %d from the queue.\n", deletedValue);

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty, nothing to display.\n");
        return;
    }

    printf("Queue contents: ");
    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", q->data[i]);
    }
    printf("%d\n", q->data[i]);
}

int main() {
    Queue q;
    initialize(&q);

    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 20);
    enqueue(&q, 25); // Queue is now full
    enqueue(&q, 30); // Cannot insert, queue is full!
    display(&q); // Queue contents: 5 10 15 20 25

    dequeue(&q);
    dequeue(&q);
    display(&q); // Queue contents: 15 20 25

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q); // Queue is now empty
    dequeue(&q); // Queue is empty, nothing to delete.
    display(&q); // Queue is empty, nothing to display.

    return 0;
}
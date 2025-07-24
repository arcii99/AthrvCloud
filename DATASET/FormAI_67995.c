//FormAI DATASET v1.0 Category: Queue Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// Defining a structure for Queue
struct queue {
    int q[SIZE];
    int front;
    int rear;
};

typedef struct queue Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int is_empty(Queue *q) {
    if (q->front == -1 && q->rear == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_full(Queue *q) {
    if ((q->rear + 1) % SIZE == q->front) {
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(Queue *q, int element) {
    if (is_full(q)) {
        printf("Queue overflow!\n");
    }
    else if (is_empty(q)) {
        q->front = 0;
        q->rear = 0;
        q->q[q->rear] = element;
    }
    else {
        q->rear = (q->rear + 1) % SIZE;
        q->q[q->rear] = element;
    }
}

int dequeue(Queue *q) {
    int element;

    if (is_empty(q)) {
        printf("Queue underflow!\n");
        return -1;
    }
    else if (q->front == q->rear) {
        element = q->q[q->front];
        q->front = -1;
        q->rear = -1;
    }
    else {
        element = q->q[q->front];
        q->front = (q->front + 1) % SIZE;
    }

    return element;
}

void display(Queue *q) {
    int i;

    if (is_empty(q)) {
        printf("Queue is empty!\n");
    }
    else {
        printf("Queue elements: ");
        for (i = q->front; i != q->rear; i = (i + 1) % SIZE) {
            printf("%d ", q->q[i]);
        }
        printf("%d\n", q->q[i]);
    }
}

int main() {
    Queue q;

    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));

    display(&q);

    enqueue(&q, 60);

    display(&q);

    return 0;
}
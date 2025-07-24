//FormAI DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int is_empty(Queue *q) {
    if (q->front == -1 && q->rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

int is_full(Queue *q) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Queue *q, int data) {
    if (is_full(q)) {
        printf("Queue is full\n");
    } else if (is_empty(q)) {
        q->front = q->rear = 0;
        q->data[q->rear] = data;
    } else {
        q->rear++;
        q->data[q->rear] = data;
    }
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else if (q->front == q->rear) {
        int data = q->data[q->front];
        q->front = q->rear = -1;
        return data;
    } else {
        int data = q->data[q->front];
        q->front++;
        return data;
    }
}

void print_queue(Queue *q) {
    if (is_empty(q)) {
        return;
    } else {
        printf("%d ", dequeue(q));
        print_queue(q);
    }
}

int main() {
    Queue q;
    initialize(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    printf("Elements in queue: ");
    print_queue(&q);
    return 0;
}
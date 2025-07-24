//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue createQueue() {
    Queue q;
    q.front = q.rear = -1;
    return q;
}

void enqueue(Queue *q, int data) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = data;
}

int dequeue(Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = q->arr[q->front];
    q->front++;
    return data;
}

void display(Queue q) {
    if (q.front == -1 || q.front > q.rear) {
        printf("Queue is empty!\n");
        return;
    }
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q = createQueue();
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    display(q);
    dequeue(&q);
    display(q);
    enqueue(&q, 4);
    enqueue(&q, 5);
    display(q);
    return 0;
}
//FormAI DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int arr[MAX_SIZE];
    int front, rear;
} Queue;

Queue* init_queue(Queue* q) {
    q->front = -1;
    q->rear = -1;
    return q;
}

int is_empty(Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

int is_full(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front ? 1 : 0;
}

void enqueue(Queue* q, int item) {
    if (is_full(q)) {
        printf("Queue is full\n");
        return;
    }
    else if (is_empty(q)) {
        q->front = q->rear = 0;
        q->arr[q->rear] = item;
    }
    else {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->arr[q->rear] = item;
    }
}

int dequeue(Queue* q) {
    int item;
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    else if (q->front == q->rear) {
        item = q->arr[q->front];
        q->front = q->rear = -1;
    }
    else {
        item = q->arr[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return item;
}

void display_queue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", q->arr[i]);
    }
    printf("%d", q->arr[q->rear]);
}

int main() {
    Queue q, *ptr;
    ptr = init_queue(&q);

    printf("Enqueuing elements...\n");
    enqueue(ptr, 6);
    enqueue(ptr, 7);
    enqueue(ptr, 8);
    enqueue(ptr, 9);
    enqueue(ptr, 10);
    enqueue(ptr, 1);
    enqueue(ptr, 2);
    enqueue(ptr, 3);
    enqueue(ptr, 4);
    enqueue(ptr, 5);

    printf("Dequeuing elements...\n");
    dequeue(ptr);
    dequeue(ptr);
    dequeue(ptr);

    display_queue(ptr);

    return 0;
}
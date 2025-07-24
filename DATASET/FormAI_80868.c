//FormAI DATASET v1.0 Category: Queue ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int front, rear;
    int arr[MAX_SIZE];
} Queue;

void init(Queue* q) {
    q->front = q->rear = -1;
}

int is_empty(Queue* q) {
    return q->front == -1 && q->rear == -1;
}

int is_full(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(Queue* q, int data) {
    if(is_full(q)) {
        printf("Queue is full!\n");
        return;
    }

    if(is_empty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }

    q->arr[q->rear] = data;
}

int dequeue(Queue* q) {
    if(is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int data = q->arr[q->front];
    if(q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }

    return data;
}

void print_queue(Queue* q) {
    if(is_empty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    int i = q->front;
    while(i != q->rear) {
        printf("%d, ", q->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", q->arr[i]);
}

int main() {
    Queue q;
    init(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    print_queue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    print_queue(&q);

    enqueue(&q, 5);
    enqueue(&q, 6);

    print_queue(&q);

    return 0;
}
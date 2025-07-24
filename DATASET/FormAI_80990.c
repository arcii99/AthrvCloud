//FormAI DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10 //maximum number of elements that can be stored in the queue

struct queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

int is_empty(struct queue *q) {
    return q->front == -1;
}

int is_full(struct queue *q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(struct queue *q, int item) {
    if (is_full(q)) {
        printf("Queue Overflow!\n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear++;
    q->arr[q->rear] = item;
    printf("Enqueued element: %d.\n", item);
}

int dequeue(struct queue *q) {
    if (is_empty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }

    int item = q->arr[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }

    printf("Dequeued element: %d.\n", item);
    return item;
}

void display(struct queue *q) {
    if (is_empty(q)) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("The queue is: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct queue q = { .front = -1, .rear = -1 };

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 7);
    enqueue(&q, 8);

    display(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    display(&q);

    return 0;
}
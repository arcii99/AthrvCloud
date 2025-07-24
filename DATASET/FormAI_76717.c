//FormAI DATASET v1.0 Category: Queue Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int arr[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    if ((q->front == 0 && q->rear == MAX_QUEUE_SIZE-1) || q->rear == q->front-1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(Queue *q) {
    if (q->front == -1) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Queue *q, int x) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; 
    q->arr[q->rear] = x;
}

int dequeue(Queue *q) {
    int x;
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    x = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    return x;
}

void display(Queue *q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty. Nothing to display.\n");
        return;
    }
    printf("Queue contents: ");
    if (q->rear >= q->front) {
        for (i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
    } else {
        for (i = q->front; i < MAX_QUEUE_SIZE; i++) {
            printf("%d ", q->arr[i]);
        }
        for (i = 0; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
    }
    printf("\n");
}

int main() {
    Queue q;
    initialize(&q);

    printf("Queue initialized.\n");
    printf("Front = %d, Rear = %d\n", q.front, q.rear);

    enqueue(&q, 1);
    printf("Enqueued 1.\n");
    printf("Front = %d, Rear = %d\n", q.front, q.rear);

    enqueue(&q, 2);
    printf("Enqueued 2.\n");
    printf("Front = %d, Rear = %d\n", q.front, q.rear);

    enqueue(&q, 3);
    printf("Enqueued 3.\n");
    printf("Front = %d, Rear = %d\n", q.front, q.rear);

    enqueue(&q, 4);
    printf("Enqueued 4.\n");
    printf("Front = %d, Rear = %d\n", q.front, q.rear);

    enqueue(&q, 5);
    printf("Enqueued 5.\n");
    printf("Front = %d, Rear = %d\n", q.front, q.rear);

    display(&q);

    dequeue(&q);
    printf("Dequeued element.\n");

    display(&q);

    enqueue(&q, 6);
    printf("Enqueued 6.\n");
    printf("Front = %d, Rear = %d\n", q.front, q.rear);

    display(&q);

    enqueue(&q, 7);
    printf("Enqueued 7.\n");
    printf("Front = %d, Rear = %d\n", q.front, q.rear);

    display(&q);

    enqueue(&q, 8);
    printf("Enqueued 8.\n");
    printf("Front = %d, Rear = %d\n", q.front, q.rear);

    display(&q);

    return 0;
}
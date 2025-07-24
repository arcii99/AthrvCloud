//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct queue {
    int front, rear;
    int data[MAX_QUEUE_SIZE];
} Queue;

void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    if ((q->front == 0 && q->rear == MAX_QUEUE_SIZE - 1) || q->front == q->rear + 1)
        return 1;
    else
        return 0;
}

int isEmpty(Queue *q) {
    if (q->front == -1)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, int x) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = x;
}

int dequeue(Queue *q) {
    int x;
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        exit(1);
    }
    x = q->data[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return x;
}

int main() {
    Queue q;
    int i;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Queue: ");
    for (i = q.front; i <= q.rear; i++)
        printf("%d ", q.data[i]);
    printf("\n");

    printf("Dequeued item: %d\n", dequeue(&q));
    printf("Dequeued item: %d\n", dequeue(&q));

    printf("Queue after dequeue: ");
    for (i = q.front; i <= q.rear; i++)
        printf("%d ", q.data[i]);
    printf("\n");

    enqueue(&q, 60);
    enqueue(&q, 70);

    printf("Queue after enqueue: ");
    for (i = q.front; i <= q.rear; i++)
        printf("%d ", q.data[i]);
    printf("\n");

    return 0;
}
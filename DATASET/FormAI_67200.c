//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct Queue {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isQueueFull(struct Queue *q) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isQueueEmpty(struct Queue *q) {
    if (q->rear < q->front) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(struct Queue *q, int num) {
    if (isQueueFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    q->data[++q->rear] = num;
}

int dequeue(struct Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        exit(1);
    }
    return q->data[q->front++];
}

void printQueue(struct Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printQueue(&q);
    int num = dequeue(&q);
    printf("Dequeued element: %d\n", num);
    printQueue(&q);
    return 0;
}
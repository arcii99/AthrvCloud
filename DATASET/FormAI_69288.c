//FormAI DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int front;
    int rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

void enqueue(Queue *q, int value) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted %d\n", value);
    }
}

int dequeue(Queue *q) {
    int item;
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
    }
    return item;
}

void display(Queue *q) {
    if (q->rear == -1) {
        printf("Queue is empty\n");
    } else {
        int i;
        printf("Queue elements are:\n");
        for (i = q->front; i <= q->rear; i++) {
            printf("%d  ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    display(&q);

    enqueue(&q, 6);

    int removed = dequeue(&q);
    printf("Removed element is %d\n", removed);

    display(&q);

    return 0;
}
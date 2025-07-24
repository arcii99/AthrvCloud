//FormAI DATASET v1.0 Category: Queue Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int front;
    int rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

// function prototypes
void enqueue(Queue *q, int item);
int dequeue(Queue *q);
void display(Queue q);

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Queue after Enqueue:\n");
    display(q);

    int item = dequeue(&q);
    printf("Dequeued item: %d\n", item);

    printf("Queue after Dequeue:\n");
    display(q);

    return 0;
}

void enqueue(Queue *q, int item) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue Overflow\n");
        exit(1);
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = item;
        printf("Enqueued item: %d\n", item);
    }
}

int dequeue(Queue *q) {
    int item;
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow\n");
        exit(1);
    } else {
        item = q->items[q->front];
        q->front++;
        return item;
    }
}

void display(Queue q) {
    if (q.front == -1)
        printf("Queue is empty\n");
    else {
        for (int i = q.front; i <= q.rear; i++) {
            printf("%d ", q.items[i]);
        }
        printf("\n");
    }
}
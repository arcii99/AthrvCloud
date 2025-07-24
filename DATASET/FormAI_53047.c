//FormAI DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct queue {
    int arr[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

void init_queue(struct queue *q) {
    q->front = -1;
    q->rear = -1;
}

int is_empty(struct queue *q) {
    return (q->front == -1 && q->rear == -1);
}

int is_full(struct queue *q) {
    return (q->rear+1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(struct queue *q, int x) {
    if (is_full(q)) {
        printf("Queue is full.\n");
        return;
    }
    else if (is_empty(q)) {
        q->front = q->rear = 0;
    }
    else {
        q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    }
    q->arr[q->rear] = x;
}

int dequeue(struct queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    else if (q->front == q->rear) {
        int x = q->arr[q->front];
        q->front = q->rear = -1;
        return x;
    }
    else {
        int x = q->arr[q->front];
        q->front = (q->front+1) % MAX_QUEUE_SIZE;
        return x;
    }
}

int front(struct queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->arr[q->front];
}

int rear(struct queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->arr[q->rear];
}

int main() {
    struct queue q;
    init_queue(&q);

    printf("Enqueue 1, 2, 3\n");
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("Queue front: %d\n", front(&q));
    printf("Queue rear: %d\n", rear(&q));

    printf("Dequeue: %d\n", dequeue(&q));
    printf("Queue front: %d\n", front(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Queue front: %d\n", front(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Queue front: %d\n", front(&q));

    printf("Enqueue 4, 5\n");
    enqueue(&q, 4);
    enqueue(&q, 5);

    printf("Queue front: %d\n", front(&q));
    printf("Queue rear: %d\n", rear(&q));

    printf("Dequeue: %d\n", dequeue(&q));
    printf("Queue front: %d\n", front(&q));

    printf("Enqueue 6, 7, 8, 9, 10, 11\n");
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);
    enqueue(&q, 10);
    enqueue(&q, 11);

    printf("Dequeue: %d\n", dequeue(&q));
    printf("Queue front: %d\n", front(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Queue front: %d\n", front(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Queue front: %d\n", front(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Queue front: %d\n", front(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Queue front: %d\n", front(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Queue front: %d\n", front(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Queue front: %d\n", front(&q));

    return 0;
}
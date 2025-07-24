//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct Queue {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} queue_t;

void enqueue(queue_t *queue, int value) {
    if ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front) {
        printf("Queue full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->data[queue->rear] = value;
}

int dequeue(queue_t *queue) {
    if (queue->front == queue->rear) {
        printf("Queue empty\n");
        return -1;
    }
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    return queue->data[queue->front];
}

int main() {
    queue_t queue;
    queue.front = 0;
    queue.rear = 0;

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    printf("%d\n", dequeue(&queue));
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    enqueue(&queue, 6);
    printf("%d\n", dequeue(&queue));
    printf("%d\n", dequeue(&queue));
    printf("%d\n", dequeue(&queue));
    printf("%d\n", dequeue(&queue));
    printf("%d\n", dequeue(&queue));

    return 0;
}
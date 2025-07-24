//FormAI DATASET v1.0 Category: Queue Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

typedef struct {
    int front, rear;
    int items[QUEUE_SIZE];
} Queue;

void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueEmpty(Queue *queue) {
    if (queue->front == -1 && queue->rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isQueueFull(Queue *queue) {
    if (queue->rear == QUEUE_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Queue *queue, int item) {
    if (isQueueFull(queue)) {
        printf("Sorry, the queue is full!\n");
    } else if (isQueueEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
        queue->items[queue->rear] = item;
    } else {
        queue->rear++;
        queue->items[queue->rear] = item;
    }
}

void dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Sorry, the queue is empty!\n");
    } else if (queue->front == queue->rear) {
        printf("Dequeued item: %d\n", queue->items[queue->front]);
        initializeQueue(queue);
    } else {
        printf("Dequeued item: %d\n", queue->items[queue->front]);
        queue->front++;
    }
}

void printQueue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("The queue is empty!\n");
    } else {
        printf("Queue: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue myQueue;

    initializeQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    enqueue(&myQueue, 40);
    enqueue(&myQueue, 50);
    printQueue(&myQueue);

    enqueue(&myQueue, 60);

    dequeue(&myQueue);
    printQueue(&myQueue);

    dequeue(&myQueue);
    dequeue(&myQueue);
    dequeue(&myQueue);
    dequeue(&myQueue);
    dequeue(&myQueue);
    printQueue(&myQueue);

    return 0;
}
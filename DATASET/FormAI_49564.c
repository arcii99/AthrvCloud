//FormAI DATASET v1.0 Category: Queue ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX_SIZE 100

typedef struct {
    int data[QUEUE_MAX_SIZE];
    int head;
    int tail;
} Queue;

void initQueue(Queue *queue) {
    queue->head = -1;
    queue->tail = -1;
}

int enqueue(Queue *queue, int value) {
    if (queue->tail + 1 >= QUEUE_MAX_SIZE) {
        return 0;
    }

    if (queue->head == -1) {
        queue->head = 0;
        queue->tail = 0;
    }
    else {
        queue->tail++;
    }

    queue->data[queue->tail] = value;

    return 1;
}

int dequeue(Queue *queue) {
    if (queue->head == -1) {
        return -1;
    }

    int value = queue->data[queue->head];

    if (queue->head == queue->tail) {
        queue->head = -1;
        queue->tail = -1;
    }
    else {
        queue->head++;
    }

    return value;
}

int main() {
    Queue queue;
    initQueue(&queue);

    printf("Queue is ready!\n");

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    printf("Queue after enqueuing 1, 2, 3, 4 and 5:\n");
    for (int i = queue.head; i <= queue.tail; i++) {
        printf("%d ", queue.data[i]);
    }
    printf("\n");

    dequeue(&queue);

    printf("Queue after dequeuing first value:\n");
    for (int i = queue.head; i <= queue.tail; i++) {
        printf("%d ", queue.data[i]);
    }
    printf("\n");

    return 0;
}
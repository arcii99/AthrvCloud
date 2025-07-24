//FormAI DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct Queue {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueEmpty(Queue *queue) {
    if (queue->front == -1 && queue->rear == -1)
        return 1;
    else
        return 0;
}

int isQueueFull(Queue *queue) {
    if ((queue->rear+1)%MAX_QUEUE_SIZE == queue->front)
        return 1;
    else
        return 0;
}

void enqueue(Queue *queue, int value) {
    if (isQueueFull(queue)) {
        printf("Cannot enqueue, queue is full.\n");
        return;
    } else if (isQueueEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear+1)%MAX_QUEUE_SIZE;
    }
    queue->data[queue->rear] = value;
}

int dequeue(Queue *queue) {
    int value;
    if (isQueueEmpty(queue)) {
        printf("Cannot dequeue, queue is empty.\n");
        return -1;
    } else if (queue->front == queue->rear) {
        value = queue->data[queue->front];
        queue->front = queue->rear = -1;
    } else {
        value = queue->data[queue->front];
        queue->front = (queue->front+1)%MAX_QUEUE_SIZE;
    }
    return value;
}

int main() {
    Queue queue;
    initializeQueue(&queue);
    
    printf("Enqueue 5 values into the queue:\n");
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    
    printf("Queue contents: ");
    while (!isQueueEmpty(&queue)) {
        printf("%d ", dequeue(&queue));
    }
    printf("\n");
    
    printf("Enqueue 3 values into the queue:\n");
    enqueue(&queue, 60);
    enqueue(&queue, 70);
    enqueue(&queue, 80);
    
    printf("Queue contents: ");
    while (!isQueueEmpty(&queue)) {
        printf("%d ", dequeue(&queue));
    }
    printf("\n");
    
    return 0;
}
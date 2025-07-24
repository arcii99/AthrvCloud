//FormAI DATASET v1.0 Category: Queue Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct Queue {
    int array[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

int is_empty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int is_full(struct Queue *queue) {
    return (queue->rear == MAX_QUEUE_SIZE - 1);
}

void enqueue(struct Queue *queue, int data) {
    if (is_full(queue)) {
        printf("Queue is full. Unable to add element.\n");
        return;
    }

    if (is_empty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear += 1;
    }

    queue->array[queue->rear] = data;
}

int dequeue(struct Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty. Unable to remove element.\n");
        return -1;
    }

    int data = queue->array[queue->front];

    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front += 1;
    }

    return data;
}

void display(struct Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }

    printf("\n");
}

int main() {
    struct Queue queue;
    queue.front = queue.rear = -1;

    // enqueue a few elements
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);

    // display the queue
    printf("Queue: ");
    display(&queue);

    // dequeue an element
    printf("Dequeued element: %d\n", dequeue(&queue));

    // display the queue
    printf("Queue: ");
    display(&queue);

    return 0;
}
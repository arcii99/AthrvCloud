//FormAI DATASET v1.0 Category: Queue Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

// Defining Queue structure
struct queue{
    int items[QUEUE_SIZE];
    int front;
    int rear;
};

typedef struct queue Queue;

// Initializing the queue
void initialize(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Checking if the queue is empty
int is_empty(Queue* queue) {
    return queue->rear == -1;
}

// Checking if the queue is full
int is_full(Queue* queue) {
    return queue->rear == QUEUE_SIZE - 1;
}

// Adding an element to the queue
void enqueue(Queue* queue, int value) {
    if (is_full(queue)) {
        printf("Queue is full!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
        printf("Inserted %d to queue\n", value);
    }
}

// Removing an element from the queue
void dequeue(Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Removed %d from queue.\n", queue->items[queue->front]);
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
}

// Displaying the queue
void display(Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements:\n");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue queue;
    initialize(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    display(&queue);
    dequeue(&queue);
    display(&queue);
    return 0;
}
//FormAI DATASET v1.0 Category: Queue ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // maximum size of the queue

// defining the queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// function prototypes
void initQueue(Queue* queue);
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);
void display(Queue* queue);

int main() {
    Queue queue;
    initQueue(&queue);

    // adding elements to the queue
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    display(&queue);

    // removing elements from the queue
    int removed = dequeue(&queue);
    printf("Removed element: %d\n", removed);
    removed = dequeue(&queue);
    printf("Removed element: %d\n", removed);
    display(&queue);

    return 0;
}

// function to initialize the queue
void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// function to add an element to the queue
void enqueue(Queue* queue, int value) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue Overflow!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// function to remove an element from the queue
int dequeue(Queue* queue) {
    int removed = -1;
    if (queue->front == -1) {
        printf("Queue Underflow!\n");
    } else {
        removed = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front++;
        }
    }
    return removed;
}

// function to display the queue
void display(Queue* queue) {
    int i;
    if (queue->rear == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}
//FormAI DATASET v1.0 Category: Queue Implementation ; Style: visionary
// A visionary C Queue implementation

#include <stdio.h>

#define QUEUE_SIZE 10 // Maximum size of the queue

// The Queue structure
typedef struct {
    int data[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isQueueFull(Queue *queue) {
    return ((queue->rear + 1) % QUEUE_SIZE == queue->front);
}

// Function to add an element to the queue
void enqueue(Queue *queue, int element) {
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }
    if (isQueueEmpty(queue))
        queue->front = queue->rear = 0;
    else
        queue->rear = (queue->rear + 1) % QUEUE_SIZE;
    queue->data[queue->rear] = element;
    printf("%d enqueued to the queue.\n", element);
}

// Function to remove an element from the queue
int dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }
    int element = queue->data[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % QUEUE_SIZE;
    printf("%d dequeued from the queue.\n", element);
    return element;
}

// Function to display the queue
void displayQueue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot display elements.\n");
        return;
    }
    int i = queue->front;
    printf("Queue elements: ");
    while (i != queue->rear) {
        printf("%d, ", queue->data[i]);
        i = (i + 1) % QUEUE_SIZE;
    }
    printf("%d\n", queue->data[i]);
}

// Main function
int main() {
    Queue queue;
    initQueue(&queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    displayQueue(&queue);
    dequeue(&queue);
    displayQueue(&queue);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    enqueue(&queue, 6);
    enqueue(&queue, 7);
    enqueue(&queue, 8);
    enqueue(&queue, 9);
    enqueue(&queue, 10);
    enqueue(&queue, 11); // Queue should be full now
    displayQueue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    displayQueue(&queue); 
    return 0;
}
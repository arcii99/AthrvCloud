//FormAI DATASET v1.0 Category: Queue Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 50

// Define the queue structure
typedef struct Queue {
    int front;
    int rear;
    int size;
    int items[MAX_QUEUE_SIZE];
} Queue;

// Initialize the queue
void initializeQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->size == 0);
}

// Check if the queue is full
int isFull(Queue *queue) {
    return (queue->size == MAX_QUEUE_SIZE);
}

// Add an element to the queue
void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Error: Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->items[queue->rear] = item;
    queue->size++;
}

// Remove the first element from the queue
int dequeue(Queue *queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    item = queue->items[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
    return item;
}

// Display the elements of the queue
void display(Queue *queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front -> ");
    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", queue->items[i]);
    }
    printf("%d ", queue->items[i]);
    printf(" <- Rear\n");
}

// Main function
int main() {
    Queue queue;
    initializeQueue(&queue);
    
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    
    display(&queue);
    
    dequeue(&queue);
    dequeue(&queue);
    
    display(&queue);
    
    return 0;
}
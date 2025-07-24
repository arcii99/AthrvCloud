//FormAI DATASET v1.0 Category: Queue ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_CAPACITY 100 // Maximum number of elements in the queue

// Defining the queue structure
typedef struct {
    int front, rear;
    int size;
    int elements[QUEUE_CAPACITY];
} Queue;

// Initialize the queue
void init(Queue *queue) {
    queue->front = queue->rear = -1;
    queue->size = 0;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->size == 0;
}

// Check if the queue is full
int isFull(Queue *queue) {
    return queue->size == QUEUE_CAPACITY;
}

// Insert an element at the rear end
void enqueue(Queue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue overflow!\n");
        exit(1);
    }
    queue->rear = (queue->rear + 1) % QUEUE_CAPACITY;
    queue->elements[queue->rear] = element;
    queue->size++;
    if (queue->front == -1) {
        queue->front = queue->rear;
    }
}

// Remove the element from the front end
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow!\n");
        exit(1);
    }
    int element = queue->elements[queue->front];
    queue->front = (queue->front + 1) % QUEUE_CAPACITY;
    queue->size--;
    if (queue->size == 0) {
        queue->front = queue->rear = -1;
    }
    return element;
}

// Get the element at the front end without removing it
int peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue empty!\n");
        exit(1);
    }
    return queue->elements[queue->front];
}

// Sample usage
int main() {
    Queue myQueue;
    init(&myQueue);
    enqueue(&myQueue, 5);
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 15);
    printf("%d\n", dequeue(&myQueue)); // Should print 5
    printf("%d\n", peek(&myQueue)); // Should print 10
    printf("%d\n", dequeue(&myQueue)); // Should print 10
    printf("%d\n", dequeue(&myQueue)); // Should print 15
    return 0;
}
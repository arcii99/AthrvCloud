//FormAI DATASET v1.0 Category: Queue ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// A struct representing a queue
typedef struct {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

// Create a queue of given capacity
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));

    return queue;
}

// Check if queue is full
int isFull(Queue* queue) {
    return queue->size == queue->capacity;
}

// Check if queue is empty
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Add an item to the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Sorry, the queue is full and cannot accept any more items.\n");
        return;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;

    printf("%d was added to the queue.\n", item);
}

// Remove an item from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Sorry, the queue is empty and there are no items to remove.\n");
        return -1;
    }

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    printf("%d was removed from the queue.\n", item);

    return item;
}

// Get the front item of the queue
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Sorry, the queue is empty and there are no items to display.\n");
        return -1;
    }

    return queue->array[queue->front];
}

// Get the rear item of the queue
int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Sorry, the queue is empty and there are no items to display.\n");
        return -1;
    }

    return queue->array[queue->rear];
}

int main() {
    Queue* queue = createQueue(5);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);

    printf("Front item is: %d\n", front(queue));
    printf("Rear item is: %d\n", rear(queue));

    dequeue(queue);
    dequeue(queue);

    printf("Front item is: %d\n", front(queue));
    printf("Rear item is: %d\n", rear(queue));

    enqueue(queue, 6);
    enqueue(queue, 7);

    printf("Front item is: %d\n", front(queue));
    printf("Rear item is: %d\n", rear(queue));

    return 0;
}
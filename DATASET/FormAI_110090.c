//FormAI DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5 // Maximum number of elements the queue can hold

typedef struct {
    int front; // Index of the front item in queue (start of queue)
    int back; // Index of the back item in queue (end of queue)
    int count; // Number of elements in the queue
    int items[MAX_QUEUE_SIZE]; // Array to store the elements
} queue_t;

// Initialize the queue
void initQueue(queue_t *q) {
    q->front = 0;
    q->back = -1;
    q->count = 0;
}

// Check if the queue is empty
int isQueueEmpty(queue_t *q) {
    return (q->count == 0);
}

// Check if the queue is full
int isQueueFull(queue_t *q) {
    return (q->count == MAX_QUEUE_SIZE);
}

// Add an item to the back of the queue
void enqueue(queue_t *q, int item) {
    if (!isQueueFull(q)) {
        q->back = (q->back + 1) % MAX_QUEUE_SIZE;
        q->items[q->back] = item;
        q->count++;
        printf("Added %d to the queue.\n", item);
    } else {
        printf("Cannot add element to the queue, it's full!\n");
    }
}

// Remove an item from the front of the queue
int dequeue(queue_t *q) {
    if (!isQueueEmpty(q)) {
        int item = q->items[q->front];
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        q->count--;
        printf("Removed %d from the queue.\n", item);
        return item;
        
    } else {
        printf("Cannot remove element from the queue, it's empty!\n");
        return -1;
    }
}

// Print the elements in the queue
void displayQueue(queue_t *q) {
    if (!isQueueEmpty(q)) {
        printf("Elements in Queue: ");
        for (int i = 0; i < q->count; i++) {
            printf("%d ", q->items[(q->front + i) % MAX_QUEUE_SIZE]);
        }
        printf("\n");
    } else {
        printf("Nothing to display, the queue is empty!\n");
    }
}

int main() {
    queue_t q;
    initQueue(&q);
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    displayQueue(&q);
    
    dequeue(&q);
    displayQueue(&q);
    
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    displayQueue(&q); // Should print an error message that the queue is full
    
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q); // Should print an error message that the queue is empty
    displayQueue(&q); // Should print an error message that the queue is empty
    
    return 0;
}
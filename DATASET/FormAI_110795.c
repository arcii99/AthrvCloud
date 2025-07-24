//FormAI DATASET v1.0 Category: Queue ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Create a struct for our queue
typedef struct {
    int data[MAX_SIZE];
    int head;
    int tail;
    int size;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->head = 0;
    q->tail = 0;
    q->size = 0;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return q->size == MAX_SIZE;
}

// Function to add data to the end of the queue
void enqueue(Queue* q, int data) {
    if (isFull(q)) {
        printf("Error: Queue is full!\n");
        return;
    }
    q->data[q->tail] = data;
    q->tail = (q->tail + 1) % MAX_SIZE;
    q->size++;
}

// Function to remove data from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Error: Queue is empty!\n");
        return -1;
    }
    int temp = q->data[q->head];
    q->head = (q->head + 1) % MAX_SIZE;
    q->size--;
    return temp;
}

// Function to print the contents of the queue
void printQueue(Queue* q) {
    printf("Queue Contents: ");
    if (isEmpty(q)) {
        printf("Empty\n");
        return;
    }
    int i;
    for (i = q->head; i != q->tail; i = (i + 1) % MAX_SIZE) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Queue myQueue;
    initQueue(&myQueue);
    printf("Queue initialized!\n\n");
    
    enqueue(&myQueue, 10);
    printf("Added 10 to queue\n");
    printQueue(&myQueue);
    
    enqueue(&myQueue, 20);
    printf("Added 20 to queue\n");
    printQueue(&myQueue);
    
    enqueue(&myQueue, 30);
    printf("Added 30 to queue\n");
    printQueue(&myQueue);
    
    dequeue(&myQueue);
    printf("Removed front element from queue\n");
    printQueue(&myQueue);
    
    enqueue(&myQueue, 40);
    printf("Added 40 to queue\n");
    printQueue(&myQueue);
    
    dequeue(&myQueue);
    printf("Removed front element from queue\n");
    printQueue(&myQueue);

    return 0;
}
//FormAI DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include <stdio.h>

// Define the maximum size of the Queue
#define MAX_SIZE 10

// Define the Queue data type
typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int itemCount;
} Queue;

// Function prototypes
void initQueue(Queue* q);
void enQueue(Queue* q, int val);
int deQueue(Queue* q);
int isFull(Queue* q);
int isEmpty(Queue* q);
void printQueue(Queue* q);

int main() {
    Queue q;
    initQueue(&q);

    printf("Enqueueing 10 items...\n");

    for (int i = 0; i < MAX_SIZE; i++)
        enQueue(&q, i);

    printf("Queue elements:\n");
    printQueue(&q);

    printf("Dequeueing 4 items...\n");

    for (int i = 0; i < 4; i++)
        deQueue(&q);

    printf("Queue elements:\n");
    printQueue(&q);

    printf("Enqueueing 3 more items...\n");

    for (int i = 0; i < 3; i++)
        enQueue(&q, i+10);

    printf("Queue elements:\n");
    printQueue(&q);

    return 0;
}

// Initializes the Queue
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->itemCount = 0;
}

// Adds an element to the rear of the Queue
void enQueue(Queue* q, int val) {
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->arr[q->rear] = val;
        q->itemCount++;
    } else {
        printf("Queue is full! Could not enqueue %d\n", val);
    }
}

// Removes an element from the front of the Queue and returns its value
int deQueue(Queue* q) {
    int val = 0;
    if (!isEmpty(q)) {
        val = q->arr[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
        q->itemCount--;
    } else {
        printf("Queue is empty! Could not dequeue\n");
    }
    return val;
}

// Checks if the Queue is full
int isFull(Queue* q) {
    return (q->itemCount == MAX_SIZE);
}

// Checks if the Queue is empty
int isEmpty(Queue* q) {
    return (q->itemCount == 0);
}

// Prints the elements of the Queue
void printQueue(Queue* q) {
    if (!isEmpty(q)) {
        for (int i = q->front; i <= q->rear; i++)
            printf("%d ", q->arr[i % MAX_SIZE]); // wrapping around the array
        printf("\n");
    } else {
        printf("Queue is empty!\n");
    }
}
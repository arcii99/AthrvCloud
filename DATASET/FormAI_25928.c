//FormAI DATASET v1.0 Category: Queue Implementation ; Style: complete
// C Queue Implementation Example

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Structure for Queue
typedef struct 
{
    int front;
    int rear;
    int elements[MAX_QUEUE_SIZE];
} Queue;

// Function to initialize the queue
void initQueue(Queue *Q) 
{
    Q->front = -1;
    Q->rear = -1;     
}

// Function to check if queue is full
int isQueueFull(Queue *Q) 
{
    if(Q->rear == MAX_QUEUE_SIZE-1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if queue is empty
int isQueueEmpty(Queue *Q) 
{
    if(Q->front == -1 && Q->rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to add element in queue
void enQueue(Queue *Q, int value) 
{
    if(isQueueFull(Q)) {
        printf("Queue is Full!\n");
    } else {
        if(Q->front == -1 && Q->rear == -1) {
            Q->front = Q->rear = 0;
        } else {
            Q->rear++;
        }
        Q->elements[Q->rear] = value;
        printf("Element %d inserted in queue\n", value);
    }
}

// Function to remove element from queue
void deQueue(Queue *Q) 
{
    if(isQueueEmpty(Q)) {
        printf("Queue is Empty!\n");
    } else {
        int value = Q->elements[Q->front];
        printf("Element %d removed from queue\n", value);
        if(Q->front == Q->rear) {
            Q->front = Q->rear = -1;
        } else {
            Q->front++;
        }
    }
}

// Function to display elements of queue
void displayQueue(Queue *Q) 
{
    if(isQueueEmpty(Q)) {
        printf("Queue is Empty!\n");
    } else {
        int i;
        printf("Elements in queue are: ");
        for(i = Q->front; i <= Q->rear; i++) {
            printf("%d ", Q->elements[i]);
        }
        printf("\n");
    }
}

// Sample Driver Program
int main() 
{
    Queue myQueue;
    initQueue(&myQueue);

    enQueue(&myQueue, 10);
    enQueue(&myQueue, 20);
    enQueue(&myQueue, 30);
    displayQueue(&myQueue);
    deQueue(&myQueue);
    deQueue(&myQueue);
    displayQueue(&myQueue);
    enQueue(&myQueue, 40);
    enQueue(&myQueue, 50);
    displayQueue(&myQueue);

    return 0;
}
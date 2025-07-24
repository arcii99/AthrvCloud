//FormAI DATASET v1.0 Category: Queue ; Style: lively
/* Hi there! I'm Queuie, the liveliest queue in town! */
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10 // Maximum size of the queue

// Structure of the queue
typedef struct
{
    int elements[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initQueue(Queue *q)
{
    q->front = q->rear = 0;
}

// Check if the queue is empty
int isQueueEmpty(Queue *q)
{
    return q->front == q->rear;
}

// Check if the queue is full
int isQueueFull(Queue *q)
{
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

// Add an element to the queue
int enQueue(Queue *q, int element)
{
    if (isQueueFull(q))
    {
        printf("I am full and cannot add more elements to the queue. Please remove some elements first.\n");
        return 0;
    }

    q->elements[q->rear] = element;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    printf("I have added an element to the queue.\n");
    return 1;
}

// Remove an element from the queue
int deQueue(Queue *q, int *element)
{
    if (isQueueEmpty(q))
    {
        printf("I am empty and cannot remove any elements from the queue. Please add some elements first.\n");
        return 0;
    }

    *element = q->elements[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    printf("I have removed an element from the queue.\n");
    return 1;
}

// Main function
int main()
{
    Queue q;
    int i, element;

    initQueue(&q);

    // Add some elements to the queue
    for (i = 1; i <= 5; i++)
    {
        if (enQueue(&q, i))
        {
            printf("Element %d has been added to the queue.\n", i);
        }
    }

    // Remove some elements from the queue
    for (i = 1; i <= 5; i++)
    {
        if (deQueue(&q, &element))
        {
            printf("Element %d has been removed from the queue.\n", element);
        }
    }

    return 0;
}
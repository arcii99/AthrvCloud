//FormAI DATASET v1.0 Category: Queue ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

// Queue struct definition
typedef struct
{
    int front;
    int rear;
    int data[QUEUE_SIZE];
} queue;

// Function to check if the queue is empty
int is_empty(queue *q)
{
    return q->front == -1 && q->rear == -1;
}

// Function to check if the queue is full
int is_full(queue *q)
{
    return (q->rear + 1) % QUEUE_SIZE == q->front;
}

// Function to add an element to the queue
void enqueue(queue *q, int element)
{
    if (is_full(q))
    {
        printf("The queue is full!\n");
        return;
    }
    else if (is_empty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % QUEUE_SIZE;
    }

    q->data[q->rear] = element;

    printf("Enqueued %d to the queue.\n", element);
}

// Function to remove an element from the queue
int dequeue(queue *q)
{
    if (is_empty(q))
    {
        printf("The queue is empty!\n");
        return -1;
    }

    int element = q->data[q->front];

    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % QUEUE_SIZE;
    }

    printf("Dequeued %d from the queue.\n", element);

    return element;
}

int main()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = -1;

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    printf("Dequeuing all elements from the queue:\n");
    while (!is_empty(q))
    {
        dequeue(q);
    }

    enqueue(q, 6);

    free(q);

    return 0;
}
//FormAI DATASET v1.0 Category: Queue ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int front, rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

// Initialize the queue
void init(Queue* q)
{
    q->front = -1;
    q->rear = -1;
    printf("Queue Initialized\n");
}

// Check if the queue is full
bool isFull(Queue* q)
{
    return q->rear == MAX_QUEUE_SIZE - 1;
}

// Check if the queue is empty
bool isEmpty(Queue* q)
{
    return q->front == -1 && q->rear == -1;
}

// Add items to the queue
void enqueue(Queue* q, int val)
{
    if (isFull(q))
    {
        printf("Queue is Full!\n");
    }
    else if (isEmpty(q))
    {
        q->front = q->rear = 0;
        q->items[q->rear] = val;
        printf("%d added to queue at index %d\n", val, q->rear);
    }
    else
    {
        q->rear++;
        q->items[q->rear] = val;
        printf("%d added to queue at index %d\n", val, q->rear);
    }
}

// Remove items from the queue
void dequeue(Queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty!\n");
    }
    else if (q->front == q->rear)
    {
        printf("%d removed from queue from index %d\n", q->items[q->front], q->front);
        q->front = q->rear = -1;
    }
    else
    {
        printf("%d removed from queue from index %d\n", q->items[q->front], q->front);
        q->front++;
    }
}

// Display the queue
void display(Queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("Current Queue: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main()
{
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);

    enqueue(&q, 60);
    enqueue(&q, 70);
    display(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);

    return 0;
}
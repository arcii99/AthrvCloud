//FormAI DATASET v1.0 Category: Queue Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// C Queue implementation using a circular array
// Functions: enqueue, dequeue, printQueue

int cqueue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value)
{
    // Check for full queue
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
    {
        printf("Queue is full!\n");
        return;
    }

    // First element
    if (front == -1)
        front = 0;

    // Circular increment
    rear = (rear + 1) % MAX_SIZE;
    cqueue[rear] = value;
    printf("%d enqueued to queue.\n", value);
}

int dequeue()
{
    int element;

    // Check for empty queue
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return -1;
    }

    element = cqueue[front];

    // Reset queue after removing last element
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;

    printf("%d dequeued from queue.\n", element);
    return element;
}

void printQueue()
{
    int i;

    // Check for empty queue
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Current queue: ");
    if (rear >= front)
    {
        for (i = front; i <= rear; i++)
            printf("%d ", cqueue[i]);
    }
    else
    {
        for (i = front; i < MAX_SIZE; i++)
            printf("%d ", cqueue[i]);

        for (i = 0; i <= rear; i++)
            printf("%d ", cqueue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);

    printf("\n");
    printQueue();
    printf("\n");

    dequeue();
    dequeue();
    dequeue();

    printf("\n");
    printQueue();
    printf("\n");

    return 0;
}
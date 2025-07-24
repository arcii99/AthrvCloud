//FormAI DATASET v1.0 Category: Queue Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Initialize the queue
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Check if the queue is full
int isFull()
{
    return (rear == MAX_SIZE - 1);
}

// Check if the queue is empty
int isEmpty()
{
    return (front == -1 && rear == -1);
}

// Add an element to the queue
void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue Overflow!\n");
        return;
    }
    else if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = data;
    printf("%d added to the queue\n", data);
}

// Remove an element from the queue
void dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow!\n");
        return;
    }
    printf("%d removed from the queue\n", queue[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

// Display the queue
void display()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);
    display();
    dequeue();
    display();
    enqueue(20);
    display();
    return 0;
}
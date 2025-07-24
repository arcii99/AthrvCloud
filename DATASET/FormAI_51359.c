//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdbool.h>
#define MAX_QUEUE_SIZE 5

int queue[MAX_QUEUE_SIZE];
int front = -1; // initialize front and rear fields to -1
int rear = -1;

bool isFull() // returns true if the queue is full 
{
    return rear == MAX_QUEUE_SIZE - 1;
}

bool isEmpty() // returns true if the queue is empty
{
    return front == -1 || front > rear;
}

void enqueue(int num) // adds an element to the rear of the queue
{
    if (isFull())
    {
        printf("\nCannot enqueue, queue is full.\n");
        return;
    }
    if (front == -1) // set front to 0 if queue is empty
    {
        front = 0;
    }
    rear++;
    queue[rear] = num;
}

int dequeue() // removes the element at the front of the queue and returns it
{
    if (isEmpty())
    {
        printf("\nCannot dequeue, queue is empty.\n");
        return -1;
    }
    int num = queue[front];
    front++;
    if (front > rear) // when front and rear are equal again, reset them to -1
    {
        front = -1;
        rear = -1;
    }
    return num;
}

void display() // displays the elements of the queue
{
    if (isEmpty())
    {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nCurrent queue: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    printf("Queue Implementation Program using the C programming language\n");

    // enqueue some elements
    enqueue(5);
    enqueue(2);
    enqueue(8);
    display();

    // dequeue elements and display the queue after each dequeue
    printf("\nDequeued element: %d\n", dequeue());
    display();

    printf("\nDequeued element: %d\n", dequeue());
    display();

    printf("\nDequeued element: %d\n", dequeue());
    display();

    printf("\nDequeued element: %d\n", dequeue()); // try to dequeue from an empty queue
    display();

    // enqueue more elements
    enqueue(1);
    enqueue(9);
    display();

    printf("\nDequeued element: %d\n", dequeue());
    display();

    return 0;
}
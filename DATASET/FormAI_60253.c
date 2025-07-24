//FormAI DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int front = -1, rear = -1;
int queue[SIZE];

void enQueue(int data)
{
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1)))
    {
        printf("Queue is Full\n");
        return;
    }

    else if (front == -1)
    {
        front = rear = 0;
        queue[rear] = data;
    }

    else if (rear == SIZE - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = data;
    }

    else
    {
        rear++;
        queue[rear] = data;
    }
}

int deQueue()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return -1;
    }

    int data = queue[front];
    queue[front] = -1;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }

    else if (front == SIZE - 1)
        front = 0;

    else
        front++;

    return data;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements are:\n");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }

    else
    {
        for (int i = front; i < SIZE; i++)
            printf("%d ", queue[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    //Implementing a queue to store the names of the registered users

    printf("Welcome to our portal!\n");

    //Adding users to the queue
    enQueue("John");
    enQueue("Emily");
    enQueue("Jacob");
    enQueue("Mia");
    enQueue("Oliver");
    enQueue("Sophie"); //The queue is full

    //Displaying the queue
    display();

    //Removing users from the queue
    deQueue();
    deQueue();

    //Displaying the updated queue
    display();

    //Adding a new user to the queue
    enQueue("William");

    //Displaying the updated queue
    display();

    printf("Thank you for using our portal!\n");

    return 0;
}
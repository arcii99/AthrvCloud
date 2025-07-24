//FormAI DATASET v1.0 Category: Queue Implementation ; Style: excited
#include<stdio.h>
#define MAX_SIZE 5 // Maximum size of the queue

int front=-1, rear=-1; // Pointers to keep track of front and rear positions of queue

int queue[MAX_SIZE]; // Initializing a queue of size MAX_SIZE

// Function to check if the queue is empty
int is_empty()
{
    if(front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

// Function to check if the queue is full
int is_full()
{
    if(rear == MAX_SIZE-1)
        return 1;
    else
        return 0;
}

// Function to add an element to the queue
void enqueue(int item)
{
    if(is_full())
    {
        printf("Queue is Full!!\n");
        return;
    }
    else if(is_empty())
    {
        front = rear = 0;
        queue[rear] = item;
    }
    else
    {
        rear++;
        queue[rear] = item;
    }
    printf("%d enqueued to queue successfully!\n", item);
}

// Function to remove an element from the queue
void dequeue()
{
    if(is_empty())
    {
        printf("Queue is Empty!!\n");
        return;
    }
    else if(front == rear)
    {
        printf("%d dequeued from queue successfully!\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("%d dequeued from queue successfully!\n", queue[front]);
        front++;
    }
}

// Function to display the elements of queue
void display()
{
    if(is_empty())
    {
        printf("Queue is Empty!!\n");
        return;
    }
    else
    {
        printf("The elements of queue are:\n");
        for(int i=front; i<=rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}

int main()
{
    printf("Welcome to the Unique C Queue Implementation program!\n\n");

    int choice, item;

    do {
        printf("\nEnter your choice:\n");
        printf("1. Enqueue an element\n");
        printf("2. Dequeue an element\n");
        printf("3. Display elements of queue\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element to be enqueued:\n");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program! Thank you for using the Unique C Queue Implementation program!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice!=4);

    return 0;
}
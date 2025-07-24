//FormAI DATASET v1.0 Category: Queue ; Style: complex
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5 // defining the size of the queue 
int front = -1, rear = -1; // Initializing front and rear pointers to -1
int queue[SIZE];

void enqueue(int item) // Function to insert an item in the queue
{
    if (rear == SIZE-1) // If the queue is full
    {
        printf("\nQueue overflow\n");
        return;
    }
    else if (front == -1 && rear == -1) // If the queue is empty
    {
        front = rear = 0;
        queue[rear] = item;
    }
    else // If the queue has some elements
    {
        rear++;
        queue[rear] = item;
    }
}

void dequeue() // Function to delete an item from the queue
{
    if (front == -1 && rear == -1) // If the queue is empty
    {
        printf("\nQueue underflow\n");
        return;
    }
    else if (front == rear) // If there is only one element in the queue
    {
        printf("\nDeleted element: %d\n", queue[front]);
        front = rear = -1;
    }
    else // If there are more than one elements in the queue
    {
        printf("\nDeleted element: %d\n", queue[front]);
        front++;
    }
}

void display() // Function to display the elements of the queue
{
    if (front == -1 && rear == -1) // If the queue is empty
    {
        printf("\nQueue underflow\n");
        return;
    }
    else // If there are elements in the queue
    {
        printf("\nQueue elements:\n");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

int main() // Main function
{
    int choice, item;
    while (1) // Loop until user exits
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) // Switch case for menu driven program
        {
            case 1:
                printf("Enter the element to be inserted: ");
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
                exit(0); // Exit from the program
            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}
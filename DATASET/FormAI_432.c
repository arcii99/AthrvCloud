//FormAI DATASET v1.0 Category: Queue Implementation ; Style: cheerful
/* 
Greetings and salutations! Welcome to my cheerful C Queue implementation program.
In this program, we will be implementing a Queue data structure using C programming language.
Without further ado, let's dive in and get started with the code!
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // define the size of queue

int queue[SIZE]; // create the queue

int rear = -1; // initialize rear pointer
int front = -1; // initialize front pointer

// function to add an element to the queue
void enqueue(int item)
{
    if (rear == SIZE - 1) // check if queue is full
    {
        printf("Sorry, the queue is full. Cannot add any more items.\n");
        return; // sorry message for full queue
    }
    else
    {
        if (front == -1) // check if queue is empty
        {
            front = 0; // set front to 0
        }
        rear++; // increment rear
        queue[rear] = item; // add item to queue
        printf("Woohoo! Added item %d to the queue.\n", item);
    }
}

// function to remove an element from the queue
void dequeue()
{
    if (front == -1) // check if queue is empty
    {
        printf("Sorry, the queue is empty. There are no more items to remove.\n");
        return; // sorry message for empty queue
    }
    else
    {
        printf("Yay! Removing item %d from the queue.\n", queue[front]);
        front++; // increment front
        if (front > rear) // check if queue is empty
        {
            front = rear = -1; // reset front and rear
        }
    }
}

// function to display the elements of the queue
void display()
{
    if (front == -1) // check if queue is empty
    {
        printf("The queue is currently empty. There are no items to display.\n");
        return; // sorry message for empty queue
    }
    else
    {
        int i;
        printf("Here are the items currently in the queue:\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]); // print out each item
        }
        printf("\n"); // add a new line for aesthetic purposes
    }
}

// main function to test the queue implementation
int main()
{
    printf("Welcome to my cheerful C Queue implementation program!\n");
    printf("Let's add some items to the queue.\n");

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); // this will exceed the size of the queue and trigger the full queue error message

    printf("\n");

    printf("Now, let's remove some items from the queue.\n");

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // this will trigger the empty queue error message

    printf("\n");

    printf("Finally, let's display the items currently in the queue.\n");

    display();

    printf("\n");

    printf("Thank you for using my cheerful C Queue implementation program!\n");

    return 0;
}
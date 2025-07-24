//FormAI DATASET v1.0 Category: Queue Implementation ; Style: curious
#include<stdio.h>
#define MAX_QUEUE_SIZE 10 //Define the maximum size of the Queue

int front = 0; //Initialize Front of the queue to 0
int rear = -1; //Initialize Rear of the queue to -1
int queue[MAX_QUEUE_SIZE]; //Initialize Queue with required size

int isFull() //Function to check if the queue is full
{
    if(rear == MAX_QUEUE_SIZE - 1)
    	return 1;
    else
        return 0;
}

int isEmpty() //Function to check if the queue is empty
{
    if(front > rear)
    	return 1;
    else
        return 0;
}

void enqueue(int data) //Function to enqueue the data
{
    if(isFull() == 1)
    {
        printf("\n Queue is full.");
    }
    else
    {
        rear = rear + 1;
        queue[rear] = data;
    }
}

void dequeue() //Function to dequeue the data
{
    if(isEmpty() == 1)
    {
        printf("\n Queue is empty.");
    }
    else
    {
        front = front + 1;
    }
}

int main() //Main function
{
    printf("\nCurious C Queue Implementation Example");
    printf("\n--------------------------------------\n");
    printf("\nQueue Size: %d", MAX_QUEUE_SIZE); //Printing the maximum size of queue
    
    //Performing enqueue operation
    printf("\n\nPerforming Enqueue Operation:");
    enqueue(5);
    enqueue(3);
    enqueue(9);
    enqueue(7);
    
    //Performing dequeue operation
    printf("\n\nPerforming Dequeue Operation:");
    dequeue();
    dequeue();
    
    //Printing the final queue
    printf("\n\nFinal Queue: ");
    int i;
    for(i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
    
    return 0;
}
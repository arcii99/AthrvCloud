//FormAI DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE], front=-1, rear=-1;

void insert()
{
    int data;
    
    if(rear == MAX_SIZE-1) //checking overflow condition
    {
        printf("\nQueue is full!");
    }
    else
    {
        printf("\nEnter data to insert: ");
        scanf("%d", &data);
        
        if(front == -1) //checking underflow condition
        {
            front = rear = 0; //inserting first element
        }
        else
        {
            rear += 1; //inserting at rear end of queue
        }
        
        queue[rear] = data; //inserting data into queue
        printf("\n%d has been inserted successfully.", data);
        printf("\nCurrent Queue elements are: ");
        display(); //displaying current queue elements
    }
}

void delete()
{
    if(front == -1 && rear == -1) //checking underflow condition
    {
        printf("\nQueue is empty!");
    }
    else
    {
        int data = queue[front]; //deleting front element from queue
        if(front == rear) //if only one element is present in queue
        {
            front = rear = -1; //resetting front and rear to initial values
        }
        else
        {
            front += 1; //updating front to next element
        }
        printf("\n%d has been deleted successfully.", data);
        printf("\nCurrent Queue elements are: ");
        display(); //displaying current queue elements
    }
}

void display()
{
    if(front == -1 && rear == -1) //checking underflow condition
    {
        printf("\nQueue is empty!");
    }
    else
    {
        int i;
        for(i=front; i<=rear; i++) //printing elements from front to rear
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    int choice;
    
    while(1)
    {
        printf("\n\nChoose an option:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0); break;
            default: printf("\nInvalid Choice!");
        }
    }
    
    return 0;
}
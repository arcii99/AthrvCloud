//FormAI DATASET v1.0 Category: Queue Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int value);
int dequeue();
void display();

int main()
{
    printf("Welcome to the queue implementation program!\n");

    enqueue(1);
    enqueue(2);
    enqueue(3);
    display(); // expected output: 1 2 3 

    dequeue();
    display(); // expected output: 2 3 

    dequeue();
    display(); // expected output: 3 

    dequeue(); 
    display(); // expected output: Empty queue

    printf("Thank you for using our program!\n");
    return 0;
}

void enqueue(int value)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Error: Queue overflow!\n");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = value;
}

int dequeue()
{
    int item;
    if (front == -1 || front > rear)
    {
        printf("Error: Queue underflow!\n");
        return -1;
    }
    item = queue[front];
    front++;
    return item;
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Empty queue\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
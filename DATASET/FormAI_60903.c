//FormAI DATASET v1.0 Category: Data structures visualization ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Maximum size of the array

int queue[MAX_SIZE]; // Defining a queue of maximum size 10
int front = -1, rear = -1; // Initializing front and rear indices as negative

// Function to check if the queue is empty
int isEmpty()
{
  if (front == -1 && rear == -1)
    return 1;
  else
    return 0;
}

// Function to check if the queue is full
int isFull()
{
  if (rear == MAX_SIZE - 1)
    return 1;
  else
    return 0;
}

// Function to insert element in the queue
void enqueue(int x)
{
  if (isFull())
  {
    printf("\nQueue is full!");
    return;
  }
  else if (isEmpty())
    front = rear = 0;
  else
    rear++;
  queue[rear] = x;
}

// Function to remove element from the queue
void dequeue()
{
  if (isEmpty())
  {
    printf("\nQueue is empty!");
    return;
  }
  else if (front == rear)
    front = rear = -1;
  else
    front++;
}

// Function to display the elements of queue
void display()
{
  if (isEmpty())
  {
    printf("\nQueue is empty!");
    return;
  }
  printf("\nElements of queue are:");
  for (int i = front; i <= rear; i++)
    printf(" %d", queue[i]);
}

int main()
{
  enqueue(5); // Inserting 5 in the queue
  enqueue(7); // Inserting 7 in the queue
  enqueue(8); // Inserting 8 in the queue
  display(); // Displaying the elements of queue
  dequeue(); // Removing element from the queue
  display(); // Displaying the elements of queue
  enqueue(9); // Inserting 9 in the queue
  display(); // Displaying the elements of queue
  return 0;
}
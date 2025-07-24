//FormAI DATASET v1.0 Category: Queue Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 //Define maximum size of queue

int front = -1, rear = -1; //Initialize front and rear pointers to -1
int queue[MAX_SIZE]; //Array to store the queue elements

//Function to check if the queue is full
int isFull()
{
  if (rear == MAX_SIZE - 1)
    return 1;
  else
    return 0;
}

//Function to check if the queue is empty
int isEmpty()
{
  if (front == -1 || front > rear)
    return 1;
  else
    return 0;
}

//Function to add elements to the queue
void enqueue(int element)
{
  if (isFull()) //If queue is full
    printf("Queue Full\n");
  else
  {
    rear++; //Increment rear pointer
    queue[rear] = element; //Add element to queue
    if (front == -1) //If this is the first element added
      front = 0; //Set front pointer to 0
  }
}

//Function to remove elements from the queue
void dequeue()
{
  if (isEmpty()) //If queue is empty
    printf("Queue Empty\n");
  else
  {
    printf("Removed Element: %d\n", queue[front]); //Print removed element
    front++; //Increment front pointer
  }
}

//Function to display the elements of the queue
void display()
{
  if (isEmpty()) //If queue is empty
    printf("Queue Empty\n");
  else
  {
    printf("Queue Elements: ");
    for (int i = front; i <= rear; i++) //Loop through elements and print them
      printf("%d ", queue[i]);
    printf("\n");
  }
}

int main()
{
  int choice, element;

  //Menu to interact with the queue
  do
  {
    printf("\nMenu\n");
    printf("1. Add Element\n");
    printf("2. Remove Element\n");
    printf("3. Display Elements\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
      case 1:
        printf("Enter Element: ");
        scanf("%d", &element);
        enqueue(element);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("Invalid Choice\n");
    }
  } while(choice != 4);
  
  return 0;
}
//FormAI DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Defining the maximum size of the queue
#define MAX_SIZE 10

// Initializing the queue
int queue[MAX_SIZE];
int rear = -1;
int front = -1;

// Function to insert element into the queue
void insert(int item) {
  if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
    printf("Queue Overflow\n");
    return;
  } 
  
  if (front == -1) {
    front = rear = 0;
    queue[rear] = item;
    return;
  }
  
  if (rear == MAX_SIZE - 1 && front != 0) {
    rear = 0;
    queue[rear] = item;
    return;
  }
  
  rear++;
  queue[rear] = item;
}

// Function to delete element from the queue
int delete() {
  if (front == -1) {
    printf("Queue Underflow\n");
    return -1;
  }
  
  int data = queue[front];
  queue[front] = -1;
  
  if (front == rear) {
    front = rear = -1;
  } else if (front == MAX_SIZE - 1) {
    front = 0;
  } else {
    front++;
  }
  
  return data;
}

// Function to display the queue
void display() {
  if (front == -1) {
    printf("Queue is Empty\n");
    return;
  }
  
  printf("Elements in the queue are: ");
  if (rear >= front) {
    for (int i = front; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
  } else {
    for (int i = front; i <= MAX_SIZE - 1; i++) {
      printf("%d ", queue[i]);
    }
    for (int i = 0; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
  }
}

// Main function
int main() {
  insert(10);
  insert(20);
  insert(30);
  insert(40);
  insert(50);
  display();
  
  int deleted = delete();
  printf("\nDeleted element is %d\n", deleted);
  display();
  
  insert(60);
  insert(70);
  insert(80);
  insert(90);
  insert(100);
  display();
  
  insert(110);
  delete();
  delete();
  display();
  
  return 0;
}
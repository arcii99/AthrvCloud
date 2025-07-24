//FormAI DATASET v1.0 Category: Queue ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

// initialize queue and its variables
int queue[QUEUE_SIZE];
int front = -1;
int rear = -1;

// function to check if queue is empty
int is_empty() {
  return front == -1;
}

// function to check if queue is full
int is_full() {
  return rear == QUEUE_SIZE - 1;
}

// function to add an element to the queue
void enqueue(int data) {
  if (is_full()) {
    printf("Queue is full");
    return;
  }
  if (is_empty()) {
    front = 0;
  }
  rear++;
  queue[rear] = data;
  printf("%d added to the queue.\n", data);
}

// function to remove an element from the queue
int dequeue() {
  if (is_empty()) {
    printf("Queue is empty");
    return -1;
  }
  int data = queue[front];
  if (front == rear) {
    front = rear = -1;
  }
  else {
    front++;
  }
  printf("%d removed from the queue.\n", data);
  return data;
}

int main() {
  // add elements to the queue
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);
  
  // attempt to add one more element
  enqueue(60);
  
  // remove all elements from the queue
  printf("Removing elements from the queue:\n");
  while (!is_empty()) {
    dequeue();
  }
  
  return 0;
}
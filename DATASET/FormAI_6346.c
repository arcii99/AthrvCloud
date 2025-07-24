//FormAI DATASET v1.0 Category: Queue Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

// Structure of the queue
typedef struct {
  int data[MAX_QUEUE_SIZE];
  int front;
  int rear;
} Queue;

// Initializes the queue
void initQueue(Queue *q) {
  q->front = -1;
  q->rear = -1;
}

// Checks if the queue is empty
int isQueueEmpty(Queue *q) {
  return q->front == -1;
}

// Checks if the queue is full
int isQueueFull(Queue *q) {
  return ((q->rear + 1) % MAX_QUEUE_SIZE) == q->front;
}

// Adds an element to the queue
void enqueue(Queue *q, int val) {
  if (isQueueFull(q)) {
    printf("Queue is full!\n");
    return;
  }
  
  if (isQueueEmpty(q)) {
    q->front = 0;
    q->rear = 0;
  } else {
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
  }
  
  q->data[q->rear] = val;
  printf("Added %d to the queue.\n", val);
}

// Removes an element from the queue
void dequeue(Queue *q) {
  if (isQueueEmpty(q)) {
    printf("Queue is empty!\n");
    return;
  }
  
  int val = q->data[q->front];
  
  if (q->front == q->rear) {
    q->front = -1;
    q->rear = -1;
  } else {
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
  }
  
  printf("Removed %d from the queue.\n", val);
}

// Prints the current state of the queue
void printQueue(Queue *q) {
  if (isQueueEmpty(q)) {
    printf("Queue is empty!\n");
    return;
  }
  
  printf("Current Queue: ");
  
  int i;
  for (i = q->front; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
    printf("%d ", q->data[i]);
  }
  
  printf("%d\n", q->data[q->rear]);
}

int main() {
  Queue q;
  initQueue(&q);
  
  // Add some elements to the queue
  enqueue(&q, 5);
  enqueue(&q, 3);
  enqueue(&q, 7);
  enqueue(&q, 1);
  
  // Print the queue
  printQueue(&q);
  
  // Remove an element
  dequeue(&q);
  
  // Print the queue
  printQueue(&q);
  
  // Add some more elements
  enqueue(&q, 9);
  enqueue(&q, 2);
  enqueue(&q, 6);
  
  // Print the queue
  printQueue(&q);
  
  // Remove all elements
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);
  
  // Print the queue
  printQueue(&q);
  
  // Try to remove from an empty queue
  dequeue(&q);
  
  return 0;
}
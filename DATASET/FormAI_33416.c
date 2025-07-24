//FormAI DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

// Represent the structure of a queue
typedef struct Queue {
  int items[MAX_QUEUE_SIZE];
  int front;
  int rear;
} Queue;

// Initialize the queue
void initializeQueue(Queue* q) {
  q->front = -1;
  q->rear = -1;
}

// Check if the queue is empty
int isQueueEmpty(Queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Check if the queue is full
int isQueueFull(Queue* q) {
  if (q->rear == MAX_QUEUE_SIZE - 1)
    return 1;
  else
    return 0;
}

// Add an item to the queue
void enqueue(Queue* q, int newItem) {
  if (isQueueFull(q)) {
    printf("Queue is full\n");
  } else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = newItem;
    printf("Added %d to queue\n", newItem);
  }
}

// Remove an item from the queue
void dequeue(Queue* q) {
  if (isQueueEmpty(q)) {
    printf("Queue is empty\n");
  } else {
    printf("Removed %d from queue\n", q->items[q->front]);
    q->front++;
    if (q->front > q->rear)
      initializeQueue(q);
  }
}

// Get the length of the queue
int getQueueLength(Queue* q) {
  int counter = 0;
  for (int i = q->front; i <= q->rear; i++)
    counter++;
  return counter;
}

// Get the value at the front of the queue
int getFrontValue(Queue* q) {
  if (isQueueEmpty(q)) {
    printf("Queue is empty\n");
    return -1;
  }
  return q->items[q->front];
}

// Print the queue
void printQueue(Queue* q) {
  printf("Queue: ");
  for (int i = q->front; i <= q->rear; i++)
    printf("%d ", q->items[i]);
  printf("\n");
}

int main() {
  Queue q;
  initializeQueue(&q);

  enqueue(&q, 5);
  enqueue(&q, 7);
  enqueue(&q, 3);
  enqueue(&q, 9);
  printQueue(&q); // Queue: 5 7 3 9

  dequeue(&q);
  printQueue(&q); // Queue: 7 3 9

  printf("Length of queue: %d\n", getQueueLength(&q)); // Length of queue: 3

  printf("Front value: %d\n", getFrontValue(&q)); // Front value: 7

  return 0;
}
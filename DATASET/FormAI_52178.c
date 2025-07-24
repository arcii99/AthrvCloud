//FormAI DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

/* Defining the Queue Struct */
typedef struct {
  int front, rear;
  int elements[MAX_SIZE];
} Queue;

/* Function to initialize the queue */
void initQueue(Queue* queue) {
  queue->front = -1;
  queue->rear = -1;
}

/* Function to check if the queue is empty */ 
int isQueueEmpty(Queue* queue) {
  return queue->front == -1 && queue->rear == -1;
}

/* Function to check if the queue is full */
int isQueueFull(Queue* queue) {
  return (queue->rear+1)%MAX_SIZE == queue->front;
}

/* Function to enqueue an element at the rear of the queue */
void enqueue(Queue* queue, int x) {
  if (isQueueFull(queue)) {
    printf("Error: Queue is full\n");
    return;
  } 
  else if (isQueueEmpty(queue)) {
    queue->front = queue->rear = 0;
  } 
  else {
    queue->rear = (queue->rear+1)%MAX_SIZE;
  }
  queue->elements[queue->rear] = x;
}

/* Function to dequeue an element from the front of the queue */
int dequeue(Queue* queue) {
  if (isQueueEmpty(queue)) {
    printf("Error: Queue is empty\n");
    return -1;
  } 
  else if (queue->front == queue->rear) {
    int element = queue->elements[queue->front];
    queue->front = queue->rear = -1;
    return element;
  } 
  else {
    int element = queue->elements[queue->front];
    queue->front = (queue->front+1)%MAX_SIZE;
    return element;
  }
}

/* Function to display the elements in the queue */
void displayQueue(Queue* queue) {
  if (isQueueEmpty(queue)) {
    printf("Queue is empty\n");
    return;
  }
  printf("Front: %d, Rear: %d\n", queue->front, queue->rear);
  printf("Elements: ");
  int i = queue->front;
  while (i != queue->rear) {
    printf("%d ", queue->elements[i]);
    i = (i+1)%MAX_SIZE;
  }
  printf("%d\n", queue->elements[i]);
}

int main() {
  Queue queue;
  initQueue(&queue);

  enqueue(&queue, 10);
  enqueue(&queue, 20);
  enqueue(&queue, 30);
  printf("Dequeued Element: %d\n", dequeue(&queue));
  displayQueue(&queue);
  
  return 0;
}
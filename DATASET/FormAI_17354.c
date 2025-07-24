//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
// It was a dark and foggy night in London as I sat down to write a program for a C Queue Implementation. 
// I took out my trusty magnifying glass and began to inspect every detail of the code.

#include <stdio.h>
#include <stdlib.h>

// First, let's define our Queue structure.
typedef struct Queue {
  int front, rear, size;
  unsigned capacity;
  int* array;
} Queue;

// Next, we need a function to create our Queue.
Queue* createQueue(unsigned capacity) {
  Queue* queue = (Queue*) malloc(sizeof(Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;

  // Initialize rear and array
  queue->rear = capacity - 1;
  queue->array = (int*) malloc(queue->capacity * sizeof(int));
  return queue;
}

// Now, let's implement our Queue operations.
int isFull(Queue* queue) { return (queue->size == queue->capacity); }
int isEmpty(Queue* queue) { return (queue->size == 0); }

void enqueue(Queue* queue, int item) {
  if (isFull(queue)) return;
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = item;
  queue->size = queue->size + 1;
}

int dequeue(Queue* queue) {
  if (isEmpty(queue)) return -1;
  int item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size = queue->size - 1;
  return item;
}

int front(Queue* queue) {
  if (isEmpty(queue)) return -1;
  return queue->array[queue->front];
}

int rear(Queue* queue) {
  if (isEmpty(queue)) return -1;
  return queue->array[queue->rear];
}

// Finally, let's test our Queue Implementation.
int main() {
  Queue* queue = createQueue(5);

  // Enqueue some items
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);

  // Dequeue and print the front element
  printf("Front element is %d\n", dequeue(queue));

  // Enqueue more items
  enqueue(queue, 4);
  enqueue(queue, 5);

  // Dequeue all elements and print them
  while (!isEmpty(queue)) {
    printf("%d ", dequeue(queue));
  }
  printf("\n");

  // Free up memory
  free(queue->array);
  free(queue);

  return 0;
}
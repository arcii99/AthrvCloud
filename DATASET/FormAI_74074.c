//FormAI DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

// Define the Queue structure
struct Queue {
  int front, rear, size;
  unsigned capacity;
  int* array;
};

// Function to create a new Queue
struct Queue* createQueue(unsigned capacity) {
  struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;
  queue->rear = capacity - 1;  // since the queue will be empty initially
  queue->array = (int*) malloc(queue->capacity * sizeof(int));
  return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
  return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
  return (queue->size == 0);
}

// Function to add an item to the back of the queue
void enqueue(struct Queue* queue, int item) {
  if (isFull(queue))
    return;
  queue->rear = (queue->rear + 1)%queue->capacity;
  queue->array[queue->rear] = item;
  queue->size++;
  printf("\n%d enqueued to Queue\n", item);
}

// Function to remove an item from the front of the queue
int dequeue(struct Queue* queue) {
  if (isEmpty(queue))
    return -99999;  // Return a sentinel value if queue is empty
  int item = queue->array[queue->front];
  queue->front = (queue->front + 1)%queue->capacity;
  queue->size--;
  return item;
}

// Function to get the front element of the queue
int front(struct Queue* queue) {
  if (isEmpty(queue))
    return -99999;  // Return a sentinel value if queue is empty
  return queue->array[queue->front];
}

// Function to get the rear element of the queue
int rear(struct Queue* queue)
{
  if (isEmpty(queue))
    return -99999;  // Return a sentinel value if queue is empty
  return queue->array[queue->rear];
}

// Main function to test the queue implementation
int main() {
  struct Queue* queue = createQueue(1000);  // Create a queue of capacity 1000

  enqueue(queue, 10);  // Enqueue some elements
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  
  printf("\nFront element is %d\n", front(queue));  // Print the front element
  
  printf("\nRear element is %d\n", rear(queue));  // Print the rear element
  
  printf("\n%d dequeued from Queue\n", dequeue(queue));  // Dequeue an element

  printf("\nFront element is %d\n", front(queue));  // Print the front element
  
  printf("\nRear element is %d\n", rear(queue));  // Print the rear element
  
  return 0;  // Exit program normally
}
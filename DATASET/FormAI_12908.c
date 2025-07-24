//FormAI DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

// Queue Data Structure
struct Queue {
  int front, rear;
  int items[MAX_QUEUE_SIZE];
};

// Function to create an empty queue
void create_queue(struct Queue* q) {
  q->front = -1;
  q->rear = -1;
}

// Function to check if queue is full
int is_full(struct Queue* q) {
  if (q->rear == MAX_QUEUE_SIZE - 1) {
    return 1;
  }
  return 0;
}

// Function to check if queue is empty
int is_empty(struct Queue* q) {
  if (q->front == -1 && q->rear == -1) {
    return 1;
  }
  return 0;
}

// Function to add an item to the queue
void enqueue(struct Queue* q, int value) {
  if (is_full(q)) {
    printf("Queue is full.\n");
  } else {
    if (q->front == -1) {
      q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Inserted %d to the queue.\n", value);
  }
}

// Function to remove an item from the queue
int dequeue(struct Queue* q) {
  int item;
  if (is_empty(q)) {
    printf("Queue is empty.\n");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      q->front = q->rear = -1;
    }
    printf("Removed %d from the queue.\n", item);
  }
  return item;
}

// Function to display the items in the queue
void display(struct Queue* q) {
  if (is_empty(q)) {
    printf("Queue is empty.\n");
  } else {
    int i;
    printf("Queue items are:\n");
    for (i = q->front; i <= q->rear; i++) {
      printf("%d ", q->items[i]);
    }
    printf("\n");
  }
}

int main() {
  struct Queue q;
  create_queue(&q);
  
  // Operations
  enqueue(&q, 2);
  enqueue(&q, 3);
  enqueue(&q, 4);
  enqueue(&q, 5);
  enqueue(&q, 6);
  display(&q);
  dequeue(&q);
  dequeue(&q);
  display(&q);
  
  return 0;
}
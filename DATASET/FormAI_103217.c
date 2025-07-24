//FormAI DATASET v1.0 Category: Queue ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 50

// Data structure containing the Queue properties.
typedef struct {
  int data[MAX_QUEUE_SIZE];
  int head; // Pointer to the front of the queue
  int tail; // Pointer to the end of the queue
} Queue;

// Checks if the queue is empty
int is_empty(Queue *q) {
  return q->head == q->tail;
}

// Adds an element to the end of the queue
void enqueue(Queue *q, int element) {
  if(q->tail == MAX_QUEUE_SIZE) {
    printf("Queue is full. Can't add elements.\n");
    return;
  }
  q->data[q->tail++] = element;
}

// Removes an element from the front of the queue
int dequeue(Queue *q) {
  if(is_empty(q)) {
    printf("Queue is empty. Can't remove elements.\n");
    return -1;
  }
  int element = q->data[q->head++];
  return element;
}

// Displays the contents of the queue
void display(Queue *q) {
  printf("[ ");
  for(int i = q->head; i < q->tail; i++) {
    printf("%d ", q->data[i]);
  }
  printf("]\n");
}

int main() {
  printf("Welcome to the innovative C Queue program!\n");

  Queue q;
  q.head = q.tail = 0;

  // Adding elements to the queue
  printf("Adding elements to the queue...\n");
  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  enqueue(&q, 40);
  enqueue(&q, 50);
  enqueue(&q, 60);
  enqueue(&q, 70);
  enqueue(&q, 80);
  enqueue(&q, 90);
  enqueue(&q, 100);
  printf("Elements added successfully!\n");

  // Displaying the contents of the queue
  printf("\nContents of the queue:\n");
  display(&q);

  // Removing elements from the queue
  printf("\nRemoving elements from the queue...\n");
  printf("%d\n", dequeue(&q));
  printf("%d\n", dequeue(&q));
  printf("%d\n", dequeue(&q));
  printf("%d\n", dequeue(&q));
  printf("%d\n", dequeue(&q));
  printf("%d\n", dequeue(&q));
  printf("%d\n", dequeue(&q));
  printf("%d\n", dequeue(&q));
  printf("%d\n", dequeue(&q));
  printf("%d\n", dequeue(&q));
  printf("Elements removed successfully!\n");

  // Displaying the contents of the queue
  printf("\nContents of the queue:\n");
  display(&q);

  // Adding more elements to the queue
  printf("\nAdding more elements to the queue...\n");
  enqueue(&q, 110);
  enqueue(&q, 120);
  enqueue(&q, 130);
  printf("Elements added successfully!\n");

  // Displaying the contents of the queue
  printf("\nContents of the queue:\n");
  display(&q);

  printf("\nThank you for using the innovative C Queue program!");
}
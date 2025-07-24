//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int front = -1, rear = -1;
int *queueArray;

void enqueue(int value) {
  if (rear == MAX - 1) {
    printf("Overflow\n");
    return;
  }
  if (front == -1) front = 0;
  rear++;
  *(queueArray + rear) = value;
}

void dequeue() {
  if (front == -1 || front > rear) {
    printf("Underflow\n");
    return;
  }
  front++;
}

void display() {
  if (front == -1) {
    printf("Empty\n");
    return;
  }
  printf("Queue elements: ");
  int i;
  for (i = front; i <= rear; i++) {
    printf("%d ", *(queueArray + i));
  }
  printf("\n");
}

int main() {
  queueArray = (int *) malloc(MAX * sizeof(int));
  enqueue(1);
  enqueue(2);
  enqueue(3);
  display();
  dequeue();
  display();
  enqueue(4);
  enqueue(5);
  display();
  dequeue();
  dequeue();
  display();
  dequeue();
  dequeue();
  dequeue();
  display();
  enqueue(6);
  enqueue(7);
  enqueue(8);
  enqueue(9);
  enqueue(10);
  enqueue(11);
  display();
  return 0;
}
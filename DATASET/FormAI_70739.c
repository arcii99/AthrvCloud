//FormAI DATASET v1.0 Category: Queue Implementation ; Style: grateful
#include <stdio.h>
#define MAX_QUEUE_SIZE 5

int front = -1;
int rear = -1;
int queue[MAX_QUEUE_SIZE];

void push(int data) {
  if ((rear + 1) % MAX_QUEUE_SIZE == front) {
    printf("Queue overflow!\n");
    return;
  }
  rear = (rear + 1) % MAX_QUEUE_SIZE;
  queue[rear] = data;
  if (front == -1) {
    front = rear;
  }
}

int pop() {
  if (front == -1 && rear == -1) {
    printf("Queue underflow!\n");
    return -1;
  }
  int data = queue[front];
  if (front == rear) {
    front = -1;
    rear = -1;
  } else {
    front = (front + 1) % MAX_QUEUE_SIZE;
  }
  return data;
}

int main() {
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  // queue is now full
  push(6);    // Queue overflow!
  printf("%d ", pop());    // 1
  printf("%d ", pop());    // 2
  push(6);    // Now we can push again
  push(7);
  push(8);
  printf("%d ", pop());    // 3
  printf("%d ", pop());    // 4
  printf("%d ", pop());    // 5
  printf("%d ", pop());    // 6
  printf("%d ", pop());    // 7
  printf("%d ", pop());    // 8
  pop();    // Queue underflow!
  return 0;
}
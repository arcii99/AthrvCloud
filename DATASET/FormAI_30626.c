//FormAI DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

struct Queue {
  int arr[MAX_QUEUE_SIZE];
  int front;
  int rear;
};

void initializeQueue(struct Queue *q) {
  q->front = -1;
  q->rear = -1;
}

void addToQueue(struct Queue *q, int value) {
  if (q->rear == MAX_QUEUE_SIZE - 1) {
    printf("Queue is full!\n");
    return;
  }
  if (q->front == -1 && q->rear == -1) {
    q->front = q->rear = 0;
  } else {
    q->rear++;
  }
  q->arr[q->rear] = value;
}

void removeFromQueue(struct Queue *q) {
  if (q->front == -1) {
    printf("Queue is empty!\n");
    return;
  }
  if (q->front == q->rear) {
    q->front = q->rear = -1;
  } else {
    q->front++;
  }
}

void displayQueue(struct Queue *q) {
  if (q->front == -1) {
    printf("Queue is empty!\n");
    return;
  }
  printf("Queue: ");
  for (int i = q->front; i <= q->rear; i++) {
    printf("%d ", q->arr[i]);
  }
  printf("\n");
}

int main() {
  struct Queue q;
  initializeQueue(&q);
  addToQueue(&q, 10);
  addToQueue(&q, 20);
  displayQueue(&q);
  addToQueue(&q, 30);
  removeFromQueue(&q);
  displayQueue(&q);
  return 0;
}
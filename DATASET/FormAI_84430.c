//FormAI DATASET v1.0 Category: Queue Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct Queue {
  int items[SIZE];
  int front;
  int rear;
};

typedef struct Queue queue;

void initQueue(queue *q) {
  q->front = -1;
  q->rear = -1;
}

int isFull(queue *q) {
  if (q->rear == SIZE - 1) {
    return 1;
  }
  return 0;
}

int isEmpty(queue *q) {
  if (q->front == -1 && q->rear == -1) {
    return 1;
  }
  return 0;
}

void enqueue(queue *q, int value) {
  if (isFull(q)) {
    printf("Queue is full\n");
  } else {
    if (isEmpty(q)) {
      q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Inserted %d\n", value);
  }
}

int dequeue(queue *q) {
  int item;
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      printf("Queue is empty\n");
      q->front = q->rear = -1;
    }
  }
  return item;
}

void display(queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
  } else {
    printf("Front -> ");
    for (int i = q->front; i <= q->rear; i++) {
      printf("%d -> ", q->items[i]);
    }
    printf("Rear\n");
  }
}

int main() {
  queue q;
  initQueue(&q);

  // Test enqueue
  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  enqueue(&q, 4);
  enqueue(&q, 5);

  // Test isFull and enqueue
  enqueue(&q, 6);

  // Test dequeue
  dequeue(&q);

  // Test isEmpty and dequeue
  while (!isEmpty(&q)) {
    dequeue(&q);
  }

  // Test dequeue
  dequeue(&q);

  return 0;
}
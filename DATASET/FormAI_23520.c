//FormAI DATASET v1.0 Category: Queue Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
  int arr[MAX_SIZE];
  int front;
  int rear;
} Queue;

void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int is_empty(Queue *q);
int is_full(Queue *q);

int main() {
  Queue q;
  q.front = q.rear = -1;

  // enqueue values into the queue
  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  enqueue(&q, 4);
  enqueue(&q, 5);
  enqueue(&q, 6);
  enqueue(&q, 7);
  enqueue(&q, 8);
  enqueue(&q, 9);
  enqueue(&q, 10);

  // dequeue and print values from the queue
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

  return 0;
}

void enqueue(Queue *q, int value) {
  if (is_full(q)) {
    printf("Queue is full\n");
    return;
  }

  if (q->front == -1 && q->rear == -1) {
    q->front = q->rear = 0;
    q->arr[q->rear] = value;
  } else {
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->arr[q->rear] = value;
  }
}

int dequeue(Queue *q) {
  if (is_empty(q)) {
    printf("Queue is empty\n");
    return -1;
  }

  int value = q->arr[q->front];

  if (q->front == q->rear) {
    q->front = q->rear = -1;
  } else {
    q->front = (q->front + 1) % MAX_SIZE;
  }

  return value;
}

int is_empty(Queue *q) {
  return (q->front == -1 && q->rear == -1);
}

int is_full(Queue *q) {
  return ((q->rear + 1) % MAX_SIZE == q->front);
}
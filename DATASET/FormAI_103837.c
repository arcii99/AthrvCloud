//FormAI DATASET v1.0 Category: Queue ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
  int data[MAX_QUEUE_SIZE];
  int front;
  int rear;
} Queue;

void init(Queue *q) {
  q->front = q->rear = 0;
}

int is_empty(Queue *q) {
  return (q->front == q->rear);
}

int is_full(Queue *q) {
  return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(Queue *q, int data) {
  if (is_full(q)) {
    printf("Error: Queue is full.\n");
    exit(EXIT_FAILURE);
  }
  q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
  q->data[q->rear] = data;
}

int dequeue(Queue *q) {
  if (is_empty(q)) {
    printf("Error: Queue is empty.\n");
    exit(EXIT_FAILURE);
  }
  q->front = (q->front + 1) % MAX_QUEUE_SIZE;
  return q->data[q->front];
}

void print(Queue *q) {
  int i;
  printf("Queue: ");
  for (i = (q->front + 1) % MAX_QUEUE_SIZE; i != (q->rear + 1) % MAX_QUEUE_SIZE;
       i = (i + 1) % MAX_QUEUE_SIZE) {
    printf("%d ", q->data[i]);
  }
  printf("\n");
}

int main(void) {
  Queue q;
  int i;

  init(&q);

  for (i = 0; i < 10; ++i) {
    enqueue(&q, i);
  }

  printf("Dequeue from Queue: ");
  while (!is_empty(&q)) {
    printf("%d ", dequeue(&q));
  }
  printf("\n");

  return EXIT_SUCCESS;
}
//FormAI DATASET v1.0 Category: Queue ; Style: shocked
#include <stdio.h>
#define MAX_QUEUE_SIZE 10

typedef struct queue {
  int front;
  int rear;
  int items[MAX_QUEUE_SIZE];
} Queue;

void initialize_queue(Queue *q) {
  q->front = -1;
  q->rear = -1;
}

int is_empty(Queue *q) {
  return q->front == -1 && q->rear == -1;
}

int is_full(Queue *q) {
  return q->rear == MAX_QUEUE_SIZE-1;
}

void enqueue(Queue *q, int value) {
  if (is_full(q)) {
    printf("Oh no! The queue is already full!\n");
    return;
  }
  if (is_empty(q)) {
    q->front = 0;
    q->rear = 0;
  } else {
    q->rear++;
  }
  q->items[q->rear] = value;
  printf("Yay! Successfully added %d to the queue.\n", value);
}

int dequeue(Queue *q) {
  if (is_empty(q)) {
    printf("Oops! The queue is already empty!\n");
    return -1;
  }
  int removed_value = q->items[q->front];
  if (q->front == q->rear) {
    q->front = -1;
    q->rear = -1;
  } else {
    q->front++;
  }
  printf("Woohoo! Successfully removed %d from the queue.\n", removed_value);
  return removed_value;
}

int peek(Queue *q) {
  if (is_empty(q)) {
    printf("Oh no! The queue is already empty!\n");
    return -1;
  }
  printf("The front value of the queue is %d.\n", q->items[q->front]);
  return q->items[q->front];
}

int main() {
  Queue q;
  initialize_queue(&q);
  peek(&q);
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
  enqueue(&q, 11);
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);  
  peek(&q);
  return 0;
}
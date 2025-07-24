//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct Queue {
   int front, rear;
   int items[MAX_QUEUE_SIZE];
} Queue;

void enqueue(Queue *q, int item) {
   if (q->rear == MAX_QUEUE_SIZE - 1) {
      printf("Queue is full!\n");
      return;
   }
   q->rear++;
   q->items[q->rear] = item;
}

int dequeue(Queue *q) {
   if (q->front == q->rear) {
      printf("Queue is empty!\n");
      return -1;
   }
   q->front++;
   int dequeued = q->items[q->front];
   return dequeued;
}

int main() {
   Queue q;
   q.front = -1;
   q.rear = -1;

   printf("Enqueuing 5, 10, 15, 20...\n");
   enqueue(&q, 5);
   enqueue(&q, 10);
   enqueue(&q, 15);
   enqueue(&q, 20);

   printf("Dequeuing %d...\n", dequeue(&q));
   printf("Dequeuing %d...\n", dequeue(&q));

   printf("Enqueuing 25, 30, 35, 40...\n");
   enqueue(&q, 25);
   enqueue(&q, 30);
   enqueue(&q, 35);
   enqueue(&q, 40);

   printf("Dequeuing %d...\n", dequeue(&q));
   printf("Dequeuing %d...\n", dequeue(&q));
   printf("Dequeuing %d...\n", dequeue(&q));
   printf("Dequeuing %d...\n", dequeue(&q));
   printf("Dequeuing %d...\n", dequeue(&q));
   return 0;
}
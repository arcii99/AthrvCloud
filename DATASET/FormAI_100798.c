//FormAI DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
   int front;
   int rear;
   int count;
   int queued_items[MAX_QUEUE_SIZE];
} queue;

void init(queue *q) {
   q->front = 0;
   q->rear = -1;
   q->count = 0;
}

bool is_empty(queue *q) {
   return (q->count == 0);
}

bool is_full(queue *q) {
   return (q->count == MAX_QUEUE_SIZE);
}

void enqueue(int value, queue *q) {
   if (is_full(q)) {
      printf("Queue is full\n");
   } else {
      q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
      q->queued_items[q->rear] = value;
      q->count++;
   }
}

int dequeue(queue *q) {
   int value;

   if (is_empty(q)) {
      printf("Queue is empty\n");
      return -1;
   } else {
      value = q->queued_items[q->front];
      q->front = (q->front + 1) % MAX_QUEUE_SIZE;
      q->count--;
      return value;
   }
}

int main() {
   queue my_queue;

   init(&my_queue);

   // Enqueue some items into the queue
   enqueue(17, &my_queue);
   enqueue(23, &my_queue);
   enqueue(19, &my_queue);
   enqueue(3, &my_queue);
   enqueue(7, &my_queue);

   // Dequeue all items in the queue
   while (!is_empty(&my_queue)) {
      printf("%d ", dequeue(&my_queue));
   }

   return 0;
}
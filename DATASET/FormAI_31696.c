//FormAI DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

struct queue{
    int items[MAX_QUEUE_SIZE];
    int front, rear;
};

typedef struct queue Queue;

void initialize_queue(Queue *q) {
   q->front = -1;
   q->rear = -1;
}

int is_full(Queue *q) {
   if (q->rear == MAX_QUEUE_SIZE - 1) {
       return 1;
   }
   else {
       return 0;
   }
}

int is_empty(Queue *q) {
   if (q->front == -1) {
       return 1;
   }
   else {
       return 0;
   }
}

void enqueue(Queue *q, int value) {
   if (is_full(q)) {
       printf("Queue is full\n");
   }
   else {
       if (q->front == -1) {
           q->front = 0;
       }
       q->rear++;
       q->items[q->rear] = value;
       printf("Element %d has been enqueued to the queue\n", value);
   }
}

void dequeue(Queue *q) {
   if (is_empty(q)) {
       printf("Queue is empty\n");
   }
   else {
       printf("Element %d has been dequeued from the queue\n", q->items[q->front]);
       q->front++;
       if (q->front > q->rear) {
           q->front = q->rear = -1;
       }
   }
}

void display(Queue *q) {
   if (is_empty(q)) {
       printf("Queue is empty\n");
   }
   else {
       int i;
       printf("Queue elements are: ");
       for (i = q->front; i <= q->rear; i++) {
           printf("%d ", q->items[i]);
       }
       printf("\n");
   }
}

int main() {
   Queue q;
   initialize_queue(&q);

   enqueue(&q, 10);
   enqueue(&q, 20);
   enqueue(&q, 30);

   display(&q);

   dequeue(&q);

   display(&q);

   enqueue(&q, 40);
   enqueue(&q, 50);

   display(&q);

   enqueue(&q, 60);

   dequeue(&q);

   display(&q);

   return 0;
}
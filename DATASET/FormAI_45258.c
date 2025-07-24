//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include<stdio.h>
#define MAX_SIZE 100

struct Queue {
   int items[MAX_SIZE];
   int front;
   int rear;
};

/* 
 * Check if the queue is full 
 */
int isFull(struct Queue* queue) {
   return queue->rear == MAX_SIZE - 1;
}

/* 
 * Check if the queue is empty 
 */
int isEmpty(struct Queue* queue) {
   return queue->rear == -1 && queue->front == -1;
}

/* 
 * Add element to the end of the queue 
 */
void enqueue(struct Queue* queue, int value) {
   if (isFull(queue)) {
      printf("Queue is full");
   }
   else {
      if (isEmpty(queue)) {
         queue->front = 0;
      }
      queue->rear++;
      queue->items[queue->rear] = value;
      printf("Insertion of %d in the queue was successful\n",value);
   }
}

/* 
 * Remove and return the front element of the queue 
 */
int dequeue(struct Queue* queue) {
   int element;
   if (isEmpty(queue)) {
      printf("Queue is empty\n");
      return -1;
   }
   else {
      element = queue->items[queue->front];
      if (queue->front >= queue->rear) {
         queue->front = -1;
         queue->rear = -1;
      }
      else {
         queue->front++;
      }
      printf("Removal of %d from the queue was successful\n",element);
      return element;
   }
}

/* 
 * Print all the elements in the queue 
 */
void display(struct Queue* queue) {
   int i;
   if (isEmpty(queue)) {
      printf("Queue is empty");
   }
   else {
      printf("\n");
      for (i = queue->front; i <= queue->rear; i++) {
         printf("%d ", queue->items[i]);
      }  
   printf("\n");
   }
}

int main() {
   struct Queue myQueue;
   myQueue.front = -1;
   myQueue.rear = -1;

   enqueue(&myQueue, 10);
   enqueue(&myQueue, 20);
   enqueue(&myQueue, 30);
   enqueue(&myQueue, 40);

   display(&myQueue);

   dequeue(&myQueue);

   display(&myQueue);

   return 0;
}
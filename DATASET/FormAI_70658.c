//FormAI DATASET v1.0 Category: Queue Implementation ; Style: portable
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

// Definition of Circular Queue Struct
typedef struct {
    int front, rear;
    int elements[MAX_SIZE];
} CircularQueue;

// Creating Circular Queue
CircularQueue makeCircularQueue() {
   CircularQueue Q;
   Q.front = -1;
   Q.rear = -1;
   return Q;
}

// Check if Queue is empty or not
int isEmpty(CircularQueue * Q) {
   if(Q->front == -1 && Q->rear == -1)
      return 1;
   return 0;
}

// Check if Queue is full or not
int isFull(CircularQueue * Q) {
   if((Q->rear+1)%MAX_SIZE == Q->front)
      return 1;
   return 0;
}

// Add element to Circular Queue
void enqueue(CircularQueue * Q, int value) {
   if(isFull(Q))
      printf("Queue is full!\n");
   else {
      if(isEmpty(Q))
         Q->front = Q->rear = 0;
      else
         Q->rear = (Q->rear+1)%MAX_SIZE;
      Q->elements[Q->rear] = value;
      printf("Inserted %d into the Queue!\n", value);
   }
}

// Remove element from Circular Queue
void dequeue(CircularQueue * Q) {
   if(isEmpty(Q))
      printf("Queue is empty!\n");
   else {
      int removedElement = Q->elements[Q->front];
      printf("Removed %d from the Queue!\n", removedElement);
      if(Q->front == Q->rear)
         Q->front = Q->rear = -1;
      else
         Q->front = (Q->front+1)%MAX_SIZE;
   }
}

// Get element at the front of Circular Queue
int getFront(CircularQueue * Q) {
   if(isEmpty(Q))
      return -1;
   return Q->elements[Q->front];
}

// Get element at the rear of Circular Queue
int getRear(CircularQueue * Q) {
   if(isEmpty(Q))
      return -1;
   return Q->elements[Q->rear];
}

int main() {
    CircularQueue Q = makeCircularQueue();
    enqueue(&Q, 1);
    enqueue(&Q, 2);
    enqueue(&Q, 3);
    enqueue(&Q, 4);
    printf("Front: %d\n", getFront(&Q));
    printf("Rear: %d\n", getRear(&Q));
    dequeue(&Q);
    printf("Front: %d\n", getFront(&Q));
    printf("Rear: %d\n", getRear(&Q));
    enqueue(&Q, 5);
    enqueue(&Q, 6);
    printf("Front: %d\n", getFront(&Q));
    printf("Rear: %d\n", getRear(&Q));
    dequeue(&Q);
    printf("Front: %d\n", getFront(&Q));
    printf("Rear: %d\n", getRear(&Q));
    return 0;
}
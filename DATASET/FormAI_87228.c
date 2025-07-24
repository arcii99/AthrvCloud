//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
/* 
   Ada's C Queue Implementation
   A program that implements a queue in C using an array.
   In honor of Ada Lovelace, who is recognized as the world's first computer programmer.
*/

#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE]; // global array to store queue elements
int rear = -1; // variable to point at the end of the queue
int front = -1; // variable to point at the front of the queue

// function to check if the queue is full
int isFull() {
   if (rear == MAX_SIZE - 1) {
      return 1;
   }
   else {
      return 0;
   }
}

// function to check if the queue is empty
int isEmpty() {
   if (front == -1 || front > rear) {
      return 1;
   }
   else {
      return 0;
   }
}

// function to add an element to the queue
void enqueue(int element) {
   if (isFull()) {
      printf("Queue is full!");
   }
   else {
      rear++;
      queue[rear] = element;
      if (front == -1) {
         front = 0;
      }
   }
}

// function to remove an element from the queue
void dequeue() {
   if (isEmpty()) {
      printf("Queue is empty!");
   }
   else {
      printf("Element %d removed from queue.\n", queue[front]);
      front++;
   }
}

// function to display the elements of the queue
void display() {
   int i;
   if (isEmpty()) {
      printf("Queue is empty!");
   }
   else {
      printf("\nQueue elements: \n");
      for (i = front; i <= rear; i++) {
         printf("%d ", queue[i]);
      }
   }
}

int main() {
   enqueue(7);
   enqueue(14);
   enqueue(21);
   enqueue(28);
   enqueue(35);
   printf("\nAfter inserting 5 elements, the queue is:\n");
   display();
   dequeue();
   dequeue();
   printf("\nAfter removing 2 elements, the queue is:\n");
   display();
   return 0;
}
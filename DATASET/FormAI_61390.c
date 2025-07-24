//FormAI DATASET v1.0 Category: Queue Implementation ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 5

int queueArray[MAX_SIZE];
int rear = -1;
int front = -1;

void insert(int value) {
   if ((front == 0 &&  rear == MAX_SIZE - 1) || (front == rear+1)) {
      printf("Queue is full \n");
      return;
   }
   if (rear == -1) {
      rear++;
      front++;
   } else {
      if (rear == MAX_SIZE - 1) {
         rear = 0;
      } else {
         rear++;
      }
   }
   queueArray[rear] = value;
}

int delete() {
   if (front == -1) {
      printf("Queue is empty \n");
      return -1;
   }
   int element = queueArray[front];
   if (front == rear) {
      front = -1;
      rear = -1;
   } else {
      if (front == MAX_SIZE - 1) {
         front = 0;
      } else {
         front++;
      }
   }
   return element;
}

bool isEmpty() {
   return front == -1;
}

bool isFull() {
   return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

int peek() {
   if (front == -1) {
      printf("Queue is empty \n");
      return -1;
   }
   return queueArray[front];
}

void display() {
   if (front == -1) {
      printf("Queue is empty \n");
      return;
   }
   printf("Elements in queue are:\n");
   int i = front;
   if (front <= rear) {
      while (i <= rear) {
         printf("%d ", queueArray[i]);
         i++;
      }
   } else {
      while (i <= MAX_SIZE - 1) {
         printf("%d ", queueArray[i]);
         i++;
      }
      i = 0;
      while (i <= rear) {
         printf("%d ", queueArray[i]);
         i++;
      }
   }
   printf("\n");
}

int main() {
   printf("Queue implementation program using C\n");
   printf("\n");
   insert(10);
   insert(20);
   insert(30);
   insert(40);
   display();
   printf("\n");
   
   int deleteElement = delete();
   printf("Deleted element : %d\n", deleteElement);
   printf("\n");
   
   printf("Element at front of the queue: %d\n", peek());
   printf("\n");
   
   insert(50);
   display();
   printf("\n");
   
   printf("Current size of queue : %d\n",rear-front+1);
   printf("\n");
   
   if(isEmpty()) {
      printf("Queue is empty\n");
   }else {
      printf("Queue is not empty\n");
   }
   printf("\n");
   
   if(isFull()) {
      printf("Queue is full\n");
   }else {
      printf("Queue is not full\n");
   }
   printf("\n");
   
   return 0;
}
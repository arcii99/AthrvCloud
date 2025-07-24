//FormAI DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int data){
  if(rear == MAX_SIZE-1){
    printf("Queue is full!");
    return;
  }
  if(front == -1){
    front = 0;
  }
  rear++;
  queue[rear] = data;
  printf("%d has been enqueued!\n", data);
}

void dequeue(){
  if(front == -1 || front > rear){
    printf("Queue is empty!");
    return;
  }
  int data = queue[front];
  front++;
  printf("%d has been dequeued!\n", data);
}

void display(){
  if(front == -1 || front > rear){
    printf("Queue is empty!");
    return;
  }
  printf("Queue contains: ");
  for(int i=front; i<=rear; i++){
    printf("%d ", queue[i]);
  }
  printf("\n");
}

int main(){
  printf("Whoa! A C Queue Implementation program!\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  display();
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  dequeue();
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  display();
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  enqueue(50);
  enqueue(60);
  enqueue(70);
  enqueue(80);
  enqueue(90);
  enqueue(100);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  display();
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  display();
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  enqueue(110);
  enqueue(120);
  enqueue(130);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  display();
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  display();
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  dequeue();
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  display();
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  return 0;
}
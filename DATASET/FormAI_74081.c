//FormAI DATASET v1.0 Category: Queue Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

bool is_empty() {
  return (front == -1 && rear == -1);
}

bool is_full() {
  return (rear+1)%MAX_SIZE == front ? true : false;
}

void insert(int val) {
  if(is_full()) {
    printf("Queue is full\n");
    return;
  } else if(is_empty()) {
    front = 0;
    rear = 0;
  } else {
    rear = (rear+1)%MAX_SIZE;
  }
  queue[rear] = val;
}

int delete() {
  int val;
  if(is_empty()) {
    printf("Queue is empty\n");
    exit(0);
  } else if(front == rear) {
    val = queue[front];
    front = -1;
    rear = -1;
  } else {
    val = queue[front];
    front = (front+1)%MAX_SIZE;
  }
  return val;
}

int main() {
  insert(5);
  insert(10);
  insert(15);
  printf("%d ", delete()); //5
  printf("%d ", delete()); //10
  printf("%d ", delete()); //15
  insert(20);
  insert(25);
  printf("%d ", delete()); //20
  printf("%d ", delete()); //25
  printf("\n");
  return 0;
}
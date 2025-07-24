//FormAI DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct{
  int data[MAX_QUEUE_SIZE];
  int front;
  int rear;
}Queue;

void init(Queue *q){
  q->front = -1;
  q->rear = -1;
}

int isFull(Queue *q){
  return (q->rear == MAX_QUEUE_SIZE-1);
}

int isEmpty(Queue *q){
  return (q->front == -1 && q->rear == -1);
}

void enqueue(Queue *q, int x){
  if(isFull(q)){
    printf("\nQueue is Full\n");
    return;
  }else if(isEmpty(q)){
    q->front = q->rear = 0;
    q->data[0] = x;
  }else{
    q->rear++;
    q->data[q->rear] = x;
  }
}

int dequeue(Queue *q){
  if(isEmpty(q)){
    printf("\nQueue is Empty\n");
    return -1;
  }else if(q->front == q->rear){
    int x = q->data[q->front];
    q->front = q->rear = -1;
    return x;
  }else{
    int x = q->data[q->front];
    q->front++;
    return x;
  }
}

int main(){
  Queue q;
  init(&q);
  
  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  
  printf("%d ", dequeue(&q)); // 10
  printf("%d ", dequeue(&q)); // 20
  
  enqueue(&q, 40);
  enqueue(&q, 50);
  
  printf("%d ", dequeue(&q)); // 30
  printf("%d ", dequeue(&q)); // 40
  printf("%d ", dequeue(&q)); // 50

  return 0;
}
//FormAI DATASET v1.0 Category: Queue ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
  int arr[MAX_SIZE];
  int front;
  int rear;
  int size;
} Queue;

void init_q(Queue* q){
  q->front = -1;
  q->rear = -1;
  q->size = 0;
}

int is_empty(Queue* q){
  return q->front == -1;
}

int is_full(Queue* q){
  return q->front == 0 && q->rear == MAX_SIZE - 1;
}

void enqueue(Queue* q, int data){

  if (is_full(q)) {
    printf("Queue overflow!\n");
    return;
  }

  if (q->front == -1) {
    q->front = 0;
  }

  q->rear++;
  q->arr[q->rear] = data;
  q->size++;
}

int dequeue(Queue* q){

  if (is_empty(q)) {
    printf("Queue underflow!\n");
    return -1;
  }

  int data = q->arr[q->front];

  if (q->front == q->rear) {
    q->front = -1;
    q->rear = -1;
  }
  else {
    q->front++;
  }

  q->size--;

  return data;
}

void display(Queue* q){
  if (is_empty(q)) {
    printf("Queue is empty!\n");
    return;
  }

  for (int i = q->front; i <= q->rear; i++){
    printf("%d <- ", q->arr[i]);
  }

  printf("\n");
}

int main(){

  Queue my_queue;
  init_q(&my_queue);

  enqueue(&my_queue, 10);
  enqueue(&my_queue, 20);
  enqueue(&my_queue, 30);

  printf("Queue after initial enqueue:\n");
  display(&my_queue);

  int x = dequeue(&my_queue);
  printf("Dequeued element: %d\n", x);

  printf("Queue after first dequeue:\n");
  display(&my_queue);

  enqueue(&my_queue, 40);
  enqueue(&my_queue, 50);

  printf("Queue after further enqueue:\n");
  display(&my_queue);

  return 0;
}
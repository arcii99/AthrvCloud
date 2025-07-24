//FormAI DATASET v1.0 Category: Queue ; Style: beginner-friendly
#include <stdio.h>
#define MAX_SIZE 5 // maximum size of the queue

struct Queue {
  int queue[MAX_SIZE];
  int front;
  int rear;
  int size;
};

// function to check if queue is empty
int isEmpty(struct Queue* q) {
  return q->size == 0;
}

// function to check if queue is full
int isFull(struct Queue* q) {
  return q->size == MAX_SIZE;
}

// function to add an element to the queue
void enqueue(struct Queue* q, int val) {
  if (isFull(q)) {
    printf("Queue is full\n");
    return;
  }
  q->queue[q->rear] = val;
  q->rear = (q->rear + 1) % MAX_SIZE;
  q->size++;
}

// function to remove an element from the queue
int dequeue(struct Queue* q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return -1;
  }
  int val = q->queue[q->front];
  q->front = (q->front + 1) % MAX_SIZE;
  q->size--;
  return val;
}

// function to display the elements in the queue
void display(struct Queue* q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue: ");
  for (int i = 0; i < q->size; i++) {
    int index = (q->front + i) % MAX_SIZE;
    printf("%d ", q->queue[index]);
  }
  printf("\n");
}

// main function
int main() {
  struct Queue q;
  q.front = 0;
  q.rear = 0;
  q.size = 0;
  
  // adding elements to the queue
  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  enqueue(&q, 40);
  enqueue(&q, 50);
  
  // displaying the contents of the queue
  display(&q);
  
  // removing elements from the queue
  int val = dequeue(&q);
  printf("%d removed from the queue\n", val);
  
  val = dequeue(&q);
  printf("%d removed from the queue\n", val);
  
  // displaying the contents of the queue after removal
  display(&q);
  
  return 0;
}
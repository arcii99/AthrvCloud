//FormAI DATASET v1.0 Category: Data structures visualization ; Style: funny
#include <stdio.h>

typedef struct {
  char *name;
  int age;
} Person;

typedef struct {
  int front, rear;
  Person data[5];
} Queue;

void addToQueue(Queue *q, char *name, int age) {
  if (q->rear == 4) {
    printf("Queue is Full!\n");
    return;
  }
  q->rear++;
  q->data[q->rear].name = name;
  q->data[q->rear].age = age;
}

void removeFromQueue(Queue *q) {
  if (q->front == q->rear) {
    printf("Queue is Empty!\n");
    return;
  }
  q->front++;
}

void displayQueue(Queue q) {
  if (q.front == q.rear) {
    printf("Queue is Empty!\n");
    return;
  }
  printf("The queue is:\n");
  for (int i = q.front+1; i <= q.rear; i++)
    printf("%s, %d\n", q.data[i].name, q.data[i].age);
}

int main() {
  Queue q = {0, 0};
  
  addToQueue(&q, "Alice", 21);
  addToQueue(&q, "Bob", 23);
  addToQueue(&q, "Charlie", 22);
  addToQueue(&q, "Derrick", 20);
  addToQueue(&q, "Eevee", 19);
  addToQueue(&q, "Frank", 25); // This one should not fit in the queue and hence we will get an error message
  
  displayQueue(q); // Displaying the queue
  
  removeFromQueue(&q); // Removing the first person in the queue
  
  displayQueue(q); // Displaying the queue after removal
  
  return 0;
}
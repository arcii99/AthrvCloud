//FormAI DATASET v1.0 Category: Data structures visualization ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct { 
    int front;
    int rear; 
    int items[MAX_QUEUE_SIZE];
} Queue;

void enqueue(Queue *q, int data) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue overflow!");
        exit(1);
    }
    
    if (q->front == -1) {
        q->front = 0;
    }
    
    q->rear++;
    q->items[q->rear] = data;
}

int dequeue(Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue underflow!");
        exit(1);
    }
    
    int value = q->items[q->front];
    q->front++;
    return value;
}

int main() {
    Queue myQueue;
    myQueue.front = -1;
    myQueue.rear = -1;
    
    printf("Let's add some items to our queue!\n");
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    enqueue(&myQueue, 40);
    
    printf("\nOur current queue:\n");
    for (int i = myQueue.front; i <= myQueue.rear; i++) {
        printf("%d ", myQueue.items[i]);
    }
    
    printf("\n\nNow let's dequeue an item and see what happens...\n");
    int dequeuedValue = dequeue(&myQueue);
    printf("\nItem dequeued: %d\n\n", dequeuedValue);
    
    printf("Our updated queue:\n");
    for (int i = myQueue.front; i <= myQueue.rear; i++) {
        printf("%d ", myQueue.items[i]);
    }
    
    return 0;
}
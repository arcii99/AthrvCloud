//FormAI DATASET v1.0 Category: Queue ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10 // size of the queue

typedef struct queue {
    int front, rear;
    int items[MAX_QUEUE_SIZE];
}queue;

// initialize an empty queue
void initializeQueue(queue *q) {
    q->front = -1;
    q->rear = -1;
}

// check if the queue is empty
int isQueueEmpty(queue *q) {
    return (q->front == -1 && q->rear == -1);
}

// check if the queue is full
int isQueueFull(queue *q) {
    return (q->rear+1)%MAX_QUEUE_SIZE == q->front ? 1 : 0;
}

// insert an element into the queue
void enqueue(queue *q, int element) {
    if (isQueueFull(q)) {
        printf("Queue overflow!\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    }
    else {
        q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
    }
    q->items[q->rear] = element;
}

// remove an element from the queue
int dequeue(queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue underflow!\n");
        return -1;
    }
    int removedElement = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else {
        q->front = (q->front+1)%MAX_QUEUE_SIZE;
    }
    return removedElement;
}

// display the contents of the queue
void display(queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front->");
    int i;
    for (i=q->front; i!=q->rear; i=(i+1)%MAX_QUEUE_SIZE) {
        printf("%d ", q->items[i]);
    }
    printf("%d<-Rear\n", q->items[i]);
}

// main function
int main() {
    queue q;
    initializeQueue(&q);
    
    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 20);
    enqueue(&q, 25);
    display(&q);
    
    int removedElement = dequeue(&q);
    if (removedElement != -1) {
        printf("Removed element: %d\n", removedElement);
    }
    display(&q);

    enqueue(&q, 30);
    display(&q);
    
    return 0;
}
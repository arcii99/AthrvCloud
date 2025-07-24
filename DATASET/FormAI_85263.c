//FormAI DATASET v1.0 Category: Queue Implementation ; Style: peaceful
#include<stdio.h>

#define MAX_QUEUE_SIZE 5

// Struct to hold queue data
typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// Function to initialize the queue
void init_queue(Queue *q) {
    int i;
    q->front = q->rear = 0;
    for(i=0; i<MAX_QUEUE_SIZE; i++) {
        q->data[i] = 0;
    }
}

// Function to check if the queue is empty
int is_empty(Queue *q) {
    return q->front == q->rear;
}

// Function to check if the queue is full
int is_full(Queue *q) {
    return (q->rear+1)%MAX_QUEUE_SIZE == q->front;
}

// Function to add an element to the queue
void enqueue(Queue *q, int value) {
    if(is_full(q)) {
        printf("Queue Overflow. Cannot insert value.");
        return;
    }
    q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
    q->data[q->rear] = value;
}

// Function to remove an element from the queue
int dequeue(Queue *q) {
    if(is_empty(q)) {
        printf("Queue Underflow. Cannot remove value.");
        return -1;
    }
    q->front = (q->front+1)%MAX_QUEUE_SIZE;
    int value = q->data[q->front];
    q->data[q->front] = 0;
    return value;
}

// Function to print the queue elements
void print_queue(Queue *q) {
    int i = q->front+1;
    printf("Queue: ");
    while(i!=(q->rear+1)%MAX_QUEUE_SIZE) {
        printf("%d ", q->data[i]);
        i = (i+1)%MAX_QUEUE_SIZE;
    }
}

// Main function to test the queue implementation
int main() {
    Queue q;
    init_queue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5); // Queue overflow from this point on
    print_queue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q); // Queue underflow from this point on
    print_queue(&q);
    return 0;
}
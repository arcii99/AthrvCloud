//FormAI DATASET v1.0 Category: Queue Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#define MAX 50 // Maximum size of Queue


// Queue structure
typedef struct {
    int data[MAX]; // Data elements in the Queue
    int front; // Index of front element in the Queue
    int rear; // Index of rear element in the Queue
    int size; // Size of Queue
} Queue;


// Create an empty Queue
Queue createQueue() {
    Queue q;
    q.front = q.rear = -1;
    q.size = 0;
    return q;
}


// Check if Queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}


// Check if Queue is full
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}


// Add element to the rear of the Queue
void enQueue(Queue *q, int x) {
    if (isFull(q)) {
        printf("Overflow Error: Queue is Full.\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = x;
    q->size++;
    if (q->front == -1) {
        q->front = 0;
    }
}


// Remove element from the front of the Queue
int deQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Underflow Error: Queue is Empty.\n");
        return -1;
    }
    int x = q->data[q->front];
    q->front++;
    q->size--;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return x;
}


// Display the elements in the Queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}


// Main function
int main() {
    Queue q = createQueue();

    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);
    enQueue(&q, 40);
    enQueue(&q, 50);

    display(&q);

    printf("Deleted element: %d\n", deQueue(&q));
    printf("Deleted element: %d\n", deQueue(&q));

    display(&q);

    enQueue(&q, 60);
    enQueue(&q, 70);

    display(&q);

    return 0;
}
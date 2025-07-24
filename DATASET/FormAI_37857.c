//FormAI DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Maximum queue size

/* Queue data structure */
typedef struct {
    int data[MAX_SIZE]; // Queue elements
    int front; // Index of the front element
    int rear; // Index of the rear element
    int size; // Current number of elements in the queue
} Queue;

/* Initialize the queue */
void init(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

/* Check if the queue is empty */
int is_empty(Queue* q) {
    return q->size == 0;
}

/* Check if the queue is full */
int is_full(Queue* q) {
    return q->size == MAX_SIZE;
}

/* Enqueue an element */
void enqueue(Queue* q, int x) {
    if (is_full(q)) {
        printf("Error: Queue is full\n");
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->data[q->rear] = x;
        q->size++;
    }
}

/* Dequeue an element */
int dequeue(Queue* q) {
    int x = 0;
    if (is_empty(q)) {
        printf("Error: Queue is empty\n");
    } else {
        x = q->data[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
        q->size--;
    }
    return x;
}

/* Print the queue contents */
void print_queue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", q->data[q->rear]);
}

/* Main function */
int main() {
    Queue q;
    init(&q);
    enqueue(&q, 5);
    enqueue(&q, 7);
    enqueue(&q, 3);
    print_queue(&q);
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    print_queue(&q);
    return 0;
}
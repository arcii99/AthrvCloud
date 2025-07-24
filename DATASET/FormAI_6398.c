//FormAI DATASET v1.0 Category: Queue Implementation ; Style: introspective
#include <stdio.h>

#define MAX_SIZE 10

// defining the structure of the queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// function prototypes
void enQueue(Queue *q, int value);
int deQueue(Queue *q);
void display(Queue *q);

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;

    // testing the queue operations
    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 3);
    enQueue(&q, 4);
    enQueue(&q, 5);
    enQueue(&q, 6);
    enQueue(&q, 7);
    enQueue(&q, 8);
    enQueue(&q, 9);
    enQueue(&q, 10);

    display(&q);

    deQueue(&q);
    deQueue(&q);

    printf("After dequeueing the first two elements: \n");
    display(&q);

    return 0;
}

// enqueue function
void enQueue(Queue *q, int value) {
    // checking if the queue is full
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue Overflow \n");
    } else {
        // if queue is empty
        if (q->front == -1) {
            q->front = 0;
        }
        // incrementing the rear pointer
        q->rear++;
        q->items[q->rear] = value;
    }
}

// dequeue function
int deQueue(Queue *q) {
    int item;
    // checking if the queue is empty
    if (q->front == -1) {
        printf("Queue Underflow \n");
        item = -1;
    } else {
        item = q->items[q->front];
        // incrementing the front pointer
        q->front++;
        // check if front and rear pointers are at the same position
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// display function
void display(Queue *q) {
    if (q->rear == -1) {
        printf("Queue is Empty \n");
    } else {
        int i;
        printf("Queue elements are: \n");
        for (i = q->front; i <= q->rear; i++) {
            printf("%d \n", q->items[i]);
        }
    }
}
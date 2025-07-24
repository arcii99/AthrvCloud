//FormAI DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5 // size of our queue

// queue struct
typedef struct queue {
    int front;
    int rear;
    int queue_array[MAX_QUEUE_SIZE];
} queue;

// function prototypes
void enqueue(queue *q, int value);
int dequeue(queue *q);
void print_queue(queue *q);

int main() {
    queue q; // declare our queue
    q.front = 0;
    q.rear = -1;

    // test enqueue and print function
    printf("Enqueueing values 10, 20, 30, 40, 50:\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    print_queue(&q);

    // test dequeue function
    printf("Dequeuing two values:\n");
    dequeue(&q);
    dequeue(&q);
    print_queue(&q);

    // test enqueue function again
    printf("Enqueueing two more values 60, 70:\n");
    enqueue(&q, 60);
    enqueue(&q, 70);
    print_queue(&q);

    // test dequeue function again
    printf("Dequeuing three values:\n");
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    print_queue(&q);

    // test enqueue function again
    printf("Enqueueing three more values 80, 90, 100:\n");
    enqueue(&q, 80);
    enqueue(&q, 90);
    enqueue(&q, 100);
    print_queue(&q);

    // test dequeue function again
    printf("Dequeuing all values:\n");
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        dequeue(&q);
    }
    print_queue(&q);

    return 0;
}

// enqueue function
void enqueue(queue *q, int value) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full! Cannot enqueue.\n");
        return;
    } else {
        q->rear++;
        q->queue_array[q->rear] = value;
    }
}

// dequeue function
int dequeue(queue *q) {
    if (q->front > q->rear) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    } else {
        int dequeue_value = q->queue_array[q->front];
        q->front++;
        return dequeue_value;
    }
}

// print queue function
void print_queue(queue *q) {
    printf("Front --> ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->queue_array[i]);
    }
    printf("<-- Rear\n");
}
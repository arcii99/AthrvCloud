//FormAI DATASET v1.0 Category: Queue ; Style: content
// C Queue Example Program
// Author: Chatbot

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // define queue size

typedef struct {
    int front;  // front index of the queue
    int rear;   // rear index of the queue
    int items[SIZE];  // array to hold the queue items
} queue;

void initQueue(queue *q) {
    q->front = -1;  // initialize front to -1
    q->rear = -1;   // initialize rear to -1
}

int isFull(queue *q) {
    if ((q->front == 0 && q->rear == SIZE - 1) || (q->front == q->rear + 1)) {
        return 1;   // queue is full
    } else {
        return 0;   // queue is not full
    }
}

int isEmpty(queue *q) {
    if (q->front == -1) {
        return 1;   // queue is empty
    } else {
        return 0;   // queue is not empty
    }
}

void enqueue(queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full, cannot enqueue\n");
    } else {
        if (q->front == -1) {
            q->front = 0;   // set front to 0
        }
        q->rear = (q->rear + 1) % SIZE;  // increase rear index by 1 and use modulo operator to wrap around the array
        q->items[q->rear] = value;  // insert value into the rear of the queue
        printf("Enqueued %d\n", value);
    }
}

int dequeue(queue *q) {
    int value;
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    } else {
        value = q->items[q->front];  // get value at front of queue
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;   // queue is now empty
        } else {
            q->front = (q->front + 1) % SIZE;    // increase front index by 1 and use modulo operator to wrap around the array
        }
        printf("Dequeued %d\n", value);
        return value;
    }
}

int main() {
    queue q;   // create queue object
    initQueue(&q);   // initialize queue
    enqueue(&q, 10);   // enqueue 10
    enqueue(&q, 20);   // enqueue 20
    enqueue(&q, 30);   // enqueue 30
    dequeue(&q);   // dequeue
    enqueue(&q, 40);   // enqueue 40
    enqueue(&q, 50);   // enqueue 50
    enqueue(&q, 60);   // enqueue 60
    dequeue(&q);   // dequeue
    dequeue(&q);   // dequeue
    enqueue(&q, 70);   // enqueue 70
    dequeue(&q);   // dequeue
    dequeue(&q);   // dequeue
    dequeue(&q);   // dequeue
    dequeue(&q);   // dequeue
    return 0;   // exit main function
}
//FormAI DATASET v1.0 Category: Queue Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

int front = -1, rear = -1;
int queue[QUEUE_SIZE];

void enqueue(int data) {
    if ((front == 0 && rear == QUEUE_SIZE - 1) || front == rear + 1) {
        printf("Queue overflow!\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = data;
        printf("Successfully enqueued element %d\n", data);
    } else if (rear == QUEUE_SIZE - 1 && front != 0) {
        rear = 0;
        queue[rear] = data;
        printf("Successfully enqueued element %d at position %d\n", data, rear);
    } else {
        rear++;
        queue[rear] = data;
        printf("Successfully enqueued element %d at position %d\n", data, rear);
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue underflow!\n");
    } else if (front == rear) {
        printf("Dequeuing element %d from position %d\n", queue[front], front);
        front = rear = -1;
    } else if (front == QUEUE_SIZE - 1) {
        printf("Dequeuing element %d from position %d\n", queue[front], front);
        front = 0;
    } else {
        printf("Dequeuing element %d from position %d\n", queue[front], front);
        front++;
    }
}

int main() {
    printf("Welcome to my happy C queue program!\n");

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);
    // queue is full, next enqueue operation will result in queue overflow
    enqueue(110);

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    // queue is empty, next dequeue operation will result in queue underflow
    dequeue();

    printf("Thank you for using my happy C queue program!\n");

    return 0;
}
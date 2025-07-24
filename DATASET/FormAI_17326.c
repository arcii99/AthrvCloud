//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 5

int queue[QUEUE_SIZE];
int front = -1;
int rear = -1;

void Enqueue(int data) {
    if (rear == QUEUE_SIZE - 1) {
        printf("Queue Overflow!\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = data;
    } else {
        rear++;
        queue[rear] = data;
    }
}

void Dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue Underflow!\n");
    } else if (front == rear) {
        printf("%d has been dequeued!\n", queue[front]);
        front = rear = -1;
    } else {
        printf("%d has been dequeued!\n", queue[front]);
        front++;
    }
}

void Display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty!\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Display();
    Dequeue();
    Display();
    Enqueue(40);
    Enqueue(50);
    Enqueue(60);
    Display();
    Enqueue(70);
    Dequeue();
    Display();
    return 0;
}
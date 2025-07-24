//FormAI DATASET v1.0 Category: Queue Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1 && rear == -1) 
        front = rear = 0;
    else
        rear++;
    queue[rear] = item;
    printf("%d enqueued to queue.\n", item);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    int item = queue[front];
    if (front == rear) 
        front = rear = -1;
    else
        front++;
    printf("%d dequeued from queue.\n", item);
}

void printQueue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    printQueue();
    dequeue();
    dequeue();
    printQueue();
    enqueue(50);
    printQueue();
    return 0;
}
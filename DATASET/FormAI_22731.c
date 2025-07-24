//FormAI DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item) {
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full!\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = item;
    } else {
        rear++;
        queue[rear] = item;
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int item = queue[front];
        front++;
        return item;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    display();
    enqueue(60);
    enqueue(70);
    display();
    return 0;
}
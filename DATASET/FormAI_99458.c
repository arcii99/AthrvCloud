//FormAI DATASET v1.0 Category: Queue ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

int front = -1;
int rear = -1;
int queue[MAX_QUEUE_SIZE];

void enqueue(int value) {
    if(rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    if(front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Enqueued %d!\n", value);
}

int dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    int dequeuedValue = queue[front];
    front++;
    printf("Dequeued %d!\n", dequeuedValue);
    return dequeuedValue;
}

void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    printf("Welcome to the exciting Queue example program!\n\n");

    printf("Let's start by enqueuing some values!\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); // This should fail, since the queue is full.

    printf("\nNow let's take a peek at our queue!\n");
    display();

    printf("\nLet's dequeue some values!\n");
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // This should fail, since the queue is empty.

    printf("\nNow let's take another peek at our queue!\n");
    display();

    printf("\nThanks for using our Queue example program! Hope you had fun!\n");

    return 0;
}
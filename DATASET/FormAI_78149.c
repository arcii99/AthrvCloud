//FormAI DATASET v1.0 Category: Queue ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

int front = -1, rear = -1;
int queue[MAX_SIZE];

bool isFull() {
    return rear == MAX_SIZE - 1;
}

bool isEmpty() {
    return front == -1 || front > rear;
}

int size() {
    if (isEmpty()) {
        return 0;
    } else {
        return 1 + size();
    }
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear++;
    queue[rear] = value;
    printf("%d enqueued to queue.\n", value);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int value = queue[front];
    front++;
    printf("%d dequeued from queue.\n", value);
    return value;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

void main() {
    display();

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);

    display();

    dequeue();
    dequeue();
    dequeue();

    display();

    printf("Size of queue: %d\n", size());
}
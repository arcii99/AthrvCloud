//FormAI DATASET v1.0 Category: Queue ; Style: surprised
#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

int isFull() {
    if (front == 0 && rear == MAX - 1) {
        return 1;
    }
    if (front == rear + 1) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full. Cannot add more elements.\n");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = data;
        printf("%d is added to the queue successfully!\n", data);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot remove any elements.\n");
    }
    else {
        printf("%d is removed from the queue.\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to display.\n");
    }
    else {
        printf("Queue elements are: ");
        int i;
        for (i = front; i != rear; i = (i + 1) % MAX) {
            printf("%d ", queue[i]);
        }
        printf("%d", queue[i]);
    }
}

int main() {
    printf("Welcome to the rollercoaster queue!\n");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    printf("\nOops, I forgot my phone in the car. BRB!\n");
    dequeue();
    dequeue();
    display();
    printf("\nOkay, back in line! Let's see where I left off.\n");
    enqueue(4);
    enqueue(5);
    display();
    return 0;
}
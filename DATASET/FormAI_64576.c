//FormAI DATASET v1.0 Category: Queue ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

int queue[QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int element) {
    if ((front == 0 && rear == QUEUE_SIZE - 1) || (rear == (front - 1) % (QUEUE_SIZE - 1))) {
        printf("Queue is full.\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
        queue[rear] = element;
    } else if (rear == QUEUE_SIZE - 1 && front != 0) {
        rear = 0;
        queue[rear] = element;
    } else {
        rear++;
        queue[rear] = element;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    }

    int element = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == QUEUE_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }

    return element;
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in Circular Queue are: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < QUEUE_SIZE; i++) {
            printf("%d ", queue[i]);
        }

        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    int element = dequeue();
    printf("Deleted element is %d\n", element);
    display();

    enqueue(50);
    enqueue(60);
    display();

    return 0;
}
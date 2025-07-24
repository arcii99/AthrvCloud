//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Alan Touring
//Title: Unique C Queue Implementation
//Author: AI Bot inspired by Alan Turing
//Date: February 2021

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Define a Max Size for the Queue

/* Structure for Queue in C */
struct Queue {
    int front, rear;
    int data[MAX_SIZE];
} queue;

/* Initialize the Queue */
void initializeQueue() {
    queue.front = -1;
    queue.rear = -1;
}

/* Check if Queue is Empty */
bool isQueueEmpty() {
    return queue.front == -1;
}

/* Check if Queue is Full */
bool isQueueFull() {
    return queue.rear == MAX_SIZE - 1;
}

/* Add Element to Queue */
void enqueue(int value) {
    if (isQueueFull()) {
        printf("Queue is Full.\n");
        return;
    }
    if (queue.front == -1) {
        queue.front = 0;
    }
    queue.rear++;
    queue.data[queue.rear] = value;
}

/* Remove Element from Queue */
int dequeue() {
    int value;
    if (isQueueEmpty()) {
        printf("Queue is Empty.\n");
        return -1;
    }
    else {
        value = queue.data[queue.front];
        if (queue.front >= queue.rear) {
            queue.front = -1;
            queue.rear = -1;
        }
        else {
            queue.front++;
        }
    }
    return value;
}

/* Display the Queue's Elements */
void displayQueue() {
    if (isQueueEmpty()) {
        printf("Queue is Empty.\n");
        return;
    }
    for (int i = queue.front; i <= queue.rear; i++) {
        printf("%d ", queue.data[i]);
    }
    printf("\n");
}

int main() {
    initializeQueue(); // Initialize the Queue

    /* Test the Queue's Functionality */
    enqueue(5);
    enqueue(1);
    enqueue(7);
    enqueue(9);
    enqueue(2);
    dequeue();
    enqueue(4);
    enqueue(6);

    printf("Current Queue Elements: ");
    displayQueue(); // Display the Queue's Elements

    return 0;
}
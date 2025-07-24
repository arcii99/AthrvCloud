//FormAI DATASET v1.0 Category: Queue ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Define the maximum size of the queue

// Declare global variables
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to insert an element into the queue
void enqueue(int value) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1))) {
        printf("Queue is full\n");
        return;
    }
    else if (front == -1) {
        front = rear = 0;
        queue[rear] = value;
    }
    else if (rear == MAX_SIZE - 1 && front != 0) {
        rear = 0;
        queue[rear] = value;
    }
    else {
        rear++;
        queue[rear] = value;
    }
}

// Function to delete an element from the queue
void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Element deleted from queue is : %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX_SIZE - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

// Function to display the elements of the queue
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements in Circular Queue are : ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    else {
        for (int i = front; i < MAX_SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); // Queue is full. Cannot insert any more elements.
    display(); // Elements in Circular Queue are : 10 20 30 40 50
    
    dequeue();
    dequeue();
    display(); // Elements in Circular Queue are : 30 40
    
    enqueue(60);
    enqueue(70);
    display(); // Elements in Circular Queue are : 30 40 60 70
    
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // Queue is empty. Cannot delete any more elements.
    display(); // Queue is empty
    return 0;
}
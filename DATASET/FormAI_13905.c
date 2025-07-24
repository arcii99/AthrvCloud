//FormAI DATASET v1.0 Category: Queue ; Style: content
#include <stdio.h>

#define MAX_SIZE 100 // Maximum size of the queue

int queue[MAX_SIZE]; // Declaring the queue as an integer array
int front = -1; // Initializing front pointer to -1
int rear = -1; // Initializing rear pointer to -1

// Function to check if the queue is empty
int is_empty() {
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

// Function to check if the queue is full
int is_full() {
    if ((rear+1)%MAX_SIZE == front)
        return 1;
    else
        return 0;
}

// Function to add an element to the queue
void enqueue(int x) {
    if (is_full()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    else if (is_empty()) {
        front = 0;
        rear = 0;
    }
    else {
        rear = (rear+1)%MAX_SIZE;
    }
    queue[rear] = x;
}

// Function to remove an element from the queue
void dequeue() {
    if (is_empty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    else if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front+1)%MAX_SIZE;
    }
}

// Function to print the elements of the queue
void print_queue() {
    if (is_empty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i+1)%MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    // Adding elements to the queue
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);
    
    // Printing the queue
    print_queue();
    
    // Removing an element from the queue
    dequeue();
    
    // Printing the queue
    print_queue();
    
    return 0;
}
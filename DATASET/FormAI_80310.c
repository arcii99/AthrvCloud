//FormAI DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_SIZE 10

// Define a struct to represent the elements of the stack
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Define a struct to represent the elements of the queue
typedef struct {
    int data[MAX_SIZE];
    int front, rear;
    int size;
} Queue;

// Define global variables for the stack and queue
Stack myStack = { .top = -1 };
Queue myQueue = { .front = 0, .rear = -1, .size = 0 };

// Function to check whether the stack is empty
bool isStackEmpty() {
    return myStack.top == -1;
}

// Function to check whether the stack is full
bool isStackFull() {
    return myStack.top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void pushStack(int data) {
    if (isStackFull()) {
        printf("Stack Overflow!\n");
        return;
    }
    myStack.data[++myStack.top] = data;
}

// Function to pop an element from the stack
int popStack() {
    if (isStackEmpty()) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return myStack.data[myStack.top--];
}

// Function to check whether the queue is empty
bool isQueueEmpty() {
    return myQueue.size == 0;
}

// Function to check whether the queue is full
bool isQueueFull() {
    return myQueue.size == MAX_SIZE;
}

// Function to insert an element into the queue
void enqueue(int data) {
    if (isQueueFull()) {
        printf("Queue Overflow!\n");
        return;
    }
    myQueue.data[++myQueue.rear] = data;
    myQueue.size++;
}

// Function to remove an element from the queue
int dequeue() {
    if (isQueueEmpty()) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int data = myQueue.data[myQueue.front];
    myQueue.front = (myQueue.front + 1) % MAX_SIZE;
    myQueue.size--;
    return data;
}

// Function to display the contents of the stack
void displayStack() {
    if (isStackEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack Contents: ");
    for (int i = myStack.top; i >= 0; i--) {
        printf("%d ", myStack.data[i]);
    }
    printf("\n");
}

// Function to display the contents of the queue
void displayQueue() {
    if (isQueueEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue Contents: ");
    int i = myQueue.front;
    int count = 0;
    while (count < myQueue.size) {
        printf("%d ", myQueue.data[i]);
        i = (i + 1) % MAX_SIZE;
        count++;
    }
    printf("\n");
}

// Function to run the visualization (asynchronous)
void *runVisualization(void *arg) {
    for (int i = 0; i < 10; i++) {
        int data = rand() % 10 + 1;
        printf("Iteration %d:\n", i+1);
        printf("Data to push onto stack: %d\n", data);
        pushStack(data);
        displayStack();
        usleep(1000000);

        data = rand() % 10 + 1;
        printf("Data to enqueue into queue: %d\n", data);
        enqueue(data);
        displayQueue();
        usleep(1000000);

        printf("Data to pop from stack: %d\n", popStack());
        displayStack();
        usleep(1000000);

        printf("Data to dequeue from queue: %d\n", dequeue());
        displayQueue();
        usleep(1000000);
    }
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Create a thread for the visualization
    pthread_t thread;
    if (pthread_create(&thread, NULL, runVisualization, NULL)) {
        printf("Error creating thread.\n");
        exit(-1);
    }

    pthread_join(thread, NULL);
    return 0;
}
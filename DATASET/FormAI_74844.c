//FormAI DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum capacity of the array

// Defining structures for stack and queue
struct Stack {
    int top;
    int arr[MAX_SIZE];
};

struct Queue {
    int front, rear;
    int arr[MAX_SIZE];
};

// Function to initialize an empty stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isStackEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isStackFull(struct Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element to the stack
void push(struct Stack* stack, int value) {
    if (isStackFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to initialize an empty queue
void initializeQueue(struct Queue* queue) {
    queue->front = queue->rear = -1;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isQueueFull(struct Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* queue, int value) {
    if (isQueueFull(queue)) {
        printf("Queue overflow\n");
        return;
    }
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = 0;
        queue->arr[queue->rear] = value;
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = value;
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue underflow\n");
        return -1;
    }
    if (queue->front == queue->rear) {
        int value = queue->arr[queue->front];
        queue->front = queue->rear = -1;
        return value;
    }
    int value = queue->arr[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    return value;
}

int main() {

    // Initializing stack and queue
    struct Stack stack;
    struct Queue queue;
    initializeStack(&stack);
    initializeQueue(&queue);

    // Pushing some values to the stack
    push(&stack, 3);
    push(&stack, 7);
    push(&stack, 9);
    push(&stack, 4);

    // Printing the stack
    printf("Stack: ");
    while (!isStackEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");

    // Adding some values to the queue
    enqueue(&queue, 5);
    enqueue(&queue, 2);
    enqueue(&queue, 1);
    enqueue(&queue, 8);

    // Printing the queue
    printf("Queue: ");
    while (!isQueueEmpty(&queue)) {
        printf("%d ", dequeue(&queue));
    }
    printf("\n");

    return 0;
}
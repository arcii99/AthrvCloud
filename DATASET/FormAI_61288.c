//FormAI DATASET v1.0 Category: Data structures visualization ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Declare the Stack data structure
typedef struct Stack {
    int items[MAX_SIZE];
    int top;
} Stack;

// Initialize the Stack data structure
void initialize(Stack* stack) {
    stack->top = -1;
}

// Check if the Stack data structure is full
bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Check if the Stack data structure is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Add an item element to the Stack data structure
bool push(Stack* stack, int item) {
    if (isFull(stack)) {
        return false;
    } else {
        stack->top++;
        stack->items[stack->top] = item;
        return true;
    }
}

// Remove the first element from the Stack data structure
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    } else {
        int removedItem = stack->items[stack->top];
        stack->top--;
        return removedItem;
    }
}

// Display the Stack data structure
void display(Stack* stack) {
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

// Main function to test the Stack data structure
int main() {
    Stack stack;
    initialize(&stack);

    printf("Pushing elements onto Stack...\n");
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    display(&stack);

    printf("Popping an element from Stack...\n");
    int removedItem = pop(&stack);
    printf("Removed Item: %d\n", removedItem);

    display(&stack);

    return 0;
}
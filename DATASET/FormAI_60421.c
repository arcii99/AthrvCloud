//FormAI DATASET v1.0 Category: Data structures visualization ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define the stack data structure
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Initialize the stack
void initialize(Stack *stack) {
    stack->top = -1;
}

// Push an element onto the stack
bool push(Stack *stack, int value) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return false;
    }
    
    stack->data[++stack->top] = value;
    return true;
}

// Pop an element from the stack
bool pop(Stack *stack, int *result) {
    if (stack->top < 0) {
        printf("Stack underflow!\n");
        return false;
    }
    
    *result = stack->data[stack->top--];
    return true;
}

// Display the stack
void display(Stack stack) {
    printf("Stack (top to bottom): ");
    for (int i = stack.top; i >= 0; i--) {
        printf("%d ", stack.data[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initialize(&stack);
    
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    
    display(stack);
    
    int result1, result2, result3;
    pop(&stack, &result1);
    pop(&stack, &result2);
    pop(&stack, &result3);
    
    printf("Popped elements: %d %d %d\n", result1, result2, result3);
    
    display(stack);
    
    return 0;
}
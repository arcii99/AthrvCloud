//FormAI DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include <stdio.h>

#define MAX_ELEMENTS 10

// Define a struct representing a stack data structure
typedef struct Stack {
    int elements[MAX_ELEMENTS];
    int top;
} Stack;

// Initialize an empty stack
void init(Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *stack) {
    return (stack->top == -1);
}

// Check if the stack is full
int isFull(Stack *stack) {
    return (stack->top == MAX_ELEMENTS - 1);
}

// Push an element onto the stack
void push(Stack *stack, int element) {
    if (!isFull(stack)) {
        stack->elements[++stack->top] = element;
    }
}

// Pop an element off the stack
int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->elements[stack->top--];
    }
}

// Display the contents of the stack
void display(Stack *stack) {
    int i;
    printf("Stack: ");
    for (i = stack->top; i >= 0; i--) {
        printf("%d ", stack->elements[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    init(&stack);
    
    // Push some elements onto the stack
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    
    // Display the stack
    display(&stack);
    
    // Pop an element off the stack
    int element = pop(&stack);
    printf("Popped element: %d\n", element);
    
    // Display the stack again
    display(&stack);
    
    return 0;
}
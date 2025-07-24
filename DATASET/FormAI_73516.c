//FormAI DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure of the Stack
struct Stack {
    int top_index; // tracking the index of the top element
    int data[MAX_SIZE]; // actual data of the Stack
};

// function prototypes
void initialize_stack(struct Stack *stack);
int is_empty(struct Stack stack);
int is_full(struct Stack stack);
void push(struct Stack *stack, int value);
int pop(struct Stack *stack);
void display(struct Stack stack);

// function to initialize the Stack
void initialize_stack(struct Stack *stack) {
    stack->top_index = -1;
}

// function to check if Stack is empty
int is_empty(struct Stack stack) {
    if (stack.top_index == -1) {
        return 1;
    }
    return 0;
}

// function to check if Stack is full
int is_full(struct Stack stack) {
    if (stack.top_index == MAX_SIZE-1) {
        return 1;
    }
    return 0;
}

// function to add an element to the Stack
void push(struct Stack *stack, int value) {
    if (is_full(*stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top_index++;
    stack->data[stack->top_index] = value;
}

// function to remove an element from the Stack
int pop(struct Stack *stack) {
    int popped_element = -1;
    if (is_empty(*stack)) {
        printf("Stack Underflow\n");
        return popped_element;
    }
    popped_element = stack->data[stack->top_index];
    stack->top_index--;
    return popped_element;
}

// function to display the Stack
void display(struct Stack stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i=stack.top_index; i>=0; i--) {
        printf("%d\n", stack.data[i]);
    }
}

int main() {
    struct Stack myStack; // Create a new Stack
    initialize_stack(&myStack); // Initialize the Stack
    push(&myStack, 10); // add an element to the Stack
    push(&myStack, 20); // add an element to the Stack
    push(&myStack, 30); // add an element to the Stack
    display(myStack); // display Stack elements
    int popped_element = pop(&myStack); // remove an element from the Stack
    printf("Popped element: %d\n", popped_element);
    display(myStack); // display Stack elements
    return 0;
}
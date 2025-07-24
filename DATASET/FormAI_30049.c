//FormAI DATASET v1.0 Category: Data structures visualization ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define our custom node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define our custom stack structure
typedef struct Stack {
    Node* top;
} Stack;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if stack is empty
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// Function to push element to the stack
void push(Stack* stack, int data) {
    Node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}

// Function to pop element from the stack
int pop(Stack* stack) {
    if(isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to visualize the stack
void visualizeStack(Stack* stack) {
    if(isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    Node* current = stack->top;
    printf("TOP\n");
    while(current != NULL) {
        printf("| %d |\n", current->data);
        printf("----\n");
        current = current->next;
    }
}

// Main function
int main() {
    // Create new stack
    Stack* stack = createStack();

    // Push some elements to the stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    // Visualize the stack
    visualizeStack(stack);

    // Pop some elements from the stack
    pop(stack);
    pop(stack);

    // Visualize the stack
    visualizeStack(stack);

    // Push some more elements to the stack
    push(stack, 50);
    push(stack, 60);

    // Visualize the final stack
    visualizeStack(stack);

    return 0;
}
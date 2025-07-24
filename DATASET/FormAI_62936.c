//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Linus Torvalds
#include <stdio.h>

#define MAX_SIZE 5

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Pushes a new element on top of the stack
void push(struct Stack* stack, int data) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Error: Stack overflow.\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = data;
    printf("Pushed %d on top of the stack.\n", data);
}

// Pops the topmost element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Error: Stack underflow.\n");
        return -1;
    }
    int data = stack->arr[stack->top];
    stack->top--;
    printf("Popped %d from top of the stack.\n", data);
    return data;
}

// Prints the current state of the stack
void print_stack(struct Stack* stack) {
    printf(" Stack\n");
    printf("--------\n");
    for (int i = MAX_SIZE - 1; i >= 0; i--) {
        if (i <= stack->top) {
            printf("| %3d |\n", stack->arr[i]);
        } else {
            printf("|     |\n");
        }
    }
    printf("--------\n");
}

int main() {
    // Initialize an empty stack
    struct Stack stack = { .top = -1 };
    
    // Push some elements in the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Print the current state of the stack
    print_stack(&stack);
    
    // Pop the topmost element from the stack
    pop(&stack);
    
    // Print the current state of the stack
    print_stack(&stack);

    return 0;
}
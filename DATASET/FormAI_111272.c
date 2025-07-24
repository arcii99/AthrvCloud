//FormAI DATASET v1.0 Category: Data structures visualization ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int arr[MAX_STACK_SIZE];
    int top;
} paranoid_stack;

void init_stack(paranoid_stack *stack) {
    for(int i=0; i<MAX_STACK_SIZE; i++) {
        stack->arr[i] = 0;
    }
    stack->top = -1;
}

void push(paranoid_stack *stack, int data) {
    if(stack->top >= MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->top++;
    stack->arr[stack->top] = data;

    // paranoia check
    if(stack->arr[stack->top] != data) {
        printf("Stack Corrupted! Exiting program...\n");
        exit(1);
    }
}

int pop(paranoid_stack *stack) {
    if(stack->top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }

    int data = stack->arr[stack->top];
    stack->arr[stack->top] = 0;
    stack->top--;

    // paranoia check
    if(stack->arr[stack->top+1] != data) {
        printf("Stack Corrupted! Exiting program...\n");
        exit(1);
    }

    return data;
}

void print_stack(paranoid_stack *stack) {
    if(stack->top < 0) {
        printf("Empty Stack\n");
        return;
    }

    for(int i=stack->top; i>=0; i--) {
        printf("%d\n", stack->arr[i]);
    }
}

int main() {
    paranoid_stack my_stack;
    init_stack(&my_stack);

    push(&my_stack, 10);
    push(&my_stack, 20);
    push(&my_stack, 30);

    printf("Stack Contents: \n");
    print_stack(&my_stack);

    int popped = pop(&my_stack);
    printf("\nPopped element: %d\n", popped);

    printf("\nStack Contents: \n");
    print_stack(&my_stack);

    return 0;
}
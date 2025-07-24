//FormAI DATASET v1.0 Category: Data structures visualization ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Custom data structure called Stack
typedef struct Stack {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Function to initialize stack
void initialize_stack(Stack *s) {
    s->top = -1;
}

// Function to check if stack is empty
bool is_empty(Stack *s) {
    return s->top == -1;
}

// Function to check if stack is full
bool is_full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Function to push element onto stack
void push(Stack *s, int val) {
    if (is_full(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->arr[++s->top] = val;
}

// Function to pop element from stack
int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->arr[s->top--];
}

// Function to display stack contents
void display_stack(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("| %d |\n", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initialize_stack(&s);

    // Pushing elements onto stack
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    // Displaying stack contents
    display_stack(&s);

    // Popping element from stack
    int popped = pop(&s);
    printf("Popped element: %d\n", popped);

    // Displaying stack contents again
    display_stack(&s);

    return 0;
}
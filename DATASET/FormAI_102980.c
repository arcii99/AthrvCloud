//FormAI DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>

#define MAX_SIZE 100

typedef enum {false, true} bool;

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void push(Stack *stack, int data) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Error: stack overflow!\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = data;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Error: stack underflow!\n");
        return -1;
    }
    int data = stack->arr[stack->top];
    stack->top--;
    return data;
}

void display(Stack *stack) {
    if (stack->top == -1) {
        printf("Error: stack is empty!\n");
        return;
    }
    printf("\n|");
    for (int i = stack->top; i >= 0; i--) {
        printf("   %d   |\n", stack->arr[i]);
        if (i != 0) printf("|");
    }
    printf("\n");
}

int main() {
    Stack stack = {.top = -1};
    push(&stack, 3);
    push(&stack, 7);
    push(&stack, 1);
    push(&stack, 8);
    printf("Initial Stack:\n");
    display(&stack);
    pop(&stack);
    push(&stack, 5);
    printf("Updated Stack:\n");
    display(&stack);
    return 0;
}
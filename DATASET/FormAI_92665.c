//FormAI DATASET v1.0 Category: Data structures visualization ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Stack {
    int data[MAX];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isFull(Stack *stack) {
    if (stack->top == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty(Stack *stack) {
    if (stack->top == -1)
        return 1;
    else
        return 0;
}

void push(Stack *stack, int element) {
    if (isFull(stack))
        printf("Stack Overflow");
    else {
        stack->top++;
        stack->data[stack->top] = element;
    }
}

int pop(Stack *stack) {
    int element;
    if (isEmpty(stack)) {
        printf("Stack Underflow");
        return -1;
    } else {
        element = stack->data[stack->top];
        stack->top--;
        return element;
    }
}

void display(Stack *stack) {
    int i;
    if (isEmpty(stack))
        printf("Stack Empty");
    else {
        printf("Stack: ");
        for (i = stack->top; i >= 0; i--)
            printf("%d ", stack->data[i]);
        printf("\n");
    }
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Popped: %d\n", pop(&stack));

    display(&stack);

    return 0;
}
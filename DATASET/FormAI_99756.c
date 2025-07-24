//FormAI DATASET v1.0 Category: Data structures visualization ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

int top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top];
}

void display(Stack* stack) {
    printf("STACK:\n");
    printf("-----\n");
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
    } else {
        int i;
        for (i = stack->top; i >= 0; i--) {
            printf("%d\n", stack->data[i]);
        }
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);
    push(&stack, 20);

    printf("After pushing 5, 10, 15, and 20 into the stack:\n");
    display(&stack);

    pop(&stack);
    pop(&stack);

    printf("After popping 2 elements from stack:\n");
    display(&stack);

    printf("Top element of stack is: %d\n", top(&stack));

    return 0;
}
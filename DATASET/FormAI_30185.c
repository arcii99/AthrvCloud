//FormAI DATASET v1.0 Category: Data structures visualization ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// structure for a stack
typedef struct {
    int array[MAX_SIZE];
    int top;
} Stack;

// initialize stack
void initStack(Stack *stack) {
    stack->top = 0;
}

// check if stack is empty
int isEmpty(Stack *stack) {
    return stack->top == 0;
}

// check if stack is full
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE;
}

// push element into stack
void push(Stack *stack, int element) {
    if (isFull(stack)) {
        printf("Error: Stack is full\n");
        return;
    }
    stack->array[stack->top++] = element;
}

// pop element from stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return stack->array[--stack->top];
}

// print stack contents
void printStack(Stack *stack) {
    printf("Stack: ");
    for (int i = stack->top-1; i >= 0; i--) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    Stack stack1;
    Stack stack2;
    initStack(&stack1);
    initStack(&stack2);

    // push elements into stack1
    push(&stack1, 1);
    push(&stack1, 2);
    push(&stack1, 3);
    printStack(&stack1);

    // pop element from stack1 and push into stack2
    push(&stack2, pop(&stack1));
    push(&stack2, pop(&stack1));
    printStack(&stack1);
    printStack(&stack2);

    // push elements into stack1
    push(&stack1, 4);
    push(&stack1, 5);
    push(&stack1, 6);
    printStack(&stack1);
    printStack(&stack2);

    // pop element from stack1 and push into stack2
    push(&stack2, pop(&stack1));
    printStack(&stack1);
    printStack(&stack2);

    return 0;
}
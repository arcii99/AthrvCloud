//FormAI DATASET v1.0 Category: Data structures visualization ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;    
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isFull(Stack stack) {
    return stack.top == MAX_SIZE - 1;
}

int isEmpty(Stack stack) {
    return stack.top == -1;
}

void push(Stack* stack, int item) {
    if(isFull(*stack)) {
        printf("Stack Overflow!");
        return;
    }
    stack->data[++stack->top] = item;
}

int pop(Stack* stack) {
    if(isEmpty(*stack)) {
        printf("Stack Underflow!");
        return -999;
    }
    return stack->data[stack->top--];
}

void display(Stack stack) {
    if(isEmpty(stack)) {
        printf("Stack is empty!");
        return;
    }
    printf("Stack Contents: ");
    for(int i = stack.top; i >= 0; i--) {
        printf("%d ", stack.data[i]);
    }
}

int main() {

    Stack stack;
    initStack(&stack);

    printf("Stack Visualization:\n\n");

    printf("Pushing elements...\n");
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    printf("\n");
    display(stack);
    
    printf("\nPopping elements...\n");
    pop(&stack);
    pop(&stack);

    printf("\n");
    display(stack);

    printf("\n");

    return 0;
}
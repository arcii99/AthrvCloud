//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// structure for stack
struct stack {
    int arr[MAX_SIZE];
    int top;
};

// function to initialize the stack
void initializeStack(struct stack *s) {
    s->top = -1;
}

// function to check if stack is full
int isFull(struct stack *s) {
    if(s->top == MAX_SIZE-1)
        return 1;
    else
        return 0;
}

// function to check if stack is empty
int isEmpty(struct stack *s) {
    if(s->top == -1)
        return 1;
    else
        return 0;
}

// function to push element into stack
void push(struct stack *s, int data) {
    if(isFull(s))
        printf("Stack is full\n");
    else {
        s->top++;
        s->arr[s->top] = data;
        printf("%d pushed into stack\n", data);
    }
}

// function to pop element from stack
int pop(struct stack *s) {
    if(isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    else {
        int data = s->arr[s->top];
        s->top--;
        return data;
    }
}

// function to print stack contents
void printStack(struct stack *s) {
    if(isEmpty(s))
        printf("Stack is empty\n");
    else {
        printf("Stack contents:\n");
        for(int i=s->top; i>=0; i--)
            printf("%d\n", s->arr[i]);
    }
}

// example usage
int main() {
    struct stack s;
    initializeStack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));
    printStack(&s);
    return 0;
}
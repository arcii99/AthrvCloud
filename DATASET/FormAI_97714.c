//FormAI DATASET v1.0 Category: Data structures visualization ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Stack {
    int top;
    int data[MAX_SIZE];
} Stack;

// Function to initialize stack
void init(Stack *s) {
    s->top = -1;
}

// Function to push element into stack
void push(Stack *s, int element) {
    if (s->top >= MAX_SIZE) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = element;
}

// Function to pop top element from stack
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

// Function to display stack contents
void display(Stack s) {
    if (s.top == -1) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack Contents:\n");
    for (int i = s.top; i >= 0; --i) {
        printf("%d\n", s.data[i]);
    }
}

int main() {
    Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(s);
    printf("Popped Element: %d\n", pop(&s));
    display(s);
    return 0;
}
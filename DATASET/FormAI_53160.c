//FormAI DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 15

typedef struct stack {
    int elements[MAX_ELEMENTS];
    int top;
} stack_t;

void initialize(stack_t* s) {
    s->top = -1;
}

void push(stack_t* s, int element) {
    if(s->top == MAX_ELEMENTS - 1) {
        printf("Error: Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->elements[++(s->top)] = element;
}

int pop(stack_t* s) {
    if(s->top == -1) {
        printf("Error: Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->elements[(s->top)--];
}

void display_stack(stack_t* s) {
    printf("Stack Elements are:\n");
    for(int i=0; i<=s->top; ++i) {
        printf("%d ", s->elements[i]);
    }
    printf("\n");
}

int main() {
    stack_t s;
    initialize(&s);
    printf("Stack after initialization:\n");
    display_stack(&s);
    push(&s, 10);
    printf("Stack after pushing 10:\n");
    display_stack(&s);
    push(&s, 20);
    printf("Stack after pushing 20:\n");
    display_stack(&s);
    int element = pop(&s);
    printf("Popped element: %d\n", element);
    printf("Stack after popping 20:\n");
    display_stack(&s);
    return 0;
}
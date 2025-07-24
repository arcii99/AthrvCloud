//FormAI DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>

#define STACK_SIZE 100

typedef struct Stack {
    int data[STACK_SIZE];
    int top;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == STACK_SIZE - 1;
}

void push(Stack *s, int value) {
    if (is_full(s)) {
        printf("Error: stack overflow\n");
        return;
    }

    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Error: stack underflow\n");
        return -1;
    }

    return s->data[s->top--];
}

void print_stack(Stack *s) {
    int i;

    printf("Stack:\n");

    for (i = s->top; i >= 0; i--)
        printf("%d\n", s->data[i]);
}

int main() {
    Stack s;

    init_stack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    pop(&s);
    push(&s, 40);
    print_stack(&s);

    return 0;
}
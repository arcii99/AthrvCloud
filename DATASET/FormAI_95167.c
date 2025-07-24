//FormAI DATASET v1.0 Category: Data structures visualization ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int items[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack* s, int value) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("Error: Stack is full.\n");
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(Stack* s) {
    int value;

    if (s->top == -1) {
        printf("Error: Stack is empty.\n");
        return -1;
    } else {
        value = s->items[s->top];
        s->top--;
        return value;
    }
}

int main() {
    Stack s;
    s.top = -1;

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Stack: %d, %d, %d\n", s.items[2], s.items[1], s.items[0]);

    int popped = pop(&s);

    printf("Popped: %d\n", popped);
    printf("Stack: %d, %d\n", s.items[1], s.items[0]);

    return 0;
}
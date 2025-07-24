//FormAI DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Error: Stack overflow\n");
        return;
    }

    s->top++;
    s->data[s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Error: Stack underflow\n");
        return -1;
    }

    int value = s->data[s->top];
    s->top--;

    return value;
}

int main() {
    Stack s;
    initStack(&s);

    printf("Pushing elements onto stack:\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("\nStack visualization:\n");
    printf("+--------+\n");

    for (int i = MAX_SIZE - 1; i >= 0; i--) {
        if (i == s.top) {
            printf("|%-8d|\n", s.data[i]);
        } else {
            printf("|        |\n");
        }
        printf("+--------+\n");
    }

    printf("\nPopped element: %d\n", pop(&s));

    printf("\nStack visualization:\n");
    printf("+--------+\n");

    for (int i = MAX_SIZE - 1; i >= 0; i--) {
        if (i == s.top) {
            printf("|%-8d|\n", s.data[i]);
        } else {
            printf("|        |\n");
        }
        printf("+--------+\n");
    }

    return 0;
}
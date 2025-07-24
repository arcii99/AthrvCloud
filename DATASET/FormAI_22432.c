//FormAI DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>

typedef struct {
    int data[5];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int push(Stack *s, int value) {
    if (s->top >= 4) {
        return 0;
    }
    s->top++;
    s->data[s->top] = value;
    return 1;
}

int pop(Stack *s) {
    if (s->top < 0) {
        return -1;
    }
    return s->data[s->top--];
}

void showStack(Stack *s) {
    printf("\nStack\n");
    printf("-----\n");
    for (int i = s->top; i >= 0; i--) {
        printf("| %d |\n", s->data[i]);
    }
    printf("-----\n");
}

int main() {
    Stack s;
    initStack(&s);
    push(&s, 5);
    push(&s, 10);
    push(&s, 15);
    showStack(&s);
    pop(&s);
    showStack(&s);
    push(&s, 20);
    push(&s, 25);
    push(&s, 30);
    push(&s, 35);
    showStack(&s);
    return 0;
}
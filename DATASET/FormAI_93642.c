//FormAI DATASET v1.0 Category: Data structures visualization ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_SIZE 10

/* The Data Structure */
typedef struct {
    int arr[MAX_SIZE];
    int top;
} stack;

/* Functions to operate on the stack */
void init_stack(stack *s) {
    s->top = -1;
}

bool is_empty(stack *s) {
    return s->top == -1;
}

bool is_full(stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(stack *s, int data) {
    if (is_full(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->arr[++s->top] = data;
    usleep(500000); /* for a cool visual effect */
}

int pop(stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->arr[s->top--];
}

void display_stack(stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("\nStack Contents:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("|%3d|\n", s->arr[i]);
    }
    printf("+---+\n");
}

/* Main function */
int main() {
    stack my_stack;
    init_stack(&my_stack);
    push(&my_stack, 5);
    push(&my_stack, 8);
    push(&my_stack, 3);
    push(&my_stack, 1);
    push(&my_stack, 2);
    display_stack(&my_stack);
    pop(&my_stack);
    display_stack(&my_stack);
    push(&my_stack, 6);
    push(&my_stack, 7);
    push(&my_stack, 9);
    display_stack(&my_stack);
    pop(&my_stack);
    pop(&my_stack);
    display_stack(&my_stack);
    pop(&my_stack);
    pop(&my_stack);
    pop(&my_stack);
    display_stack(&my_stack);
    return 0;
}
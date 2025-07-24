//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_SIZE 100 // Maximum size of the calculator's stack

typedef struct {
    int top;
    double items[STACK_SIZE];
} Stack;

void push(Stack *s, double value) {
    if (s->top == STACK_SIZE - 1) {
        printf("Stack is full!\n");
        exit(1);
    }
    s->top++;
    s->items[s->top] = value;
}

double pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        exit(1);
    }
    double value = s->items[s->top];
    s->top--;
    return value;
}

double calculate(char *expression) {
    Stack s;
    s.top = -1;

    char *endptr;
    while (*expression != '\0') {
        if (*expression >= '0' && *expression <= '9') {
            double value = strtod(expression, &endptr);
            push(&s, value);
            expression = endptr;
        } else if (*expression == '+') {
            double op1 = pop(&s);
            double op2 = pop(&s);
            push(&s, op2 + op1);
            expression++;
        } else if (*expression == '-') {
            double op1 = pop(&s);
            double op2 = pop(&s);
            push(&s, op2 - op1);
            expression++;
        } else if (*expression == '*') {
            double op1 = pop(&s);
            double op2 = pop(&s);
            push(&s, op2 * op1);
            expression++;
        } else if (*expression == '/') {
            double op1 = pop(&s);
            double op2 = pop(&s);
            push(&s, op2 / op1);
            expression++;
        } else if (*expression == '^') {
            double op1 = pop(&s);
            double op2 = pop(&s);
            push(&s, pow(op2, op1));
            expression++;
        } else if (*expression == 'sqrt') {
            double op1 = pop(&s);
            push(&s, sqrt(op1));
            expression += 3;
        } else if (*expression == 'sin') {
            double op1 = pop(&s);
            push(&s, sin(op1));
            expression += 2;
        } else if (*expression == 'cos') {
            double op1 = pop(&s);
            push(&s, cos(op1));
            expression += 2;
        } else if (*expression == 'tan') {
            double op1 = pop(&s);
            push(&s, tan(op1));
            expression += 2;
        } else {
            expression++;
        }
    }

    double result = pop(&s);
    if (s.top != -1) {
        printf("Invalid expression!\n");
        exit(1);
    }

    return result;
}

int main() {
    char expression[100];
    printf("Enter an expression to calculate: ");
    fgets(expression, 100, stdin);
    double result = calculate(expression);
    printf("Result: %f\n", result);
    return 0;
}
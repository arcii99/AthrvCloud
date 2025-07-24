//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 50
 
typedef struct {
    double stack_array[MAX_STACK_SIZE];
    int top;
} Stack;

/* Initialize the stack */
void initialize(Stack *stack) {
    stack->top = -1;
}

/* Push value onto the stack */
void push(Stack *stack, double value) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->top++;
        stack->stack_array[stack->top] = value;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

/* Pop value off of the stack */
double pop(Stack *stack) {
    double value;
    if (stack->top >= 0) {
        value = stack->stack_array[stack->top];
        stack->top--;
        return value;
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

/* Evaluate the expression */
void evaluate(char *expression) {
    Stack stack;
    initialize(&stack);
    double x, y, z;
    char *p = expression;
    while (*p != '\0') {
        if (*p == ' ') {
            p++;
            continue;
        }
        if (isdigit(*p)) {
            push(&stack, atof(p));
            while (isdigit(*p) || *p == '.') {
                p++;
            }
        } else if (*p == '+') {
            y = pop(&stack);
            x = pop(&stack);
            push(&stack, x + y);
            p++;
        } else if (*p == '-') {
            y = pop(&stack);
            x = pop(&stack);
            push(&stack, x - y);
            p++;
        } else if (*p == '*') {
            y = pop(&stack);
            x = pop(&stack);
            push(&stack, x * y);
            p++;
        } else if (*p == '/') {
            y = pop(&stack);
            x = pop(&stack);
            push(&stack, x / y);
            p++;
        } else if (*p == '^') {
            y = pop(&stack);
            x = pop(&stack);
            push(&stack, pow(x, y));
            p++;
        } else if (*p == 's') {
            if (*(p + 1) == 'i' && *(p + 2) == 'n') {
                x = pop(&stack);
                push(&stack, sin(x));
                p += 3;
            } else {
                printf("Invalid expression\n");
                exit(1);
            }
        } else if (*p == 'c') {
            if (*(p + 1) == 'o' && *(p + 2) == 's') {
                x = pop(&stack);
                push(&stack, cos(x));
                p += 3;
            } else {
                printf("Invalid expression\n");
                exit(1);
            }
        } else if (*p == 't') {
            if (*(p + 1) == 'a' && *(p + 2) == 'n') {
                x = pop(&stack);
                push(&stack, tan(x));
                p += 3;
            } else {
                printf("Invalid expression\n");
                exit(1);
            }
        } else {
            printf("Invalid expression\n");
            exit(1);
        }
    }
    z = pop(&stack);
    if (stack.top >= 0) {
        printf("Invalid expression\n");
        exit(1);
    }
    printf("%f\n", z);
}

int main() {
    char input[100];
    printf("Enter expression: ");
    fgets(input, sizeof(input), stdin);
    evaluate(input);
    return 0;
}
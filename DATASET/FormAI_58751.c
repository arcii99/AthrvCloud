//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define STACK_SIZE 100 // maximum size of stack

double stack[STACK_SIZE]; // stack to hold operands
int top = 0; // index of top of stack

// push operand onto stack
void push(double operand) {
    if (top == STACK_SIZE) {
        printf("Error: stack full\n");
        exit(EXIT_FAILURE);
    }
    stack[top++] = operand;
}

// pop operand from stack
double pop() {
    if (top == 0) {
        printf("Error: stack empty\n");
        exit(EXIT_FAILURE);
    }
    return stack[--top];
}

// clear stack
void clear() {
    top = 0;
}

// perform operation on top two operands of stack
void perform_operation(char operator) {
    double operand1, operand2, result;
    
    operand2 = pop();
    operand1 = pop();
    
    switch (operator) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            if (operand2 == 0) {
                printf("Error: division by zero\n");
                exit(EXIT_FAILURE);
            }
            result = operand1 / operand2;
            break;
        case '^':
            result = pow(operand1, operand2);
            break;
        case 's':
            result = sin(operand1);
            break;
        case 'c':
            result = cos(operand1);
            break;
        case 't':
            result = tan(operand1);
            break;
        case 'r':
            result = sqrt(operand1);
            break;
        default:
            printf("Error: unsupported operator\n");
            exit(EXIT_FAILURE);
    }
    
    push(result);
}

// main program loop
int main() {
    char input[100];
    char *ptr;
    double operand;
    
    printf("Welcome to the Scientific Calculator!\n");
    
    while (1) {
        printf("> ");
        fgets(input, 100, stdin);
        
        if (isdigit(input[0]) || ((input[0] == '-' || input[0] == '+') && isdigit(input[1]))) {
            operand = strtod(input, &ptr);
            push(operand);
        } else if (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/' || input[0] == '^' ||
                   input[0] == 's' || input[0] == 'c' || input[0] == 't' || input[0] == 'r') {
            perform_operation(input[0]);
        } else if (input[0] == 'c') {
            clear();
        } else if (input[0] == 'q') {
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Error: unsupported input\n");
        }
        
        // print contents of stack
        printf("= ");
        for (int i = 0; i < top; i++) {
            printf("%.2f ", stack[i]);
        }
        printf("\n");
    }
}
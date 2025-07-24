//FormAI DATASET v1.0 Category: Syntax parsing ; Style: mathematical
/* A Mathematical C program to parse mathematical expressions */
#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAX_SIZE 100

/* defining a stack structure for parsing */
struct stack {
    int top;
    char items[MAX_SIZE];
};

/* initializing the stack */
void initialize(struct stack* s) {
    s->top = -1;
}

/* check if the stack is empty */
int isEmpty(struct stack* s) {
    if (s->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

/* check if the stack is full */
int isFull(struct stack* s) {
    if (s->top == MAX_SIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

/* push an item onto the stack */
void push(struct stack* s, char item) {
    if (isFull(s)) {
        printf("Stack is full");
    }
    else {
        s->top++;
        s->items[s->top] = item;
    }
}

/* pop an item from the stack */
char pop(struct stack* s) {
    char item;

    if (isEmpty(s)) {
        printf("Stack is empty");
        item = '\0';
    }
    else {
        item = s->items[s->top];
        s->top--;
    }

    return item;
}

/* function to perform the arithmetic operations */
int performOperation(char operator, int operand1, int operand2) {
    int result;

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
            result = operand1 / operand2;
            break;
        case '^':
            result = pow(operand1,operand2);
            break;
        default:
            result = 0;
    }

    return result;
}

/* function to check if a character is an operator or not */
int isOperator(char character) {
    if (character == '+' || character == '-' || character == '*' || character == '/' || character == '^') {
        return 1;
    }
    else {
        return 0;
    }
}

/* function to evaluate the mathematical expression */
int evaluateExpression(char expression[]) {
    struct stack operandStack;
    struct stack operatorStack;
    int operand = 0;
    int i;
    int result;

    initialize(&operandStack);
    initialize(&operatorStack);

    for (i = 0; expression[i] != '\0'; i++) {
        /* check if the character is a digit */
        if (isdigit(expression[i])) {
            operand = operand * 10 + (expression[i] - '0');
        }
        else if (expression[i] == ' ') {
            continue;
        }
        else {
            /* push the operand onto the stack */
            push(&operandStack, operand);
            operand = 0;

            /* check if the character is an operator */
            if (isOperator(expression[i])) {
                /* push the operator onto the stack */
                while (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] != '(' && operatorStack.items[operatorStack.top] != ')' && expression[i] <= operatorStack.items[operatorStack.top]) {
                    int operand2 = pop(&operandStack);
                    int operand1 = pop(&operandStack);
                    char operator = pop(&operatorStack);
                    int tempResult = performOperation(operator, operand1, operand2);
                    push(&operandStack, tempResult);
                }
                push(&operatorStack, expression[i]);
            }
            else if (expression[i] == '(') {
                push(&operatorStack, expression[i]);
            }
            else if (expression[i] == ')') {
                while (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] != '(' && operatorStack.items[operatorStack.top] != ')') {
                    int operand2 = pop(&operandStack);
                    int operand1 = pop(&operandStack);
                    char operator = pop(&operatorStack);
                    int tempResult = performOperation(operator, operand1, operand2);
                    push(&operandStack, tempResult);
                }
                pop(&operatorStack);
            }
        }
    }

    while (!isEmpty(&operatorStack)) {
        int operand2 = pop(&operandStack);
        int operand1 = pop(&operandStack);
        char operator = pop(&operatorStack);
        int tempResult = performOperation(operator, operand1, operand2);
        push(&operandStack, tempResult);
    }

    return pop(&operandStack);
}

/* main program */
int main() {
    char expression[MAX_SIZE];

    printf("Enter a mathematical expression: ");
    gets(expression);

    int result = evaluateExpression(expression);

    printf("Result: %d", result);

    return 0;
}
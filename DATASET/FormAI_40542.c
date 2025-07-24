//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_EXPRESSION_LENGTH 100

int top = -1;
double stack[MAX_EXPRESSION_LENGTH];

int isOperator(char c);
int precedence(char c);
void push(double element);
double pop();
void calculate(char *expression);

int main()
{
    char expression[MAX_EXPRESSION_LENGTH];
    printf("*** WELCOME TO MY SCIENTIFIC CALCULATOR ***\n\n");
    printf("Enter an arithmetic expression to calculate: ");

    fgets(expression, MAX_EXPRESSION_LENGTH, stdin);
    // remove new line from end of expression
    expression[strcspn(expression, "\n")] = 0;

    calculate(expression);
    printf("\n");

    return 0;
}

void calculate(char *expression)
{
    char num[MAX_EXPRESSION_LENGTH];
    int i, j;
    double operand1, operand2, result;
    for (i = 0, j = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == ' ')
            continue;
        else if (isdigit(expression[i]) || expression[i] == '.')
        {
            while (isdigit(expression[i]) || expression[i] == '.')
            {
                num[j++] = expression[i++];
            }
            num[j] = '\0';
            j = 0;
            push(atof(num));
            i--;
        }
        else if (isOperator(expression[i]))
        {
            operand2 = pop();
            operand1 = pop();
            switch (expression[i])
            {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                push(operand1 / operand2);
                break;
            case '^':
                push(pow(operand1, operand2));
                break;
            case '%':
                push(fmod(operand1, operand2));
                break;
            default:
                printf("Error: Invalid operator\n");
            }
        }
        else if (expression[i] == '(')
        {
            push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (stack[top] != '(')
            {
                operand2 = pop();
                operand1 = pop();
                char operator = (char)pop();
                switch (operator)
                {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                case '^':
                    push(pow(operand1, operand2));
                    break;
                case '%':
                    push(fmod(operand1, operand2));
                    break;
                }
            }

            // remove left parenthesis from stack
            pop();
        }
        else
        {
            printf("Error: Invalid character\n");
        }
    }

    // evaluate remaining expression in stack
    while (top != -1)
    {
        operand2 = pop();
        operand1 = pop();
        char operator = (char)pop();
        switch (operator)
        {
        case '+':
            push(operand1 + operand2);
            break;
        case '-':
            push(operand1 - operand2);
            break;
        case '*':
            push(operand1 * operand2);
            break;
        case '/':
            push(operand1 / operand2);
            break;
        case '^':
            push(pow(operand1, operand2));
            break;
        case '%':
            push(fmod(operand1, operand2));
            break;
        }
    }

    // print result
    printf("Result: %.2f\n", pop());
}

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
        return 1;
    return 0;
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    else if (c == '%')
        return 4;
    else
        return -1;
}

void push(double element)
{
    if (top == MAX_EXPRESSION_LENGTH - 1)
    {
        printf("Error: Stack is full\n");
        exit(1);
    }
    stack[++top] = element;
}

double pop()
{
    if (top == -1)
    {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    return stack[top--];
}
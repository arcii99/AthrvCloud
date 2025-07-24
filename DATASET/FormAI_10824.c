//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_EXPRESSION_LENGTH 100

void clear_output_buffer(char* output, int size);
void print_output_buffer(char* output, int size);

int main() {
    char expression[MAX_EXPRESSION_LENGTH];
    char output[MAX_EXPRESSION_LENGTH];
    
    clear_output_buffer(output, MAX_EXPRESSION_LENGTH);
    
    printf("Enter an expression: ");
    fgets(expression, MAX_EXPRESSION_LENGTH, stdin);
    
    char* token;
    char* delimiter = " \t\n";
    double operand_stack[MAX_EXPRESSION_LENGTH];
    int operand_stack_top = -1;
    
    token = strtok(expression, delimiter);
    
    while (token != NULL) {
        double value = strtod(token, NULL);
        if (value != 0.0 || token[0] == '0') {
            // Token is a number, push to operand stack
            operand_stack_top++;
            operand_stack[operand_stack_top] = value;
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            // Token is an operator, perform operation and push result to operand stack
            double operand1 = operand_stack[operand_stack_top];
            operand_stack_top--;
            double operand2 = operand_stack[operand_stack_top];
            operand_stack_top--;
            double result = 0.0;
            
            switch(token[0]) {
                case '+':
                    result = operand2 + operand1;
                    break;
                case '-':
                    result = operand2 - operand1;
                    break;
                case '*':
                    result = operand2 * operand1;
                    break;
                case '/':
                    result = operand2 / operand1;
                    break;
            }
            
            operand_stack_top++;
            operand_stack[operand_stack_top] = result;
        } else if (token[0] == '^') {
            // Token is an exponent operator, perform operation and push result to operand stack
            double base = operand_stack[operand_stack_top - 1];
            double exponent = operand_stack[operand_stack_top];
            double result = pow(base, exponent);
            
            operand_stack_top--;
            operand_stack[operand_stack_top] = result;
        } else if (strcmp(token, "sqrt") == 0) {
            // Token is a square root operator, perform operation and push result to operand stack
            double operand = operand_stack[operand_stack_top];
            double result = sqrt(operand);
            
            operand_stack[operand_stack_top] = result;
        }
        
        token = strtok(NULL, delimiter);
    }
    
    if (operand_stack_top == 0) {
        // Valid expression, print result
        sprintf(output, "%.3lf", operand_stack[operand_stack_top]);
    } else {
        // Invalid expression
        sprintf(output, "Invalid expression");
    }
    
    print_output_buffer(output, MAX_EXPRESSION_LENGTH);
    
    return 0;
}

void clear_output_buffer(char* output, int size) {
    for (int i = 0; i < size; i++) {
        output[i] = '\0';
    }
}

void print_output_buffer(char* output, int size) {
    printf("%s\n", output);
}
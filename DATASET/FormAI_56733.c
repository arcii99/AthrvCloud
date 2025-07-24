//FormAI DATASET v1.0 Category: Syntax parsing ; Style: cheerful
// Hello there! Welcome to my cheerful C syntax parsing example program!

// Let's start by including the necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// We'll now define a function to parse a simple mathematical expression
int parse_expression(char* exp) {
    // First, we'll create an array to store the individual elements of the expression
    char* elements[3];
    int i = 0;

    // We'll use strtok to split the expression into its respective elements
    char* token = strtok(exp, "+-*/");
    while (token != NULL) {
        elements[i++] = token;
        token = strtok(NULL, "+-*/");
    }

    // Next, we'll store the operator in a separate variable
    char op = exp[strlen(elements[0])];

    // We'll convert the operands to integers
    int op1 = atoi(elements[0]);
    int op2 = atoi(elements[1]);

    // Finally, we'll perform the operation based on the operator
    int result;
    switch (op) {
        case '+':
            result = op1 + op2;
            break;
        case '-':
            result = op1 - op2;
            break;
        case '*':
            result = op1 * op2;
            break;
        case '/':
            result = op1 / op2;
            break;
        default:
            printf("Invalid operator!\n");
            return -1;
    }

    // Return the result
    return result;
}

// Now, let's define the main function
int main() {
    // Here's an example expression: 25+3
    char exp[] = "25+3";

    // Let's parse the expression using our function
    int result = parse_expression(exp);

    // Print the result
    printf("Result: %d\n", result);

    // Yay! We parsed the expression successfully!

    // Let's return 0 to indicate that everything ran smoothly
    return 0;
}
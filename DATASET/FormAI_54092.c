//FormAI DATASET v1.0 Category: Calculator ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

//struct to represent a mathematical expression
typedef struct {
    char operation;     //the operation to be performed (+, -, *, /, ^)
    double operand1;    //the first operand
    double operand2;    //the second operand
} Expression;

//function to get user input for a mathematical expression
Expression getInput() {
    Expression exp;
    printf("Enter the first operand: ");
    scanf("%lf", &exp.operand1);
    printf("Enter the operation (+, -, *, /, ^): ");
    scanf(" %c", &exp.operation);
    printf("Enter the second operand: ");
    scanf("%lf", &exp.operand2);
    return exp;
}

//function to perform a mathematical operation and return the result
double performOperation(Expression exp) {
    switch (exp.operation) {
        case '+':
            return exp.operand1 + exp.operand2;
        case '-':
            return exp.operand1 - exp.operand2;
        case '*':
            return exp.operand1 * exp.operand2;
        case '/':
            if (exp.operand2 == 0) {
                printf("Error: Divide by zero\n");
                exit(1);
            }
            return exp.operand1 / exp.operand2;
        case '^':
            double result = 1;
            int i;
            for (i = 0; i < exp.operand2; i++) {
                result *= exp.operand1;
            }
            return result;
        default:
            printf("Error: Invalid operation\n");
            exit(1);
    }
}

int main() {
    printf("Welcome to the Mathematical Calculator\n");
    Expression exp = getInput();
    double result = performOperation(exp);
    printf("%.2f %c %.2f = %.2f\n", exp.operand1, exp.operation, exp.operand2, result);
    return 0;
}
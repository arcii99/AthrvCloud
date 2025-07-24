//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
bool valid_operator(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/' || op == '^';
}
 
double calculate(double num1, double num2, char op) {
    double result;
    switch(op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': result = num1 / num2; break;
        case '^': result = pow(num1, num2); break;
        default: result = 0;
    }
    return result;
}
 
int main() {
    double num1, num2, result;
    char operator;
 
    printf("Enter a mathematical equation (+, -, *, /, ^): ");
    scanf("%lf %c %lf", &num1, &operator, &num2);
 
    if(!valid_operator(operator)) {
        printf("Invalid Operator. Please enter a valid operator.\n");
        return 0;
    }
 
    result = calculate(num1, num2, operator);
 
    printf("%lf %c %lf = %lf\n", num1, operator, num2, result);
 
    return 0;
}
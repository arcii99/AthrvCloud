//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INPUT 100

int main()
{
    char input[MAX_INPUT];
    double num1, num2;
    char operator;
    
    printf("Welcome to the Scientific Calculator!\n\n");
    
    while(1) {
        printf("Please enter an expression: ");
        
        fgets(input, MAX_INPUT, stdin);
        
        if (sscanf(input, "%lf %c %lf", &num1, &operator, &num2) == 3) {
            if (operator == '+') {
                printf("%.2f\n", num1 + num2);
            } else if (operator == '-') {
                printf("%.2f\n", num1 - num2);
            } else if (operator == '*') {
                printf("%.2f\n", num1 * num2);
            } else if (operator == '/') {
                if (num2 == 0) {
                    printf("Error: division by zero\n");
                } else {
                    printf("%.2f\n", num1 / num2);
                }
            } else if (operator == '^') {
                printf("%.2f\n", pow(num1, num2));
            } else {
                printf("Error: invalid operator\n");
            }
        } else if (sscanf(input, "%lf", &num1) == 1) {
            printf("Square root: %.2f\n", sqrt(num1));
            printf("Absolute value: %.2f\n", fabs(num1));
            printf("Natural log: %.2f\n", log(num1));
            printf("Log base 10: %.2f\n", log10(num1));
            printf("Exponential: %.2f\n", exp(num1));
        } else {
            printf("Error: invalid input\n");
        }
    }
    
    return 0;
}
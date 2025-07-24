//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_EXPR_SIZE 100

float calculate(char *expr) {
    // Evaluate the passed expression and return the result
    float result = 0;
    char operator = '+';
    float num = 0;
    for(int i=0; i<strlen(expr); i++) {
        if(isdigit(expr[i])) {
            num = num*10 + (expr[i] - '0');
        }
        if(!isdigit(expr[i]) || i==strlen(expr)-1) {
            if(operator == '+') {
                result += num;
            }
            else if(operator == '-') {
                result -= num;
            }
            else if(operator == '*') {
                result *= num;
            }
            else if(operator == '/') {
                result /= num;
            }
            operator = expr[i];
            num = 0;
        }
    }
    return result;
}

int main() {
    printf("Welcome to the Cyberpunk Scientific Calculator!");

    char expr[MAX_EXPR_SIZE];
    printf("\nEnter the expression you want to evaluate: ");
    fgets(expr, MAX_EXPR_SIZE, stdin);

    float result = calculate(expr);
    printf("\nThe result is: %f", result);

    printf("\nThank you for using the Cyberpunk Scientific Calculator!");
    return 0;
}
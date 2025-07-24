//FormAI DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given string is a valid mathematical expression
int isValidExpr(char* str) {
    int len = strlen(str);
    int i, j;
    int count = 0;

    // Loop through each character in the string
    for(i = 0; i < len; i++) {
        // If there are any invalid characters
        if(!(isdigit(str[i]) || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')')) {
            return 0;
        } 

        // Check if parentheses are balanced
        if(str[i] == '(') {
            count++;
        } else if(str[i] == ')') {
            count--;
            if(count < 0) {
                return 0;
            }
        }

        // Check if there are any consecutive signs
        if((i != 0) && (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')) {
            if(str[i-1] == '+' || str[i-1] == '-' || str[i-1] == '*' || str[i-1] == '/') {
                return 0;
            }
        }
    }

    if(count != 0) {
        return 0;
    }

    return 1;
}

// Function to evaluate a given mathematical expression
double evaluate(char* str) {
    char* ptr;
    double res = 0.0;
    double num;
    char op;

    // Loop through each character in the string
    while(*str != '\0') {
        // If the character is a number
        if(isdigit(*str)) {
            num = strtod(str, &ptr);
            str = ptr;
            if(op == '+') {
                res += num;
            } else if (op == '-') {
                res -= num;
            } else if (op == '*') {
                res *= num;
            } else if (op == '/') {
                res /= num;
            } else {
                res = num;
            }
        } else {
            op = *str;
            str++;
        }
    }

    return res;
}

int main() {
    char expr[100];

    printf("Enter a mathematical expression: ");
    scanf("%s", expr);

    if(isValidExpr(expr)) {
        printf("Result: %f\n", evaluate(expr));
    } else {
        printf("Invalid expression!\n");
    }

    return 0;
}
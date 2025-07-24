//FormAI DATASET v1.0 Category: Calculator ; Style: satisfied
/*
 * A Simple Calculator Program
 * Written By: [Your Name]
 * Created On: [Date]
 * Updated On: [Date]
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float num1, num2, result;
    char op;
    
    printf("Enter a simple math problem (+, -, *, /): ");
    scanf("%f %c %f", &num1, &op, &num2);
    
    switch(op) {
        case '+':
            result = num1 + num2;
            printf("The sum of %.2f and %.2f is: %.2f", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("The difference between %.2f and %.2f is: %.2f", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("The product of %.2f and %.2f is: %.2f", num1, num2, result);
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero!");
                exit(0);
            } else {
                result = num1 / num2;
                printf("The quotient of %.2f and %.2f is: %.2f", num1, num2, result);
            }
            break;
        default:
            printf("Invalid Operator Entered!");
            exit(0);
    }
    
    return 0;
}
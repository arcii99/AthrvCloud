//FormAI DATASET v1.0 Category: Calculator ; Style: lively
#include <stdio.h>

int main() {
    printf("Hello and welcome to the lively C Calculator!\n");
    printf("What would you like to do?\n\n");
    
    char operator;
    double num1, num2;
    
    while (1) {
        printf("Enter an operator (+, -, *, /) or Q to quit: ");
        scanf("%c", &operator);
        
        if (operator == 'q' || operator == 'Q') {
            printf("Thank you for using the C Calculator!\n");
            break;
        } else if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
            printf("Enter two numbers:\n");
            scanf("%lf %lf", &num1, &num2);
            
            switch(operator) {
                case '+':
                    printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
                    break;
                case '-':
                    printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
                    break;
                case '*':
                    printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
                    break;
                case '/':
                    if (num2 == 0) {
                        printf("Error: Cannot divide by zero!\n");
                    } else {
                        printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
                    }
                    break;
            }
        } else {
            printf("Error: Invalid Operator!\n");
        }
        
        // Clear input buffer for next iteration
        while ((operator = getchar()) != '\n' && operator != EOF) {}
    }
    
    return 0;
}
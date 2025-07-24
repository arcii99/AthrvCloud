//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

int main() {
    char operator;
    double num1, num2, result;

    printf("Enter an operator (+, -, *, /, ^, %%): ");
    scanf("%c", &operator);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    switch(operator) {
        case '+':
            result = num1 + num2;
            break;

        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            if(num2 == 0) {
                printf("Error: Cannot divide by zero");
                return 0;
            }
            result = num1 / num2;
            break;

        case '^':
            result = pow(num1, num2);
            break;
        
        case '%':
            result = fmod(num1, num2);
            break;

        default:
            printf("Error: Invalid Operation");
            return 0;
    }

    printf("%.14lf %c %.14lf = %.14lf", num1, operator, num2, result);
    return 0;
}
//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: light-weight
#include <stdio.h>
#include <math.h>

int main() { 

    double firstNum, secondNum, result=0; 
    char operation;

    printf("Welcome to the C Scientific Calculator!\n");
    printf("----------------------------------------\n\n");

    printf("Enter your first number: ");
    scanf("%lf", &firstNum);

    printf("Enter the operation you want to perform (+, -, *, /, ^, s): ");
    scanf(" %c", &operation);

    if (operation == 's' || operation == 'S') {
        result = sin(firstNum);
        printf("\nResult: %lf\n", result);
    } else {
        printf("Enter your second number: ");
        scanf("%lf", &secondNum);

        switch (operation) {
            case '+':
                result = firstNum + secondNum;
                break;
            case '-':
                result = firstNum - secondNum;
                break;
            case '*':
                result = firstNum * secondNum;
                break;
            case '/':
                result = firstNum / secondNum;
                break;
            case '^':
                result = pow(firstNum, secondNum);
                break;
            default:
                printf("Invalid operator.\n");
                break;
        }

        if (result != 0) {
            printf("\nResult: %lf\n", result); 
        }
    }

    return 0; 
}
//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: realistic
#include <stdio.h>
#include <math.h>

int main() {
    double num1, num2, result;
    char operator;

    printf("Welcome to my scientific calculator!\n");
    printf("Please enter first number: ");
    scanf("%lf", &num1);

    printf("Please enter operator (+, -, *, /, sin, cos, tan, sqrt, ^): ");
    scanf(" %c", &operator);

    switch(operator) {
        case '+':
            printf("Please enter second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            break;

        case '-':
            printf("Please enter second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            break;

        case '*':
            printf("Please enter second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            break;

        case '/':
            printf("Please enter second number: ");
            scanf("%lf", &num2);
            if(num2 == 0){
                printf("Error: cannot divide by zero\n");
                return 0;
            }
            result = num1 / num2;
            break;

        case 's':
        case 'S':
            result = sin(num1);
            break;

        case 'c':
        case 'C':
            result = cos(num1);
            break;

        case 't':
        case 'T':
            result = tan(num1);
            break;

        case 'q':
        case 'Q':
            if(num1 < 0){
                printf("Error: cannot take square root of negative number\n");
                return 0;
            }
            result = sqrt(num1);
            break;

        case '^':
            printf("Please enter second number: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            break;

        default:
            printf("Invalid operator entered\n");
            return 0;
    }

    printf("The result is: %lf", result);

    return 0;
}
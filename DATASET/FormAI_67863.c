//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    double num1, num2, result;
    char operator;

    printf("\n Welcome to the Scientific Calculator \n");
    printf("=====================================\n");

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the operator (+, -, *, /, ^, s): ");
    scanf(" %c", &operator);

    // Checking for square root operator
    if (operator == 's')
    {
        result = sqrt(num1);
        printf("The square root of %.2lf is %.2lf", num1, result);
        exit(0);
    }

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    // Performing the calculation based on the operator
    switch(operator)
    {
        case '+': result = num1 + num2;
                  break;

        case '-': result = num1 - num2;
                  break;

        case '*': result = num1 * num2;
                  break;

        case '/': result = num1 / num2;
                  break;

        case '^': result = pow(num1, num2);
                  break;

        default: printf("Invalid operator selected");
                 exit(0);
    }

    printf("%.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);

    return 0;
}
//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: rigorous
// C Scientific Calculator Implementation

#include<stdio.h>
#include<math.h>

int main()
{
    int choice;
    double num1, num2, result;
    printf("Welcome to C Scientific Calculator\n");

    while(1)
    {
        printf("Enter the operation you want to perform:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square Root\n7. Logarithm\n8. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 + num2;
                printf("Result: %lf\n\n", result);
                break;

            case 2:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 - num2;
                printf("Result: %lf\n\n", result);
                break;

            case 3:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 * num2;
                printf("Result: %lf\n\n", result);
                break;

            case 4:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                if(num2 == 0)
                {
                    printf("Error! Division by zero.\n\n");
                    break;
                }
                result = num1 / num2;
                printf("Result: %lf\n\n", result);
                break;

            case 5:
                printf("Enter a base number: ");
                scanf("%lf", &num1);
                printf("Enter an exponent number: ");
                scanf("%lf", &num2);
                result = pow(num1, num2);
                printf("Result: %lf\n\n", result);
                break;

            case 6:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = sqrt(num1);
                printf("Result: %lf\n\n", result);
                break;

            case 7:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = log(num1);
                printf("Result: %lf\n\n", result);
                break;

            case 8:
                printf("Thank you for using C Scientific Calculator\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }
    return 0;
}
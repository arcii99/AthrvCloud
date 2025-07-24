//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: rigorous
#include <stdio.h>
#include <math.h>

int main()
{
    int choice;
    float num1, num2, result;

    printf("Scientific Calculator\n----------------------------\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square root\n6. Exponential\n7. Logarithm\n8. Power\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter two numbers: ");
            scanf("%f%f", &num1, &num2);
            result = num1 + num2;
            printf("Result: %.2f", result);
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%f%f", &num1, &num2);
            result = num1 - num2;
            printf("Result: %.2f", result);
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%f%f", &num1, &num2);
            result = num1 * num2;
            printf("Result: %.2f", result);
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%f%f", &num1, &num2);
            if(num2 == 0)
            {
                printf("Error: Division by zero.");
            }
            else
            {
                result = num1 / num2;
                printf("Result: %.2f", result);
            }
            break;

        case 5:
            printf("Enter a number: ");
            scanf("%f", &num1);
            if(num1 < 0)
            {
                printf("Error: Square root of negative number.");
            }
            else
            {
                result = sqrt(num1);
                printf("Result: %.2f", result);
            }
            break;

        case 6:
            printf("Enter a number: ");
            scanf("%f", &num1);
            result = exp(num1);
            printf("Result: %.2f", result);
            break;

        case 7:
            printf("Enter a number: ");
            scanf("%f", &num1);
            if(num1 <= 0)
            {
                printf("Error: Logarithm of non-positive number.");
            }
            else
            {
                result = log(num1);
                printf("Result: %.2f", result);
            }
            break;

        case 8:
            printf("Enter two numbers: ");
            scanf("%f%f", &num1, &num2);
            result = pow(num1, num2);
            printf("Result: %.2f", result);
            break;

        default:
            printf("Error: Invalid choice.");
            break;
    }
    return 0;
}
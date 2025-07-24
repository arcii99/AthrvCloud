//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

int main()
{
    int choice;
    float num1, num2, result;

    printf("Select an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square Root\n6. Power\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 + num2;
            printf("Result: %.2f", result);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 - num2;
            printf("Result: %.2f", result);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 * num2;
            printf("Result: %.2f", result);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 / num2;
            printf("Result: %.2f", result);
            break;
        case 5:
            printf("Enter a number: ");
            scanf("%f", &num1);
            result = sqrt(num1);
            printf("Result: %.2f", result);
            break;
        case 6:
            printf("Enter base: ");
            scanf("%f", &num1);
            printf("Enter exponent: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("Result: %.2f", result);
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}
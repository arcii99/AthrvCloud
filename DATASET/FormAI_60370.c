//FormAI DATASET v1.0 Category: Math exercise ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num1, num2, option;
    float result;

    printf("Welcome to the Mathematical Operations Program!\n\n");

    printf("Please enter your first number: ");
    scanf("%d", &num1);

    printf("Please enter your second number: ");
    scanf("%d", &num2);

    printf("\nPlease choose from the following options:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Raise to power\n");
    printf("6. Square root\n");
    printf("Option: ");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            result = num1 + num2;
            printf("\n%d + %d = %.2f\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("\n%d - %d = %.2f\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("\n%d * %d = %.2f\n", num1, num2, result);
            break;
        case 4:
            if(num2 == 0)
            {
                printf("\nError: division by zero\n");
            }
            else
            {
                result = (float)num1 / num2;
                printf("\n%d / %d = %.2f\n", num1, num2, result);
            }
            break;
        case 5:
            result = pow(num1, num2);
            printf("\n%d raised to power of %d = %.2f\n", num1, num2, result);
            break;
        case 6:
            result = sqrt(num1);
            printf("\nSquare root of %d = %.2f\n", num1, result);
            break;
        default:
            printf("\nInvalid option selected\n");
            break;
    }

    printf("\nThank you for using the Mathematical Operations Program!\n");

    return 0;
}
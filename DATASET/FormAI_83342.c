//FormAI DATASET v1.0 Category: Arithmetic ; Style: immersive
#include <stdio.h>

int main()
{
    int num1, num2, result;

    printf("Welcome to the Immersive Arithmetic Calculator!\n");
    printf("Please enter the first number: ");
    scanf("%d", &num1);
    printf("Please enter the second number: ");
    scanf("%d", &num2);

    printf("\nPerforming Arithmetic Operations...\n\n");

    // Addition
    printf("%d + %d = %d\n", num1, num2, (num1 + num2));

    // Subtraction
    printf("%d - %d = %d\n", num1, num2, (num1 - num2));

    // Multiplication
    printf("%d * %d = %d\n", num1, num2, (num1 * num2));

    // Division
    if (num2 == 0)
    {
        printf("Cannot divide by 0.\n");
    }
    else
    {
        printf("%d / %d = %.2f\n", num1, num2, ((float)num1 / num2));
    }

    // Modulus
    printf("%d %% %d = %d\n", num1, num2, (num1 % num2));

    // Increment
    printf("++%d = %d\n", num1, (++num1));

    // Decrement
    printf("--%d = %d\n", num2, (--num2));

    printf("\nThank you for using the Immersive Arithmetic Calculator!\n");

    return 0;
}
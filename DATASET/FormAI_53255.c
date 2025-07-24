//FormAI DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Happy Error Handling program!\n");

    // Declare variables
    int a, b, result;

    // Read in two numbers
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Enter another number: ");
    scanf("%d", &b);

    // Perform the calculation and handle any errors
    if (b == 0)
    {
        printf("Oops! You can't divide by zero!\n");

        // Let's make the user happy and suggest a different input
        printf("Please enter a different number for 'b': ");
        scanf("%d", &b);
        while (b == 0)
        {
            printf("Sorry, that's still zero. Please try again: ");
            scanf("%d", &b);
        }

        // Calculate the result with the new input
        result = a / b;
        printf("The result of the calculation is: %d\n", result);
    }
    else
    {
        result = a / b;
        printf("The result of the calculation is: %d\n", result);
    }

    printf("Thank you for using the Happy Error Handling program! Have a nice day!\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Error handling ; Style: curious
#include<stdio.h>

int division(int dividend, int divisor)
{
    if(divisor == 0)
        // Oh boy! Trying to divide by zero? Let me handle this.
        // Here's the error message for your problem. Feel free to thank me later.
        printf("\nError! Division by zero is impossible.\n");
    else
        // Good job! You didn't try to divide by zero. Let's give you the result.
        return (dividend / divisor);
}

int main()
{
    int dividend, divisor;
    printf("Enter dividend: ");
    scanf("%d", &dividend);
    printf("Enter divisor: ");
    scanf("%d", &divisor);

    // This function will handle the division for you. Just sit back and relax.
    int result = division(dividend, divisor);

    // Let's display the result if there's no error.
    if(result != 0)
        printf("\nResult: %d\n", result);

    // If the program reaches this point, it means an error occurred.
    return 0;
}
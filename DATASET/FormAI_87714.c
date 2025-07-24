//FormAI DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


void divideIntegers(int dividend, int divisor)
{
    if (divisor == 0)
    {
        errno = EINVAL;
        printf("Division by zero is not allowed.\n");
        return;
    }

    int quotient = dividend / divisor;
    printf("Quotient = %d\n", quotient);
}



int main()
{
    int dividend, divisor;

    printf("Enter dividend: ");
    scanf("%d", &dividend);

    printf("Enter divisor: ");
    scanf("%d", &divisor);

    // Calling function to divide integers
    divideIntegers(dividend, divisor);

    // Checking if an error occurred during division
    if (errno)
    {
        perror("Error ");
        exit(EXIT_FAILURE);
    }

    return 0;
}
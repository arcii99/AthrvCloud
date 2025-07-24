//FormAI DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dividend = 15;
    int divisor = 0;
    int quotient;

    if(divisor == 0)
    {
        printf("Error: Division by zero is not possible\n");
        exit(1);
    }

    quotient = dividend / divisor;
    printf("Quotient = %d", quotient);

    return 0;
}
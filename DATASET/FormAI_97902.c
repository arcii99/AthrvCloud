//FormAI DATASET v1.0 Category: Error handling ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dividend, divisor, quotient;
    
    printf("Enter the dividend: ");
    scanf("%d", &dividend);
    
    printf("Enter the divisor: ");
    scanf("%d", &divisor);
    
    if (divisor == 0) // Check for division by zero error
    {
        printf("Error: Division by zero.\n");
        exit(0);
    }
    
    quotient = dividend / divisor;
    
    printf("Quotient = %d\n", quotient);
    
    return 0;
}
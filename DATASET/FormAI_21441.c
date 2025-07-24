//FormAI DATASET v1.0 Category: Binary Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// This is a binary to decimal converter

int main()
{
    int binary, decimal = 0, base = 1, remainder;
    printf("Enter a binary number: ");
    scanf("%d", &binary);
    while (binary > 0)
    {
        remainder = binary % 10;
        decimal += remainder * base;
        binary /= 10;
        base *= 2;
    }
    printf("Decimal equivalent is: %d\n", decimal);
    return 0;
}
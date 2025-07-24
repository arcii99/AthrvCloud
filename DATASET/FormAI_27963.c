//FormAI DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main()
{
    int num, binary = 0, decimal, rem, count = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    num = decimal;
    
    // Count number of digits in decimal number
    while (num != 0)
    {
        num = num / 2;
        count++;
    }

    num = decimal;

    // Convert decimal number to binary
    while (num != 0)
    {
        rem = num % 2;
        binary = binary + rem * pow(10, count - 1);
        num = num / 2;
        count--;
    }

    printf("Binary representation of %d is %d", decimal, binary);
    return 0;
}
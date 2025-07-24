//FormAI DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>

long decimalToBinary(long decimal)
{
    int remainder;
    long binary = 0, i = 1;

    while(decimal != 0)
    {
        remainder = decimal % 2;
        decimal /= 2;
        binary += remainder * i;
        i *= 10;
    }

    return binary;
}

int main()
{
    long decimal;
    
    printf("Enter a decimal number: ");
    scanf("%ld", &decimal);

    printf("Binary number of entered decimal number is: %ld", decimalToBinary(decimal));

    return 0;
}
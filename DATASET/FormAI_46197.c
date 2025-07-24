//FormAI DATASET v1.0 Category: Binary Converter ; Style: scientific
#include <stdio.h>

void convertBinaryToDecimal(long long num);

int main()
{
    long long num;

    printf("Enter a binary number: ");
    scanf("%lld", &num);

    convertBinaryToDecimal(num);

    return 0;
}

void convertBinaryToDecimal(long long num)
{
    int decimal = 0, i = 0, remainder;

    while (num != 0)
    {
        remainder = num % 10;
        num /= 10;
        decimal += remainder * (1 << i);
        ++i;
    }

    printf("Decimal equivalent is: %d", decimal);
}
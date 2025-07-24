//FormAI DATASET v1.0 Category: Binary Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void convertDecimalToBinary(int decimalNumber);

int main()
{
    int decimalNumber;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    convertDecimalToBinary(decimalNumber);

    return 0;
}

void convertDecimalToBinary(int decimalNumber)
{
    int binaryNumber[32];
    int index = 0;

    // Convert decimal to binary
    while (decimalNumber > 0)
    {
        binaryNumber[index] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        index++;
    }

    // Print binary number in reverse order
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%d", binaryNumber[i]);
    }
}
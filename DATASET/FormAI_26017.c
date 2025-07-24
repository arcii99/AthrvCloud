//FormAI DATASET v1.0 Category: Binary Converter ; Style: unmistakable
#include <stdio.h>

int convertToDecimal(int binaryNumber);
long convertToBinary(int decimalNumber);

int main()
{
    int binaryNumber, decimalNumber;
    printf("Enter a binary number: ");
    scanf("%d", &binaryNumber);
    printf("Decimal number of %d is: %d\n", binaryNumber, convertToDecimal(binaryNumber));

    printf("Enter a decimal number: ");
    scanf("%ld", &decimalNumber);
    printf("Binary number of %ld is: %ld", decimalNumber, convertToBinary(decimalNumber));
    return 0;
}

int convertToDecimal(int binaryNumber)
{
    int decimalNumber = 0, i = 0, remainder;
    while (binaryNumber != 0)
    {
        remainder = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += remainder * pow(2, i);
        i++;
    }
    return decimalNumber;
}

long convertToBinary(int decimalNumber)
{
    long binaryNumber = 0;
    int remainder, i = 1;
    while (decimalNumber != 0)
    {
        remainder = decimalNumber % 2;
        decimalNumber /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}
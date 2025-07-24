//FormAI DATASET v1.0 Category: Binary Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert binary to decimal
int binaryToDecimal(int binaryNum)
{
    int decimalNum = 0, i = 0, rem;
    while (binaryNum != 0)
    {
        rem = binaryNum % 10;
        binaryNum /= 10;
        decimalNum += rem * pow(2, i);
        ++i;
    }
    return decimalNum;
}

// Function to convert decimal to binary
void decimalToBinary(int decimalNum)
{
    int binaryNum[32], i = 0;
    while (decimalNum > 0)
    {
        binaryNum[i] = decimalNum % 2;
        decimalNum /= 2;
        ++i;
    }
    for (int j = i - 1; j >= 0; --j)
    {
        printf("%d", binaryNum[j]);
    }
}

int main()
{
    int binaryNum, decimalNum;
    printf("Enter a binary number: ");
    scanf("%d", &binaryNum);
    decimalNum = binaryToDecimal(binaryNum);
    printf("Decimal number is: %d\n", decimalNum);
    printf("Binary number is: ");
    decimalToBinary(decimalNum);
    printf("\n");
    return 0;
}
//FormAI DATASET v1.0 Category: Binary Converter ; Style: ephemeral
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int decimalNumber)
{
    int binaryNumber[100], index = 0;

    while(decimalNumber > 0)
    {
        binaryNumber[index] = decimalNumber % 2;
        decimalNumber /= 2;
        index++;
    }

    printf("Binary Number: ");

    for(int i = index - 1; i >= 0; i--)
    {
        printf("%d", binaryNumber[i]);
    }

    printf("\n");
}

int main()
{
    int decimalNumber;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    decimalToBinary(decimalNumber);

    return 0;
}
//FormAI DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINARY_LENGTH 8

int main()
{
    int decimalNumber;
    char binaryNumber[MAX_BINARY_LENGTH+1] = ""; // Extra space for NULL character

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    if (decimalNumber < 0)
    {
        printf("Error: negative numbers cannot be converted to binary\n");
        return 0;
    }

    int quotient = decimalNumber, remainder, index = MAX_BINARY_LENGTH;

    while (quotient != 0 && index >= 0)
    {
        remainder = quotient % 2;
        quotient /= 2;

        binaryNumber[index] = remainder + '0'; // Convert int to char
        index--;
    }

    if (index < 0 && quotient != 0)
    {
        printf("Error: binary number is too large to fit in %d bits\n", MAX_BINARY_LENGTH);
        return 0;
    }

    printf("Binary conversion of %d is: %s", decimalNumber, binaryNumber+index+1);

    return 0;
}
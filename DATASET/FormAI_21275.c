//FormAI DATASET v1.0 Category: Binary Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int decimalNum, binaryNum = 0, remainder, place = 1;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);

    while (decimalNum > 0)
    {
        remainder = decimalNum % 2;
        binaryNum = binaryNum + remainder * place;
        decimalNum /= 2;
        place *= 10;
    }

    printf("The binary equivalent of the number is: %u", binaryNum);

    return 0;
}
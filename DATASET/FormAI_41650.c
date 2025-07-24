//FormAI DATASET v1.0 Category: Binary Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int decimal, binaryNumber = 0, remainder, remainder_container;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    if(decimal == 0)
    {
        printf("The binary equivalent of 0 is 0");
        exit(0);
    }

    if(decimal < 0)
    {
        printf("Invalid input. Please enter a positive integer.");
        exit(0);
    }

    while(decimal != 0)
    {
        remainder = decimal % 2;
        binaryNumber += remainder * 10;
        decimal /= 2;
    }

    binaryNumber /= 10;
    remainder_container = binaryNumber;

    printf("The binary equivalent of %d is ", remainder_container);

    while(remainder_container != 0)
    {
        remainder = remainder_container % 10;
        remainder_container /= 10;

        if(remainder == 0)
            printf("1");
        else
            printf("0");
    }

    return 0;
}
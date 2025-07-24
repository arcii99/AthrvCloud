//FormAI DATASET v1.0 Category: Bitwise operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of a number
void printBinary(unsigned int num)
{
    if (num > 1)
        printBinary(num / 2);

    printf("%u", num % 2);
}

int main()
{
    unsigned int x = 73;
    unsigned int y = 101;

    printf("X: ");
    printBinary(x);
    printf("\nY: ");
    printBinary(y);

    // Bitwise AND
    unsigned int resultAnd = x & y;
    printf("\n\nX & Y: ");
    printBinary(resultAnd);

    // Bitwise OR
    unsigned int resultOr = x | y;
    printf("\n\nX | Y: ");
    printBinary(resultOr);

    // Bitwise XOR
    unsigned int resultXor = x ^ y;
    printf("\n\nX ^ Y: ");
    printBinary(resultXor);

    // Bitwise NOT
    unsigned int resultNot = ~x;
    printf("\n\n~X: ");
    printBinary(resultNot);

    // Left Shift
    unsigned int resultLeftShift = x << 2;
    printf("\n\nX << 2: ");
    printBinary(resultLeftShift);

    // Right Shift
    unsigned int resultRightShift = y >> 2;
    printf("\n\nY >> 2: ");
    printBinary(resultRightShift);

    return 0;
}
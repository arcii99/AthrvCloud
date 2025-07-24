//FormAI DATASET v1.0 Category: Bitwise operations ; Style: high level of detail
#include <stdio.h>

// function to print a binary number
void printBinary(unsigned int num)
{
    if(num > 1)
        printBinary(num/2);

    printf("%d", num%2);
}

int main() {
    unsigned int a = 127;
    unsigned int b = 255;

    // bitwise AND
    unsigned int resultAnd = a & b;

    printf("Binary of %d: ", a);
    printBinary(a);
    printf("\n");

    printf("Binary of %d: ", b);
    printBinary(b);
    printf("\n");

    printf("Binary of a & b: ");
    printBinary(resultAnd);
    printf("\n");
    printf("\n");

    // bitwise OR
    unsigned int resultOr = a | b;

    printf("Binary of a | b: ");
    printBinary(resultOr);
    printf("\n");
    printf("\n");

    // bitwise XOR
    unsigned int resultXor = a ^ b;

    printf("Binary of a ^ b: ");
    printBinary(resultXor);
    printf("\n");
    printf("\n");

    // bitwise left shift
    unsigned int resultLeft = a << 3;

    printf("Binary of a << 3: ");
    printBinary(resultLeft);
    printf("\n");
    printf("\n");

    // bitwise right shift
    unsigned int resultRight = b >> 4;

    printf("Binary of b >> 4: ");
    printBinary(resultRight);
    printf("\n");

    return 0;
}
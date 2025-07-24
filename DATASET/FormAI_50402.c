//FormAI DATASET v1.0 Category: Bitwise operations ; Style: unmistakable
#include <stdio.h>

// Function to print binary of a number
void printBinary(unsigned int num)
{
    if (num > 1)
        printBinary(num / 2);

    printf("%d", num % 2);
}

int main()
{
    unsigned int a = 60; // 60 in binary: 0011 1100
    unsigned int b = 13; // 13 in binary: 0000 1101
    unsigned int c, d;

    // Bitwise AND of a and b
    c = a & b; // 12 in binary: 0000 1100
    printf("a & b = %d (binary: ", c);
    printBinary(c);
    printf(")\n");

    // Bitwise OR of a and b
    c = a | b; // 61 in binary: 0011 1101
    printf("a | b = %d (binary: ", c);
    printBinary(c);
    printf(")\n");

    // Bitwise XOR of a and b
    c = a ^ b; // 49 in binary: 0011 0001
    printf("a ^ b = %d (binary: ", c);
    printBinary(c);
    printf(")\n");

    // Bitwise NOT of a
    c = ~a; // -61 in binary (assuming 2's complement): 1100 0011
    printf("~a = %d (binary: ", c);
    printBinary(c);
    printf(")\n");

    // Bitwise left shift of a
    d = a << 2; // 240 in binary: 1111 0000
    printf("a << 2 = %d (binary: ", d);
    printBinary(d);
    printf(")\n");

    // Bitwise right shift of a
    d = a >> 2; // 15 in binary: 0000 1111
    printf("a >> 2 = %d (binary: ", d);
    printBinary(d);
    printf(")\n");

    return 0;
}
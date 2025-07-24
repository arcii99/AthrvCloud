//FormAI DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>

// Function to print bits of an unsigned integer
void printBits(unsigned int num) {
    int bit;
    for (bit = 31; bit >= 0; bit--) {
        printf("%d", (num >> bit) & 1);
    }
    printf("\n");
}

int main() {
    unsigned int a = 42;        // 00101010 in binary
    unsigned int b = 27;        // 00011011 in binary
    unsigned int result = 0;

    // Bitwise AND
    result = a & b;
    printf("a & b: ");
    printBits(result);

    // Bitwise OR
    result = a | b;
    printf("a | b: ");
    printBits(result);

    // Bitwise XOR
    result = a ^ b;
    printf("a ^ b: ");
    printBits(result);

    // Bitwise NOT
    result = ~a;
    printf("~a: ");
    printBits(result);

    // Bitwise left shift
    result = a << 1;
    printf("a << 1: ");
    printBits(result);

    // Bitwise right shift
    result = a >> 1;
    printf("a >> 1: ");
    printBits(result);

    return 0;
}
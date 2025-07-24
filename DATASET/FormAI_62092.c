//FormAI DATASET v1.0 Category: Bitwise operations ; Style: unmistakable
#include <stdio.h>

// define binary constants
#define BINARY_0000 0b0000
#define BINARY_0001 0b0001
#define BINARY_0010 0b0010
#define BINARY_0011 0b0011
#define BINARY_0100 0b0100
#define BINARY_0101 0b0101
#define BINARY_0110 0b0110
#define BINARY_0111 0b0111
#define BINARY_1000 0b1000
#define BINARY_1001 0b1001
#define BINARY_1010 0b1010
#define BINARY_1011 0b1011
#define BINARY_1100 0b1100
#define BINARY_1101 0b1101
#define BINARY_1110 0b1110
#define BINARY_1111 0b1111

int main() {
    // Demonstrate bitwise AND operator
    unsigned int a = BINARY_0110;
    unsigned int b = BINARY_1010;
    unsigned int c;

    c = a & b;

    printf("a AND b = %d (binary %04d)\n", c, c);

    // Demonstrate bitwise OR operator
    a = BINARY_0001;
    b = BINARY_0100;

    c = a | b;

    printf("a OR b = %d (binary %04d)\n", c, c);

    // Demonstrate bitwise XOR operator
    a = BINARY_1101;
    b = BINARY_0011;

    c = a ^ b;

    printf("a XOR b = %d (binary %04d)\n", c, c);

    // Demonstrate bitwise NOT operator
    a = BINARY_1010;

    c = ~a;

    printf("NOT a = %d (binary %04d)\n", c, c);

    // Demonstrate bitwise left shift operator
    a = BINARY_1000;

    c = a << 2;

    printf("a shifted left by 2 bits = %d (binary %04d)\n", c, c);

    // Demonstrate bitwise right shift operator
    a = BINARY_1011;

    c = a >> 3;

    printf("a shifted right by 3 bits = %d (binary %04d)\n", c, c);

    return 0;
}
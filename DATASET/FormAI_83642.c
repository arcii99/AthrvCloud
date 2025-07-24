//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include <stdio.h>

// Define binary operators using bitwise operations
#define AND(x, y) ((x) & (y))
#define OR(x, y) ((x) | (y))
#define XOR(x, y) ((x) ^ (y))
#define NOT(x) (~(x))
#define LEFT_SHIFT(x, n) ((x) << (n))
#define RIGHT_SHIFT(x, n) ((x) >> (n))

int main() {
    // Declare variables
    int a = 15;  // 1111 in binary
    int b = 10;  // 1010 in binary
    int c;

    // Perform bitwise operations and print results
    printf("a = 0x%X, b = 0x%X\n", a, b);
    c = AND(a, b);
    printf("a & b = 0x%X\n", c);
    c = OR(a, b);
    printf("a | b = 0x%X\n", c);
    c = XOR(a, b);
    printf("a ^ b = 0x%X\n", c);
    c = NOT(a);
    printf("~a = 0x%X\n", c);
    c = LEFT_SHIFT(a, 2);
    printf("a << 2 = 0x%X\n", c);
    c = RIGHT_SHIFT(b, 1);
    printf("b >> 1 = 0x%X\n", c);

    // Test edge cases
    printf("\nTesting edge cases...\n");
    a = 0;  // 0000 in binary
    b = ~a;  // 1111 in binary
    printf("a = 0x%X, b = 0x%X\n", a, b);
    c = AND(a, b);
    printf("a & b = 0x%X\n", c);
    c = OR(a, b);
    printf("a | b = 0x%X\n", c);
    c = XOR(a, b);
    printf("a ^ b = 0x%X\n", c);
    c = NOT(a);
    printf("~a = 0x%X\n", c);
    c = LEFT_SHIFT(a, 2);
    printf("a << 2 = 0x%X\n", c);
    c = RIGHT_SHIFT(b, 1);
    printf("b >> 1 = 0x%X\n", c);

    return 0;
}
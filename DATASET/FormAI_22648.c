//FormAI DATASET v1.0 Category: Bitwise operations ; Style: random
#include <stdio.h>

int main() {
    unsigned int a = 10;
    unsigned int b = 15;

    printf("Initial Values:\n");
    printf("a = %u\n", a);
    printf("b = %u\n", b);

    // Bitwise AND operation
    printf("\nBitwise AND operation:\n");
    unsigned int c = a & b;
    printf("%u & %u = %u\n", a, b, c);

    // Bitwise OR operation
    printf("\nBitwise OR operation:\n");
    c = a | b;
    printf("%u | %u = %u\n", a, b, c);

    // Bitwise XOR operation
    printf("\nBitwise XOR operation:\n");
    c = a ^ b;
    printf("%u ^ %u = %u\n", a, b, c);

    // Bitwise NOT operation
    printf("\nBitwise NOT operation:\n");
    c = ~a;
    printf("~%u = %u\n", a, c);

    // Bitwise left shift operation
    printf("\nBitwise left shift operation:\n");
    c = a << 2;
    printf("%u << 2 = %u\n", a, c);

    // Bitwise right shift operation
    printf("\nBitwise right shift operation:\n");
    c = b >> 2;
    printf("%u >> 2 = %u\n", b, c);

    return 0;
}
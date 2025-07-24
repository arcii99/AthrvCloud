//FormAI DATASET v1.0 Category: Bitwise operations ; Style: minimalist
#include<stdio.h>

int main() {
    int a = 10, b = 5, c = 0;
    printf("Initial values:\n");
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    // Bitwise AND operator
    c = a & b;
    printf("\nBitwise AND operator:\n");
    printf("a & b = %d\n", c);

    // Bitwise OR operator
    c = a | b;
    printf("\nBitwise OR operator:\n");
    printf("a | b = %d\n", c);

    // Bitwise XOR operator
    c = a ^ b;
    printf("\nBitwise XOR operator:\n");
    printf("a ^ b = %d\n", c);

    // Bitwise LEFT SHIFT operator
    c = a << 1;
    printf("\nBitwise LEFT SHIFT operator:\n");
    printf("a << 1 = %d\n", c);

    // Bitwise RIGHT SHIFT operator
    c = a >> 1;
    printf("\nBitwise RIGHT SHIFT operator:\n");
    printf("a >> 1 = %d\n", c);

    // Bitwise NOT operator
    c = ~a;
    printf("\nBitwise NOT operator:\n");
    printf("~a = %d\n", c);

    return 0;
}
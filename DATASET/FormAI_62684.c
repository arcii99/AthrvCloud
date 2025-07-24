//FormAI DATASET v1.0 Category: Bitwise operations ; Style: grateful
#include <stdio.h>

int main() {
    unsigned int a = 60; // 0011 1100 
    unsigned int b = 13; // 0000 1101 
    int result;

    // Bitwise AND operator
    result = a & b;    // 0000 1100
    printf("a & b = %d\n", result );

    // Bitwise OR operator
    result = a | b;    // 0011 1101 
    printf("a | b = %d\n", result );

    // Bitwise XOR operator
    result = a ^ b;    // 0011 0001
    printf("a ^ b = %d\n", result );

    // Bitwise NOT operator
    result = ~a;       // 1100 0011
    printf("~a = %d\n", result );

    // Bitwise left shift operator
    result = a << 2;   // 1111 0000
    printf("a << 2 = %d\n", result );

    // Bitwise right shift operator
    result = a >> 2;   // 0000 1111
    printf("a >> 2 = %d\n", result );

    return 0;
}
//FormAI DATASET v1.0 Category: Bitwise operations ; Style: portable
#include <stdio.h>

int main() {
    unsigned int a = 20; // 00010100 in binary
    unsigned int b = 10; // 00001010 in binary

    // Using bitwise AND operator
    printf("a & b = %u\n", a & b); // Output: 00000000

    // Using bitwise OR operator
    printf("a | b = %u\n", a | b); // Output: 00011110

    // Using bitwise XOR operator
    printf("a ^ b = %u\n", a ^ b); // Output: 00011110

    // Using bitwise NOT operator
    printf("~a = %u\n", ~a); // Output: 11101011 (2's complement)

    // Using left shift operator
    printf("a << 2 = %u\n", a << 2); // Output: 01010000

    // Using right shift operator
    printf("b >> 2 = %u\n", b >> 2); // Output: 00000010

    return 0;
}
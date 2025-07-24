//FormAI DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>

/*
This program demonstrates the use of bitwise operators in C.
*/

int main() {
    unsigned int a = 5;   // 0000 0101
    unsigned int b = 3;   // 0000 0011

    // Bitwise AND operator
    printf("a & b = %d\n", a & b);   // 0000 0001

    // Bitwise OR operator
    printf("a | b = %d\n", a | b);   // 0000 0111
    
    // Bitwise XOR operator
    printf("a ^ b = %d\n", a ^ b);   // 0000 0110

    // Bitwise NOT operator
    printf("~a = %d\n", ~a);   // 1111 1010
    printf("~b = %d\n", ~b);   // 1111 1100
    
    // Left shift operator
    printf("a << 1 = %d\n", a << 1);   // 0000 1010
    printf("b << 2 = %d\n", b << 2);   // 0000 1100
    
    // Right shift operator
    printf("a >> 1 = %d\n", a >> 1);   // 0000 0010
    printf("b >> 2 = %d\n", b >> 2);   // 0000 0000

    return 0;
}
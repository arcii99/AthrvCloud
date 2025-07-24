//FormAI DATASET v1.0 Category: Bitwise operations ; Style: peaceful
#include <stdio.h>

int main() {
    int a = 6; // Binary value: 0110
    int b = 9; // Binary value: 1001
    
    printf("Initial values: a = %d, b = %d\n", a, b);

    int bit_or = a | b; // Bitwise OR operation
    printf("a | b = %d\n", bit_or);

    int bit_and = a & b; // Bitwise AND operation
    printf("a & b = %d\n", bit_and);

    int bit_xor = a ^ b; // Bitwise XOR operation
    printf("a ^ b = %d\n", bit_xor);

    int left_shift = a << 2; // Left shift
    printf("a << 2 = %d\n", left_shift);

    int right_shift = b >> 2; // Right shift
    printf("b >> 2 = %d\n", right_shift);

    int bit_not_a = ~a; // Bitwise NOT operation on variable a
    printf("~a = %d\n", bit_not_a);

    int bit_not_b = ~b; // Bitwise NOT operation on variable b
    printf("~b = %d\n", bit_not_b);

    return 0;
}
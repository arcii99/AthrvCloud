//FormAI DATASET v1.0 Category: Bitwise operations ; Style: safe
#include <stdio.h>

int main() {
    int a = 10, b = 5;

    // Bitwise AND operator example
    int and_result = a & b;
    printf("a & b = %d\n", and_result);

    // Bitwise OR operator example
    int or_result = a | b;
    printf("a | b = %d\n", or_result);

    // Bitwise XOR operator example
    int xor_result = a ^ b;
    printf("a ^ b = %d\n", xor_result);

    // Bitwise complement operator example
    int comp_result = ~a;
    printf("~a = %d\n", comp_result);

    // Left shift operator example
    int left_shift = a<<2;
    printf("a<<2 = %d\n", left_shift);

    // Right shift operator example
    int right_shift = a>>2;
    printf("a>>2 = %d\n", right_shift);

    // Setting a bit example
    int num = 0;
    int set_bit = 4;
    num |= (1 << set_bit);
    printf("Setting %dth bit of %d is %d\n", set_bit, 0, num);

    // Clearing a bit example
    int clear_bit = 2;
    num &= ~(1 << clear_bit);
    printf("Clearing %dth bit of %d is %d\n", clear_bit, 1, num);

    return 0;
}
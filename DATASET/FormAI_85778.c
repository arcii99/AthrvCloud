//FormAI DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include <stdio.h>

/* This program demonstrates expert-level usage of C bitwise operations. */

int main() {
    // variable declarations
    unsigned char a = 0b01100110; // 102
    unsigned char b = 0b11001001; // 201
    int x = 560;
    int y = -321;

    // display initial values
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("x = %d\n", x);
    printf("y = %d\n\n", y);

    // bitwise AND operation
    unsigned char result_and = a & b;
    printf("a & b = %d\n\n", result_and);

    // bitwise OR operation
    unsigned char result_or = a | b;
    printf("a | b = %d\n\n", result_or);

    // bitwise XOR operation
    unsigned char result_xor = a ^ b;
    printf("a ^ b = %d\n\n", result_xor);

    // bitwise negation operation
    unsigned char result_not_a = ~a;
    printf("~a = %d\n\n", result_not_a);

    // bitwise shift left operation
    int result_shift_left_x = x << 2;
    printf("x << 2 = %d\n\n", result_shift_left_x);

    // bitwise shift right operation
    int result_shift_right_y = y >> 3;
    printf("y >> 3 = %d\n\n", result_shift_right_y);

    // bitwise AND assignment operation
    a &= b;
    printf("a &= b => a = %d\n\n", a);

    // bitwise OR assignment operation
    b |= a;
    printf("b |= a => b = %d\n\n", b);

    // bitwise XOR assignment operation
    a ^= b;
    printf("a ^= b => a = %d\n\n", a);

    return 0;
}
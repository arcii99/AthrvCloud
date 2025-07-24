//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Ada Lovelace
#include <stdio.h>

int main(void) {
    int x = 10; // 1010 in binary
    int y = 6; // 0110 in binary

    // Bitwise AND
    int result_and = x & y;
    printf("Bitwise AND of %d and %d is %d\n", x, y, result_and); // Output: 2

    // Bitwise OR
    int result_or = x | y;
    printf("Bitwise OR of %d and %d is %d\n", x, y, result_or); // Output: 14

    // Bitwise XOR
    int result_xor = x ^ y;
    printf("Bitwise XOR of %d and %d is %d\n", x, y, result_xor); // Output: 12

    // Bitwise NOT
    int result_not = ~x;
    printf("Bitwise NOT of %d is %d\n", x, result_not); // Output: -11

    // Left shift
    int result_left_shift = x << 2;
    printf("Left shifting %d by 2 gives %d\n", x, result_left_shift); // Output: 40

    // Right shift
    int result_right_shift = y >> 1;
    printf("Right shifting %d by 1 gives %d\n", y, result_right_shift); // Output: 3

    return 0;
}
//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Alan Touring
#include <stdio.h>

int main() {
    // Declare two integer variables
    int x = 23, y = 18;

    // Perform a bitwise AND operation on x and y
    int bitwise_and = x & y;
    printf("Bitwise AND of %d and %d is %d\n", x, y, bitwise_and);

    // Perform a bitwise OR operation on x and y
    int bitwise_or = x | y;
    printf("Bitwise OR of %d and %d is %d\n", x, y, bitwise_or);

    // Perform a bitwise XOR operation on x and y
    int bitwise_xor = x ^ y;
    printf("Bitwise XOR of %d and %d is %d\n", x, y, bitwise_xor);

    // Perform a bitwise NOT operation on x
    int bitwise_not = ~x;
    printf("Bitwise NOT of %d is %d\n", x, bitwise_not);

    // Perform a left shift operation on x
    int left_shift = x << 2;
    printf("Left shift of %d by 2 is %d\n", x, left_shift);

    // Perform a right shift operation on y
    int right_shift = y >> 2;
    printf("Right shift of %d by 2 is %d\n", y, right_shift);

    return 0;
}
//FormAI DATASET v1.0 Category: Bitwise operations ; Style: peaceful
#include <stdio.h>

// A peaceful example program showcasing the power of bitwise operations

int main() {
    int x = 25; // Arbitrary number
    int y = 15; // Another arbitrary number
    int result;

    // AND operation
    result = x & y; // Bits that are set in both x and y are set in the result
    printf("The result of %d & %d is %d\n", x, y, result);

    // OR operation
    result = x | y; // Bits that are set in either x or y are set in the result
    printf("The result of %d | %d is %d\n", x, y, result);

    // XOR operation
    result = x ^ y; // Bits that are set in either x or y but not in both are set in the result
    printf("The result of %d ^ %d is %d\n", x, y, result);

    // Ones complement operation
    result = ~x; // Inverts all bits of x
    printf("The ones complement of %d is %d\n", x, result);

    // Left shift operation
    result = x << 2; // Shifts all bits in x to the left by 2 places
    printf("The result of %d << 2 is %d\n", x, result);

    // Right shift operation
    result = x >> 2; // Shifts all bits in x to the right by 2 places
    printf("The result of %d >> 2 is %d\n", x, result);

    return 0;
}
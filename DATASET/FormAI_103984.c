//FormAI DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include <stdio.h>

int main() {
    int x = 5, y = 9, i;

    // Bitwise AND operator
    i = x & y;
    printf("i is %d\n", i);

    // Bitwise OR operator
    i = x | y;
    printf("i is %d\n", i);

    // Bitwise XOR operator
    i = x ^ y;
    printf("i is %d\n", i);

    // Bitwise NOT operator
    i = ~x;
    printf("i is %d\n", i);

    // Left shift operator
    i = x << 2;
    printf("i is %d\n", i);

    // Right shift operator
    i = y >> 2;
    printf("i is %d\n", i);

    // Bitwise AND assignment operator
    x &= y;
    printf("x is %d\n", x);

    // Bitwise OR assignment operator
    x |= y;
    printf("x is %d\n", x);

    // Bitwise XOR assignment operator
    x ^= y;
    printf("x is %d\n", x);

    // Left shift assignment operator
    x <<= 2;
    printf("x is %d\n", x);

    // Right shift assignment operator
    y >>= 2;
    printf("y is %d\n", y);

    return 0;
}
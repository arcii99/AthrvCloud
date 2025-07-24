//FormAI DATASET v1.0 Category: Bitwise operations ; Style: shape shifting
#include <stdio.h>

int main() {
    int x = 10;
    int y = 5;
    printf("Original values: x = %d, y = %d\n", x, y);

    // Shifting x to the left by 1
    x = x << 1;
    printf("After shifting x to the left by 1: x = %d, y = %d\n", x, y);

    // Shifting y to the right by 2
    y = y >> 2;
    printf("After shifting y to the right by 2: x = %d, y = %d\n", x, y);

    // Performing AND operation on x and y
    x = x & y;
    printf("After ANDing x and y: x = %d, y = %d\n", x, y);

    // Performing XOR operation on x and y
    y = y ^ x;
    printf("After XORing x and y: x = %d, y = %d\n", x, y);

    // Performing OR operation on x and y
    x = x | y;
    printf("After ORing x and y: x = %d, y = %d\n", x, y);

    // Flipping all the bits in x
    x = ~x;
    printf("After flipping all bits in x: x = %d, y = %d\n", x, y);

    return 0;
}
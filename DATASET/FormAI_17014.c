//FormAI DATASET v1.0 Category: Bitwise operations ; Style: minimalist
#include <stdio.h>

int main() {
    unsigned int x = 0b1010;
    unsigned int y = 0b1100;

    // Bitwise AND operator
    unsigned int result = x & y;
    printf("Bitwise AND: %u\n", result);

    // Bitwise OR operator
    result = x | y;
    printf("Bitwise OR: %u\n", result);

    // Bitwise XOR operator
    result = x ^ y;
    printf("Bitwise XOR: %u\n", result);

    // Bitwise complement operator
    result = ~x;
    printf("Bitwise complement of %u: %u\n", x, result);

    // Left shift operator
    result = x << 2;
    printf("Left shift of %u by 2 bits: %u\n", x, result);

    // Right shift operator
    result = y >> 2;
    printf("Right shift of %u by 2 bits: %u\n", y, result);

    return 0;
}
//FormAI DATASET v1.0 Category: Bitwise operations ; Style: optimized
#include <stdio.h>

int main() {
    unsigned int x = 128;
    unsigned int y = 64;
    unsigned int z;

    // Bitwise AND operator
    z = x & y;
    printf("%d & %d = %d\n", x, y, z);

    // Bitwise OR operator
    z = x | y;
    printf("%d | %d = %d\n", x, y, z);

    // Bitwise XOR operator
    z = x ^ y;
    printf("%d ^ %d = %d\n", x, y, z);

    // Bitwise NOT operator
    z = ~x;
    printf("~%d = %u\n", x, z);

    // Bitwise Left Shift operator
    z = x << 2;
    printf("%d << 2 = %u\n", x, z);

    // Bitwise Right Shift operator
    z = y >> 2;
    printf("%d >> 2 = %u\n", y, z);

    return 0;
}
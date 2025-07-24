//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include <stdio.h>

int main() {
    // Initializing variables
    unsigned int x = 93;
    unsigned int y = 227;
    unsigned int result;

    // Performing bitwise operations
    result = x & y;
    printf("x & y = %u\n", result); // Output: 65

    result = x | y;
    printf("x | y = %u\n", result); // Output: 255

    result = x ^ y;
    printf("x ^ y = %u\n", result); // Output: 190

    result = ~x;
    printf("~x = %u\n", result); // Output: 4294967202

    result = x << 2;
    printf("x << 2 = %u\n", result); // Output: 372

    result = y >> 1;
    printf("y >> 1 = %u\n", result); // Output: 113

    return 0;
}
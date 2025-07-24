//FormAI DATASET v1.0 Category: Bitwise operations ; Style: calm
#include <stdio.h>

int main()
{
    // Bitwise AND operator
    int x = 23;
    int y = 56;
    int z = x & y;
    printf("z = %d\n", z); // Output: z = 16

    // Bitwise OR operator
    x = 23;
    y = 56;
    z = x | y;
    printf("z = %d\n", z); // Output: z = 63

    // Bitwise XOR operator
    x = 23;
    y = 56;
    z = x ^ y;
    printf("z = %d\n", z); // Output: z = 47

    // Bitwise NOT operator
    x = 23;
    z = ~x;
    printf("z = %d\n", z); // Output: z = -24

    // Bitwise left shift operator
    x = 23;
    z = x << 2;
    printf("z = %d\n", z); // Output: z = 92

    // Bitwise right shift operator
    x = 23;
    z = x >> 2;
    printf("z = %d\n", z); // Output: z = 5

    return 0;
}
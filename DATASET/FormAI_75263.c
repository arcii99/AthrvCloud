//FormAI DATASET v1.0 Category: Bitwise operations ; Style: genious
#include <stdio.h>

int main() {
    int x = 10, y = 20;
    printf("Initial Values:\n x = %d, y = %d\n\n", x, y);

    // Bitwise AND
    int result = x & y;
    printf("x & y = %d\n", result);
    printf("Binary equivalent: %d & %d = %d \n\n", x, y, result);

    // Bitwise OR
    result = x | y;
    printf("x | y = %d\n", result);
    printf("Binary equivalent: %d | %d = %d \n\n", x, y, result);

    // Bitwise XOR
    result = x ^ y;
    printf("x ^ y = %d\n", result);
    printf("Binary equivalent: %d ^ %d = %d \n\n", x, y, result);

    // Bitwise NOT
    result = ~x;
    printf("~x = %d\n", result);
    printf("Binary equivalent: ~%d = %d \n\n", x, result);

    // Left Shift
    result = x << 1;
    printf("x << 1 = %d\n", result);
    printf("Binary equivalent: %d << 1 = %d \n\n", x, result);

    // Right Shift
    result = x >> 1;
    printf("x >> 1 = %d\n", result);
    printf("Binary equivalent: %d >> 1 = %d \n\n", x, result);

    // Bitwise combinations
    result = (x ^ y) & (x | y);
    printf("(x ^ y) & (x | y) = %d\n", result);
    printf("Binary equivalent: (%d ^ %d) & (%d | %d) = %d \n\n", x, y, x, y, result);

    return 0;
}
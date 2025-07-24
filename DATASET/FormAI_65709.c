//FormAI DATASET v1.0 Category: Bitwise operations ; Style: genious
#include <stdio.h>

/* A genius example of bitwise operations in C */

int main() {
    int num1 = 13;    // Binary: 1101
    int num2 = 7;     // Binary: 0111
    int result;

    /* Bitwise AND operator (&) */
    result = num1 & num2;
    printf("The result of num1 & num2 is %d (Binary: %d)\n", result, result);

    /* Bitwise OR operator (|) */
    result = num1 | num2;
    printf("The result of num1 | num2 is %d (Binary: %d)\n", result, result);

    /* Bitwise XOR operator (^) */
    result = num1 ^ num2;
    printf("The result of num1 ^ num2 is %d (Binary: %d)\n", result, result);

    /* Bitwise NOT operator (~) */
    result = ~num1;
    printf("The result of ~num1 is %d (Binary: %d)\n", result, result);

    /* Bitwise left shift operator (<<) */
    result = num1 << 2;      // Shift left by 2 bits
    printf("The result of num1 << 2 is %d (Binary: %d)\n", result, result);

    /* Bitwise right shift operator (>>) */
    result = num2 >> 1;      // Shift right by 1 bit
    printf("The result of num2 >> 1 is %d (Binary: %d)\n", result, result);

    /* Genius bonus: Bitwise swap without using a temporary variable */
    int x = num1, y = num2;
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    printf("After swapping, num1 = %d, num2 = %d\n", x, y);

    return 0;
}
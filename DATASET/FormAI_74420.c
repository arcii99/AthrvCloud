//FormAI DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include<stdio.h>

/*
 * This program demonstrates the usage of various bitwise operations in C.
 */

int main()
{
    int a = 8, b = 12, result;

    // Bitwise OR (|)
    result = a | b;
    printf("Output of %d | %d = %d\n", a, b, result);

    // Bitwise AND (&)
    result = a & b;
    printf("Output of %d & %d = %d\n", a, b, result);

    // Bitwise XOR (^)
    result = a ^ b;
    printf("Output of %d ^ %d = %d\n", a, b, result);

    // Bitwise NOT (~)
    result = ~a;
    printf("Output of ~%d = %d\n", a, result);

    // Bitwise Left Shift (<<)
    result = a << 2;
    printf("Output of %d << 2 = %d\n", a, result);

    // Bitwise Right Shift (>>)
    result = b >> 2;
    printf("Output of %d >> 2 = %d\n", b, result);

    // Bitwise AND with Mask
    int c = 25; // In binary, c is 11001
    int mask = 7; // In binary, mask is 111
    result = c & mask;
    printf("Output of %d & %d = %d\n", c, mask, result);

    // Bitwise Swapping without third variable
    int x = 10, y = 20;
    printf("Before Swapping: x = %d, y = %d\n", x, y);
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    printf("After Swapping: x = %d, y = %d\n", x, y);

    return 0;
}
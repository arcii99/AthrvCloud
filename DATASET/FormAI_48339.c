//FormAI DATASET v1.0 Category: Bitwise operations ; Style: excited
#include <stdio.h>

int main() 
{
    printf("Are you ready to see some magical Bitwise operations?!\n");

    // Bitwise AND operation
    int x = 5, y = 3;
    int andResult = x & y;
    printf("The Bitwise AND between %d and %d is: %d\n", x, y, andResult);

    // Bitwise OR operation
    int orResult = x | y;
    printf("The Bitwise OR between %d and %d is: %d\n", x, y, orResult);

    // Bitwise NOT operation
    int notX = ~x;
    printf("The Bitwise NOT of %d is: %d\n", x, notX);

    // Bitwise XOR operation
    int xorResult = x ^ y;
    printf("The Bitwise XOR between %d and %d is: %d\n", x, y, xorResult);

    // Bitwise left shift operation
    int leftShiftResult = x << 2;
    printf("The Bitwise left shift of %d by 2 is: %d\n", x, leftShiftResult);

    // Bitwise right shift operation
    int rightShiftResult = x >> 1; 
    printf("The Bitwise right shift of %d by 1 is: %d\n", x, rightShiftResult);

    printf("Wow, that was amazing! Bitwise operations are so cool!\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>

int main() {
    // This program demonstrates some creative uses of bitwise operations in C

    // Example 1: Check if a number is even or odd using bitwise AND operator
    int num1 = 15;
    if (num1 & 1) {
        printf("%d is odd\n", num1);
    } else {
        printf("%d is even\n", num1);
    }

    // Example 2: Set a bit in a number using bitwise OR operator
    int num2 = 0b0010;
    int mask = 0b0011;
    int result = num2 | mask;
    printf("Setting a bit in %d with mask %d gives %d\n", num2, mask, result);

    // Example 3: Toggle a bit in a number using bitwise XOR operator
    int num3 = 0b1010;
    int toggle_bit = 1;
    int result2 = num3 ^ toggle_bit;
    printf("Toggling a bit in %d with bit %d gives %d\n", num3, toggle_bit, result2);

    // Example 4: Shifting bits left and right using bitwise shift operators
    int num4 = 0b1100;
    int shifted_left = num4 << 2;
    int shifted_right = num4 >> 1;
    printf("Shifted left: %d, shifted right: %d\n", shifted_left, shifted_right);

    // Example 5: Using bitwise NOT operator to flip all bits in a number
    int num5 = 0b1111;
    int flipped = ~num5;
    printf("Flipping all bits in %d gives %d\n", num5, flipped);

    return 0;
}
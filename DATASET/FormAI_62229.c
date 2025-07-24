//FormAI DATASET v1.0 Category: Bitwise operations ; Style: shape shifting
#include <stdio.h>

/* A fun program that demonstrates bitwise operations in a shape-shifting style */

int main() {

    /* Let's start with a shape that has 8 sides */
    unsigned char shape = 0b00001111; // each bit represents one side

    /* Let's shift the shape to the right by 2 bits */
    shape >>= 2;

    /* The shape now has 6 sides */
    printf("The new shape has %d sides.\n", shape);

    /* Let's flip the shape */
    shape ^= 0xff;

    /* The shape now has inverted sides */
    printf("The inverted shape has sides:\n");
    printf("%d", (shape >> 7) & 1); // the first bit
    printf("%d", (shape >> 6) & 1); // the second bit
    printf("%d", (shape >> 5) & 1); // the third bit
    printf("%d", (shape >> 4) & 1); // the fourth bit
    printf("%d", (shape >> 3) & 1); // the fifth bit
    printf("%d", (shape >> 2) & 1); // the sixth bit
    printf("%d", (shape >> 1) & 1); // the seventh bit
    printf("%d\n", shape & 1); // the eighth bit

    /* Let's set the fourth side to 1 */
    shape |= 0b00001000;

    /* The shape has a new side */
    printf("The new shape has %d sides:\n", __builtin_popcount(shape)); // using a built-in function to count the number of 1's
    printf("%d", (shape >> 7) & 1); // the first bit
    printf("%d", (shape >> 6) & 1); // the second bit
    printf("%d", (shape >> 5) & 1); // the third bit
    printf("%d", (shape >> 4) & 1); // the fourth bit
    printf("%d", (shape >> 3) & 1); // the fifth bit
    printf("%d", (shape >> 2) & 1); // the sixth bit
    printf("%d", (shape >> 1) & 1); // the seventh bit
    printf("%d\n", shape & 1); // the eighth bit

    /* Let's shift the shape to the left by 4 bits */
    shape <<= 4;

    /* The shape has expanded */
    printf("The expanded shape has %d sides:\n", __builtin_popcount(shape));
    printf("%d", (shape >> 7) & 1); // the first bit
    printf("%d", (shape >> 6) & 1); // the second bit
    printf("%d", (shape >> 5) & 1); // the third bit
    printf("%d", (shape >> 4) & 1); // the fourth bit
    printf("%d", (shape >> 3) & 1); // the fifth bit
    printf("%d", (shape >> 2) & 1); // the sixth bit
    printf("%d", (shape >> 1) & 1); // the seventh bit
    printf("%d\n", shape & 1); // the eighth bit

    /* Let's clear the third side */
    shape &= 0b11111011;

    /* The shape has lost a side */
    printf("The new shape has %d sides:\n", __builtin_popcount(shape));
    printf("%d", (shape >> 7) & 1); // the first bit
    printf("%d", (shape >> 6) & 1); // the second bit
    printf("%d", (shape >> 5) & 1); // the third bit
    printf("%d", (shape >> 4) & 1); // the fourth bit
    printf("%d", (shape >> 3) & 1); // the fifth bit
    printf("%d", (shape >> 2) & 1); // the sixth bit
    printf("%d", (shape >> 1) & 1); // the seventh bit
    printf("%d\n", shape & 1); // the eighth bit

    return 0;
}
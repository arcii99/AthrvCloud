//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Ken Thompson
#include <stdio.h>

int main() {
    unsigned int x = 0b11001110;
    unsigned int y = 0b10101010;

    printf("Initial values: x = %u, y = %u\n\n", x, y);

    // Toggle the 2nd, 4th, and 6th bits of x
    x ^= (1 << 1) | (1 << 3) | (1 << 5);
    printf("After toggling the 2nd, 4th, and 6th bits of x: x = %u\n\n", x);

    // Set the 3rd, 5th, and 7th bits of y
    y |= (1 << 2) | (1 << 4) | (1 << 6);
    printf("After setting the 3rd, 5th, and 7th bits of y: y = %u\n\n", y);

    // Clear the 1st, 3rd, and 5th bits of x
    x &= ~((1 << 0) | (1 << 2) | (1 << 4));
    printf("After clearing the 1st, 3rd, and 5th bits of x: x = %u\n\n", x);

    // Check if the 2nd bit of y is set
    if (y & (1 << 1)) {
        printf("The 2nd bit of y is set\n\n");
    } else {
        printf("The 2nd bit of y is not set\n\n");
    }

    // Shift x left by 2 bits
    x <<= 2;
    printf("After shifting x left by 2 bits: x = %u\n\n", x);

    // Shift y right by 3 bits
    y >>= 3;
    printf("After shifting y right by 3 bits: y = %u\n\n", y);

    // Rotate x left by 4 bits
    x = (x << 4) | (x >> (32-4));
    printf("After rotating x left by 4 bits: x = %u\n\n", x);

    // Rotate y right by 5 bits
    y = (y >> 5) | (y << (32-5));
    printf("After rotating y right by 5 bits: y = %u\n\n", y);

    return 0;
}
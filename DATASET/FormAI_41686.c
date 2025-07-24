//FormAI DATASET v1.0 Category: Bitwise operations ; Style: curious
#include <stdio.h>

int main() {
    int val = 5;
    printf("The initial value of val is %d\n", val);

    // Set the 2nd bit of val
    val |= 1 << 1;
    printf("After setting the 2nd bit in val, val is now %d\n", val);

    // Check if the 3rd bit of val is set
    if (val & (1 << 2)) {
        printf("The 3rd bit in val is set\n");
    } else {
        printf("The 3rd bit in val is not set\n");
    }

    // Clear the 1st bit in val
    val &= ~(1 << 0);
    printf("After clearing the 1st bit in val, val is now %d\n", val);

    // Toggle the 2nd bit in val
    val ^= 1 << 1;
    printf("After toggling the 2nd bit in val, val is now %d\n", val);

    // Shift left by 3 bits
    val <<= 3;
    printf("After shifting left by 3 bits, val is now %d\n", val);

    // Shift right by 2 bits
    val >>= 2;
    printf("After shifting right by 2 bits, val is now %d\n", val);

    return 0;
}
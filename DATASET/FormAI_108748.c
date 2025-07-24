//FormAI DATASET v1.0 Category: Bitwise operations ; Style: automated
#include <stdio.h>

// Function to set the n-th bit of x
int set_bit(int x, int n) {
    return x | (1 << n);
}

// Function to clear the n-th bit of x
int clear_bit(int x, int n) {
    return x & ~(1 << n);
}

// Function to flip the n-th bit of x
int flip_bit(int x, int n) {
    return x ^ (1 << n);
}

int main() {
    int x = 10; // Binary value of 10 is 1010

    // Printing the original value of x
    printf("Original value of x: %d\n", x);

    // Setting the 3rd bit of x
    x = set_bit(x, 3);
    printf("After setting 3rd bit, x is now: %d\n", x); // Output should be 10 + 2^3 = 18

    // Clearing the 2nd bit of x
    x = clear_bit(x, 2);
    printf("After clearing 2nd bit, x is now: %d\n", x); // Output should be 18 - 2^2 = 14

    // Flipping the 1st bit of x
    x = flip_bit(x, 1);
    printf("After flipping 1st bit, x is now: %d\n", x); // Output should be 14 ^ 2^1 = 12

    return 0;
}
//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Donald Knuth
/*
 * C Bitwise Operations Example Program
 * Inspired by Donald Knuth's Art of Computer Programming
 */

#include <stdio.h>

// Convenience Macros for Integer -> Binary Conversion and Debug Printing
#define INT_TO_BIN(i) (printf(#i " in binary: %s\n", int_to_bin_str(i)))
#define DEBUG_PRINT(s, x) (printf("%s: %d\n", s, x))

// Convert an Integer to Binary String
char* int_to_bin_str(int num) {
    static char bin_str[32];
    int i = 0;
    while (num > 0) {
        bin_str[i++] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
    bin_str[i] = '\0';
    return bin_str;
}

int main() {
    // Scenario 1: Clearing All Bits except the Least Significant (LSB)
    unsigned char byte = 0b10110110;
    DEBUG_PRINT("Before", byte);
    byte &= 1;  // Clear All Bits except the LSB
    DEBUG_PRINT("After", byte);

    // Scenario 2: Flipping the Nth Bit of an Integer
    unsigned int num = 0b11001100;
    int n = 3;  // Flip the 4th bit (from right to left)
    DEBUG_PRINT("Before", num);
    num ^= (1 << n);
    DEBUG_PRINT("After", num);

    // Scenario 3: Extracting the Nth Bit of an Integer
    unsigned short int short_num = 0b01101011;
    n = 5;  // Extract the 6th Bit (from right to left)
    DEBUG_PRINT("Original Number", short_num);
    int n_bit = (short_num >> n) & 1;
    DEBUG_PRINT("Nth Bit", n_bit);

    // Scenario 4: Replacing the Nth Bit of an Integer with a given Value (0 or 1)
    num = 0b10101010;
    n = 2;  // Replace the 3rd Bit (from right to left)
    int val_to_replace = 1;
    DEBUG_PRINT("Before", num);
    num = (num & ~(1 << n)) | (val_to_replace << n);
    DEBUG_PRINT("After", num);

    // Scenario 5: Concatenating Two Numbers
    unsigned char hi = 0b11000000;
    unsigned char lo = 0b00001111;
    DEBUG_PRINT("High", hi);
    DEBUG_PRINT("Low", lo);
    unsigned short concat = (hi << 8) | lo;
    DEBUG_PRINT("Concatenated", concat);

    // Scenario 6: Swapping Two Numbers with XOR
    int x = 10;
    int y = 20;
    DEBUG_PRINT("Before", x);
    DEBUG_PRINT("Before", y);
    x ^= y;
    y ^= x;
    x ^= y;
    DEBUG_PRINT("After", x);
    DEBUG_PRINT("After", y);

    // Scenario 7: Constructing a Bit Pattern with Shift and OR
    unsigned char pattern = (1 << 4) | (1 << 2) | (1 << 1) | (1 << 0);
    INT_TO_BIN(pattern);

    return 0;
}
//FormAI DATASET v1.0 Category: Bitwise operations ; Style: lively
#include <stdio.h>

/*
 * This program is a fun example of C Bitwise Operations
 * We will create our own binary lucky number generator
 * We will use bitwise XOR and AND operators to modify the bits
 * of numbers to create a unique lucky number
 */

int main() {

    // Our lucky number starts with the binary value 1010 (decimal value 10)
    int luckyNumber = 10;

    // Let's print out the binary and decimal value of our lucky number
    printf("Our lucky number starts as binary: %d%d%d%d (decimal value %d)\n", (luckyNumber >> 3) & 1, (luckyNumber >> 2) & 1, (luckyNumber >> 1) & 1, luckyNumber & 1, luckyNumber);

    // We want to make our number more unique by flipping the bits in the 2nd and 3rd positions
    luckyNumber = luckyNumber ^ (1 << 2); // Flips the bit in position 2 (0100)
    luckyNumber = luckyNumber ^ (1 << 1); // Flips the bit in position 3 (0010)
    // Let's print out our new binary and decimal value of our lucky number
    printf("Flipping bits 2 and 3 gives binary: %d%d%d%d (decimal value %d)\n", (luckyNumber >> 3) & 1, (luckyNumber >> 2) & 1, (luckyNumber >> 1) & 1, luckyNumber & 1, luckyNumber);

    // We can make our number even luckier by setting the 4th and 1st bits to 1
    luckyNumber = luckyNumber | (1 << 3); // Sets the bit in position 1 (1000)
    luckyNumber = luckyNumber | (1 << 0); // Sets the bit in position 4 (0001)
    // Let's print out our new binary and decimal value of our lucky number
    printf("Setting bits 1 and 4 gives binary: %d%d%d%d (decimal value %d)\n", (luckyNumber >> 3) & 1, (luckyNumber >> 2) & 1, (luckyNumber >> 1) & 1, luckyNumber & 1, luckyNumber);

    // We can make our number even more unique by flipping the entire binary value
    luckyNumber = ~luckyNumber;
    // Let's print out our new binary and decimal value of our lucky number
    printf("Flipping the bits gives binary: %d%d%d%d (decimal value %d)\n", (luckyNumber >> 3) & 1, (luckyNumber >> 2) & 1, (luckyNumber >> 1) & 1, luckyNumber & 1, luckyNumber);

    // Finally, let's make sure our lucky number is only 4 bits long by using the AND operator
    luckyNumber = luckyNumber & 0b1111; // 0b1111 is the binary value of 15, which will only keep the rightmost 4 bits
    // Let's print out our final binary and decimal value of our lucky number
    printf("Our final lucky number is: %d%d%d%d (decimal value %d)\n", (luckyNumber >> 3) & 1, (luckyNumber >> 2) & 1, (luckyNumber >> 1) & 1, luckyNumber & 1, luckyNumber);

    return 0;
}
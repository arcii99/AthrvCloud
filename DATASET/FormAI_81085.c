//FormAI DATASET v1.0 Category: Bitwise operations ; Style: active
#include <stdio.h>

// Bitwise OR operation
int bitwiseOR(int x, int y) {
    return x|y;
}

// Bitwise AND operation
int bitwiseAND(int x, int y) {
    return x&y;
}

// Bitwise XOR operation
int bitwiseXOR(int x, int y) {
    return x^y;
}

// Get Bit at a specific position
int getBit(int n, int pos) {
    return (n >> pos) & 1;
}

// Set Bit at a specific position
int setBit(int n, int pos) {
    return n | (1 << pos);
}

// Clear Bit at a specific position
int clearBit(int n, int pos) {
    return n & (~(1 << pos));
}

// Update Bit at a specific position
int updateBit(int n, int pos, int bit) {
    return (n & ~(1 << pos)) | (bit << pos);
}

int main() {
    int x = 5; // Binary: 101
    int y = 3; // Binary: 011

    printf("Bitwise OR: %d\n", bitwiseOR(x, y)); // Output: 7 (Binary: 111)
    printf("Bitwise AND: %d\n", bitwiseAND(x, y)); // Output: 1 (Binary: 001)
    printf("Bitwise XOR: %d\n", bitwiseXOR(x, y)); // Output: 6 (Binary: 110)

    printf("Bit at position 1 in %d is %d\n", x, getBit(x, 1)); // Output: Bit at position 1 in 5 is 0
    printf("Bit at position 2 in %d is %d\n", y, getBit(y, 2)); // Output: Bit at position 2 in 3 is 1

    printf("Setting bit at position 2 in %d will result in %d\n", x, setBit(x, 2)); // Output: Setting bit at position 2 in 5 will result in 7
    printf("Clearing bit at position 0 in %d will result in %d\n", y, clearBit(y, 0)); // Output: Clearing bit at position 0 in 3 will result in 2

    printf("Updating bit at position 0 in %d to 1 will result in %d\n", x, updateBit(x, 0, 1)); // Output: Updating bit at position 0 in 5 to 1 will result in 5

    return 0;
}
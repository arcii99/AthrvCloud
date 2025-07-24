//FormAI DATASET v1.0 Category: Bitwise operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// This program demonstrates bitwise operations in C

// Helper function to print binary of an unsigned integer
void printBinary(unsigned int num) {
    for(int i=31; i>=0; i--) {
        printf("%d", num & (1 << i) ? 1 : 0);
    }
    printf("\n");
}

int main() {
    unsigned int a = 0b10101010; // Binary literal for 170
    unsigned int b = 0b01010101; // Binary literal for 85

    // Bitwise AND operator &
    printf("a & b = "); printBinary(a & b);
    // Bitwise OR operator |
    printf("a | b = "); printBinary(a | b);
    // Bitwise XOR operator ^
    printf("a ^ b = "); printBinary(a ^ b);
    // Bitwise NOT operator ~
    printf("~a = "); printBinary(~a); 
    // Left shift operator <<
    printf("a << 1 = "); printBinary(a << 1); 
    // Right shift operator >>
    printf("a >> 1 = "); printBinary(a >> 1);

    // Example use case: Creating a bit mask
    unsigned int mask = 0;
    mask |= 1 << 2; // Set bit 2 to 1
    mask |= 1 << 5; // Set bit 5 to 1
    printf("Mask: "); printBinary(mask);

    // Example use case: Checking if a bit is set
    unsigned int flags = 0b01001010; // Binary literal for 74
    if(flags & 1 << 3) { // Check if bit 3 is set
        printf("Bit 3 is set!\n");
    } else {
        printf("Bit 3 is not set!\n");
    }

    return 0;
}
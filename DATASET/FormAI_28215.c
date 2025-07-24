//FormAI DATASET v1.0 Category: Bitwise operations ; Style: genious
#include <stdio.h>

int main() {
    int x = 0b10101010; // Binary number: 170
    int y = 0b00111100; // Binary number: 60
    
    printf("Initial values of x and y: x = %d, y = %d\n", x, y);
    
    // Bitwise AND (&) operation
    int z = x & y; // Binary result: 0b00101000 = 40
    printf("Result of x & y: %d\n", z);
    
    // Bitwise OR (|) operation
    z = x | y; // Binary result: 0b10111110 = 190
    printf("Result of x | y: %d\n", z);
    
    // Bitwise XOR (^) operation
    z = x ^ y; // Binary result: 0b10010110 = 150
    printf("Result of x ^ y: %d\n", z);
    
    // Bitwise complement (~) operation
    z = ~x; // Binary result: 0b01010101 = -171 (two's complement)
    printf("Result of ~x: %d\n", z);
    
    // Left shift (<<) operation
    z = x << 2; // Binary result: 0b1010101000 = 680
    printf("Result of x << 2: %d\n", z);
    
    // Right shift (>>) operation
    z = y >> 2; // Binary result: 0b00001111 = 15
    printf("Result of y >> 2: %d\n", z);
    
    return 0;
}
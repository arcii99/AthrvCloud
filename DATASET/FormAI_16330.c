//FormAI DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

/* This program demonstrates various bitwise operations in C */

int main()
{
    unsigned char a = 0b01100100; // 100 in binary
    unsigned char b = 0b00101011; // 43 in binary
    
    printf("a = %d, b = %d\n", a, b);
    
    // Bitwise AND (&) operation
    unsigned char c = a & b; // Performs AND on each bit
    printf("a & b = %d\n", c); // Output: 36
    
    // Bitwise OR (|) operation
    unsigned char d = a | b; // Performs OR on each bit
    printf("a | b = %d\n", d); // Output: 107
    
    // Bitwise XOR (^) operation
    unsigned char e = a ^ b; // Performs XOR on each bit
    printf("a ^ b = %d\n", e); // Output: 71
    
    // Bitwise NOT (~) operation
    unsigned char f = ~a; // Performs NOT on each bit
    printf("~a = %d\n", f); // Output: 155
    
    // Left shift (<<) operation
    unsigned char g = b << 2; // Shifts b left by 2 bits
    printf("b << 2 = %d\n", g); // Output: 172
    
    // Right shift (>>) operation
    unsigned char h = a >> 3; // Shifts a right by 3 bits
    printf("a >> 3 = %d\n", h); // Output: 8
    
    return 0;
}
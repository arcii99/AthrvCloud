//FormAI DATASET v1.0 Category: Bitwise operations ; Style: unmistakable
#include <stdio.h>

/* Bitwise operations example program */

int main() {
    
    // Define some integer variables
    int a = 0xFA; 
    int b = 0x83;
    int c = 0x7C;
    int d = 0x10;
    
    // Bitwise operations examples
    
    // Bitwise AND: compare each bit of operands and place a 1 in the result if both bits of the corresponding position are 1 
    printf("a & b: %X\n", a & b); // output: 82 (bits 0b10000010)
    
    // Bitwise OR: compare each bit of operands and place a 1 in the result if at least one bit of the corresponding position is 1 
    printf("a | b: %X\n", a | b); // output: FB (bits 0b11111011)
    
    // Bitwise XOR: compare each bit of operands and place a 1 in the result if both bits of the corresponding position are different
    printf("a ^ b: %X\n", a ^ b); // output: 79 (bits 0b01111001)
    
    // Bitwise NOT: invert all bits of an operand 
    printf("~a: %X\n", ~a); // output: -FB (bits 0b00000100 11110101)
    
    // Bitwise left shift: shift the bits of an operand to the left by a given number of positions, filling the empty positions with 0s
    printf("c << 2: %X\n", c << 2); // output: F0 (bits 0b11110000)
    
    // Bitwise right shift: shift the bits of an operand to the right by a given number of positions, filling the empty positions with 0s
    printf("c >> 2: %X\n", c >> 2); // output: 1F (bits 0b00011111)
    
    // Bitwise operators can be used for more complex operations as well, for example, to test the value of a specific bit:
    if ((d & 0x08) == 0x08) {
        printf("The 4th bit of d is 1\n");
    } else {
        printf("The 4th bit of d is 0\n");
    }

    return 0;
}
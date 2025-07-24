//FormAI DATASET v1.0 Category: Bitwise operations ; Style: brave
#include <stdio.h>

int main() {
    unsigned int x = 0xA5; // 165 in decimal
    unsigned int y = 0x5A; // 90 in decimal
    
    // Perform bitwise AND
    unsigned int and_result = x & y;
    printf("AND Result: 0x%X\n", and_result);
    
    // Perform bitwise OR
    unsigned int or_result = x | y;
    printf("OR Result: 0x%X\n", or_result);
    
    // Perform bitwise XOR
    unsigned int xor_result = x ^ y;
    printf("XOR Result: 0x%X\n", xor_result);
    
    // Perform bitwise complement
    unsigned int complement_result = ~x;
    printf("Complement Result: 0x%X\n", complement_result);
    
    // Shift left by 2 bits
    unsigned int shift_left_result = x << 2;
    printf("Shift Left Result: 0x%X\n", shift_left_result);
    
    // Shift right by 4 bits
    unsigned int shift_right_result = y >> 4;
    printf("Shift Right Result: 0x%X\n", shift_right_result);
    
    // Set the 5th bit of x to 1
    unsigned int set_bit_result = x | (1 << 5);
    printf("Set Bit Result: 0x%X\n", set_bit_result);
    
    // Clear the 3rd bit of y
    unsigned int clear_bit_result = y & ~(1 << 3);
    printf("Clear Bit Result: 0x%X\n", clear_bit_result);
    
    // Check if the 7th bit of x is set
    if (x & (1 << 6)) {
        printf("Bit 7 of X is set\n");
    } else {
        printf("Bit 7 of X is not set\n");
    }
    
    // Check if the 0th bit of y is clear
    if (!(y & 1)) {
        printf("Bit 0 of Y is clear\n");
    } else {
        printf("Bit 0 of Y is set\n");
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>

int main() {
    unsigned int num1 = 0xAC; // In binary: 10101100
    unsigned int num2 = 0x5F; // In binary: 01011111
    unsigned int result = 0;
    
    printf("Initial values:\n");
    printf("num1 = 0x%X\n", num1);
    printf("num2 = 0x%X\n", num2);
    
    // Bitwise AND
    result = num1 & num2;
    printf("\nBitwise AND:\n");
    printf("num1 & num2 = 0x%X\n", result);
    
    // Bitwise OR
    result = num1 | num2;
    printf("\nBitwise OR:\n");
    printf("num1 | num2 = 0x%X\n", result);
    
    // Bitwise XOR
    result = num1 ^ num2;
    printf("\nBitwise XOR:\n");
    printf("num1 ^ num2 = 0x%X\n", result);
    
    // Bitwise NOT
    result = ~num1;
    printf("\nBitwise NOT:\n");
    printf("~num1 = 0x%X\n", result);
    
    // Shifting left
    result = num1 << 3;
    printf("\nShifting left:\n");
    printf("num1 << 3 = 0x%X\n", result);
    
    // Shifting right
    result = num2 >> 4;
    printf("\nShifting right:\n");
    printf("num2 >> 4 = 0x%X\n", result);
        
    return 0;
}
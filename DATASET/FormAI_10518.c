//FormAI DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>

int main() {
    int num1 = 60;   // 0011 1100
    int num2 = 13;   // 0000 1101
    int result = 0;
    
    // Bitwise AND
    result = num1 & num2;
    printf("Bitwise AND: %d\n", result);
    
    // Bitwise OR
    result = num1 | num2;
    printf("Bitwise OR: %d\n", result);
    
    // Bitwise XOR
    result = num1 ^ num2;
    printf("Bitwise XOR: %d\n", result);
    
    // Bitwise NOT
    result = ~num1;
    printf("Bitwise NOT (num1): %d\n", result);
    
    // Bitwise LEFT SHIFT
    result = num1 << 2;   // Shift left by 2 bits
    printf("Bitwise LEFT SHIFT: %d\n", result);
    
    // Bitwise RIGHT SHIFT
    result = num1 >> 2;   // Shift right by 2 bits
    printf("Bitwise RIGHT SHIFT: %d\n", result);
    
    return 0;
}
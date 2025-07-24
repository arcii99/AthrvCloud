//FormAI DATASET v1.0 Category: Bitwise operations ; Style: satisfied
#include <stdio.h>

int main() {
    unsigned char a = 100, b = 200;
    printf("a = %d, b = %d\n", a, b);
    
    // Bitwise AND operation
    unsigned char c = a & b;
    printf("a & b = %d\n", c);
    
    // Bitwise OR operation
    c = a | b;
    printf("a | b = %d\n", c);

    // Bitwise XOR operation
    c = a ^ b;
    printf("a ^ b = %d\n", c);

    // Bitwise NOT operation
    c = ~a;
    printf("~a = %d\n", c);
      
    // Left Shift operation
    c = a << 2;
    printf("a << 2 = %d\n", c);

    // Right Shift operation
    c = b >> 3;
    printf("b >> 3 = %d\n", c);
    
    // Checking for a bit value
    unsigned char d = 0b01100110;
    int bit_position = 5;
    int bit_value = (d >> bit_position) & 1;
    printf("Bit at position %d in %d is %d", bit_position, d, bit_value);
    
    return 0;
}
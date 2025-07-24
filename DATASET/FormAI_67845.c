//FormAI DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include <stdio.h>

int main() {
    unsigned char a = 170;     // 10101010 in binary
    unsigned char b = 85;      // 01010101 in binary

    // Bitwise AND operator
    printf("a & b = %d\n", a & b);        // Output: 0
    
    // Bitwise OR operator
    printf("a | b = %d\n", a | b);        // Output: 255
    
    // Bitwise XOR operator
    printf("a ^ b = %d\n", a ^ b);        // Output: 255
    
    // Bitwise NOT operator
    printf("~a = %d\n", ~a);              // Output: 85
    
    // Left shift operator
    printf("a << 2 = %d\n", a << 2);      // Output: 136 (10101010 becomes 1010101000)
    
    // Right shift operator
    printf("a >> 2 = %d\n", a >> 2);      // Output: 42 (10101010 becomes 10)

    // Setting a bit at a particular position (using OR operator)
    int pos = 3;
    unsigned char mask = 1 << pos;
    a = a | mask;
    printf("a = %d\n", a);                // Output: 178 (10101110 in binary)
    
    // Clearing a bit at a particular position (using AND operator)
    pos = 6;
    mask = ~(1 << pos);
    a = a & mask;
    printf("a = %d\n", a);                // Output: 50 (00110010 in binary)

    // Toggling a bit at a particular position (using XOR operator)
    pos = 5;
    mask = 1 << pos;
    a = a ^ mask;
    printf("a = %d\n", a);                // Output: 18 (00010010 in binary)

    return 0;
}
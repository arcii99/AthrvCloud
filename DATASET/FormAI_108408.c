//FormAI DATASET v1.0 Category: Bitwise operations ; Style: calm
#include <stdio.h>

int main() {
    unsigned int a = 10; // Binary equivalent: 0000 1010
    unsigned int b = 7;  // Binary equivalent: 0000 0111
    
    printf("a & b = %u\n", a & b); // Bitwise AND: 0000 0010 (Output: 2)
    printf("a | b = %u\n", a | b); // Bitwise OR: 0000 1111 (Output: 15)
    printf("a ^ b = %u\n", a ^ b); // Bitwise XOR: 0000 1101 (Output: 13)
    printf("~a = %u\n", ~a);       // Bitwise NOT: 1111 0101 (Output: 4294967285)
    
    unsigned int c = 3; // Binary equivalent: 0000 0011
    
    printf("a << 1 = %u\n", a << 1); // Left shift by 1: 0000 1010 -> 0001 0100 (Output: 20)
    printf("b >> 1 = %u\n", b >> 1); // Right shift by 1: 0000 0111 -> 0000 0011 (Output: 3)
    printf("c << 2 = %u\n", c << 2); // Left shift by 2: 0000 0011 -> 0000 1100 (Output: 12)
    printf("c >> 2 = %u\n", c >> 2); // Right shift by 2: 0000 0011 -> 0000 0000 (Output: 0)
    
    return 0;
}
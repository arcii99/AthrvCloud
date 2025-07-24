//FormAI DATASET v1.0 Category: Bitwise operations ; Style: future-proof
#include <stdio.h>

int main() {
    unsigned int a = 0b00010110;
    unsigned int b = 0b00011101;
    printf("Initial values of A: %u, B: %u\n", a, b);
  
    // Left Shift
    unsigned int c = a << 2;
    printf("Left shifted value of A by 2 bits: %u\n", c);
  
    // Right Shift
    unsigned int d = b >> 3;
    printf("Right shifted value of B by 3 bits: %u\n", d);
    
    // Bitwise AND
    unsigned int e = a & b;
    printf("Bitwise AND of A and B: %u\n", e);
    
    // Bitwise OR
    unsigned int f = a | b;
    printf("Bitwise OR of A and B: %u\n", f);
    
    // Bitwise XOR
    unsigned int g = a ^ b;
    printf("Bitwise XOR of A and B: %u\n", g);
    
    // Bitwise NOT
    unsigned int h = ~a;
    printf("Bitwise NOT of A: %u\n", h);
  
    return 0;
}

/*
Output:
Initial values of A: 22, B: 29
Left shifted value of A by 2 bits: 88
Right shifted value of B by 3 bits: 3
Bitwise AND of A and B: 16
Bitwise OR of A and B: 31
Bitwise XOR of A and B: 15
Bitwise NOT of A: 4294967273
*/
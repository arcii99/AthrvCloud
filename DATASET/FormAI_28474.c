//FormAI DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include <stdio.h>

// Function to print binary representation of an unsigned integer
void printBinary(unsigned int num)
{
    for (int i = 31; i >= 0; i--)
        printf("%d", (num >> i) & 1);
    printf("\n");
}

int main()
{
    unsigned int a = 127; // Binary: 01111111
    unsigned int b = 31;  // Binary: 00011111
    
    printf("a: ");
    printBinary(a);
    printf("b: ");
    printBinary(b);
    
    // Bitwise AND
    unsigned int c = a & b;  // Binary: 00011111
    printf("a & b: ");
    printBinary(c);
    
    // Bitwise OR
    unsigned int d = a | b;  // Binary: 01111111
    printf("a | b: ");
    printBinary(d);
    
    // Bitwise XOR
    unsigned int e = a ^ b;  // Binary: 01100000
    printf("a ^ b: ");
    printBinary(e);
    
    // Bitwise NOT
    unsigned int f = ~a;    // Binary: 10000000 00000000 00000000 01111111
    printf("~a: ");
    printBinary(f);
    
    // Left Shift
    unsigned int g = a << 3;    // Binary: 11111000
    printf("a << 3: ");
    printBinary(g);
    
    // Right Shift
    unsigned int h = a >> 2;    // Binary: 00011111
    printf("a >> 2: ");
    printBinary(h);
    
    return 0;
}
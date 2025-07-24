//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multivariable
#include<stdio.h>

int main() {
    unsigned int a = 0x5; // 0101 in binary
    unsigned int b = 0xA; // 1010 in binary

    // Bitwise AND
    unsigned int c = a & b;
    printf("Bitwise AND: %x\n", c); // Output: 0x0

    // Bitwise OR
    unsigned int d = a | b;
    printf("Bitwise OR: %x\n", d); // Output: 0xF

    // Bitwise XOR
    unsigned int e = a ^ b;
    printf("Bitwise XOR: %x\n", e); // Output: 0xF

    // Bitwise negation
    unsigned int f = ~a;
    printf("Bitwise negation: %x\n", f); // Output: 0xFFFFFFFa

    // Bitwise left shift
    unsigned int g = a << 2; // Shift left by 2 bits
    printf("Bitwise left shift: %x\n", g); // Output: 0x14

    // Bitwise right shift
    unsigned int h = a >> 2; // Shift right by 2 bits
    printf("Bitwise right shift: %x\n", h); // Output: 0x1

    // Bitwise AND with multiple variables
    unsigned int i = 0x1;
    unsigned int j = 0x3;
    unsigned int k = 0x5;
    unsigned int l = i & j & k;
    printf("Bitwise AND with multiple variables: %x\n", l); // Output: 0x1

    // Bitwise OR with multiple variables
    unsigned int m = i | j | k;
    printf("Bitwise OR with multiple variables: %x\n", m); // Output: 0x7

    // Bitwise XOR with multiple variables
    unsigned int n = i ^ j ^ k;
    printf("Bitwise XOR with multiple variables: %x\n", n); // Output: 0x7

    // Bitwise left shift with multiple variables
    unsigned int o = i << 2 | j << 4 | k << 6;
    printf("Bitwise left shift with multiple variables: %x\n", o); // Output: 0x175

    // Bitwise right shift with multiple variables
    unsigned int p = i >> 1 | j >> 3 | k >> 5;
    printf("Bitwise right shift with multiple variables: %x\n", p); // Output: 0x1

    return 0;
}
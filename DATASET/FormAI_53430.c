//FormAI DATASET v1.0 Category: Bitwise operations ; Style: minimalist
#include <stdio.h>

int main() {
    
    unsigned int a = 0x20;   // Hexadecimal value 0x20 is 00100000 in binary
    unsigned int b = 0x01;   // Hexadecimal value 0x01 is 00000001 in binary

    printf("Initial values:\n");
    printf("a = 0x%x\n", a);
    printf("b = 0x%x\n\n", b);

    // Bitwise AND operation
    unsigned int c = a & b;
    printf("Bitwise AND operation (a & b):\n");
    printf("c = 0x%x\n\n", c);

    // Bitwise OR operation
    unsigned int d = a | b;
    printf("Bitwise OR operation (a | b):\n");
    printf("d = 0x%x\n\n", d);

    // Bitwise XOR operation
    unsigned int e = a ^ b;
    printf("Bitwise XOR operation (a ^ b):\n");
    printf("e = 0x%x\n\n", e);

    // Bitwise NOT operation
    unsigned int f = ~a;
    printf("Bitwise NOT operation (~a):\n");
    printf("f = 0x%x\n\n", f);

    // Bit shift left operation
    unsigned int g = a << 2;
    printf("Bit shift left operation (a << 2):\n");
    printf("g = 0x%x\n\n", g);

    // Bit shift right operation
    unsigned int h = a >> 2;
    printf("Bit shift right operation (a >> 2):\n");
    printf("h = 0x%x\n\n", h);

    return 0;
}
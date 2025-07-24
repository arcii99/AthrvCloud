//FormAI DATASET v1.0 Category: Bitwise operations ; Style: single-threaded
#include <stdio.h>

int main() {
    unsigned int a = 0x6; //binary: 0110
    unsigned int b = 0x5; //binary: 0101
    unsigned int c = a & b; //AND operation: 0100
    unsigned int d = a | b; //OR operation: 0111
    unsigned int e = a ^ b; //XOR operation: 0011
    unsigned int f = ~a; //NOT operation: 1001
    unsigned int g = b << 1; //LEFT SHIFT operation: 1010
    unsigned int h = a >> 1; //RIGHT SHIFT operation: 0011

    printf("a = 0x%x, b = 0x%x\n", a, b);
    printf("a & b = 0x%x\n", c);
    printf("a | b = 0x%x\n", d);
    printf("a ^ b = 0x%x\n", e);
    printf("~a = 0x%x\n", f);
    printf("b << 1 = 0x%x\n", g);
    printf("a >> 1 = 0x%x\n", h);

    return 0;
}
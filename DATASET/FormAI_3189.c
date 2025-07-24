//FormAI DATASET v1.0 Category: Bitwise operations ; Style: lively
#include <stdio.h>

typedef union {
    struct {
        unsigned int a:3;
        unsigned int b:3;
        unsigned int c:3;
        unsigned int d:3;
    }bit;
    unsigned char ch;
}BIT_REG;

int main() {
    BIT_REG reg;
    printf("Enter a character to set the register: ");
    scanf("%c", &reg.ch);

    printf("Byte in binary before any operations: %d%d%d%d%d%d%d%d\n\n", 
    reg.bit.d >> 2, reg.bit.d >> 1, reg.bit.d, 
    reg.bit.c >> 2, reg.bit.c >> 1, reg.bit.c, 
    reg.bit.b >> 2, reg.bit.b >> 1, reg.bit.b);

    reg.ch &= ~(0b00011100); // bitwise AND with NOT

    printf("Byte in binary after an AND with NOT operation: %d%d%d%d%d%d%d%d\n\n", 
    reg.bit.d >> 2, reg.bit.d >> 1, reg.bit.d, 
    reg.bit.c >> 2, reg.bit.c >> 1, reg.bit.c, 
    reg.bit.b >> 2, reg.bit.b >> 1, reg.bit.b);

    reg.ch |= 0b00100100; // bitwise OR

    printf("Byte in binary after an OR operation: %d%d%d%d%d%d%d%d\n\n", 
    reg.bit.d >> 2, reg.bit.d >> 1, reg.bit.d, 
    reg.bit.c >> 2, reg.bit.c >> 1, reg.bit.c, 
    reg.bit.b >> 2, reg.bit.b >> 1, reg.bit.b);

    reg.ch ^= 0b00010000; // bitwise XOR

    printf("Byte in binary after a XOR operation: %d%d%d%d%d%d%d%d\n\n", 
    reg.bit.d >> 2, reg.bit.d >> 1, reg.bit.d, 
    reg.bit.c >> 2, reg.bit.c >> 1, reg.bit.c, 
    reg.bit.b >> 2, reg.bit.b >> 1, reg.bit.b);

    return 0;
}
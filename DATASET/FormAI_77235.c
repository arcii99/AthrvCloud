//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Dennis Ritchie
#include <stdio.h>

/* Bitwise operations example program */
/* by Dennis Ritchie */

int main() {
    unsigned int a = 0x12345678; /* sample hexadecimal number */
    unsigned int b = 0x87654321; /* sample hexadecimal number */
    int shift = 4; /* sample shift value */
    unsigned int c = 0; /* result variable */

    printf("a = 0x%x, b = 0x%x\n\n", a, b); /* print the values of a and b */

    /* Bitwise AND operation */
    c = a & b;
    printf("a & b = 0x%x\n\n", c);

    /* Bitwise OR operation */
    c = a | b;
    printf("a | b = 0x%x\n\n", c);

    /* Bitwise XOR operation */
    c = a ^ b;
    printf("a ^ b = 0x%x\n\n", c);

    /* Bitwise NOT operation */
    c = ~a;
    printf("~a = 0x%x\n\n", c);

    /* Bitwise left shift operation */
    c = a << shift;
    printf("a << %d = 0x%x\n\n", shift, c);

    /* Bitwise right shift operation */
    c = b >> shift;
    printf("b >> %d = 0x%x\n\n", shift, c);

    /* Bitwise bit toggle operation */
    c = a;
    c ^= (1 << 0); /* toggle the first bit */
    printf("a with first bit toggled = 0x%x\n\n", c);

    return 0;
}
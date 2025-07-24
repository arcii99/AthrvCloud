//FormAI DATASET v1.0 Category: Bitwise operations ; Style: light-weight
#include <stdio.h>

int main()
{
    unsigned int a = 8; // Binary 1000
    unsigned int b = 3; // Binary 0011

    printf("Bitwise AND: %d\n", a & b); // Binary 0000 => Decimal 0
    printf("Bitwise OR: %d\n", a | b); // Binary 1011 => Decimal 11
    printf("Bitwise XOR: %d\n", a ^ b); // Binary 1011 => Decimal 11
    printf("Complement of a: %d\n", ~a); // Binary 0111 => Decimal 7
    printf("Left shift of a by 2: %d\n", a << 2); // Binary 100000 => Decimal 32
    printf("Right shift of a by 2: %d\n", a >> 2); // Binary 10 => Decimal 2

    return 0;
}
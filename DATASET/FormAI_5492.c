//FormAI DATASET v1.0 Category: Bitwise operations ; Style: portable
#include <stdio.h>

int main()
{
    unsigned int a = 60; // 0011 1100
    unsigned int b = 13; // 0000 1101

    // Bitwise AND: &
    printf("a & b = %d\n", a & b); // Outputs: 0000 1100 (decimal 12)

    // Bitwise OR: |
    printf("a | b = %d\n", a | b); // Outputs: 0011 1101 (decimal 61)

    // Bitwise XOR: ^
    printf("a ^ b = %d\n", a ^ b); // Outputs: 0011 0001 (decimal 49)

    // Bitwise NOT: ~
    printf("~a = %d\n", ~a); // Outputs: 1100 0011 (as 2's complement)

    // Bitwise Left Shift: <<
    printf("a << 2 = %d\n", a << 2); // Outputs: 1111 0000 (decimal 240)

    // Bitwise Right Shift: >>
    printf("a >> 2 = %d\n", a >> 2); // Outputs: 0000 1111 (decimal 15)

    return 0;
}
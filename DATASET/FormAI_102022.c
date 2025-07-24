//FormAI DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>

int main() {
    int a = 35;
    int b = 13;
    int c, d;

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    // Bitwise AND
    c = a & b;
    printf("a & b = %d\n", c);

    // Bitwise OR
    c = a | b;
    printf("a | b = %d\n", c);

    // Bitwise XOR
    c = a ^ b;
    printf("a ^ b = %d\n", c);

    // Bitwise NOT
    c = ~a;
    printf("~a = %d\n", c);

    // Bitwise left shift
    c = a << 2;
    printf("a << 2 = %d\n", c);

    // Bitwise right shift
    c = a >> 2;
    printf("a >> 2 = %d\n", c);

    // Compound assignment AND
    d = 10;
    d &= 5;
    printf("d = %d\n", d);

    // Compound assignment OR
    d = 10;
    d |= 5;
    printf("d = %d\n", d);

    // Compound assignment XOR
    d = 10;
    d ^= 5;
    printf("d = %d\n", d);

    // Compound assignment left shift
    d = 10;
    d <<= 2;
    printf("d = %d\n", d);

    // Compound assignment right shift
    d = 10;
    d >>= 2;
    printf("d = %d\n", d);

    return 0;
}
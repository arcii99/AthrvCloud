//FormAI DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>

int main() {
    unsigned int a = 60; // 0011 1100
    unsigned int b = 13; // 0000 1101

    printf("a = %d\n", a); // prints the decimal value of a
    printf("b = %d\n", b); // prints the decimal value of b

    // Bitwise AND => 0011 1000 = 56
    printf("a & b = %d\n", a & b);

    // Bitwise OR => 0011 1101 = 61
    printf("a | b = %d\n", a | b);

    // Bitwise XOR => 0011 0001 = 49
    printf("a ^ b = %d\n", a ^ b);

    // Bitwise NOT => 1100 0011 = 4294967235
    printf("~a = %u\n", ~a);

    // Bitwise LEFT SHIFT => 1111 0000 = 240
    printf("a << 4 = %d\n", a << 4);

    // Bitwise RIGHT SHIFT => 0000 1111 = 15
    printf("a >> 2 = %d\n", a >> 2);

    return 0;
}
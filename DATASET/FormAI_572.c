//FormAI DATASET v1.0 Category: Bitwise operations ; Style: peaceful
#include <stdio.h>

int main() {
    printf("Peaceful C Bitwise Operations Example Program\n\n");

    // Bitwise AND operator
    int a = 17;     // Binary 10001
    int b = 27;     // Binary 11011
    int c = a & b;  // Binary 10001 AND 11011 = 10001 = 17 in decimal
    printf("17 AND 27 = %d\n", c);

    // Bitwise OR operator
    a = 55;         // Binary 110111
    b = 28;         // Binary 11100
    c = a | b;      // Binary 110111 OR 11100 = 111111 = 63 in decimal
    printf("55 OR 28 = %d\n", c);

    // Bitwise XOR operator
    a = 34;         // Binary 100010
    b = 41;         // Binary 101001
    c = a ^ b;      // Binary 100010 XOR 101001 = 001011 = 11 in decimal
    printf("34 XOR 41 = %d\n", c);

    // Bitwise NOT operator
    a = 83;         // Binary 1010011
    c = ~a;         // Binary NOT 1010011 = 0101100 = 44 in decimal
    printf("NOT 83 = %d\n", c);

    // Bitwise left shift operator
    a = 8;          // Binary 01000
    c = a << 2;     // Binary 01000 shifted left by 2 positions = 010000 = 16 in decimal
    printf("8 shifted left by 2 = %d\n", c);

    // Bitwise right shift operator
    a = 17;         // Binary 10001
    c = a >> 2;     // Binary 10001 shifted right by 2 positions = 000100 = 4 in decimal
    printf("17 shifted right by 2 = %d\n", c);

    return 0;
}
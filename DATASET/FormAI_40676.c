//FormAI DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>

int main() {
    int a = 7; // Binary representation: 00000111
    int b = 12; // Binary representation: 00001100
    int c;

    printf("Initial values:\n");
    printf("a = %d\n", a);
    printf("b = %d\n\n", b);

    // Bitwise AND operation
    c = a & b; // Binary representation: 00000100

    printf("Bitwise AND:\n");
    printf("%d\n", c);
    printf("Binary: %d%d%d%d%d%d%d%d\n\n", (c >> 7) & 1, (c >> 6) & 1, (c >> 5) & 1, (c >> 4) & 1,
                                            (c >> 3) & 1, (c >> 2) & 1, (c >> 1) & 1, c & 1);

    // Bitwise OR operation
    c = a | b; // Binary representation: 00001111

    printf("Bitwise OR:\n");
    printf("%d\n", c);
    printf("Binary: %d%d%d%d%d%d%d%d\n\n", (c >> 7) & 1, (c >> 6) & 1, (c >> 5) & 1, (c >> 4) & 1,
                                            (c >> 3) & 1, (c >> 2) & 1, (c >> 1) & 1, c & 1);

    // Bitwise XOR operation
    c = a ^ b; // Binary representation: 00001011

    printf("Bitwise XOR:\n");
    printf("%d\n", c);
    printf("Binary: %d%d%d%d%d%d%d%d\n\n", (c >> 7) & 1, (c >> 6) & 1, (c >> 5) & 1, (c >> 4) & 1,
                                            (c >> 3) & 1, (c >> 2) & 1, (c >> 1) & 1, c & 1);

    // Bitwise NOT operation
    c = ~a; // Binary representation: 11111000

    printf("Bitwise NOT:\n");
    printf("%d\n", c);
    printf("Binary: %d%d%d%d%d%d%d%d\n\n", (c >> 7) & 1, (c >> 6) & 1, (c >> 5) & 1, (c >> 4) & 1,
                                            (c >> 3) & 1, (c >> 2) & 1, (c >> 1) & 1, c & 1);

    // Bitwise left shift operation
    c = a << 2; // Binary representation: 00011100

    printf("Bitwise left shift:\n");
    printf("%d\n", c);
    printf("Binary: %d%d%d%d%d%d%d%d\n\n", (c >> 7) & 1, (c >> 6) & 1, (c >> 5) & 1, (c >> 4) & 1,
                                            (c >> 3) & 1, (c >> 2) & 1, (c >> 1) & 1, c & 1);

    // Bitwise right shift operation
    c = b >> 1; // Binary representation: 00000110

    printf("Bitwise right shift:\n");
    printf("%d\n", c);
    printf("Binary: %d%d%d%d%d%d%d%d\n\n", (c >> 7) & 1, (c >> 6) & 1, (c >> 5) & 1, (c >> 4) & 1,
                                            (c >> 3) & 1, (c >> 2) & 1, (c >> 1) & 1, c & 1);

    return 0;
}
//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    // Let's play with some bitwise operations!
    int a = 12;  // binary: 00001100
    int b = 18;  // binary: 00010010

    // Bitwise AND
    int c = a & b;  // binary: 00000000
    printf("Result of bitwise AND operation on %d and %d is %d\n", a, b, c);

    // Bitwise OR
    int d = a | b;  // binary: 00011110
    printf("Result of bitwise OR operation on %d and %d is %d\n", a, b, d);

    // Bitwise XOR
    int e = a ^ b;  // binary: 00011110
    printf("Result of bitwise XOR operation on %d and %d is %d\n", a, b, e);

    // Bitwise NOT
    int f = ~a;  // binary: 11110011
    printf("Result of bitwise NOT operation on %d is %d\n", a, f);

    // Left shift
    int g = b << 2;  // binary: 01001000
    printf("Result of left shift operation on %d by 2 is %d\n", b, g);

    // Right shift
    int h = b >> 3;  // binary: 00000100
    printf("Result of right shift operation on %d by 3 is %d\n", b, h);

    return 0;
}
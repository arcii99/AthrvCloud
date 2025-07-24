//FormAI DATASET v1.0 Category: Bitwise operations ; Style: careful
#include <stdio.h>

int main()
{
    int a = 5;      // 0b101 in binary
    int b = 6;      // 0b110 in binary

    // Bitwise AND &
    int c = a & b;  // 0b100 in binary, which is equal to decimal 4
    printf("Bitwise AND of %d and %d is %d\n", a, b, c);

    // Bitwise OR |
    int d = a | b;  // 0b111 in binary, which is equal to decimal 7
    printf("Bitwise OR of %d and %d is %d\n", a, b, d);

    // Bitwise XOR ^
    int e = a ^ b;  // 0b011 in binary, which is equal to decimal 3
    printf("Bitwise XOR of %d and %d is %d\n", a, b, e);

    // Bitwise NOT ~
    int f = ~a;     // 0b11111111111111111111111111111010 in binary, which is equal to decimal -6
    printf("Bitwise NOT of %d is %d\n", a, f);

    // Bitwise left shift <<
    int g = a << 2; // 0b10100 in binary, which is equal to decimal 20
    printf("%d shifted left by 2 is %d\n", a, g);

    // Bitwise right shift >>
    int h = b >> 1; // 0b11 in binary, which is equal to decimal 3
    printf("%d shifted right by 1 is %d\n", b, h);

    return 0;
}
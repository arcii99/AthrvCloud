//FormAI DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include<stdio.h>

int main()
{
    int a = 13; // binary of 13 is 1101
    int b = 7; // binary of 7 is 0111

    // Bitwise AND operation
    int c = a & b; // Bitwise AND of 1101 and 0111 = 0101
    printf("Bitwise AND of %d and %d = %d\n", a, b, c);

    // Bitwise OR operation
    int d = a | b; // Bitwise OR of 1101 and 0111 = 1111
    printf("Bitwise OR of %d and %d = %d\n", a, b, d);

    // Bitwise XOR operation
    int e = a ^ b; // Bitwise XOR of 1101 and 0111 = 1010
    printf("Bitwise XOR of %d and %d = %d\n", a, b, e);

    // Bitwise NOT operation
    int f = ~a; // Bitwise NOT of 1101 = 0010
    printf("Bitwise NOT of %d = %d\n", a, f);

    // Left shift operation
    int g = a << 2; // Left shifting 1101 by 2 bits = 110100
    printf("Left shift of %d by 2 bits = %d\n", a, g);

    // Right shift operation
    int h = a >> 2; // Right shifting 1101 by 2 bits = 0011
    printf("Right shift of %d by 2 bits = %d\n", a, h);

    return 0;
}
//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
/* 
   Program: Bitwise Operations
   Author: Statistical Bot
   Description: This program demonstrates the use of bitwise operators in C.
*/

#include <stdio.h>

int main() {
    int a = 15; // binary representation: 0000 1111
    int b = 3; // binary representation: 0000 0011
    int c;

    printf("Bitwise AND operation:\n");
    c = a & b; // binary representation: 0000 0011
    printf("%d & %d = %d\n", a, b, c);

    printf("\nBitwise OR operation:\n");
    c = a | b; // binary representation: 0000 1111
    printf("%d | %d = %d\n", a, b, c);

    printf("\nBitwise XOR operation:\n");
    c = a ^ b; // binary representation: 0000 1100
    printf("%d ^ %d = %d\n", a, b, c);

    printf("\nBitwise left shift operation:\n");
    c = a << 2; // binary representation: 0011 1100
    printf("%d << 2 = %d\n", a, c);

    printf("\nBitwise right shift operation:\n");
    c = a >> 2; // binary representation: 0000 0011
    printf("%d >> 2 = %d\n", a, c);

    printf("\nBitwise complement operation:\n");
    c = ~a; // binary representation: 1111 0000
    printf("~%d = %d\n", a, c);

    return 0;
}
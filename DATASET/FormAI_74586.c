//FormAI DATASET v1.0 Category: Bitwise operations ; Style: systematic
#include <stdio.h>

int main()
{
    // Example of bitwise AND (&) operator
    unsigned char a = 11;  // 0000 1011 in binary
    unsigned char b = 7;   // 0000 0111 in binary
    unsigned char c = a & b; // Perform bitwise AND operation
    // Result will be 0000 0011 which is 3 in decimal
    printf("Result of AND operation: %d\n", c);

    // Example of bitwise OR (|) operator
    unsigned char d = a | b; // Perform bitwise OR operation
    // Result will be 0000 1111 which is 15 in decimal
    printf("Result of OR operation: %d\n", d);

    // Example of bitwise XOR (^) operator
    unsigned char e = a ^ b; // Perform bitwise XOR operation
    // Result will be 0000 1100 which is 12 in decimal
    printf("Result of XOR operation: %d\n", e);

    // Example of bitwise NOT (~) operator
    unsigned char f = ~a; // Perform bitwise NOT operation
    // Result will be 1111 0100 which is -12 in decimal
    printf("Result of NOT operation: %d\n", f);

    // Example of left shift (<<) operator
    int g = 5; // 0000 0101 in binary
    int h = g << 2; // Shift left by 2 bits
    // Result will be 0001 0100 which is 20 in decimal
    printf("Result of left shift operation: %d\n", h);

    // Example of right shift (>>) operator
    int i = 16; // 0001 0000 in binary
    int j = i >> 3; // Shift right by 3 bits
    // Result will be 0000 0010 which is 2 in decimal
    printf("Result of right shift operation: %d\n", j);

    return 0;
}
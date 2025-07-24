//FormAI DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>

int main() {
    int a = 7;  // 0111 in binary
    int b = 10; // 1010 in binary

    // Bitwise AND operator (&)
    int c = a & b; // 0010 in binary, which is 2 in decimal
    printf("The result of AND operator is: %d\n", c);

    // Bitwise OR operator (|)
    int d = a | b; // 1111 in binary, which is 15 in decimal
    printf("The result of OR operator is: %d\n", d);

    // Bitwise XOR operator (^)
    int e = a ^ b; // 1101 in binary, which is 13 in decimal
    printf("The result of XOR operator is: %d\n", e);

    // Bitwise NOT operator (~)
    int f = ~a; // 1000 0000 0000 0111 in binary, which is -8 in decimal
    printf("The result of NOT operator is: %d\n", f);

    // Bitwise left shift operator (<<)
    int g = a << 2; // 0111 00 in binary, which is 28 in decimal
    printf("The result of left shift operator is: %d\n", g);

    // Bitwise right shift operator (>>)
    int h = b >> 1; // 101 in binary, which is 5 in decimal
    printf("The result of right shift operator is: %d\n", h);

    return 0;
}
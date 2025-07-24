//FormAI DATASET v1.0 Category: Bitwise operations ; Style: curious
#include <stdio.h>

int main() {
    // A curious program to showcase bitwise operations in C

    // First, we will create some variables to play with
    unsigned int a = 5;     // 5 in binary: 0000 0101
    unsigned int b = 2;     // 2 in binary: 0000 0010
    unsigned int c = 0;     // We will use this variable to store the result of our operations
    printf("a = %u, b = %u, c = 0\n", a, b);

    // Now we will start our curious operations using bitwise AND operator (&)
    c = a & b;              // c = 0000 0000
    printf("a & b = %u\n", c);

    c = a & 1;              // c = 0000 0001
    printf("a & 1 = %u\n", c);

    c = a & -1;             // c = 0000 0101
    printf("a & -1 = %u\n", c);

    // Next, we will use bitwise OR operator (|)
    c = a | b;              // c = 0000 0111
    printf("a | b = %u\n", c);

    c = a | 1;              // c = 0000 0101
    printf("a | 1 = %u\n", c);

    c = a | -1;             // c = 1111 1111
    printf("a | -1 = %u\n", c);

    // Let's now try bitwise XOR operator (^)
    c = a ^ b;              // c = 0000 0111
    printf("a ^ b = %u\n", c);

    c = a ^ 1;              // c = 0000 0100
    printf("a ^ 1 = %u\n", c);

    c = a ^ -1;             // c = 1111 1010
    printf("a ^ -1 = %u\n", c);

    // For our final trick, we will use bitwise NOT operator (~)
    c = ~a;                 // c = 1111 1010
    printf("~a = %u\n", c);

    c = ~b;                 // c = 1111 1101
    printf("~b = %u\n", c);

    // That's it folks, wasn't that curious?
    return 0;
}
//FormAI DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>

int main() {
    int a = 5;
    int b = 9;

    printf("a = %d, b = %d\n", a, b);

    // Bitwise AND operator
    int c = a & b;
    printf("a & b = %d\n", c);

    // Bitwise OR operator
    int d = a | b;
    printf("a | b = %d\n", d);

    // Bitwise XOR operator
    int e = a ^ b;
    printf("a ^ b = %d\n", e);

    // Bitwise NOT operator
    int f = ~a;
    printf("~a = %d\n", f);

    // Bitwise left shift operator
    int g = a << 2;
    printf("a << 2 = %d\n", g);

    // Bitwise right shift operator
    int h = b >> 2;
    printf("b >> 2 = %d\n", h);

    // Setting a bit using bitwise OR operator
    int i = 0b0101; // Binary representation of 5
    i = i | (1 << 2); // Setting the third bit to 1
    printf("New binary value = %d\n", i);

    // Clearing a bit using bitwise AND operator
    int j = 0b1010; // Binary representation of 10
    j = j & ~(1 << 1); // Clearing the second bit
    printf("New binary value = %d\n", j);

    // Toggling a bit using bitwise XOR operator
    int k = 0b1100; // Binary representation of 12
    k = k ^ (1 << 0); // Toggling the first bit
    printf("New binary value = %d\n", k);

    return 0;
}
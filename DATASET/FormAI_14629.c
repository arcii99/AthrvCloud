//FormAI DATASET v1.0 Category: Bitwise operations ; Style: peaceful
#include <stdio.h>

int main() {
    int a = 5;
    int b = 3;
    int c;

    // Bitwise AND operator
    c = a & b; // Result should be 1
    printf("a & b = %d\n", c);

    // Bitwise OR operator
    c = a | b; // Result should be 7
    printf("a | b = %d\n", c);

    // Bitwise XOR operator
    c = a ^ b; // Result should be 6
    printf("a ^ b = %d\n", c);

    // Bitwise NOT operator
    c = ~a; // Result should be -6
    printf("~a = %d\n", c);

    // Bitwise left shift operator
    c = a << 1; // Result should be 10
    printf("a << 1 = %d\n", c);

    // Bitwise right shift operator
    c = a >> 1; // Result should be 2
    printf("a >> 1 = %d\n", c);

    return 0;
}
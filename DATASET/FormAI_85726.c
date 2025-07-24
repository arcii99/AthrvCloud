//FormAI DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>

int main() {
    int a = 27; // In binary: 11011
    int b = 14; // In binary: 01110

    // Bitwise AND operator "&"
    int c = a & b; // In binary: 01010 (decimal: 10)
    printf("Bitwise AND operator:\n");
    printf("%d & %d = %d\n\n", a, b, c);

    // Bitwise OR operator "|"
    int d = a | b; // In binary: 11111 (decimal: 31)
    printf("Bitwise OR operator:\n");
    printf("%d | %d = %d\n\n", a, b, d);

    // Bitwise XOR operator "^"
    int e = a ^ b; // In binary: 10101 (decimal: 21)
    printf("Bitwise XOR operator:\n");
    printf("%d ^ %d = %d\n\n", a, b, e);

    // Bitwise NOT operator "~"
    printf("Bitwise NOT operator:\n");
    printf("~%d = %d\n", a, ~a);
    printf("~%d = %d\n\n", b, ~b);

    // Bitwise left shift operator "<<"
    int f = a << 2; // In binary: 11101100 (decimal: 108)
    printf("Bitwise left shift operator:\n");
    printf("%d << 2 = %d\n\n", a, f);

    // Bitwise right shift operator ">>"
    int g = a >> 2; // In binary: 00011011 (decimal: 6)
    printf("Bitwise right shift operator:\n");
    printf("%d >> 2 = %d\n\n", a, g);

    return 0;
}
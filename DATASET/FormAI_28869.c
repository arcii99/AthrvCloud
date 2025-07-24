//FormAI DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
#include <stdio.h>

int main() {
    int a = 15;  // 1111 in binary
    int b = 9;   // 1001 in binary

    printf("a = %d and b = %d\n", a, b);

    // Bitwise OR operator
    int c = a | b; // 1111 | 1001 = 1111 (15)
    printf("a | b = %d\n", c);

    // Bitwise XOR operator
    int d = a ^ b; // 1111 ^ 1001 = 0110 (6)
    printf("a ^ b = %d\n", d);

    // Bitwise AND operator
    int e = a & b; // 1111 & 1001 = 1001 (9)
    printf("a & b = %d\n", e);

    // Bitwise NOT operator
    int f = ~a;   // ~1111 = 0000 (0)
    printf("~a = %d\n", f);

    // Bitwise left shift operator
    int g = a << 1; // 1111 << 1 = 11110 (30)
    printf("a << 1 = %d\n", g);

    // Bitwise right shift operator
    int h = a >> 1; // 1111 >> 1 = 0111 (7)
    printf("a >> 1 = %d\n", h);

    return 0;
}
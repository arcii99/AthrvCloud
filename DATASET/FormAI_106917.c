//FormAI DATASET v1.0 Category: Bitwise operations ; Style: portable
#include <stdio.h>

int main() {
    int a = 15;     // 00001111 (binary)
    int b = 10;     // 00001010 (binary)

    // Bitwise AND
    int c = a & b;  // 00001010 (binary)
    printf("a & b = %d\n", c);

    // Bitwise OR
    int d = a | b;  // 00001111 (binary)
    printf("a | b = %d\n", d);

    // Bitwise XOR
    int e = a ^ b;  // 00000101 (binary)
    printf("a ^ b = %d\n", e);

    // Bitwise NOT
    int f = ~a;     // 11110000 (binary)
    printf("~a = %d\n", f);

    // Bitwise LEFT SHIFT
    int g = a << 2; // 00111100 (binary)
    printf("a << 2 = %d\n", g);

    // Bitwise RIGHT SHIFT
    int h = a >> 2; // 00000011 (binary)
    printf("a >> 2 = %d\n", h);

    return 0;
}
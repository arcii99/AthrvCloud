//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 60; // 60 = 0011 1100
    int b = 13; // 13 = 0000 1101
    int c;

    printf("a = %d, b = %d\n", a, b);
    c = a & b; // 12 = 0000 1100
    printf("a & b = %d\n", c);

    c = a | b; // 61 = 0011 1101
    printf("a | b = %d\n", c);

    c = a ^ b; // 49 = 0011 0001
    printf("a ^ b = %d\n", c);

    c = ~a; // -61 = 1100 0011
    printf("~a = %d\n", c);

    c = a << 2; // 240 = 1111 0000
    printf("a << 2 = %d\n", c);

    c = a >> 2; // 15 = 0000 1111
    printf("a >> 2  = %d\n", c);

    return 0;
}